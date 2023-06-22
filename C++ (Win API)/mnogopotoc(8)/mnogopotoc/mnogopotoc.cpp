#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string.h>
void coutthread(LPVOID number) {
	int numer = *(int*)number;
	
	for (int i = 1; i <= 15; ++i) {
		printf("Создан поток с номером %i с номером сообщения %i \n", numer, i);
	}
}

int main(int argc, LPTSTR argv[]) {
	setlocale(LC_ALL, "Russian");
	if (argc != 2) {
		printf("Недостаточное количество аргументов, вы должны указать количество потоков");
		return 0;
	}
	const int count = atoi(argv[1]);
	if (count == 0) {
		printf("Введите аргументом число больше 0");
		return 0;
	}
	HANDLE *hThreads = new HANDLE[count];
	for (int i = 1; i <= count; ++i) {
		hThreads[i] = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)coutthread, &i, NULL, NULL);
		WaitForSingleObject(hThreads[i], INFINITE);
		CloseHandle(hThreads[i]);
	}
	return 0;
}