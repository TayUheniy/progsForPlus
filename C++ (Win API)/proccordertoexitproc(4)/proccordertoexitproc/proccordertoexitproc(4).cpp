#include "pch.h"
#include <iostream>

void createProcessCmdAndNewProc() {
	STARTUPINFO structureInfo;
	PROCESS_INFORMATION structureProcessInfo;
	structureInfo = { 0 };
	structureInfo.cb = sizeof(structureInfo);
	CreateProcess(TEXT("C:\\Windows\\System32\\cmd.exe"), NULL, NULL, NULL, TRUE, NULL, NULL, NULL, &structureInfo, &structureProcessInfo);
	WaitForSingleObject(structureProcessInfo.hProcess, 7000);
	TerminateProcess(structureProcessInfo.hProcess, 0);
	CloseHandle(structureProcessInfo.hProcess);
	CloseHandle(structureProcessInfo.hThread);
}

int main(int argc, LPTSTR argv[]) {
	setlocale(LC_ALL, "Russian");
	createProcessCmdAndNewProc();
	return 0;
}