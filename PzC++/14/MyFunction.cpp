#include "stdafx.h"
#include "MyFunction.h"

std::string Loade(const char* Typename)
{
	FILE *ptrFile;
	fopen_s(&ptrFile, Typename, "r");
	if (ptrFile == nullptr)
		return 0;
	std::string rez{};
	fseek(ptrFile, 0, SEEK_END);
	long fileSize = ftell(ptrFile);
	rewind(ptrFile);
	long count = 1024;
	for (; fileSize != 0;)
	{
		char* buffer = new char[count + 1]{};
		if (fileSize - count > count)
		{
			fread(buffer, 1, count, ptrFile);
			fileSize -= count;
			buffer[count] = '\0';
		}
		else
		{
			fread(buffer, 1, fileSize, ptrFile);
			buffer[fileSize] = '\0';
			fileSize = 0;
		}
		rez += buffer;
		delete[] buffer;
	}
	fclose(ptrFile);
	return rez;
}

std::string sovpad(std::string a, std::string b)
{
	std::string rez = {};
	if (a.size()<b.size())
		std::swap(a, b);
	
	int m = a.size();
	int n = b.size();
	int i1 = -1;
	int maxl = -1;
	int* diag = new int[n] {0};

		for (int count=0;count<m;++count)
		{
			if (m - count < maxl)
				break;
			int i = 0;
			int j = 0;
			while (i + count<m && j < n)
			{
				if (a[i + count] == b[j])
				{
					diag[i+1] = 1 + diag[i];
					if (maxl < diag[i+1])
					{
						maxl = diag[i+1];
						i1 = i + count;
					}
				}
				else
					diag[i+1] = 0;
				if (diag[i] == 0 && m - i < maxl)
					break;
				++i;
				++j;
			}
		}

		for (int count = 1; count < n; ++count)
		{
			if (n - count < maxl)
				break;
			int i = 0;
			int j = 0;
			while (j + count < n && i < m)
			{
				if (a[i] == b[j+count])
				{
					diag[i+1] = 1 + diag[i];
					if (maxl < diag[i+1])
					{
						maxl = diag[i+1];
						i1 = i;
					}
				}
				else
					diag[i+1] = 0;
				if (diag[i] == 0 && n - j < maxl)
					break;
				++i;
				++j;
			}
			
		}
		if (i1 == -1)
			rez = {};
		else
		{
			for (int i = 0; i < maxl; ++i)
				rez+=a[i1 - maxl+1 + i];
		}
		return rez;
}
