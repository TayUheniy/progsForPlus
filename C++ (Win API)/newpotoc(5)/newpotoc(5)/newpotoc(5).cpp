#include "pch.h"
#include <iostream>

void createThreads() {
	HANDLE thread = CreateThread(NULL, NULL, NULL, NULL, CREATE_SUSPENDED, NULL);
	printf("Создан второй поток");
	Sleep(5000);
	ResumeThread(thread);
	CloseHandle(thread);
}
int main(int argc, LPTSTR argv[]) {
	setlocale(LC_ALL, "Russian");
	printf("Создан первый главный поток. ");
	createThreads();
	return 0;
}