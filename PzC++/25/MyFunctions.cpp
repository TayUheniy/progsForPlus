#include "stdafx.h"
#include "LearningGroup.hpp"
bool WriteTextLearningGroup(const char *fileName, LearningGroup const& t)
{
	
	FILE *ptrFile;
	ptrFile = fopen(fileName, "w+");
	if (!ptrFile) 
		return false;
	
	fprintf(ptrFile, "%s", t.Faculty);
	fprintf(ptrFile, "\n");
	fprintf(ptrFile, "%d", t.Number);
	fprintf(ptrFile, "\n");
	fprintf(ptrFile, "%d", t.StudentCount);
	fprintf(ptrFile, "\n");
	fclose(ptrFile);
	return true;
}

bool ReadTextLearningGroup(const char *fileName, LearningGroup& t)
{
	FILE *ptrFile;
	ptrFile = fopen(fileName, "r");
	if (!ptrFile )
		return false;
	
	fscanf(ptrFile, "%s%d%d", t.Faculty, &t.Number, &t.StudentCount);
	fclose(ptrFile);
	return true;
}

bool WriteBinaryLearningGroup(const char *fileName, const LearningGroup& t)
{
	FILE *ptrFile;
	ptrFile = fopen(fileName, "w+");
	if (!ptrFile)
		return false;
	fwrite(&t, sizeof(LearningGroup), 1, ptrFile);
	fclose(ptrFile);
	return true;
}
bool ReadBinaryLearningGroup(const char *fileName, LearningGroup& t)
{
	FILE *ptrFile;
	ptrFile = fopen(fileName, "r");
	if (!ptrFile)
		return false;
	fread(&t, sizeof(LearningGroup), 1, ptrFile);
	fclose(ptrFile);
	return true;
}