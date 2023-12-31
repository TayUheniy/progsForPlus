#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFunctions.h"
using namespace std;

TEST(MyTest, test)
{

	int count = 0;
	char *str = StrFromFile("data.json");
	TrainRoute *TrainRoutes = ArrayOfTrainRoute(str, count);
	TrainRoute *NewTrainRoutes = Sort(TrainRoutes, count);
	const int v = 3;
	const char* l[v] = { "Владивосток","Ярославль", "Ижевск"};

	wchar_t** s = new wchar_t*[count];
	for (int i = 0; i < count; ++i)
		s[i] = new wchar_t[20];

	for (int i = 0; i < v; ++i)
		s[i] = StrToWideStr(l[i]);
	
	TrainRoute* nov;
	
	int g = 0;
	nov = finde(TrainRoutes, count, s,v,g);
	

	Vivod(NewTrainRoutes, count, "json1.json");
	VivodNew(nov, count, "json2.json", g);

}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

