#include "stdafx.h"
#include "MyFunction.h"
int log2(int znach)
{
	if (znach <= 0) 
		return -2; 
	
	int peremen = 1;
	int stepen = 0;
		
	while (peremen < znach)
	{
		peremen *= 2;
		++stepen;
	}
		
	if (peremen == znach)
		return stepen;
	
	return -1;
}

int NOD_rec(int x, int y)
{
	
	if (x == 0)  
		return y;
	if (y == 0) 
		return x;
	
	if (x < y)
		return NOD_rec(x, y%x); 
	if (x>y)
		return NOD_rec(x%y, y);
		return x;
}

int NOD_nerec(int x, int y)
{
	if (x == 0)
		return y;
	if (y == 0) 
		return x;

	if (x != y)
		while (x != y)
			{
			if (x > y)
				x -= y;
			if (x<y)
				y -= x;
			}

		return x;
}

double Taylor(double x, double E, int &n)
{
	n = 1;
	double s = x - 1, c = x - 1;
	
	while (abs(c) >= E)
	{
		c *= -(x - 1)*n / (n + 1);
		s +=  c;
		++n;
	}
	return s;
}