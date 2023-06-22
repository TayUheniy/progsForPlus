#include "stdafx.h"
#include "MyFunctions.h"
int sum(int arr[], int n)
{
	int vse = 0;
	int posl_n = 0;
	for (int i = 0; i < n; ++i)
		if (arr[i] == 0) 
			posl_n = i;
	for (int k = n - 1; k > posl_n; --k)
		vse += arr[k];
	return vse;
}

void up(int arr[], int n)
{
	int count = 0;
	/*for (int i = 0; i < n - 1; ++i)
	{
		++count;
		if (abs(arr[i]) > abs(arr[i + 1]))
		{
			int l = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = l;
			i = -1;
		}

	}*/
	for (int j = 0; j < n - 1; ++j)
	{
		for (int i = 0; i < n - j - 1; ++i)
		{
			++count;
			if (abs(arr[i]) > abs(arr[i + 1]))
			{
				int l = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = l;
			}
		}
	}
	std::cout << "n=" << n << "count=" << count << std::endl;
}

void preobr(double** a, const int n) 
{
	for (int i = 0; i < n; ++i) 
	{
		double maxElement = abs(a[i][i]);
		int maxRow = i;
		for (int k = i + 1; k < n; ++k) 
		{
			if (abs(a[k][i]) > maxElement) 
			{
				maxElement = abs(a[k][i]);
				maxRow = k;
			}
		}

		for (int k = i; k < n + 1; ++k) 
		{
			double t = a[maxRow][k];
			a[maxRow][k] = a[i][k];
			a[i][k] = t;
		}

		for (int k = i + 1; k < n+1; ++k) 
		{
			double c = -a[k][i] / a[i][i];
			for (int j = i; j < n + 1; ++j) 
			{
				if (i == j)
					a[k][j] = 0;
				else
					a[k][j] += c * a[i][j];
			}
		}
	}
}

