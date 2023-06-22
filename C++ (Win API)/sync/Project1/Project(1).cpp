#include "pch.h"

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
	descriptOneFile = CreateFile(firstFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (descriptOneFile == INVALID_HANDLE_VALUE) {
		printf("Не открывается файл, который нужно скопировать.");
		return 0;
	}
	if (fileExists(twoFile)) {
		printf("Файл с таким названием уже существует");
		return 0;
	}
	else {
		descriptTwoFile = CreateFile(twoFile, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
		if (descriptTwoFile == INVALID_HANDLE_VALUE) {
			printf("Не открывается файл,в который нужно скопировать");
			return 0;
		}
	}
	TCHAR buff[1024];
	DWORD numberByteOne, numberByteTwo;
	while (ReadFile(descriptOneFile, buff, 1024, &numberByteOne, NULL) && numberByteOne > 0) {
		WriteFile(descriptTwoFile, buff, numberByteOne, &numberByteTwo, NULL);
	}
	CloseHandle(descriptOneFile);
	CloseHandle(descriptTwoFile);
	return 0;
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
