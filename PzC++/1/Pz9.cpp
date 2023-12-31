#include "stdafx.h"
#include "gtest\gtest.h"
#include "Cone.h"

TEST(MyFunction, TEST1)
{
	Cone ar(10, 2, 3, 5, 5);
	Cone ar1(5, 5, 5, 2, 4);
	Cone ar2(10, 2, 3, 5, 5);
	ASSERT_TRUE(ar == ar2);
	
}

TEST(MyFunction, TEST2)
{
	Cone ar1(5, 5, 5, 2, 4);
	double s = M_PI * (2)* sqrt(4 * 4 * 2 * 2);
	ASSERT_DOUBLE_EQ(s, Areabok(ar1));
}

TEST(MyFunction, TEST3)
{
	Cone ar1(5, 5, 5, 2, 4);
	double s = M_PI * 2 * 2;
	ASSERT_DOUBLE_EQ(s, Area(ar1));
}

TEST(MyFunction, TEST4)
{
	Cone ar1(5, 5, 5, 2, 4);
	double s = M_PI * (2)*(2);
	ASSERT_DOUBLE_EQ(s, Lenghtokr(ar1));
}

TEST(MyFunction, TEST5)
{
	Cone ar1(5, 5, 5, 2, 4);
	double s = (1. / 3.)*M_PI*2*2*4;
	ASSERT_DOUBLE_EQ(s, Ob(ar1));

}

TEST(MyFunction, TEST6)
{
	Cone ar1(1, 1, 1, 2, 4);
	Cone ar2(5, 5, 5, 2, 4);
	Cone ar3(5, 5, 5, 5, 4);
	ASSERT_TRUE(VolEq(ar1 , ar2));
	ASSERT_FALSE(VolEq(ar1 , ar3));
}

TEST(MyFunction, TEST7)
{
	Cone ar1(1., 1., 1., 2., 4.);
	ar1 = ar1 + 3.;
	Cone ar3(1., 1., 1., 5., 4.);
	ASSERT_TRUE(VolEq(ar1, ar3));

}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


