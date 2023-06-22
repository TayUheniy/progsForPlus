#include "stdafx.h"
#include "MyFunctions.h"



double **ReadBinary(const char *fileName, int &n, int &m)
{
	FILE *ptrFile;
	ptrFile = fopen(fileName, "rb");
	
	fread(&n, sizeof(int), 1, ptrFile);
	fread(&m, sizeof(int), 1, ptrFile);
	double **arr = new double*[n];
	for (int i = 0; i < n; ++i)
	{ 
		arr[i] = new double[m];
		for (int j = 0; j<m; ++j)
			fread(&arr[i][j], sizeof(double), 1, ptrFile);
		}
	return arr;
}

double proizv(double** arr, int n, int m)
{
	double* min = new double[n];
	int k = 0;
	double prois = 1;
	for (int i = 0; i < n; ++i)
	{
		min[k] = arr[i][0];
		for (int j = 0; j < m; ++j)
			if (arr[i][j] < min[k])
				min[k] = arr[i][j];
		++k;
	}
	for (int i = 0; i < n; ++i)
		prois *= min[i];
	return prois;
}
