#include "stdafx.h"
#include "MyFunction.h"
#include <fstream>
char ToLower(char c, const char* tab)
{
	return tab[(unsigned char)c];
}
bool IsSeparator(char c, bool* table)
{
	return table[(unsigned char)c];
}

std::vector<std::string> Vocablur(const char* Typename)
{
	std::vector<std::string> rez;
	std::string r{};
	//r.resize(50);
	std::ifstream fin(Typename);
	while (!fin.eof())
		{
			char c;
			fin.get(c);
			if (c == '.')
			{
				rez.push_back(r);
				break;
			}
			if (c != '\n')
				r += c;
			else
			{
				rez.push_back(r);
				r = {};
			}
		}
	/*{
		fin.getline(const_cast<char*>(r.c_str()),50);
		rez.push_back(r);
		r = {};
		r.resize(50);
	}*/
	return rez;
}

std::multimap<int, std::string> coun(const char* Typename)
{
	std::string files = Loade(Typename);
	std::string::iterator be = files.begin();
	std::vector<std::string> voc = Vocablur("C:\\Users\\artem\\Desktop\\voc.txt");
	std::map<std::string, int> rez;
	typedef std::pair<int, std::string> Int_Pair;
	IsSepar T;
	Table L;
	std::string slov = {};
	while (be != files.end())
	{
		if (!IsSeparator(*be, T._table))
			slov += ToLower(*be, L.getTable());
		if (IsSeparator(*be, T._table))
		{
			if ((srav(voc.begin(), voc.end(), slov)) || slov.length() == 0 || slov.length()== 1)
			{
				slov = {};
				++be;
				continue;
			}
			++rez[slov];
			slov = {};
		}
		++be;
	}
	std::multimap<int, std::string> rezult;
	for (auto begi = rez.begin(); begi != rez.end(); ++begi)
		rezult.insert(Int_Pair(begi->second, begi->first));
	return rezult;
}

bool srav(std::vector<std::string>::iterator begin, std::vector<std::string>::iterator end, std::string slov)
{
	auto first = begin;
	while (first != end)
	{
		if (slov == *first)
			return true;
		++first;
	}
	return false;
}

std::string Loade(const char* Typename)
{
	FILE *ptrFile;
	fopen_s(&ptrFile,Typename, "r");
	if (ptrFile == nullptr)
		return 0;
	std::string rez{};
	fseek(ptrFile, 0, SEEK_END);
	long fileSize = ftell(ptrFile);
	rewind(ptrFile);
	long count = 1024;
	for (; fileSize != 0;)
	{
		char* buffer = new char [count+1] {};
		if (fileSize - count > count)
		{
			fread(buffer, 1, count, ptrFile);
			fileSize -= count;
			buffer[count] = '\0';
		}
		else
		{
			fread(buffer, 1, fileSize, ptrFile);
			buffer[fileSize] = '\0';
			fileSize = 0;
		}
		rez += buffer;
		delete[] buffer;
	}
	fclose(ptrFile);
	return rez;
}
