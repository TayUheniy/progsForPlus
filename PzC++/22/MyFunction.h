#pragma once
#include "Pz18Api.hpp"
PZ18_API std::wstring Loade(const char* Typename);
class IsSepar
{
public:
	PZ18_API IsSepar()
	{
		wchar_t sepa[] = L" *&=<>^+-.,!'\t''\r''\n''\"'():[]{}^\\|?/#;0123456789";
		
		for (int i = 0; i<49; ++i)
			_table[static_cast<wchar_t>(sepa[i])] = true;
	}
	bool _table[65535]{ 0 };
};
class Table
{
public:
	PZ18_API  Table()
	{
		for (int i = 0; i<65535; ++i)
			_table[i] = static_cast<wchar_t>(towlower(i));
	}
	wchar_t _table[65535];
};
PZ18_API bool IsSeparator(wchar_t c, bool* table);
PZ18_API void coun(const char* Typename, double &counterrus, double &countereng, std::multimap<int, std::wstring> &rusik, std::multimap<int, std::wstring> &anglosaks);
PZ18_API bool srav(std::wstring a);
PZ18_API bool angley(std::wstring a);
PZ18_API wchar_t ToLower(wchar_t c, const wchar_t* tab);