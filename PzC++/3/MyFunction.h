#pragma once
#include "stdafx.h"
#include "CW2Var8Api.hpp"
#include <fstream>
using namespace std;

class Student
{
public:
	CW2VAR8_API Student() = default;
	CW2VAR8_API Student(std::string family, int years, int number, double sr) :_family(family), _years(years), _number(number), _sr(sr) {};
	CW2VAR8_API Student (const Student& ob)
	{
		_family = ob._family;
		_years = ob._years;
		_number = ob._number;
		_sr = ob._sr;
	}
	CW2VAR8_API Student& operator = (const Student& ob) 
	{
		if (this == &ob)
			return *this;
		
		_family = ob._family;
		_years = ob._years;
		_number = ob._number;
		_sr = ob._sr;
		return *this;
	}
	CW2VAR8_API friend std::istream& operator >> (istream& in,   Student& ob)
	{
		std::cout << "Student is:\n" << "Family: ";
		in >> (char*)ob._family.c_str();
		std::cout << "Years: ";
		in >> ob._years;
		std::cout << "Number: ";
		in >> ob._number;
		std::cout << "Average: ";
		in >> ob._sr;
		return in;
	}
	CW2VAR8_API friend std::ostream& operator <<(std::ostream &stream, const Student& ob)
	{
		
		stream << "Family: " << (char*)ob._family.c_str() << endl;
		stream << "Years: " << ob._years << endl;
		stream << "Number: " << ob._number << endl;
		stream << "Average: " << ob._sr << endl;
		return stream;
	}
	CW2VAR8_API int number() const
	{
		return _number;
	}
	CW2VAR8_API int years() const
	{
		return _years;
	}
	CW2VAR8_API double sr() const
	{
		return _sr;
	}
	CW2VAR8_API std::string family() const
	{
		return _family;
	}
private:
	std::string _family;
	int _years;
	int _number;
	double _sr;
};





class Group
{
public:
	CW2VAR8_API Group()  = default;
	CW2VAR8_API Group(const Group& ob)
	{
		_group = ob._group;
	}
	CW2VAR8_API void pushstudingroup(Student& st)
	{
		_group.push_back(st);
	}
	CW2VAR8_API void delstud(int number)
	{
		list<Student>::iterator beg = _group.begin();
		while (beg != _group.end())
		{
			if (beg->number() == number)
			{
				_group.erase(beg);
				return;
			}
			++beg;
		}

	}
	template<typename F>
	list<Student> sear(F Func)
	{
		list<Student> newgroup;
		list<Student>::iterator beg = _group.begin();
		Student min = *beg;
		while (beg != _group.end())
		{
			if (Func(*beg, min))
				newgroup.push_back(*beg);
			++beg;
		}
		return newgroup;
	};
	CW2VAR8_API friend std::ostream& operator <<(std::ostream &stream, const Group& ob)
	{
		auto beg = ob.group().begin();
		while (beg != ob.group().end())
		{
			stream << *beg << ' ';
			++beg;
		}
		return stream;
	}

	CW2VAR8_API friend std::istream& operator >> (istream& in, Group& ob)
	{
		Student a;
		in >> a;
		Student l((char*)a.family().c_str(), a.years(), a.number(), a.sr());
		ob.pushstudingroup(l);
		return in;
	}
	CW2VAR8_API const list<Student>& group() const
	{
		return _group;
	}
	
private:
	list<Student> _group;
};

class Predfamily
{
public:
	bool operator()(const Student &x, const Student &y)
	{
		return (x.family() < y.family());
	}
};

class Prednumber
{
public:
	bool operator()(const Student &x,const Student  &y)
	{
		return (x.number() < y.number());
	}
};



 list<Student> otbor(const Group &a)
{
	list<Student> newgroup;
	auto beg = a.group().begin();
	auto en = a.group().end();
	std::for_each(beg, en, [&]( Student c)
	{
		if (c.sr() > 4)
			newgroup.push_back(c);
	});
	return newgroup;
};

