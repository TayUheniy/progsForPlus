#pragma once
#include "Pz1114Api.hpp"
using namespace std;
struct IRoot
{
	PZ1114_API virtual ~IRoot()
	{
	}
	PZ1114_API virtual void Save(std::ostream& stream) = 0;
	PZ1114_API virtual void Solution() = 0;
};

typedef IRoot *(*BaseLoaderPtr)(std::istream& stream);

struct BaseFactory
{
	PZ1114_API void RegisterLoader(const std::string& typeName, BaseLoaderPtr loader)
	{
		_registered[typeName] = loader; 
	}

	PZ1114_API BaseLoaderPtr GetLoader(const std::string& typeName)
	{
		if(_registered.find(typeName) == _registered.end())
			throw std::runtime_error("Illegal type!");
		return _registered[typeName];
	}

	PZ1114_API static BaseFactory& GetInstance()
	{
		static BaseFactory soleInstance;
		return soleInstance;
	}
private:
	std::map<std::string, BaseLoaderPtr> _registered;
};

class Linear : public IRoot
{
public:
	PZ1114_API Linear(double, double);
	PZ1114_API void Save(std::ostream& stream) override;
	PZ1114_API void Solution()
	{
		if ((k == 0) && (b != 0)) 
			throw std::runtime_error("Нет корней");
		if ((b==0) && (k == 0)) 
			throw std::runtime_error("Бесконечно много корней");
		x = (-1)*b / k;
	}
	PZ1114_API double get_b() const
	{
		return b;
	};
	PZ1114_API double get_k() const
	{
		return k;
	};
	PZ1114_API double get_x()
	{
		return x;
	}

	PZ1114_API static IRoot *Load(std::istream& stream)
	{
		double a, b;
		stream >> a >> b;
		return new Linear(a, b);
	}

private:
	double k, b, x;
};

class Square : public IRoot
{
public:
	PZ1114_API Square(double, double, double);
	PZ1114_API void Save(std::ostream& stream) override;
	PZ1114_API void Solution()
	{
		x1 = ((-1)*b + sqrt(get_d())) / (2 * a);
		x2 = ((-1)*b - sqrt(get_d())) / (2 * a);
		
	};
	PZ1114_API static IRoot *Load(std::istream& stream)
	{
		double a, b, c;
		stream >> a >> b >> c;
		return new Square(a, b, c);
	};
	PZ1114_API double get_a() const
	{
		return a;
	};
	PZ1114_API double get_b() const
	{
		return b;
	};
	PZ1114_API double get_c() const
	{
		return c;
	}
	PZ1114_API double get_d()
	{
		d = b * b - 4 * a*c;
		if (d < 0) throw std::runtime_error("Нет корней");
		return d;
	}
	PZ1114_API double get_x1() const
	{
		return x1;
	}
	PZ1114_API double get_x2() const
	{
		return x2;
	}

private:
	double a, b, c, x1, x2, d;
};

PZ1114_API void RegisterLoaders();

PZ1114_API void Save(std::ostream& stream, IRoot  **bases, int count);

PZ1114_API std::vector<IRoot *> Load(std::ifstream& stream);

PZ1114_API bool Save(const char *fileName, IRoot **objects, size_t size);

PZ1114_API vector<IRoot *> Load(const char *fileName);


