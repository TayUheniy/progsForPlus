#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"

TEST(MyFunctions, Test_1)
{
	const char* c = "123.";
	ASSERT_EQ(27*27+2*27+3, perevod(c));
}
TEST(MyFunctions, Test_2)
{
	const char* c = "12.3";
	ASSERT_NEAR( 27. + 2. + 3./27., perevod(c), 0.01);
}
TEST(MyFunctions, Test_3)
{
	const char* c = "12.3fa";
	ASSERT_NEAR(29.1321, perevod(c), 0.01);
}
TEST(MyFunctions, Test_4)
{
	const char* c = "0";
	ASSERT_NEAR(0, perevod(c), 0.01);
}

TEST(MyPosition_of_point, Test_1)
{
	const char* c = ".123";
	ASSERT_EQ(0, position_of_point(c));
}

TEST(MyPosition_of_point, Test_2)
{
	const char* c = "12.3";
	ASSERT_EQ(2, position_of_point(c));
}
TEST(MyPosition_of_point, Test_3)
{
	const char* c = "123.";
	ASSERT_EQ(3, position_of_point(c));
}

TEST(MyPosition_of_point, Test_4)
{
	const char* c = "123";
	ASSERT_EQ(3, position_of_point(c));
}
TEST(MyPosition_of_point, Test_5)
{
	const char* c = "";
	ASSERT_EQ(0, position_of_point(c));
}
int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


