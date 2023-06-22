#pragma once
#include "Let16Api.hpp"

class Table
{
public:
	LET16_API const char* getTable()
	{
		static char _table[256];
		for(int i = 0; i<256;++i)
			_table[i]=tolower(i);
		return _table;
	}
};

class IsSepar
{
public:
	LET16_API IsSepar()
	{
		char sepa[] = "*&=<>^+-.,! '\r''\n''\"'():[]{}^\\|?/#¹;0123456789";
		int q = strlen(sepa);
		for (int i = 0; i<q; ++i)
			_table[(unsigned char)sepa[i]] = true;
	}
	bool _table[256]{0};
};

LET16_API char ToLower(char c, const char* tab);
LET16_API bool IsSeparator(char c, bool* table);
LET16_API std::string Loade(const char* Typename);
LET16_API std::vector<std::string> Vocablur(const char* Typename);
LET16_API bool srav(std::vector<std::string>::iterator begin, std::vector<std::string>::iterator end, std::string slov);
LET16_API std::multimap<int, std::string> coun(const char* Typename);
