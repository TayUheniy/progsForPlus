#include "pch.h"
#include <iostream>
#include <windows.h>



HANDLE hRead, hWrite; 
HANDLE thread1, thread2;
HANDLE hSemaphorestart,hSemaphore, hSemaphoreEnd;

void fun1()
{
	for (int i = 0; i < 10; ++i) {
		char*  buffer = (LPSTR)"Сообщение от первого потока второму потоку дошло";
		int writefile = 0;
		if (!CreatePipe(&hRead, &hWrite, NULL, 1024)) {
			printf("Канал не создан из-за ошибки с номером %i .\n", GetLastError());
			return;
		}

		if (!WriteFile(hWrite, buffer, strlen(buffer) + 1, (LPDWORD)&writefile, NULL)) {
			printf("Не записалось в канал из-за ошибки с номером %i .\n", GetLastError());
			return;
		}

		ReleaseSemaphore(hSemaphorestart, 1, NULL);
		WaitForSingleObject(hSemaphore, INFINITE);
		char buffertwo[2048];
		int readfile = 0;
		if (!ReadFile(hRead, buffertwo, 2048, (LPDWORD)&readfile, NULL)) {
			printf("Не считалось из канала из-за ошибки с номером %i .\n", GetLastError());
			return;
		}
		for (int i = 0; i < readfile; ++i) {
			std::cout << buffertwo[i];
		}
		ReleaseSemaphore(hSemaphoreEnd, 1, NULL);
	}
}

void fun2()
{
	for (int i = 0; i < 10; ++i) {
		WaitForSingleObject(hSemaphorestart, INFINITE);
		char buffer[2048];
		int readfile = 0;
		if (!ReadFile(hRead, buffer, 2048, (LPDWORD)&readfile, NULL)) {
			printf("Не считалось из канала из-за ошибки с номером %i .\n", GetLastError());
			return;
		}
		for (int i = 0; i < readfile; ++i) {
			std::cout << buffer[i];
		}
		char*  buffertwo = (LPSTR)"Сообщение от второго потока первому потоку дошло";
		int writefile = 0;
		if (!WriteFile(hWrite, buffertwo, strlen(buffertwo) + 1, (LPDWORD)&writefile, NULL)) {
			printf("Не записалось в канал из-за ошибки с номером %i .\n", GetLastError());
			return;
		}
		ReleaseSemaphore(hSemaphore, 1, NULL);
	}
}

int main(int argc, LPTSTR argv[])
{
	
	setlocale(LC_ALL, "Russian");
	if (argc != 2) {
		printf("Недостаточное количество аргументов, вы должны указать количество байт");
		return 0;
	}
	int count = atoi(argv[1]);
	if (count == 0) {
		printf("Введите 1 аргументом число больше 0");
		return 0;
	} 
	
	hSemaphorestart = CreateSemaphore(NULL, 0, 1000, NULL);
	hSemaphore = CreateSemaphore(NULL, 0, 1000, NULL);
	hSemaphoreEnd = CreateSemaphore(NULL, 0, 1000, NULL);
	thread1 = CreateThread(NULL, NULL,(LPTHREAD_START_ROUTINE)fun1, 0, NULL, NULL);
	if (thread1 == INVALID_HANDLE_VALUE) {
		printf("Поток 1 не создался из-за ошибки с номером %i .\n", GetLastError());
		return 0;
	}
	thread2 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)fun2, 0, NULL, NULL);
	if (thread2 == INVALID_HANDLE_VALUE) {
		printf("Поток 2 не создался из-за ошибки с номером %i .\n", GetLastError());
		return 0;
	}
	WaitForSingleObject(hSemaphoreEnd, INFINITE);
	WaitForSingleObject(thread1, INFINITE);
	WaitForSingleObject(thread2, INFINITE);
	CloseHandle(thread1);
	CloseHandle(thread2);
	CloseHandle(hSemaphorestart);
	CloseHandle(hSemaphore);
	CloseHandle(hSemaphoreEnd);
	return 0;
	}
