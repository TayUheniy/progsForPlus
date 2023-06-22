#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;
BOOL CALLBACK EnumProc(HWND hWnd, LPARAM lParam);

struct EnumData {
	DWORD dwProcessId;
	HWND hWnd;
};

HWND FindWindowFromProcessId(DWORD dwProcessId)
{
	EnumData ed = { dwProcessId };
	if (!EnumWindows(EnumProc, (LPARAM)&ed) && (GetLastError() == ERROR_SUCCESS))
	{
		return ed.hWnd;
	}

	return NULL;
}

BOOL CALLBACK EnumProc(HWND hWnd, LPARAM lParam)
{

	EnumData &ed = *(EnumData *)lParam;
	DWORD dwProcessId;

	GetWindowThreadProcessId(hWnd, &dwProcessId);

	if (ed.dwProcessId == dwProcessId)
	{
		ed.hWnd = hWnd;
		SetLastError(ERROR_SUCCESS);
		return FALSE;
	}

	return TRUE;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	STARTUPINFO structureInfo;
	PROCESS_INFORMATION structureProcessInfo;
	structureInfo = { 0 };
	structureInfo.cb = sizeof(structureInfo);
	CreateProcess(TEXT("C:\\Windows\\System32\\calc.exe"), NULL, NULL, NULL, TRUE, NULL, NULL, NULL, &structureInfo, &structureProcessInfo);
	Sleep(3000);
	TCHAR str[255];
	DWORD Pid = structureProcessInfo.dwProcessId;
	if (GetWindowText(FindWindowFromProcessId(Pid), str, sizeof(str))) {
		if (GetClassName(FindWindowFromProcessId(Pid), str, sizeof(str))) {
			cout << str;
		}
	}
	SendMessage(FindWindowFromProcessId(Pid), WM_CLOSE, 0, 0);
}
