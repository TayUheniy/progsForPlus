

#include "pch.h"
#include <iostream>
#include <windows.h>


void channel() {
	HANDLE hRead, hWrite;
	char* buffer = (char*)"0123456789134523465245643653635 64536565436 475375 35653747 35764654764773566";
	const int sizestr = strlen(buffer);
	int BufSize = 1024;
	if (!CreatePipe(&hRead, &hWrite, NULL, BufSize))
		printf("Канал не создан с ошибкой номером %i.\n", GetLastError());
	DWORD writeStr;
	if (!WriteFile(hWrite, buffer, sizestr, (LPDWORD)&writeStr, NULL))
	{
		printf("Не записалось в канал с ошибкой номером %i", GetLastError());
	}
	if (sizestr != writeStr) 
	{
		printf("Не записалось столько байт сколько нужно");
	}
	printf("Записали в канал %d байт : ", writeStr);
	for (int i = 0; i < writeStr; i++)
		printf("%c", buffer[i]);
	printf("\n");
	
	DWORD readStr;
	
	char* newbuffer = new char[strlen(buffer) + 1];
	if (!ReadFile(hRead, newbuffer, sizestr, (LPDWORD)&readStr, NULL))
	{
		printf("Не считался канал с ошибкой номером %i", GetLastError());
	}
	if (sizestr != readStr)
	{
		printf("Не записалось столько байт сколько нужно");
	}
	printf("Считали из канала %d байт : ", readStr);
	for (int i = 0; i < readStr; i++)
		printf("%c", newbuffer[i]);
	CloseHandle(hWrite);
	CloseHandle(hRead);
}

int main(int argc, LPTSTR argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 1) {
		printf("Не должно быть аргументов");
		return 0;
	}
	channel();
	return 0;
}
