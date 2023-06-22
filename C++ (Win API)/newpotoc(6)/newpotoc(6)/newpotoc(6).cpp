#include "pch.h"
#include <iostream>

void createThreads() {
	HANDLE thread = CreateThread(NULL, NULL, NULL, NULL, CREATE_SUSPENDED, NULL);
	Sleep(5000);
	if (TerminateThread(thread, 1)) {
		printf("Была подана команда на завершение. ");
	}
	printf("Завершился второй поток. ");
	CloseHandle(thread);
}

int main(int argc, LPTSTR argv[]) {
	setlocale(LC_ALL, "Russian");
	printf("Создан главный поток. ");
	createThreads();
	return 0;
}