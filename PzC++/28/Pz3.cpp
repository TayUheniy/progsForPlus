#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"
#include <fstream>
using namespace std;

TEST(MyFunctions, posl_0)
{
	const int n = 16;
	int arr[n] = { 1,2,3,4,5,6,7,8,0,8,7,6,5,4,3,2 };
	ASSERT_EQ(35, sum(arr, n));
}
TEST(MyFunctions, posl_net)
{
	const int n = 16;
	int arr[n] = { 1,2,3,4,5,6,7,8,8,7,6,5,4,3,2 };
	ASSERT_EQ(0, sum(arr, n));
}

TEST(MyFunctions, posl_1)
{
	const int n = 18;
	int arr[n] = { 1,2,3,4,5,6,7,8,0,8,7,0,6,5,0,4,3,2 };
	ASSERT_EQ(9, sum(arr, n));
}

TEST(MyFunctions, upor_1)
{
	const int n = 18;
	int arr[n] = { 1,2,3,-4,5,6,7,-8,0,8,7,0,6,5,0,4,3,2 };
	int mar[n] = { 0,0,0,1,2,2,3,3,-4,4,5,5,6,6,7,7,-8,8 };
	up(arr, n);
	for (int i = 0; i < n; ++i)
	{
		
		ASSERT_EQ(mar[i], arr[i]);
		
	}
}


TEST(MyFunctions, preobr_from_file) {
	
	const char* fname = "C:\\Users\\artem\\Desktop\\mass.txt";
	ifstream fin(fname);

	const int f = 3, l = 3;

	int n, m, s;
	fin >> n >> m;
	if (n > m) 
		s = m;
	else 
		s = n;

	double** A = new double*[n];
	for (int i = 0; i < n; ++i)
		A[i] = new double[m];
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)

			fin >> A[i][j];

	double mar[f][l] =
	{
	{ -4.5,3,2 },
	{ 0,6,6.333333 },
	{ 0,0,0.259259},
	
	};

	preobr(A, s-1);

	

	for (int i = 0; i < n; ++i)
	{
		cout << endl;
		for (int j = 0; j < m; ++j)
		{
			cout << A[i][j];
			cout << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ASSERT_NEAR(mar[i][j], A[i][j],0.001);

	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
}



int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

