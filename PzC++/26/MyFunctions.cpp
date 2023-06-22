#include "stdafx.h"
#include "MyFunctions.h"

/*double func1(double x)
{
	return x * x*x + x * x + x -39;
}*/

double func(double x)
{
	return  x*x - 4 ;
}

bool proverka(double x0, double x1)
{
	double y1 = func(x1);
	double y2 = func(x0);
	if (y1*y2 > 0)
		return false;
	return true;
}

double solutionofuravn(FPT func, double x0, double x1, double e)
{
	
	while (abs(x1 - x0) > e)
	{
		if (abs(func(x1)) < e) 
			return x1;
		if (abs(func(x0)) < e)
			return x0;
		double x2 = x0 - (x1 - x0) / (func(x1) - func(x0))*func(x0);
		//double x2 = (func(x1)*x0 - func(x0)*x1) / (func(x1) - func(x0));
		if ((func(x2)*func(x0)) > 0)
			x0 = x2;
		else
			x1 = x2;
	}
	return (x1+x0)/2;
}


int lenght(const char* a)
{
	int k(0);
	while (*(a + k))
		++k;
	return k;
}
long long perevod(const char* a)
{
	int base(1);
	long long s(0);
	int leng = lenght(a);
	for (int i = leng - 1; i >= 0; --i)
	{
		s += (a[i] - '0')*base;
		base *= 10;
	}
	return s;
}


char minc(char a, char b, char c)
{
	/*if ((a < b) && (a < c))
		return (int)a;
	if ((b < a) && (b < c))
		return (int)b;
	return (int)c;*/
	char res = a;
	if (b < res)
		res = b;
	if (c < res)
		res = c;
	return res;
}

int minc(int a, int b, int c)
{
	if ((a < b) && (a < c))
		return a;
	if ((b < a) && (b < c))
		return b;
		return c;
}
long long minc(long long a, long long b, long long c)
{
	if ((a < b) && (a < c))
		return a;
	if ((b < a) && (b < c))
		return b;
		return c;
}