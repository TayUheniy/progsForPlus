#include "stdafx.h"
#include "MyFunction.h"
#include <fstream>

bool IsSeparator(char c, bool* table)
{
	return table[(unsigned char)c];
}
char ToLower(char c, const char* tab)
{
	return tab[(unsigned char)c];
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
bool srav(std::string a)
{
	std::string slovo{};
	for (int i = 0; i < 3; ++i)
	{
		if (a[i] == ' ')
			continue;
		if (a[i] <= 'z' && a[i] >= 'a')
		{
			slovo += 'e';
		}
		else
			slovo += 'r';
	}
	int k = slovo.size();
	for (int i = 1; i < k; ++i)
		if (slovo[i] != slovo[0])
			return false;
	return true;
}
bool angley(std::string slovo)
{
	int k = slovo.size();
	for (int i = 0; i < k; ++i)
		if ((slovo[i]<'a' || slovo[i]>'z') &&  slovo[i]!=' ')
			return false;
	return true;
}

void coun(const char* Typename, double &counterrus,double &countereng, std::multimap<int, std::string> &rusik, std::multimap<int, std::string> &anglosaks)
{
	std::string files = Loade(Typename);
	std::map<std::string, int> ruz; 
	std::map<std::string, int> enge;
	typedef std::pair<int, std::string> Int_Pair;
	IsSepar T;
	Table L;
	std::string slov = {};
	int count = 0;
	std::string::iterator be = files.begin();
	while (be != files.end())
	{
		if (!IsSeparator(*be, T._table) && count < 3)
		{
			slov += ToLower(*be, L._table);
			++count;
		}
		if (IsSeparator(*be, T._table) && count < 3)
		{
			if (slov.length() != 0)
			{
				if (IsSeparator(*slov.rbegin(), T._table))
				{
					++be;
					continue;
				}
			}
			++count;
			slov += ' ';
		}
		if (count == 3)
		{
			if (srav(slov))
			{
				if (angley(slov))
					++enge[slov];
				else
					++ruz[slov];
			}
			slov = {};
			--be;
			--be;
			count = 0;
		}
		++be;
		
	}
	for (std::map<std::string, int>::iterator begi = ruz.begin(); begi != ruz.end(); ++begi)
	{
		rusik.insert(Int_Pair(begi->second, begi->first));
		counterrus += begi->second;
	}
	for (std::map<std::string, int>::iterator begi = enge.begin(); begi != enge.end(); ++begi)
	{
		anglosaks.insert(Int_Pair(begi->second, begi->first));
		countereng += begi->second;
	}
}

