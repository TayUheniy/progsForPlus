#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "Matrix.h"
#include <fstream>
using namespace std;


Matrica::Matrica(int stro, int stol)
{
	strok = stro;
	stolb = stol;
	 arr = new int*[strok];
	 for (int i = 0; i < strok; ++i)
		 arr[i] = new int[stolb] {};

	
}

Matrica::Matrica(const Matrica& ob)
{
	Inizialize(ob);
}

inline void Matrica::Inizialize(const Matrica& ob)
{
	strok = ob.strok;
	stolb = ob.stolb;

	arr = new int*[strok];
	for (int i = 0; i < strok; ++i)
	{
		arr[i] = new int[stolb];
		for (int j = 0; j < stolb; ++j)
			arr[i][j] = ob.arr[i][j];
	}
}

Matrica::~Matrica()
{
	for (int i = 0; i < strok; ++i)
		delete[] arr[i];
	delete[] arr;
}

const Matrica& Matrica::operator = (const Matrica& right)
{
	if (this == &right)
		return *this;

	cleaner(arr, strok);

	Inizialize(right);

	return *this;

}

int **outputbyfile(const char* fname, int& strok, int&  stolb)
{
	ifstream fin(fname);
	if (!fin)
		throw std::runtime_error("bad file");
	fin >> strok >> stolb;

	int **arr = new int*[strok];
	for (int i = 0; i < strok; ++i)
		arr[i] = new int[stolb];

	for (int i = 0; i < strok; ++i)
		for (int j = 0; j < stolb; ++j)
			fin >> arr[i][j];
	return arr;
}

void cleaner(int** arr, int& strok)
{
	for (int i = 0; i < strok; ++i)
		delete[] arr[i];
	delete[] arr;
}

void prisvintmatr(int **arr2, int strok, int stolb,  Matrica &right )
{
	cleaner(right.arr, right.strok);
	strok = right.strok;
	stolb = right.stolb;

	right.arr = new int*[strok];
	for (int i = 0; i < strok; i++)
		right.arr[i] = new int[stolb];

	for (int i = 0; i < strok; ++i)
		for (int j = 0; j < stolb; ++j)
			right.arr[i][j] = arr2[i][j];

}

bool operator==(const Matrica& left, const Matrica& right)
{
	if (left.strok != right.strok || left.stolb != right.stolb)
		return false;
	for (int i=0; i<left.strok; ++i)
		for (int j = 0; j < left.stolb; ++j)
			if (left.arr[i][j] != right.arr[i][j])
				return false;
	return true;
		
}

Matrica Matrica::operator+(const Matrica &right )
{
	if (strok != right.strok || stolb != right.stolb)
		throw std::runtime_error("bad sizes");
	Matrica nov(strok, stolb);                
	for (int i = 0; i < right.strok; ++i)
		for (int j = 0; j < right.stolb; ++j)
			nov.arr[i][j] = arr[i][j] + right.arr[i][j];
	return nov;
			
}

Matrica operator*(const Matrica &left, const Matrica &right)
{
	Matrica nov(left.strok, right.stolb);
	if (left.stolb != right.strok)
		throw std::runtime_error("bad sizes");
	for (int i = 0; i < left.strok; ++i)
		for (int j = 0; j < right.stolb; ++j)
			for (int s = 0; s < right.strok; ++s)
				nov[i][j] += left.arr[i][s] * right.arr[s][j];
	return nov;
}

int* Matrica::operator[](int index) const
{
	if (index>=strok || index<0)
		throw std::runtime_error("bad sizes");
	return arr[index];
}