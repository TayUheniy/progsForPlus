#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "Cone.h"
#include <fstream>
using namespace std;
int lenghtstr(char* c)
{
	int k = 0;
	while (*(c + k))
		++k;
	return k;
}

char *inttochar(int count)
{
	int k = 1;
	int cou = count;
	while (cou / 10 > 0)
	{
		cou /= 10;
		++k;
	}
	char* s = new char[k+1];
	if (count <= 9 && count >= 0)
	{
		s[0] = (char)count + '0';
		s[1] = '\0';
		return s;
	} 
	for (int i = k-1; i >=0; --i)
		{
			int co = count % 10;
			s[i] = (char)co + '0';
			count /= 10;
		}
	s[k] = '\0';
	return s;
}

void Cone::setname()
{
	char* name1 = (char*)"Cone#";
	char* coun = inttochar(count);

	int novco = log10(count) + 1;
	name = new char[5 + novco + 1]{};
	for (int i = 0; i < 5; ++i)
		name[i] = name1[i];
	strcat(name, coun);
}
int Cone::count;

Cone::Cone(double x1, double y1, double z1, double R1, double h1)
{
	++count;
	setname();
	

	cout << name << endl;

	x = x1;
	y = y1;
	z = z1;
	R = R1;
	h = h1;
	cout << "Coord center: " << "x=" << x << " y=" << y << " z=" << z << endl;
	cout << "Radius: " << "R=" << R << endl;
	cout << "Height: " << "h=" << h << endl << endl;
	
}

Cone::Cone(const Cone& ob)
{
	++count;
	setname();
	cout << name << endl;
	

	x = ob.x;
	y = ob.y;
	z = ob.z;
	R = ob.R;
	h = ob.h;

	cout << "Coord center: " << "x=" << x << " y=" << y << " z=" << z << endl;
	cout << "Radius: " << "R=" << R << endl;
	cout << "Height: " << "h=" << h << endl << endl;

}

Cone::~Cone()
{
	//--count;
}

const Cone& Cone::operator = (const Cone& ob)
{
	if (this == &ob)
		return *this;
	x = ob.x;
	y = ob.y;
	z = ob.z;
	R = ob.R;
	h = ob.h;
	return *this;

}

double Area(const Cone& ob)
{
	return M_PI * (ob.R)*(ob.R);
}

double Lenghtokr(const Cone& ob)
{
	return M_PI * 2 * (ob.R);
}

double Areabok(const Cone& ob)
{
	return  M_PI * (ob.R)* sqrt(ob.h*ob.h*ob.R*ob.R);
}

double Ob(const Cone& ob)
{
	return (1. / 3.)*M_PI*ob.R*ob.R*ob.h;
}

bool operator==(const Cone& left, const Cone& right)
{
	return  (left.x == right.x && left.y == right.y &&
		left.z == right.z && left.R == right.R && left.h == right.h);
}
bool operator!=(const Cone& left, const Cone& right)
{
	return  !(operator==(left, right));
}
bool VolEq(const Cone& left, const Cone& right)
{
	return (Ob(left) == Ob(right));
		
}

Cone operator+(const Cone& ob, double g)
{
	Cone nov(ob.x, ob.y, ob.z, ob.R + g, ob.h);
	return nov;
}