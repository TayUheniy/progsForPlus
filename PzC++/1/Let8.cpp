#include "stdafx.h"
#include "gtest\gtest.h"
#include "Matrix.h"

TEST(MyFinctions, TEST1)
{
	Matrica arr(5, 5);
	Matrica arr2(5, 5);
	arr = arr2;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			ASSERT_EQ(0, arr[i][j]);
}

TEST(MyFinctions, TEST2)
{
	Matrica arr(5, 5);
	Matrica& ob = arr;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			ASSERT_EQ(0, ob[i][j]);
}

TEST(MyFinctions, TEST3)
{
	int n, m;
	int **arr2 = outputbyfile("mat.txt", n, m);
	Matrica arr(n, m);
	prisvintmatr(arr2, n, m, arr);
	int mass[5][5] = {
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25}
	};
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			ASSERT_EQ(mass[i][j], arr[i][j]);
	ASSERT_THROW(outputbyfile("mat1.txt", n, m),std::runtime_error);
	ASSERT_NO_THROW(outputbyfile("mat.txt", n, m));
}

TEST(MyFinctions, TEST4)
{
	Matrica arr(5, 5);
	Matrica arr2(5, 5);
	ASSERT_TRUE(arr == arr2);
}

TEST(MyFinctions, TEST5)
{
	Matrica arr(5, 5);
	Matrica arr2(5, 5);
	Matrica arr3(5,5);
	 arr3 = arr + arr2;
	 for (int i = 0; i < 5; ++i)
		 for (int j = 0; j < 5; ++j)
		 {
			 ASSERT_EQ(0, arr3[i][j]);
			 ASSERT_NO_THROW(arr3[i][j]);
		 }
}

TEST(MyFinctions, TEST6)
{
	int** mass=new int*[2];
	for (int i = 0; i < 2; ++i)
		mass[i] = new int[2];

	int** mass2 = new int*[2];
	for (int i = 0; i < 2; ++i)
		mass2[i] = new int[2];

	mass2[0][0] = 1;
	mass2[0][1] = 0;
	mass2[1][0] = 0;
	mass2[1][1] = 1;

	mass[0][0] = 2;
	mass[0][1] = 3;
	mass[1][0] = 4;
	mass[1][1] = 5;
	
	Matrica arr(2, 2);
	Matrica arr2(2, 2);
	Matrica arr3(2, 2);

	prisvintmatr(mass, 2, 2, arr);
	prisvintmatr(mass2, 2, 2, arr2);

	arr3 = arr * arr2;

	int mass3[2][2] =
	{
		{ 2,3 },
		{ 4,5 }
	};

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			ASSERT_EQ(mass3[i][j], arr[i][j]);

}
int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


