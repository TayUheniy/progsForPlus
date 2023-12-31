
#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunction.h"



TEST(Myfunction, Log1)
{
	ASSERT_DOUBLE_EQ(-1, log2(5));
	ASSERT_DOUBLE_EQ(-1,log2(6));
	ASSERT_DOUBLE_EQ(3,log2(8));
	ASSERT_DOUBLE_EQ(1,log2(2));
	ASSERT_DOUBLE_EQ(0,log2(1));
	ASSERT_DOUBLE_EQ(-2,log2(0));
}
TEST(Myfunction, NOD_rec)
{
	ASSERT_EQ(4, NOD_rec(8, 12));
	ASSERT_EQ(12, NOD_rec(0, 12));
	ASSERT_EQ(0, NOD_rec(0, 0));
	ASSERT_EQ(1, NOD_rec(1, 1));
	ASSERT_EQ(1, NOD_rec(5, 7));
	ASSERT_EQ(1, NOD_rec(14, 93));
}

TEST(Myfunction, NOD_nerec)
{
	ASSERT_EQ(4, NOD_nerec(8, 12));
	ASSERT_EQ(12, NOD_nerec(0, 12));
	ASSERT_EQ(0, NOD_nerec(0, 0));
	ASSERT_EQ(1, NOD_nerec(1, 1));
	ASSERT_EQ(1, NOD_nerec(5, 7));
	ASSERT_EQ(1, NOD_nerec(14, 93));
}

TEST(Myfunction, Taylor_1)

{
	double x = 0.2, dx = 0.1, a = 0.1, b = 1.9;
	int n = 0;
	cout << "____________________________________________" << endl
		<< "|  x  |       f(x)      | n |       ln(x)   |" << endl
		<< "____________________________________________" << endl;
	for (x = a; x <= b; x = x + dx)
	{
		cout << "| "; printf("%100.1f", x);
		cout << " |" << "     ";
		printf("%10.6f", Taylor(x, 0.0001, n));
		cout << "   |" << setw(2) << n << " |"; cout << "    ";
		printf("%10.6f", log(x));
		cout << " " << endl;
	}
	cout << "___________________________________________" << endl;




}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
