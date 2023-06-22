#include "pch.h"
#include <iostream>
#include <windows.h>
typedef int(*LPGETZ)(int x, int y);


int main()
{
	int a = 5;
	int b = 3;
	LPGETZ lpGetZ;
	HINSTANCE hDLL = LoadLibrary("C:\\Users\\artem\\Desktop\\project\\loadlibrary\\loadlibrarydll\\Debug\\DLL1.dll");
	if (hDLL != NULL) {
		lpGetZ = (LPGETZ)GetProcAddress(hDLL, "Summator");
		std::cout << lpGetZ(a, b);
	}
	FreeLibrary(hDLL);

}


