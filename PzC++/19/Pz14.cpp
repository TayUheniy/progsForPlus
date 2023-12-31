#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"

TEST(MyFunc, Test1)
{
	std::string a = "DDRRRUURRRRRDDDDDDDDRR";
	ASSERT_EQ(MazeWay("C:\\Users\\artem\\Desktop\\mass.txt"),a);
}
TEST(MyFunc, Test2)
{
	std::string a = "RDDRR";
	ASSERT_EQ(MazeWay("C:\\Users\\artem\\Desktop\\novmas.txt"), a);
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}