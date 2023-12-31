#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"


TEST(MyFunc, Test1)
	{
	std::vector<int> a({ 10,20,30,40 });
	ASSERT_EQ(RecursiveBinarySearch(a.begin(), a.end(), -1, std::less<int>()), a.end());
		ASSERT_EQ(*RecursiveBinarySearch(a.begin(), a.end(), 20, std::less<int>()), 20);
		ASSERT_EQ(*RecursiveBinarySearch(a.begin(), a.end(), 10, std::less<int>()), 10);
		ASSERT_EQ(RecursiveBinarySearch(a.begin(), a.end(), 15, std::less<int>()), a.end());
		ASSERT_EQ(RecursiveBinarySearch(a.begin(), a.end(), 39, std::less<int>()), a.end());
		ASSERT_EQ(*RecursiveBinarySearch(a.begin(), a.end(), 40, std::less<int>()), 40);
		ASSERT_EQ(RecursiveBinarySearch(a.begin(), a.end(), 50, std::less<int>()), a.end());
	}
	TEST(MyFunc, Test2)
	{
		std::vector<int> a({ 10,20,30,40 });
		ASSERT_EQ(BinarySearch(a.begin(), a.end(), -1, std::less<int>()), a.end());
		ASSERT_EQ(*BinarySearch(a.begin(), a.end(), 20, std::less<int>()), 20);
		ASSERT_EQ(*BinarySearch(a.begin(), a.end(), 10, std::less<int>()), 10);
		ASSERT_EQ(BinarySearch(a.begin(), a.end(), 15, std::less<int>()), a.end());
		ASSERT_EQ(BinarySearch(a.begin(), a.end(), 39, std::less<int>()), a.end());
		ASSERT_EQ(*BinarySearch(a.begin(), a.end(), 40, std::less<int>()), 40);
		ASSERT_EQ(BinarySearch(a.begin(), a.end(), 50, std::less<int>()), a.end());
	}
	TEST(MyFunc, Test3)
	{
		std::list<int> d;
		d.push_back(10);
		d.push_back(20);
		d.push_back(30);
		ASSERT_EQ(RecursiveBinarySearch(d.begin(), d.end(), 1, std::less<int>()),d.end());
	
	}
	TEST(MyFunc, TEST4)
	{
		std::list<int> t;
		for (int i=0;i<1000;++i)
			t.push_back(i);
		for (int i = 0; i<10; ++i)
		EXPECT_EQ(*BinarySearch(t.begin(), t.end(), i, std::less<int>()),i);
	}
	TEST(MyFunc, TEST5)
	{
		std::list<int> k{};
		ASSERT_EQ(BinarySearch(k.begin(), k.begin(), 40, std::less<int>()), k.end());
	}
	TEST(MyFunc, TEST6)
	{
		std::list<int> t;
		for (int i = 0; i<1000; ++i)
			t.push_back(i);
		for (int i = 0; i<1000; ++i)
		ASSERT_EQ(*RecursiveBinarySearch(t.begin(), t.end(), i, std::less<int>()), i);
	}
	TEST(MyFunc, TEST10)
	{
		std::vector<int> t;
		for (int i = 0; i<1000; ++i)
			t.push_back(i);
		for (int i = 0; i<10; ++i)
			EXPECT_EQ(*BinarySearch(t.begin(), t.end(), i, std::less<int>()), i);
	}
	
	TEST(MyFunc, TEST11)
	{
		std::vector<int> t;
		for (int i = 0; i<1000; ++i)
			t.push_back(i);
		for (int i = 0; i<1000; ++i)
			ASSERT_EQ(*RecursiveBinarySearch(t.begin(), t.end(), i, std::less<int>()), i);
	}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}