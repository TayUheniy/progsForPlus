#include "stdafx.h"
#include "gtest\gtest.h"
#include "LearningGroup.hpp"

TEST(MyFunctions, Test1)
{
	LearningGroup t{ "Информационная безопасность", 1, 2 };
	ASSERT_TRUE(WriteTextLearningGroup("data.txt", t));
}
TEST(MyFunctions, Test2)
{
	LearningGroup t;
	ASSERT_TRUE(ReadTextLearningGroup("data.txt", t));
}

TEST(MyFunctions, Test3)
{
	LearningGroup t= { "Информационная безопасность", 1, 2 };
	ASSERT_TRUE(WriteBinaryLearningGroup("text.bin", t));
}

TEST(MyFunctions, Test4)
{
	LearningGroup t;
	ASSERT_TRUE(ReadBinaryLearningGroup("text.bin", t));
	
}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
