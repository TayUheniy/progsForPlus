#pragma once
#pragma pack(4)

struct LearningGroup
{
	char Faculty[38];
	int Number;
	int StudentCount;
};
bool WriteTextLearningGroup(const char *fileName, LearningGroup const& t);
bool ReadTextLearningGroup(const char *fileName, LearningGroup& t);
bool WriteBinaryLearningGroup(const char *fileName, const LearningGroup& t);
bool ReadBinaryLearningGroup(const char *fileName, LearningGroup& t);