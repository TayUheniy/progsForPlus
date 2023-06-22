#include "pch.h"
#include <sys/stat.h>

bool fileExists(LPTSTR filename) {
	WIN32_FIND_DATA FILE;
	HANDLE fileFind = ::FindFirstFile(filename, &FILE);
	if (INVALID_HANDLE_VALUE != fileFind) {
		::FindClose(fileFind);
		return true;
	}
	return false;
}

int copy(LPTSTR firstFile, LPTSTR twoFile) {
	HANDLE descriptOneFile, descriptTwoFile;
	descriptOneFile = CreateFile(firstFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
	if (descriptOneFile == INVALID_HANDLE_VALUE) {
		printf("Не открывается файл, который нужно скопировать.");
		return 0;
	}
	if (fileExists(twoFile)) {
		printf("Файл с таким названием уже существует");
		return 0;
	}
	else {
		descriptTwoFile = CreateFile(twoFile, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_FLAG_OVERLAPPED, NULL);
		if (descriptTwoFile == INVALID_HANDLE_VALUE) {
			printf("Не открывается файл,в который нужно скопировать");
			return 0;
		}
	}
	TCHAR buff[1024];
	DWORD numberByteOne, numberByteTwo;
	OVERLAPPED structureOver = { 0 };
	struct stat file;
	stat(firstFile, &file);
	long long filesize = file.st_size;
	struct stat filetwo;
	printf("Копирование: \n");
	while (true) {
		ReadFile(descriptOneFile, buff, 1, &numberByteOne, &structureOver);
		if (structureOver.InternalHigh == 0)
		{
			CloseHandle(descriptOneFile);
			CloseHandle(descriptTwoFile);
			return 0;
		}

		WriteFile(descriptTwoFile, buff, structureOver.InternalHigh, &numberByteTwo, &structureOver);
		stat(twoFile, &filetwo);
		long long filesizetwo = filetwo.st_size;
		int procent = ((double)filesizetwo / (double)filesize) * 100;
		if (((double)filesizetwo / (double)filesize) < 0.015) {
			procent = 0;
		}
		printf("%i%% \b\b\b\b\b\b\b", procent);
		Sleep(1);
		structureOver.Offset += structureOver.InternalHigh;
	}
}

int main(int argc, LPTSTR argv[]) {
	setlocale(LC_ALL, "Russian");
	if (argc != 3) {
		printf("Неправильное количество аргументов, всего параметров должно быть 3");
		return 0;
	}
	copy(argv[1], argv[2]);
	return 0;
}

