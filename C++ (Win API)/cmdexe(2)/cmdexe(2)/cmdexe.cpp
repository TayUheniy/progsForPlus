#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>



int main(int argc, LPTSTR argv[]) {
	setlocale(LC_ALL, "Russian");
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	std::string resultpath = argv[1];
	resultpath += "\\*";
	
	hf = FindFirstFile((LPCSTR)resultpath.c_str(), &FindFileData);
	if (hf != INVALID_HANDLE_VALUE) {
		do {
			std::cout << FindFileData.cFileName << "\n";
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
	return 0;
}



