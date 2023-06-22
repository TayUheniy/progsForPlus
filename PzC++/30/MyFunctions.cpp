#include "stdafx.h"
#include "MyFunctions.h"


int StrLength(const char *str)
{
	int kolvo = 0;
	while (*(str+kolvo))
	{
		++kolvo;
	}
	return kolvo;
}

char *StrFromFile(const char *data)
{
	FILE *ptrFile;
	ptrFile = fopen(data, "r+");
	if (ptrFile == nullptr)
		return nullptr;
	fseek(ptrFile, 0, SEEK_END);
	long fileSize = ftell(ptrFile);
	rewind(ptrFile);
	char *buffer = new char[fileSize + 1];
	auto readed = fread(buffer, 1, fileSize, ptrFile);
	buffer[readed] = '\0';
	fclose(ptrFile);
	return buffer;
}

int CountOfSructs(const char *str)
{
	int count = 0;
	while (*str)
	{
		if (*str++ == '{')
			++count;
	}
	return count;
}

wchar_t *StrToWideStr(const char *str)
{
	size_t length = StrLength(str);	
	size_t converted = 0;
	wchar_t *wstr = new wchar_t[length + 1];
	converted = mbstowcs(wstr, str, length + 1);
	if (converted != length)
		return nullptr;
	return wstr;
}

wchar_t *SkipUnnecessarySymbols(wchar_t *wstr)
{
	int indexOfColon = 0;
	swscanf(wstr, L"%*[^:]%n", &indexOfColon);
	if (*(wstr + indexOfColon) == L':')
		++indexOfColon;	
	return wstr + indexOfColon;
}


TrainRoute *ArrayOfTrainRoute(const char *str, int &count)
{
	count = CountOfSructs(str);
	if (!count)
		return nullptr;
	
	wchar_t *wstr = StrToWideStr(str);
	TrainRoute *TrainRoutes = new TrainRoute [count];	
	for (int k = 0; k < count; ++k)
	{
		
		int distance = 0;
		wstr = SkipUnnecessarySymbols(wstr); 
		swscanf(wstr, L"%*[^\"]%n", &distance);	
		wstr += distance + 1;	
		swscanf(wstr, L"%[^\"]s", &TrainRoutes[k].StartingPoint); 

		wstr = SkipUnnecessarySymbols(wstr);
		distance = 0;
		swscanf(wstr, L"%*[^\"]%n", &distance);	
		wstr += distance + 1;	
		swscanf(wstr, L"%[^\"]s", &TrainRoutes[k].TerminalPoint);

		wstr = SkipUnnecessarySymbols(wstr); 
		distance = 0;
		swscanf(wstr, L"%*[^0-9]%n", &distance);	
		wstr += distance;
		swscanf(wstr, L"%d", &TrainRoutes[k].Number);	

		wstr = SkipUnnecessarySymbols(wstr); 
		distance = 0;
		swscanf(wstr, L"%*[^0-9]%n", &distance);
		wstr += distance;
		swscanf(wstr, L"%d", &TrainRoutes[k].distance);
	}

	return TrainRoutes;
}

TrainRoute* Sort(TrainRoute *str, int &count)
{
	TrainRoute *novstr = str;
	for (int j = 0; j < count-1; ++j)
	{
		for (int i = 0; i < count - j - 1; ++i)
			{
				int k = 0;
				while (novstr[i].StartingPoint[k] == novstr[i + 1].StartingPoint[k] && novstr[i + 1].StartingPoint[k])
					{
						++k;
					}
				if (novstr[i].StartingPoint[k] > novstr[i+1].StartingPoint[k])
					{
						TrainRoute l = novstr[i+1];
						novstr[i + 1] = novstr[i];
						novstr[i] = l;
					}
			}
	}
	
	return novstr;
}

TrainRoute *finde(TrainRoute *str, int &count, wchar_t* vved[], const int v, int &g)
{
	TrainRoute *nov = new TrainRoute[count];

		int l = 0;

	for (int i = 0; i < count; ++i)
	{
		int k = 0;
		
		for (int j = 0; j < v; ++j)
		{
			while (str[i].StartingPoint[k] == vved[j][k] && (str[i].StartingPoint[k]))
			{
				++k;
			}
			if (str[i].StartingPoint[k] == '\0' && vved[j][k] == '\0')
			{
				nov[l] = str[i];
				++l;
				++g;
			}
		}
	}
	return nov;
}

 void Vivod(TrainRoute *str, int &count, const char *data)
 {
	 FILE *ptrFile;
	 ptrFile = fopen(data, "w+");
	 
	 const wchar_t* s[5] = { L"№",L"Отправление", L"Прибытие" ,L"Номер" ,L"Дистанция" };
	 fwprintf(ptrFile, L"+----+-------------------+---------------+--------+-----------+\n");
	 fwprintf(ptrFile, L"| %-2s | %-17s | %-13s | %-6s | %4s |\n",s[0],s[1],s[2],s[3],s[4]);
	 fwprintf(ptrFile, L"+----+-------------------+---------------+--------+-----------+\n");
	 for (int i = 0; i < count; ++i)
	 {
		 fwprintf(ptrFile, L"| %-2d | %-17s | %-13s | %6d | %9d |\n", i+1, str[i].StartingPoint, str[i].TerminalPoint, str[i].Number, str[i].distance);
		 fwprintf(ptrFile, L"+----+-------------------+---------------+--------+-----------+\n");
	 }
	 fclose(ptrFile);
 }

 void VivodNew(TrainRoute *str, int &count, const char *data, int &g)
 {
	 FILE *ptrFile;
	 ptrFile = fopen(data, "w+");

	 const wchar_t* s[5] = { L"№",L"Отправление", L"Прибытие" ,L"Номер" ,L"Дистанция" };
	 fwprintf(ptrFile, L"+----+-------------------+---------------+--------+-----------+\n");
	 fwprintf(ptrFile, L"| %-2s | %-17s | %-13s | %-6s | %4s |\n", s[0], s[1], s[2], s[3], s[4]);
	 fwprintf(ptrFile, L"+----+-------------------+---------------+--------+-----------+\n");
	 for (int i = 0; i < g; ++i)
	 {
		 fwprintf(ptrFile, L"| %-2d | %-17s | %-13s | %6d | %9d |\n", i + 1, str[i].StartingPoint, str[i].TerminalPoint, str[i].Number, str[i].distance);
		 fwprintf(ptrFile, L"+----+-------------------+---------------+--------+-----------+\n");
	 }
	 fclose(ptrFile);
 }