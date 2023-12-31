#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"

TEST(MyFun, Test1)
{
	LinkedList<int> a;
	LinkedList<int> g=a;
	LinkedList<int> c;
	a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);
		LinkedList<int>b(static_cast<LinkedList<int>&&>(a));
		c.push_back(7);
		c.push_back(8);
		c.insert(c.end(), 9);
		const LinkedList<int> &d=c;
	 auto beh = d.begin();
		ASSERT_EQ(*beh, 7);
		LinkedList<int>::iterator be = c.begin();
		for (int i = 0; i < 3; ++i)
		{
			ASSERT_EQ(*be, 7 + i);
			++be;
		};
	}
	TEST(MyFunct, Test2)
	{
		LinkedList<int> a;
		a.push_back(4);
		a.push_back(3);
		a.push_back(2);
		a.push_back(1);
		const LinkedList<int> &d = a;
		LinkedList<int>::const_reverse_iterator beh = d.rbegin();
		ASSERT_EQ(*beh, 1);
		LinkedList<int>::reverse_iterator be = a.rbegin();
		for (int i = 1; i < 5; ++i)
		{
			ASSERT_EQ(*be, i);
			++be;
		}
		ASSERT_THROW(++a.end(), std::runtime_error);
	}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
