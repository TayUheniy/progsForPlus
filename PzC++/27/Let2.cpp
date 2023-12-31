
#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"

TEST(MyFunctions, Massiv)
{
	const int N = 32;
	size_t arr[N] = { 4,5,3,5,8,6,8,6,12,10,14,20,32,54,21,2,2,4,3,2,5,6,7,8,9,0,27,24,15,39,48,32 };
	ASSERT_EQ(4, count_of_correct_elements(arr, 32, 30, 48));
}
TEST(MyFunctions, Tip_Dan)
{
	
	ASSERT_EQ(SCHAR_MIN, 0x80i8);
	ASSERT_EQ(SCHAR_MAX, 0x7f);
	ASSERT_EQ(UCHAR_MAX, 0xff);
	ASSERT_EQ(SHRT_MIN, 0x8000i16);
	ASSERT_EQ(SHRT_MAX, 0x7fff);
	ASSERT_EQ(USHRT_MAX, 0xffff);
	ASSERT_EQ(INT_MIN, 0x80000000i32);
	ASSERT_EQ(INT_MAX, 0x7fffffff);
	ASSERT_EQ(UINT_MAX, 0xffffffff);
	ASSERT_EQ(LONG_MIN, (-2147483647L - 1));
	ASSERT_EQ(LONG_MAX, 0x7fffffff);
	ASSERT_EQ(ULONG_MAX, 0xffffffffUL);
	ASSERT_EQ(LLONG_MAX, 0x7fffffffffffffffi64);
	ASSERT_EQ(LLONG_MIN, 0x8000000000000000i64);
	ASSERT_EQ(ULLONG_MAX, 0xffffffffffffffffui64);
	



}

TEST(MyFunctions, Size_of_date)
{
	ASSERT_EQ(2, sizeof(short));
	ASSERT_EQ(1, sizeof(char));
	ASSERT_EQ(1, sizeof(unsigned char));
	ASSERT_EQ(4, sizeof(int));
	ASSERT_EQ(4, sizeof(unsigned int));
	ASSERT_EQ(2, sizeof(unsigned short));
	ASSERT_EQ(4, sizeof(long));
	ASSERT_EQ(4, sizeof(unsigned long));
	ASSERT_EQ(8, sizeof(long long));
	ASSERT_EQ(8, sizeof(unsigned long long));
	ASSERT_EQ(4, sizeof(float));
	ASSERT_EQ(2, sizeof(wchar_t));
	ASSERT_EQ(8, sizeof(double));
	ASSERT_EQ(SIZE_OF_POINTER, sizeof(size_t));
	ASSERT_EQ(1, sizeof(bool));
	ASSERT_EQ(SIZE_OF_POINTER, sizeof(void*));
	ASSERT_EQ(SIZE_OF_POINTER, sizeof(size_t*));
	ASSERT_EQ(SIZE_OF_POINTER, sizeof(size_t**));


}
TEST(MyFunctions, mass)
{
	const int N = 32;
	size_t arr[N];
	ASSERT_EQ(SIZE_OF_POINTER, sizeof( arr[N]));
	ASSERT_EQ(SIZE_OF_POINTER, sizeof(arr[0]));
	ASSERT_EQ(32, sizeof(arr)/ sizeof(arr[0]));
	size_t *p = arr;
	ASSERT_NE(sizeof(arr), sizeof(p));
	ASSERT_EQ(arr, p);
	ASSERT_EQ(&arr[0], p);
	ASSERT_EQ(&arr[1], p+1);
	ASSERT_EQ(&p[1], p + 1);
	ASSERT_EQ(arr[1], *(p + 1));
	ASSERT_EQ(p[1], *(p + 1));
	ASSERT_EQ(p[1], 1[p]);

}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}