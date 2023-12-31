

#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"

TEST (MyFunctions, ReverseWord)
{
	char a[] = "qwerty";
	ReverseWord(a, 6);
	char result[] = "ytrewq";
	ASSERT_STREQ(result, a);

}
TEST(Myfunctions, Reverse_Word2)
{
	char a[] = "";
	ReverseWord(a, 0);
	char result[] = "";
	ASSERT_STREQ(result, a);
}
TEST (MyFunctions, Reverse_Word)
{
	char a[] = "asdfg";
	ReverseWord(a, 5);
	char result[] = "gfdsa";
	ASSERT_STREQ(result, a);

}

TEST(MyFunctions, Reverse_String)
{
	char str[] = " i can write my \t programm ";
	Reverse(str);
	char result[] = " i nac etirw ym \t mmargorp ";
	ASSERT_STREQ(str, result);
}
TEST(MyFunctions, Reverse_String1)
{
	char str[] = "  ";
	Reverse(str);
	char result[] = "  ";
	ASSERT_STREQ(str, result);
}
TEST(MyFunctions, Reverse_String2)
{
	char str[] = "\t";
	Reverse(str);
	char result[] = "\t";
	ASSERT_STREQ(str, result);
}



int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}