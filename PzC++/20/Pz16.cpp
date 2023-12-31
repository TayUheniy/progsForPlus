#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"
TEST(MyFunc, Test1)
{
	std::vector<int> a = { 1,2,3,4,5,6,7,8,9,10 };
	int s=sum4<std::vector<int>::iterator, int>(a.begin(), a.end());
	ASSERT_EQ(s, 12);
	std::vector<char*> f = { (char*)"Alexey",(char*)"Maksim",(char*)"Boris",(char*)"Andrey",(char*)"Denis",(char*)"Kirill",(char*)"Artem",(char*)"Roma",(char*)"Danil" };
	std::string l = sum4(f.begin(),f.end());
	ASSERT_EQ(l, "AndreyRoma");
}

TEST(MyFunc, Test2)
{
	Region A("Moscow oblast", "Moscow", 300., 3000000, 40320.);
	Region B("Krasnodarskiy Kray", "Krasnodar", 500., 2000000, 19110.);
	Region C("Republic Tatarstan", "Kazan", 700., 1000000, 21000.);
	Region D("Vladimirskaya oblast", "Vladimir", 100., 700000, 30000.);
	Region F = A;

	SpisokRegion SP;
	SP.push_back(A);
	SP.push_back(B);
	SP.push_back(C);
	SP.push_back(D);

	sor < std::vector<Region>::iterator, PredArea >(SP._regions.begin(), SP._regions.end(), PredArea());
	std::vector<Region>::iterator l = SP._regions.begin();
	ASSERT_EQ(*l, D);
	ASSERT_EQ(*++l, A);
	ASSERT_EQ(*++l, B);
	ASSERT_EQ(*++l, C);

	std::vector<int> a = { 10,7,5,3,1,9,8,2,4,6 };
	sor <std::vector<int>::iterator, Predint>(a.begin(), a.end(), Predint());
	std::vector<int>::iterator k = a.begin();
	ASSERT_EQ(*k, 1);
	for (int i=2;i<11;++i)
		ASSERT_EQ(*++k, i);
}
TEST(MyFunc, Test3)
{
	Region A("Moscow oblast", "Moscow", 300., 3000000, 40320.);
	Region B("Krasnodarskiy Kray", "Krasnodar", 500., 2000000, 19110.);
	Region C("Republic Tatarstan", "Kazan", 700., 1000000, 21000.);
	Region D("Vladimirskaya oblast", "Vladimir", 100., 700000, 30000.);

	SpisokRegion SP;
	SP.push_back(A);
	SP.push_back(B);
	SP.push_back(C);
	SP.push_back(D);

	Region l= sear<std::vector<Region>::iterator, Prednamereg>(SP._regions.begin(), SP._regions.end(), Prednamereg());
	ASSERT_EQ(B, l);
}

TEST(MyFunc, Test4)
{
	Region A("Moscow oblast", "Moscow", 300., 3000000, 40320.);
	Region B("Krasnodarskiy Kray", "Krasnodar", 500., 2000000, 19110.);
	Region C("Republic Tatarstan", "Kazan", 700., 1000000, 21000.);
	Region D("Vladimirskaya oblast", "Vladimir", 100., 700000, 30000.);

	SpisokRegion SP;
	SP.push_back(A);
	SP.push_back(B);
	SP.push_back(C);
	SP.push_back(D);

	sor < std::vector<Region>::iterator, PredArea >(SP._regions.begin(), SP._regions.end(), PredArea());
	std::vector<Region>::iterator o = BinarySearch<std::vector<Region>::iterator, Region, PredArea>(SP._regions.begin(), SP._regions.end(), C, PredArea());
	ASSERT_EQ(*o, C);
}

TEST(MyFunc, Test5)
{
	Region A("Moscow oblast", "Moscow", 300., 3000000, 40320.);
	Region B("Krasnodarskiy Kray", "Krasnodar", 500., 2000000, 19110.);
	Region C("Republic Tatarstan", "Kazan", 700., 1000000, 21000.);
	Region D("Vladimirskaya oblast", "Vladimir", 100., 700000, 30000.);

	SpisokRegion SP;
	SP.push_back(A);
	SP.push_back(B);
	SP.push_back(C);
	SP.push_back(D);

	std::list<Region> y = otbor<std::vector<Region>::iterator, Predzp, Region>(SP._regions.begin(), SP._regions.end(), D, Predzp());
	std::list<Region>::iterator be = y.begin();
	ASSERT_EQ(*be, B);
	advance(be, 1);
	ASSERT_EQ(*be, C);

	std::list<Region> e = otbork<std::vector<Region>::iterator, Predzp, Region>(SP._regions.begin(), SP._regions.end(), A, Predzp(), 3);
	std::list<Region>::iterator ed = e.begin();
	ASSERT_EQ(*ed, B);
	advance(ed, 1);
	ASSERT_EQ(*ed, C);
	
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

