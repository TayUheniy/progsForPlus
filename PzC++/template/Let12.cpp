#include "stdafx.h"
#include "gtest\gtest.h"
#include "Class.h"

TEST(MyFunc, Test1)
{
	Array<int> A(4);
	A.push_back(3);
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	A.push_back(3);
	ASSERT_EQ( 3,*A.begin());
}

TEST(MyFunc, Test2)
{
	Array<int> A(4);
	A.push_back(3);
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	A.push_back(3);
	ASSERT_EQ( 8, A.capacity());
}

TEST(MyFunc, Test3)
{
	Array<int> A(4);
	A.push_back(3);
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	A.push_back(3);
	ASSERT_EQ(5, A.size());
}

TEST(MyFunc, Test4)
{
	Array<int> A(4);
	Array<int> B(3);
	A.push_back(3);
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	B = A;
	ASSERT_EQ(4, B.size());
	ASSERT_EQ(4, B.capacity());
}
Array<int> foo()
{
	Array<int>Rez;
	return Rez;
}
TEST(MyFunc, Test5)
{
	Array<int> A(4);
	A.push_back(3);
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	Array<int> B(A);
	Array<int> C(static_cast<Array<int>&&>(A));
	foo();
}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}