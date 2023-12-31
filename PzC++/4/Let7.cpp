#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"

TEST(MyFunction, Test1)
{
	const char* s = "{}[]()";
	const char* str = "jksdg(jkjdf}";

	bool a= proverka(str,s);
	ASSERT_FALSE(a);
}

TEST(MyFunction, Test2)
{
	const char* s = "{}[]()";
	const char* str = "{[jksdg(jkjdf)]}";

	bool a = proverka(str, s);

	ASSERT_TRUE(a);
}
TEST(MyFunction, Test3)
{
	const char* s = "{}[]()";
	const char* str = "ksdg(jkjdf)]}";

	bool a = proverka(str, s);
	ASSERT_FALSE(a);
}

TEST(MyFunction, Test4)
{
	const char* s = "{}[]()";
	const char* str = ")";

	bool a = proverka(str, s);
	ASSERT_FALSE(a);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

