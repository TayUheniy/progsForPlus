#pragma once
#include "stdafx.h"
#include "MyFunctions.h"


void ReverseWord(char *a, size_t b)
{
	for (size_t i = 0; i < b / 2; ++i)
	{
		char c = a[i];
		a[i] = a[b - 1 - i];
		a[b - 1 - i] = c;
			
	}
}

void Reverse(char *str)
{
	char* sl;
	while (*str != '\0')
	{
		
		while ((*str == ' ') || (*str == '\t'))
			++str;
		sl = str;
		
		while ((*str != ' ') && (*str != '\t') && (*str != '\0'))
			++str;
		ReverseWord(sl, str - sl);
	}
}


