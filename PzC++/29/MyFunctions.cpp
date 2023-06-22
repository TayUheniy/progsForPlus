
#include "stdafx.h"
#include "MyFunctions.h"

int lenght_str(const char* c)
{
	int lenght = 0;
	while (*(c+lenght) != '\0')
	{
		++lenght;
	}
	return lenght;
}

int position_of_point(const char* s)
{

	int position=0;
	while (*s != '.' && *s!='\0')
	{
		++position;
		++s;
	}
	return position;
}

int chartoint(char c)
{
	int l = 0;
	if ((c >= '0') && (c <= '9'))
		l = c - '0';
	if ((c >= 'a') && (c <= 'q'))
		l = c - 'a' + 10;
	return l;
}

double perevod(const char* s)
{
	double ch = 0;
	double d = 1;
	int k = position_of_point(s);
	int base = 27;
	
	for (int i =k-1 ; i >= 0; --i)
	{
		
		ch += chartoint(s[i]) * d;
		d *= base;

	}
	d = 27;
	base = 27;
	int u = lenght_str(s);
	
	for (int i = k + 1; i < u; ++i)
	{
		ch += chartoint(s[i]) / d;
		d *= base;
	}

	return ch;
}
