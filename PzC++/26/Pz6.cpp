#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"


TEST(MyFunction1, Test1)
{
	double x0 = 0;
	double x1 = 4;
	ASSERT_TRUE(proverka(x0, x1));
	double sol=solutionofuravn(func, x0, x1, 1e-3);
	ASSERT_NEAR(2, sol, 0.1);
}

TEST(MyFunction1, Test2)
{
	double x0 = -3;
	double x1 = -1;
	ASSERT_TRUE(proverka(x0, x1));
	double sol = solutionofuravn(func, x0, x1, 1e-3);
	ASSERT_NEAR(-2, sol, 0.1);
}

TEST(MyFunction2, Test1)
{

	const char* a = "12";
	const char* b = "13";
	const char* c = "14";
	long long a1 = perevod(a);
	long long b1 = perevod(b);
	long long c1 = perevod(c);
	if (a1 >= -128 && a1 <= 127)
	{
		char a2 = (char)a1;
		char b2 = (char)b1;
		char c2 = (char)c1;
		ASSERT_NEAR(a1, minc(a2, b2, c2),0.01);
	}
}

TEST(MyFunction2, Test2)
{

	const char* a = "500";
	const char* b = "400";
	const char* c = "1000";
	long long a1 = perevod(a);
	long long b1 = perevod(b);
	long long c1 = perevod(c);
	if ((a1 < -128 && a1 >= -2147483647 - 1) || (a1 > 127 && a1 <= 2147483647))
	{
		int a2 = (int)a1;
		int b2 = (int)b1;
		int c2 = (int)c1;
		ASSERT_NEAR(b1, minc(a2, b2, c2), 1);
	}
}

TEST(MyFunction2, Test3)
{

	const char* a = "2147483650";
	const char* b = "2147483652";
	const char* c = "2147483654";
	long long a1 = perevod(a);
	long long b1 = perevod(b);
	long long c1 = perevod(c);
	
	if ((a1 < -2147483647 - 1) || (a1 > 2147483647))
	{
		long long a2 = a1;
		long long b2 = b1;
		long long c2 = c1;
		ASSERT_NEAR(a1, minc(a2, b2, c2), 1);
	}

}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
