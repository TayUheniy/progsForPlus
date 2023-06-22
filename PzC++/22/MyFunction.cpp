#include "stdafx.h"
#include "MyFunction.h"
#include <fstream>

bool IsSeparator(wchar_t c, bool* table)
{
	return table[static_cast<wchar_t>(c)];
}
wchar_t ToLower(wchar_t c, const wchar_t* tab)
{
	return tab[static_cast<wchar_t>(c)];
}

std::wstring Loade(const char* Typename)
{
	FILE *ptrFile;
	fopen_s(&ptrFile, Typename, "r");
	if (ptrFile == nullptr)
		return 0;
	std::string rez{};
	fseek(ptrFile, 0, SEEK_END);
	long fileSize = ftell(ptrFile);
	rewind(ptrFile);
	long count = 1024;
	for (; fileSize != 0;)
	{
		char* buffer = new char[count + 1]{};
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
	std::wstring rezult(rez.size(), 0);
	MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, rez.c_str(), -1, const_cast<wchar_t*>(rezult.data()), static_cast<int>(rez.size()));

	return rezult;
}


bool srav(std::wstring a)
{
	std::wstring slovo{};
	for (int i = 0; i < 3; ++i)
	{
		if (a[i] == L' ')
			continue;
		if (a[i] <= L'z' && a[i] >= L'a')
		{
			slovo += L'e';
		}
		else
			slovo += L'r';
	}
	int k = slovo.size();
	for (int i = 1; i < k; ++i)
		if (slovo[i] != slovo[0])
			return false;
	return true;
}
bool angley(std::wstring slovo)
{
	int k = slovo.size();
	for (int i = 0; i < k; ++i)
		if ((slovo[i]<L'a' || slovo[i]>L'z') && slovo[i] != L' ')
			return false;
	return true;
}

void coun(const char* Typename, double &counterrus, double &countereng, std::multimap<int, std::wstring> &rusik, std::multimap<int, std::wstring> &anglosaks)
{
	std::wstring files = Loade(Typename);
	std::map<std::wstring, int> ruz;
	std::map<std::wstring, int> enge;
	typedef std::pair<int, std::wstring> Int_Pair;
	IsSepar T;
	Table L;
	std::wstring slov = {};
	int count = 0;
	std::wstring::iterator be = files.begin();
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
			slov += L' ';
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
	for (std::map<std::wstring, int>::iterator begi = ruz.begin(); begi != ruz.end(); ++begi)
	{
		rusik.insert(Int_Pair(begi->second, begi->first));
		counterrus += begi->second;
	}
	for (std::map<std::wstring, int>::iterator begi = enge.begin(); begi != enge.end(); ++begi)
	{
		anglosaks.insert(Int_Pair(begi->second, begi->first));
		countereng += begi->second;
	}
}
