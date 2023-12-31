#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"
using namespace std;

TEST(MyFunctions, Test1)
{
	
	int n, m;
	double** arr = ReadBinary("task9.dat", n, m);
	 for (int i = 0; i < n; ++i)
	 {
		 std::cout << endl;
		 for (int j = 0; j < m; ++j)
		 {
			 std::cout << arr[i][j];
			 std::cout << " ";
		 }
	 }

	std::cout << endl;
	std::cout << "Proisvedenie =";
	std::cout << proizv(arr, n, m);

	ASSERT_DOUBLE_EQ(9, proizv(arr, n, m));
	ASSERT_EQ(4,n);
	ASSERT_EQ(9, m);
}

TEST(MyFunctions, Test2)
{
	const int n = 5;
	const int m = 5;
	double arr[n][m]=
	{
		{1.,2.,3.,4.,5.},
		{6.,7.,8.,9.,10.},
		{11.,12.,13.,14.,15.},
	{16.,17.,18.,19.,20.},
	{21.,22.,23.,24.,25.}
	};
	
	ASSERT_DOUBLE_EQ(22176, proizv((double**)arr, n, m));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
