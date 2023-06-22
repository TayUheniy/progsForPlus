#include "stdafx.h"
#include "MyFunctions.h"

size_t lenght(const char *str)
{
	if (str == nullptr) return 0;
	size_t k = 0;
	while (*(str+k))
	{
		++k;
	}
	return k;
}

 char *newstr(const char *str1, const char *str2)
{
	size_t lstr1 = lenght(str1);
	size_t lstr2 = lenght(str2);
	char *nstr3 = new char[lstr1 + lstr2 + 1];
	for (size_t i = 0; i < lstr1; ++i)
		nstr3[i] = str1[i];
	for (size_t i = 0; i < lstr2; ++i)
		nstr3[i+ lstr1] = str2[i];
	nstr3[lstr1 + lstr2] = '\0';
	return nstr3;
}

 char *CombinePathes(const char *directoryPath, const char *fileName)
 {
	 char* str = newstr(directoryPath, "\\");
	 str = newstr(str, fileName);
	 return str;
 }


 bool CombinePath(const char *directoryPath, const char *subDirectoryName)
 {
	 char* str = CombinePathes(directoryPath, subDirectoryName);
	 int stat = _mkdir(str);
	 return !stat; 
 }

 bool Createdirfamyly(bool isDirectory,const char *fileObjectPath)
 {
	 int stat(0);
	 char *slov = new char[10];
	 if (isDirectory)
	 {
		slov =(char*) strstr(fileObjectPath, "ин");
		 if (lenght(slov) == lenght("ин"))
			{
				 char buffer[_MAX_PATH];
				 _getcwd(buffer, _MAX_PATH);
				 char* str = newstr(buffer, "\\");			 
				 str = newstr(str, "ин");
				 _chdir(str);
				 stat += CombinePath(str, "Самостоятельные работы");
				 stat += CombinePath(str, "Контрольные работы");
				 stat += CombinePath(str, "Практические задания");
				 delete[] str;
				 return stat ? true : false;
				 str = newstr(buffer, "\\..");
				 _chdir(str);
				 delete[] str;
			}
	 }
	 return true;
 }

 bool TraverseDirectory(const char *directoryPath, FileObjectProcessor fileObjectProcessor)
 {
	 setlocale(LC_ALL, "Russian");
	 struct _finddata_t fileInfo;
	 intptr_t hFile;
	 int nextFile = 0;
	 _chdir(directoryPath);
	 char buffer[_MAX_PATH];
	 char* subDir = nullptr;
	 char* buffDel = nullptr;
	 char* subDir_file = nullptr;
	 bool play_processing = false;
	 hFile = _findfirst("*", &fileInfo);
	 do
	 {
		 _getcwd(buffer, _MAX_PATH);
		/* if (fileInfo.name[0] != '.')
		 play_processing = fileObjectProcessor(fileInfo.attrib & _A_SUBDIR, fileInfo.name);*/
		
		 if ((fileInfo.attrib & _A_SUBDIR) && !(fileInfo.attrib& _A_SYSTEM) && (fileInfo.name[0] != '.'))
			 {
				 play_processing = fileObjectProcessor(fileInfo.attrib & _A_SUBDIR, fileInfo.name);
				 subDir = newstr(buffer, "\\");
				 buffDel = subDir;
				 subDir = newstr(subDir, fileInfo.name);
				 delete[] buffDel;
				 if (!TraverseDirectory(subDir, fileObjectProcessor))
					 return false;
				 delete[] subDir;
				 if (!play_processing)
					 return false;
				 nextFile = _findnext(hFile, &fileInfo);
			 }
		 else
		 {
			 if (fileInfo.name[0] != '.')
			 {
				 subDir_file = newstr(buffer, "\\");
				 buffDel = subDir_file;
				 subDir_file = newstr(subDir_file, fileInfo.name);
				 play_processing = fileObjectProcessor(fileInfo.attrib & _A_SUBDIR, fileInfo.name);
				 delete[] buffDel;
				 delete[] subDir_file;
				 if (!play_processing)
					 return false;
			 }
			 nextFile = _findnext(hFile, &fileInfo);
		 }
		 if (nextFile != 0)
			 {
				 buffDel = newstr(buffer, "\\..");
				 _chdir(buffDel);
				 delete[] buffDel;
			 }
	 } 
	 while (nextFile == 0);
	 _findclose(hFile);
	 return true;
 }

 bool RenameFile(const char *originalFilePath, const char *newFileName)
 {
	 return !rename(originalFilePath, newFileName);
 }

 bool RenameDirectory(bool isDirectory, const char *fileObjectPath)
 {
	 char *slov = new char[10];
	 slov = (char*)strstr(fileObjectPath, "ин");
		 if (lenght(slov) == lenght("ин"))
			 return RenameFile(fileObjectPath, "ин Артем Ильич");
		 if (lenght(slov) == lenght("ин.txt"))
			 return RenameFile(fileObjectPath, "ин Артем Ильич.txt");
	 return true;
 }

 char *StrFromFile(const char *data,size_t &Lenghtsize)
 {
	 FILE *ptrFile;
	 ptrFile = fopen(data, "r");
	 if (ptrFile == nullptr)
		 return nullptr;
	 fseek(ptrFile, 0, SEEK_END);
	 long fileSize = ftell(ptrFile);
	 rewind(ptrFile);
	 char *buffer = new char[fileSize] {0};
	 fread(buffer, 1, fileSize, ptrFile);
	 Lenghtsize = fileSize;
	 fclose(ptrFile);
	 return buffer;
 }

 bool CopyFiles(const char *sourceFilePath, const char *destinationFilePath, size_t blockSize)
 {
	 FILE *ptrFile = nullptr;
	 size_t lenght = 0;
	 size_t sizeofblockssend = 0;
	 char *input = StrFromFile(sourceFilePath, lenght);
	 if (!input)
		 return false;
	 if (_chdir(destinationFilePath) != 0)
		 return false;
	 fopen_s(&ptrFile, sourceFilePath, "wb");
	 if (!ptrFile)
		 return false;
	 while (lenght > sizeofblockssend)
	 {
		 if (!fwrite(input + sizeofblockssend, 1, blockSize, ptrFile))
			 return false;
		 if (blockSize > lenght - sizeofblockssend)
			 blockSize = lenght - sizeofblockssend;
		 sizeofblockssend += blockSize;
	 }
	 if (lenght)
		 delete[] input;
	 return true;
 }

 bool CreateDirectoryWay(const char* way, const char* &create_way)
 {
	 char* delBuf = nullptr;
	 char name[_MAX_PATH]{ 0 };
	 char * rezult = nullptr;
	 char wayput[_MAX_PATH]{ 0 };
	 _getcwd(wayput, _MAX_PATH);
	 _chdir(way);
	 for (int i = 0; create_way[i] != '\0'; ++i)
	 {
		 int j = 0;
		 for (j = 0; (create_way[i + j] != '\\') && (create_way[i + j] != '\0'); ++j)
			 name[j] = create_way[i + j];
		 i += j;
		 _mkdir(name);
		 if (_chdir(name) != 0)
			 return false;
		 if (!create_way[i])
		 {
			 rezult = newstr(way, "\\");
			 delBuf = (char*)create_way;
			 create_way = newstr(rezult, create_way);
			 delete[] delBuf;
			 delete[] rezult;
			 _chdir(wayput);
			 return true;
		 }
		 for (int m = 0; m < j; ++m)
			 name[m] = '\0';
	 }
	 _chdir(wayput);
	 return true;
 }

 bool CopyDirectory(bool isDirectory, const char *fileObjectPath)
 {
	 char *slov = new char[10];
	 slov = (char*)strstr(fileObjectPath, "ин");
	 if (lenght(slov) == lenght("ин.txt"))
	 {

		 char buffer[_MAX_PATH];
		 _getcwd(buffer, _MAX_PATH);
		 const char* waycopy = "Созданная папка";
		 waycopy = newstr(waycopy, buffer+2);
		 if (!isDirectory)
		 {
			 if (!CreateDirectoryWay("C:\\", waycopy))
				 return false;
			 _chdir(buffer);
			 if (!CopyFiles(fileObjectPath, waycopy, 1))
				 return false;
			 _chdir(buffer);
			 delete[] waycopy;
		 }
	 }
	 return true;
 }
 bool TraverseDirectory(const char *directoryPath, FileObjectProcessorSize fileObjectProcessor, int &rezult)
 {
	 struct _finddata_t fileInfo;
	 intptr_t hFile;
	 int nextFile = 0;
	 _chdir(directoryPath);
	 char buffer[_MAX_PATH];
	 char* subDir = nullptr;
	 char* buffDel = nullptr;
	 bool play_processing = false;
	 hFile = _findfirst("*", &fileInfo);
	 do
	 {
		 _getcwd(buffer, _MAX_PATH);

		 if ((fileInfo.attrib & _A_SUBDIR) && !(fileInfo.attrib& _A_SYSTEM) && (fileInfo.name[0] != '.'))
			 {
				 play_processing = fileObjectProcessor(fileInfo.attrib & _A_SUBDIR, fileInfo.name, rezult, 0);
				 subDir = newstr(buffer, "\\");
				 buffDel = subDir;
				 subDir = newstr(subDir, fileInfo.name);
				 delete[] buffDel;
				 if (!TraverseDirectory(subDir, fileObjectProcessor, rezult))
					 return false;
				 delete[] subDir;
				 if (!play_processing)
					 return false;
				 nextFile = _findnext(hFile, &fileInfo);
			 }
		 else
			 {
				 if (fileInfo.name[0] != '.')
				 {
					 play_processing = fileObjectProcessor(fileInfo.attrib & _A_SUBDIR, fileInfo.name, rezult, fileInfo.size);

					 if (!play_processing)
						 return false;
				 }
				 nextFile = _findnext(hFile, &fileInfo);
			 }

		 if (nextFile != 0)
			 {
				 buffDel = newstr(buffer, "\\..");
				 _chdir(buffDel);
				 delete[] buffDel;
			 }
	 } 
	 while (nextFile == 0);
	 _findclose(hFile);
	 return true;
 }

 bool SizeDirectory(bool isDirectory, const char *fileObjectPath, int &rezult, int size)
 {
	 if (!isDirectory)
		 rezult += size;
	 return true;
 }

 bool SizeFileOfDirectory(const char *directoryPath, int &number, char** &rezult)
 {
	 struct _finddata_t fileInfo;
	 intptr_t hFile;
	 int nextFile = 0;
	 int sizeDirectory = 0;
	 char* bufferdirectoryPath = nullptr;
	 char* delBuff = nullptr;
	 _chdir(directoryPath);
	 hFile = _findfirst("*", &fileInfo);
	 do
	 {
		 if ((fileInfo.name[0] != '.'))
			 ++number;
		 nextFile = _findnext(hFile, &fileInfo);
	 }
	 while (nextFile == 0);
	 rezult = new char*[number];
	 for (int i = 0; i < number; ++i)
		 rezult[i] = new char[_MAX_PATH + 10]{ 0 };
	 hFile = _findfirst("*", &fileInfo);
	 do
	 {
		 if (!(fileInfo.attrib& _A_SYSTEM) && (fileInfo.name[0] != '.')) {
			 char buffer[_MAX_PATH]{ 0 };
			 for (int i = 0; i < number; ++i)
			 {
				 int j = 0;
				 for (j = 0; fileInfo.name[j] != '\0'; ++j)
					 rezult[i][j] = fileInfo.name[j];
				 if (fileInfo.attrib & _A_SUBDIR)
				 {
					 sizeDirectory = 0;
					 bufferdirectoryPath = newstr(directoryPath, "\\");
					 delBuff = bufferdirectoryPath;
					 bufferdirectoryPath = newstr(bufferdirectoryPath, fileInfo.name);
					 TraverseDirectory(bufferdirectoryPath, SizeDirectory, sizeDirectory);
					 delete[] bufferdirectoryPath;
					 delete[] delBuff;
					 if (sizeDirectory / 1024 < 1024) 
					 {
						 snprintf(buffer, _MAX_PATH, "%d", sizeDirectory / 1024);
						 rezult[i][j] = ' ';
						 int k = 0;
						 for (k = 0; buffer[k] != '\0'; ++k)
							 rezult[i][j + k + 1] = buffer[k];
						 rezult[i][j + k + 1] = ' ';
						 rezult[i][j + k + 2] = 'К';
						 rezult[i][j + k + 3] = 'Б';
					 }
					 else
					 {
						 double size = (double)(sizeDirectory) / 1024.0 / 1024.0;
						 snprintf(buffer, _MAX_PATH, "%f", size);
						 rezult[i][j] = ' ';
						 int k = 0;
						 for (k = 0; buffer[k] != '\0'; ++k)
							 rezult[i][j + k + 1] = buffer[k];
						 rezult[i][j + k + 1] = ' ';
						 rezult[i][j + k + 2] = 'М';
						 rezult[i][j + k + 3] = 'Б';
					 }
				 }
				 else
					 if (fileInfo.size / 1024 < 1024)
					 {
						 snprintf(buffer, _MAX_PATH, "%d", fileInfo.size / 1024);
						 rezult[i][j] = ' ';
						 int k = 0;
						 for (k = 0; buffer[k] != '\0'; ++k)
							 rezult[i][j + k + 1] = buffer[k];
						 rezult[i][j + k + 1] = ' ';
						 rezult[i][j + k + 2] = 'К';
						 rezult[i][j + k + 3] = 'Б';
					 }
					 else
					 {
						 double size = (double)(fileInfo.size) / 1024.0 / 1024.0;
						 snprintf(buffer, _MAX_PATH, "%f", size);

						 rezult[i][j] = ' ';

						 int k = 0;
						 for (k = 0; buffer[k] != '\0'; ++k)
							 rezult[i][j + k + 1] = buffer[k];
						 rezult[i][j + k + 1] = ' ';
						 rezult[i][j + k + 2] = 'М';
						 rezult[i][j + k + 3] = 'Б';
					 }
				 nextFile = _findnext(hFile, &fileInfo);
			 }
		 }
		 nextFile = _findnext(hFile, &fileInfo);
	 } 
	 while (nextFile == 0);
	 _findclose(hFile);
	 return true;
 }

 
 bool Sortirovka(const char *fileName, int N)
 {
	 FILE *fptr;
	 fopen_s(&fptr, fileName, "r+");
	 int *mas = new int[N];
	 if (fptr == nullptr)
		 return false;
	 fseek(fptr, N, SEEK_CUR);
	 for (int i = 0; i < N; ++i)
	 {
		 if (!fscanf_s(fptr, "%d", &mas[i]))
			 return false;
	 }
	 for (int i = 1; i < N; ++i)
	 {
		 int buf = mas[i];
		 int index = i - 1;
		 while (index >= 0 && mas[index] < buf)
		 {
			 mas[index + 1] = mas[index];
			 mas[index] = buf;
			 --index;
		 }
	 }
	 rewind(fptr);
	 fseek(fptr, N, SEEK_CUR);
	 for (int i = 0; i < N; ++i)
	 {
		 if (!fprintf_s(fptr, "%d ", mas[i]))
			 return false;
	 }
	 fclose(fptr);
	 return true;
 }
 
 bool OpenFileSortirovka(bool isDirectory, const char *fileObjectPath)
 {
	 char *slov = new char[10];
	 if (!isDirectory)
	 {
		 slov = (char*)strstr(fileObjectPath, "ин");
		 if (lenght(slov) == lenght("ин.txt"))
		 {
			 _chdir(fileObjectPath);

			 struct _finddata_t fileInfo;
			 intptr_t hFile;
			 int nextFile = 0;
			 hFile = _findfirst("*", &fileInfo);
			 do
			 {
				 char *slov1 = new char[10];
				 slov1 = (char*)strstr(fileInfo.name, "ин");
				 if (!(fileInfo.attrib & _A_SUBDIR) && !(fileInfo.attrib & _A_SYSTEM) && ((lenght(slov1) == lenght("ин.txt"))))
				 {
					 if (!Sortirovka(fileInfo.name, 24))
						 return false;
				 }
				 nextFile = _findnext(hFile, &fileInfo);
			 } 
			 while (nextFile == 0);
			 _findclose(hFile);
		 }
	 }
	 return true;
 }