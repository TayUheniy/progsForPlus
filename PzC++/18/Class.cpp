#include "stdafx.h"
#include "Class.h"


Rings &Rings::operator= (const Rings& ob)
{
	if (this == &ob)
		return *this;
	_r = ob._r;
	_R = ob._R;
	_S = ob._S;
	return *this;
}

Rings::Rings(double r, double R)
{
	if (r >= R) throw std::runtime_error("Incorrect radius");
	_r = r;
	_R = R;
	_S = M_PI * _R*_R - M_PI * _r*_r;
}

double Rings::Area() 
{
	return _S;
}
