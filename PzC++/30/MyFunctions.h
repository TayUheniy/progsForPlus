#pragma once
struct TrainRoute
{
	wchar_t StartingPoint[20]; //� �������� ���������� ������ ��������;
	wchar_t TerminalPoint[20]; //� �������� ��������� ������ ��������;
	int Number; //� ����� ��������;
	int distance;//� ����� �������� � ��.

};

int StrLength(const char *str);
char *StrFromFile(const char *fileName);
int CountOfSructs(const char *str);
wchar_t *StrToWideStr(const char *str);
wchar_t *SkipUnnecessarySymbols(wchar_t *wstr);
TrainRoute *ArrayOfTrainRoute(const char *str, int &count);
TrainRoute* Sort(TrainRoute *str, int &count);
TrainRoute *finde(TrainRoute *str, int &count, wchar_t* vved[], const int v, int &g);
void Vivod(TrainRoute *str, int &count, const char *data);
void VivodNew(TrainRoute *str, int &count, const char *data, int &g);
