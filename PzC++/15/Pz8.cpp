#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"


//TEST(MyFunctions, Test1)
//{
//	const char *str2 = "ин";
//		char *newst=CombinePathes("C:\\Users\\artem\\Desktop", str2);
//		ASSERT_STREQ(newst, "C:\\Users\\artem\\Desktop\\ин");
//}
//
//	
//TEST(MyFunctions, Test2)
//{
//	const char *str2 = "ин";
//	ASSERT_TRUE(CombinePath("C:\\Users\\artem\\Desktop", str2));
//}

//TEST(MyFunctions, Test3)
//{
//	ASSERT_TRUE(TraverseDirectory("C:\\Users\\artem\\Desktop" , Createdirfamyly));
//}

//char* newbuffer =strstr(buffer, "ин");
// waycopy = newstr(waycopy, "\\");
//waycopy = newstr(waycopy, newbuffer);
//TEST(MyFunctions, Test4)
//{
//	ASSERT_TRUE(TraverseDirectory("C:\\Users\\artem\\Desktop\\ин", RenameDirectory));
//}

//TEST(MyFunctions, Test5)
//{
//	ASSERT_TRUE(TraverseDirectory("C:\\Users\\artem\\Desktop\\Артем", CopyDirectory));
//
//}

//TEST(MyFunctions, Test6)
//{
//	_chdir("C:\\Users\\artem\\Desktop");
//
//	ASSERT_TRUE(CopyFiles("Chrysanthemum.jpg", "C:\\Users\\artem\\Desktop\\Артем", 1));
//}


//TEST(MyFunctions, Test7)
//{
//	_chdir("C:\\Users\\artem\\Desktop");
//
//	ASSERT_TRUE(CopyFiles("Chrysanthemum.jpg", "C:\\Users\\artem\\Desktop\\Артем", 4096));
//}

//TEST(MyFunctions, Test8)
//{
//	int number = 0;
//	char** files = nullptr;
//	EXPECT_TRUE(SizeFileOfDirectory("C:\\Users\\artem\\Desktop\\Новые лекции", number, files));
//	for (int i = 0; i < number; ++i)
//	{
//		std::cout << "\t" << files[i] << std::endl;
//	}
//}

//TEST(MyFunctions, Test9)
//{
//	ASSERT_TRUE(TraverseDirectory("C:\\Users\\artem\\Desktop", OpenFileSortirovka));
//
//}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}