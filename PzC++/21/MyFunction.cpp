#include "stdafx.h"
#include "MyFunction.h"
#include <fstream>


void sorter(std::vector<int>& a)
{
	auto f = [](int a, int b) {return a < b; };
	std::sort(a.begin(), a.end(), f);
}

std::vector<int> strtovect(std::string &chisla)
{
	std::vector<int> rez;
	std::string buffer{};
	int buff;
	int count = 0;
	int len = chisla.size();
	std::for_each(chisla.begin(), chisla.end(), [&](char a)
	{
		++count;
		if (count == len)
		{
			buffer += a;
			buff = atoi(buffer.c_str());
			rez.push_back(buff);
			buffer = {};
		}
		if (a == ' ')
		{
			buff = atoi(buffer.c_str());
			rez.push_back(buff);
			buffer = {};
		}
		else
		{
			buffer += a;
		}

	});
	return rez;
}

std::string obr(std::vector<int> vec)
{
	std::string rez;
	int count = 0;
	int len = vec.size();
	std::for_each(vec.begin(), vec.end(), [&rez,&count,&len](int n)
	{
		++count;
		if (count == len)
			rez += std::to_string(n);
		else
		{
			rez += std::to_string(n);
			rez += ' ';
		}
	});
	return rez;
}

std::string sorterstr(std::string &chisla)
{
	std::vector<int> buffer = strtovect(chisla);
	sorter(buffer);
	return obr(buffer);
}

std::vector<std::string> otbor(int leng, int &count, std::string slova)
{
	std::vector<std::string> rez;
	std::string buffer;
	int konez=0;
	int len = slova.size();
	std::for_each(slova.begin(), slova.end(), [&](char c)
	{
		++konez;
		if (konez == len)
		{
			++count;
			buffer += c;
			if (buffer.size() == leng)
				rez.push_back(buffer);
			buffer = {};
		}
		if (c == ' ' || c == ',')
		{
			++count;
			if (buffer.size() == leng)
				rez.push_back(buffer);
			buffer = {};
		}
		else
			buffer += c;
		
	});
	return rez;
}

std::string searc(std::string str)
{
	std::string maxword;
	std::string buffer;
	int strend = 0;
	int len = str.size();
	std::for_each(str.begin(), str.end(), [&](char c)
	{
		++strend;
		if (strend == len && c == 'y')
		{
			buffer += c;
			if (buffer.size() > maxword.size())
				maxword = buffer;
		}
		if (c == ' '|| c==',') 
		{
			if (buffer[buffer.size() - 1] == 'y')
				if (buffer.size() > maxword.size())
					maxword = buffer;
			buffer = {};
		}
		else
			buffer += c;
	});
	return maxword;
}

std::string iskl(std::string str)
{
	std::string buffer;
	std::string rez;
	bool isA = 0;
	int strend = 0;
	int len = str.size();
	std::for_each(str.begin(), str.end(), [&](char c)
	{
		++strend;
		if (strend == len)
		{
			buffer += c;
			if (c == 'a')
				isA = 1;
			if (isA != 1)
				rez += buffer;
		}
		if (c == ' ' || c == ',')
		{
			buffer += c;
			if (isA != 1)
				rez += buffer;
			buffer = {};
			isA = 0;
		}
		else
		{
			if (c == 'a')
				isA = 1;
			buffer += c;
		}
	});
	if (rez[rez.size() - 1] == ' ')
		rez.erase(--rez.end());
	return rez;
}

std::string Loade(const char* Typename)
{
	FILE *ptrFile;
	fopen_s(&ptrFile, Typename, "r+");
	if (ptrFile == nullptr)
		return 0;
	std::string rez{};
	fseek(ptrFile, 0, SEEK_END);
	long fileSize = ftell(ptrFile);
	rewind(ptrFile);
	
	char* buffer = new char[fileSize + 1]{};
		
	fread(buffer, 1, fileSize, ptrFile);
	buffer[fileSize] = '\0';
	fileSize = 0;	
	rez = buffer;
	delete[] buffer;
	
	fclose(ptrFile);
	return rez;
}

std::string otborstr(std::string slova)
{
	std::string buffer{};
	std::string bufferstr{};
	std::string rez{};
	bool symvola = 0;
	int konez = 0;
	int len = slova.size();
	std::for_each(slova.begin(), slova.end(), [&](char c)
	{
		++konez;
		if (konez == len)
		{
			buffer += c;
			if (buffer.size() == 2)
				if ((buffer[0] >= '0' && buffer[0] <= '9') && (buffer[1] >= '0' && buffer[1] <= '9'))
					symvola = 1;
			bufferstr += buffer;
			if (symvola != 1)
				rez += bufferstr;
		}
		if (c == ' ' || c == ',' || c == '\n')
		{
			if (buffer.size() == 2)
				if ((buffer[0] >= '0' && buffer[0] <= '9') && (buffer[1] >= '0' && buffer[1] <= '9'))
					symvola = 1;
			buffer += c;
			bufferstr += buffer;
			if (c == '\n')
			{
				if (symvola != 1)
					rez += bufferstr;
				symvola = 0;
				buffer = {};
				bufferstr = {};
			}
			buffer = {};
		}
		else
			buffer += c;
	});
	return rez;
}

std::string rezotborstr(const char* Typename)
{
	std::string rez = Loade(Typename);
	return otborstr(rez);
}