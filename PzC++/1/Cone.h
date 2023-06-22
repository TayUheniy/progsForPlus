#pragma once
#ifndef CONE_H	
#define CONE_H
#include "stdafx.h"
int lenghtstr(char *);
char* inttochar(int count);




class Cone
{

public:

	Cone( double, double, double, double, double);
	Cone(const Cone& ob);
	~Cone();
	const Cone& operator = (const Cone&);
	friend double Area(const Cone&);
	friend double Lenghtokr(const Cone& ob);
	friend double Areabok(const Cone& ob);
	friend double Ob(const Cone& ob);
	friend bool operator==(const Cone&, const Cone&);
	friend Cone operator+(const Cone&, double);
	friend bool VolEq(const Cone& left, const Cone& right);
	friend bool operator!=(const Cone& left, const Cone& right);
private:
	char* name;
	double x;
	double y;
	double z;
	double R;
	double h;
	static int count;
	void setname();

};

#endif