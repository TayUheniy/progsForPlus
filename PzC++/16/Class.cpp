#include "stdafx.h"
#include "Class.h"

void RegisterLoaders()
{
	BaseFactory::GetInstance().RegisterLoader("Linear", Linear::Load);
	BaseFactory::GetInstance().RegisterLoader("Square", Square::Load);
}

bool Save(const char *fileName, IRoot **objects, size_t size)
{
	std::ofstream outFile(fileName);
	if (!outFile)
		return false;
	Save(outFile, objects, size);
	for (size_t i = 0; i < size; ++i)
		delete objects[i];
	return true;
}

void Save(std::ostream& stream, IRoot **bases, int count)
{
	for (int i = 0; i < count; ++i)
		bases[i]->Save(stream);
}

std::vector<IRoot*> Load(std::ifstream& stream)
{
	std::vector<IRoot*> result;	
	std::string typeName;

	while (stream >> typeName)
	{
		
		IRoot *base = BaseFactory::GetInstance().GetLoader(typeName)(stream);

		
		result.push_back(base);
	}
	return result;
}

vector<IRoot *> Load(const char *fileName)
{
	std::ifstream inFile(fileName);
	if (!inFile)
		throw std::runtime_error("Cannot open file!");
	auto objects = Load(inFile);	
	return objects;
}

Square::Square(double a1, double b1, double c1)
{
	a = a1;
	b = b1;
	c = c1;
}

Linear::Linear(double k1, double b1 )
{
	k = k1;
	b = b1;
}

void Square::Save(std::ostream& stream)
{
	stream << "Square " << a << ' ' << b << ' ' << c  << std::endl;
}

void Linear::Save(std::ostream& stream)
{
	stream << "Linear " << k << ' ' << b  << std::endl;
}