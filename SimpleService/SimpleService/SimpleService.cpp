#include "stdafx.h"

#include <windows.h>
#include <winsvc.h>
#include <string>

#include <stdio.h>
#include <strsafe.h>


void WINAPI ServiceMain(DWORD argc, PTSTR* argv);
void WINAPI Handler(DWORD contolCode);

std::wstring serviceName;
SERVICE_TABLE_ENTRY DispatchedTable[2];
SERVICE_STATUS_HANDLE hService;
SERVICE_STATUS serviceStatus;

BOOL RegDelnodeRecurse(HKEY hKeyRoot, LPTSTR lpSubKey)
{
	LPTSTR lpEnd;
	LONG lResult;
	DWORD dwSize;
	TCHAR szName[MAX_PATH];
	HKEY hKey;
	FILETIME ftWrite;

	// First, see if we can delete the key without having
	// to recurse.

	lResult = RegDeleteKey(hKeyRoot, lpSubKey);

	if (lResult == ERROR_SUCCESS)
		return TRUE;

	lResult = RegOpenKeyEx(hKeyRoot, lpSubKey, 0, KEY_READ, &hKey);

	if (lResult != ERROR_SUCCESS)
	{
		if (lResult == ERROR_FILE_NOT_FOUND) {
			printf("Key not found.\n");
			return TRUE;
		}
		else {
			printf("Error opening key.\n");
			return FALSE;
		}
	}

	// Check for an ending slash and add one if it is missing.

	lpEnd = lpSubKey + lstrlen(lpSubKey);

	if (*(lpEnd - 1) != TEXT('\\'))
	{
		*lpEnd = TEXT('\\');
		lpEnd++;
		*lpEnd = TEXT('\0');
	}

	// Enumerate the keys

	dwSize = MAX_PATH;
	lResult = RegEnumKeyEx(hKey, 0, szName, &dwSize, NULL,
		NULL, NULL, &ftWrite);

	if (lResult == ERROR_SUCCESS)
	{
		do {

			StringCchCopy(lpEnd, MAX_PATH * 2, szName);

			if (!RegDelnodeRecurse(hKeyRoot, lpSubKey)) {
				break;
			}

			dwSize = MAX_PATH;

			lResult = RegEnumKeyEx(hKey, 0, szName, &dwSize, NULL,
				NULL, NULL, &ftWrite);

		} while (lResult == ERROR_SUCCESS);
	}

	lpEnd--;
	*lpEnd = TEXT('\0');

	RegCloseKey(hKey);

	// Try again to delete the key.

	lResult = RegDeleteKey(hKeyRoot, lpSubKey);

	if (lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}

//*************************************************************
//
//  RegDelnode()
//
//  Purpose:    Deletes a registry key and all its subkeys / values.
//
//  Parameters: hKeyRoot    -   Root key
//              lpSubKey    -   SubKey to delete
//
//  Return:     TRUE if successful.
//              FALSE if an error occurs.
//
//*************************************************************

BOOL RegDelnode(HKEY hKeyRoot, LPTSTR lpSubKey)
{
	TCHAR szDelKey[2 * MAX_PATH];

	StringCchCopy(szDelKey, MAX_PATH * 2, lpSubKey);
	return RegDelnodeRecurse(hKeyRoot, szDelKey);

}


int _tmain(int argc, _TCHAR* argv[])
{
	serviceName = L"SimpleService";

	DispatchedTable[0].lpServiceName = &serviceName[0];
	DispatchedTable[0].lpServiceProc = ServiceMain;

	DispatchedTable[1].lpServiceName = nullptr;
	DispatchedTable[1].lpServiceProc = nullptr;

	// Создать нужные потоки тут.
	::StartServiceCtrlDispatcher(DispatchedTable);
	return 0;
}

void WINAPI ServiceMain(DWORD argc, PTSTR* argv)
{
	serviceStatus = { SERVICE_WIN32_OWN_PROCESS, SERVICE_RUNNING, 0, 0, 0, 0, 0 };
	serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	serviceStatus.dwCurrentState = SERVICE_RUNNING;
	serviceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;

	hService = ::RegisterServiceCtrlHandler(serviceName.data(), Handler);

	::SetServiceStatus(hService, &serviceStatus);
}

void WINAPI Handler(DWORD contolCode)
{
	SERVICE_STATUS serviceStatus = { 0 };
	serviceStatus.dwCurrentState = SERVICE_RUNNING;
	serviceStatus.dwWin32ExitCode = 0;

	::SetServiceStatus(hService, &serviceStatus);

	BOOL bSuccess;
	bSuccess = RegDelnode(HKEY_LOCAL_MACHINE,
		TEXT("SYSTEM\CurrentControlSet\Enum\USB\VID_0FCE&PID_01E0"));

	if (bSuccess)
		printf("Success!\n");
	else printf("Failure.\n");

}

