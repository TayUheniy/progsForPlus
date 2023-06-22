#include "pch.h"
#include <iostream>
#include <windows.h>


HANDLE Pipe,File;
LPSTR NamePiped = LPSTR ("\\\\.\\pipe\\Pipe");

HANDLE  EventEnd, EventTwo,EventThree;

void fun1()
{
	
		Sleep(1000);
		OVERLAPPED ov;
		ZeroMemory(&ov, sizeof(OVERLAPPED));
		bool Connected = WaitNamedPipe(NamePiped, NMPWAIT_WAIT_FOREVER);
		if (!Connected) {
			printf("Клиент не подключился к экземпляру канала из-за ошибки с номером %i", GetLastError());
			return;
		}
		File = CreateFile(NamePiped, GENERIC_ALL, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (File == INVALID_HANDLE_VALUE) {
			printf("Клиент не подключился из-за ошибки с номером %i", GetLastError());
			return;
		}
		for (int i = 0; i < 10; ++i) {
		TCHAR*  buffer = LPSTR("Передано сообщение второму потоку");
		DWORD byte;
		WriteFile(File, buffer, strlen(buffer) + 1, &byte, NULL);
		SetEvent(EventTwo);
		WaitForSingleObject(EventThree, INFINITE);
		DWORD BytesOut;
		TCHAR buffertwo[1024];
		ReadFile(File, buffertwo, 1024, &BytesOut, NULL);
		for (int i = 0; i < BytesOut; ++i) {
			std::cout << buffertwo[i];
		}
		SetEvent(EventEnd);
	}
}

void fun2()
{
	
		bool Connected = ConnectNamedPipe(Pipe, NULL);
		OVERLAPPED ov;
		ZeroMemory(&ov, sizeof(OVERLAPPED));
		if (!Connected) {
			printf("Сервер не подключился из-за ошибки с номером %i", GetLastError());
			return;
		}
		for (int i = 0; i < 10; ++i) {
		TCHAR buffer[1024];
		DWORD BytesOut;

		WaitForSingleObject(EventTwo, INFINITE);
		ReadFile(Pipe, buffer, 1024, &BytesOut, NULL);
		for (int i = 0; i < BytesOut; ++i) {
			std::cout << buffer[i];
		}
		TCHAR*  bufferthree = LPSTR("Передано сообщение первому потоку");
		DWORD byte;
		WriteFile(Pipe, bufferthree, strlen(bufferthree) + 1, &byte, NULL);
		SetEvent(EventThree);
	}
}

int main(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 2) {
		printf("Недостаточное количество аргументов, вы должны указать количество байт");
		return 0;
	}
	DWORD count = atoi(argv[1]);
	if (count == 0) {
		printf("Введите 1 аргументом число больше 0");
		return 0;
	}
	Pipe = CreateNamedPipe(NamePiped,PIPE_ACCESS_DUPLEX,
	PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,PIPE_UNLIMITED_INSTANCES,
	4096, 4096, INFINITE, NULL);
	EventTwo = CreateEvent(NULL, FALSE, FALSE, "Doubleevent");
	EventThree = CreateEvent(NULL, FALSE, FALSE, "Threeevent");
	EventEnd = CreateEvent(NULL, FALSE, FALSE, "Endevent");
	HANDLE ThreadServer = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)fun2, NULL, NULL, NULL);
	HANDLE ThreadClient = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)fun1, NULL, NULL, NULL);
	WaitForSingleObject(EventEnd, INFINITE);
	WaitForSingleObject(ThreadClient, INFINITE);
	WaitForSingleObject(ThreadServer, INFINITE);
	CloseHandle(ThreadClient);
	CloseHandle(ThreadServer);
	return 0;
}