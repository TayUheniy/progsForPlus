#pragma once
#include "Let17Api.hpp"
LET17_API std::string Loade(const char* Typename);
class IsSepar
{
public:
	LET17_API IsSepar()
	{
		char sepa[] = "*&=<>^+-.,!  '\t''\r''\n''\"'():[]{}^\\|?/#¹;0123456789";
		int q = (int)strlen(sepa);
		for (int i = 0; i<q; ++i)
			_table[(unsigned char)sepa[i]] = true;
	}
	bool _table[256]{ 0 };
};
class Table
{
public:
	LET17_API Table()
	{
		for (int i = 0; i<256; ++i)
			_table[i] = towlower(i);
	}
	char _table[256];
};

LET17_API bool IsSeparator(char c, bool* table);
LET17_API void coun(const char* Typename, double &counterrus, double &countereng, std::multimap<int, std::string> &rusik, std::multimap<int, std::string> &anglosaks);
LET17_API bool srav(std::string a);
LET17_API bool angley(std::string a);
LET17_API char ToLower(char c, const char* tab);
