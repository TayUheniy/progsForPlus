
#include "stdafx.h"
#include "MyFunctions.h"
int lenghtstr(const char* str)
{
	int lenght = 0;
	
	while (*(str + lenght))
		++lenght;
	return lenght;
}

int indexofbracket(char c, const char* s)
{
	int i = 0;
	
	while (*(s+i))
	{
		if (c == *(s+i))
			return i;
		++i;
	}
	return -1;
}

bool proverka(const char* str, const char* s)
{
	int top = -1;
	int n = lenghtstr(str);
	int *stack = new int[n];
	while (*str)
	{
		const char* sn = s;
		int i = indexofbracket(*str, sn);
		if (i == -1)
		{
				++str;
				continue;
		}

		if ((i % 2) == 0)
		{
			++top;
			stack[top] = i;
			
		}
		else
		{
			if (top != -1 && i - stack[top] == 1)
				--top;
			else
				return false;
		}
		++str;
	}
	return(top == -1);

}

