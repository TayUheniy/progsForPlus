#include "stdafx.h"
#include "MyFunctions.h"
#include <fstream>
using namespace std;

void sizeq(const char *fileName, int& n, int& m)
{
	ifstream fin(fileName);
	while (!fin.eof())
	{
		char c;
		fin.get(c);
		if (c == ' ') ++m;
		if (c == '\n') ++n;
	}
	++n;
	m = m / n;
	++m;
}

void strfromfile(const char *fileName, const int n,const int m, int** &A)
{
	ifstream fin(fileName);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			fin >> A[i][j];
}

bool sravn(const int n, const int m, int** &A, int i, int j)
{
	int k = 0;
	A[i][j] = -1;
	if (i == (n - 2) && j == (m - 2))
		return true;
	if (A[i][j + 1] == 0)
	{
		k += sravn(n, m, A, i, j + 1);
	}
	if (A[i+1][j] == 0)
	{
		k += sravn(n, m, A, i+1, j);
	}
	if (A[i-1][j] == 0)
	{
		k += sravn(n, m, A, i -1, j);
	}
	if (A[i][j-1] == 0)
	{
		k += sravn(n, m, A, i, j-1);
	}
	if (k != 0) return true;
	return false;
}

bool MazeWay(const char *fileName)
{
	int n(0);
	int m(0);
	sizeq(fileName, n, m);
	int** A = new int*[n];
	for (int i = 0; i < n; ++i)
		A[i] = new int[m];
	strfromfile(fileName, n, m, A);
	return sravn(n, m, A, 1, 1);
}

