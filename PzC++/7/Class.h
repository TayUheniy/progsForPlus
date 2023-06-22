#pragma once
#include "Let11IStudentProcessorApi.hpp"
using namespace std;

class Student
{
public:
	LET11ISTUDENTPROCESSOR_API Student(char*, int, int*);
	LET11ISTUDENTPROCESSOR_API Student(const Student&);
	LET11ISTUDENTPROCESSOR_API ~Student();
	LET11ISTUDENTPROCESSOR_API Student& operator = (const Student&);
	LET11ISTUDENTPROCESSOR_API int Year() const;
	LET11ISTUDENTPROCESSOR_API int operator [] (int index) const;
private:
	char* family;
	int years;
	int* marks;

};

class IStudentProcessor
{
public:
	LET11ISTUDENTPROCESSOR_API virtual ~IStudentProcessor(void) {}
	LET11ISTUDENTPROCESSOR_API virtual void Process(Student& student) =0;
};

class AverageAgeProcessor : public IStudentProcessor
{
public:
	LET11ISTUDENTPROCESSOR_API AverageAgeProcessor();
	LET11ISTUDENTPROCESSOR_API void Process(Student& student) override;
	LET11ISTUDENTPROCESSOR_API double GetAverageAgeStudent() const;

private:
	int sumyears;
	int studentcount;
};

class AverageMarkProcessor : public IStudentProcessor
{
public:
	LET11ISTUDENTPROCESSOR_API AverageMarkProcessor();
	LET11ISTUDENTPROCESSOR_API void Process(Student& student);
	LET11ISTUDENTPROCESSOR_API double GetAverageMarkStudent() const;

private:
	double averagemark;
	int count;
	int summark;
	int studentcount;
};



LET11ISTUDENTPROCESSOR_API void ProcessStudents(Student*, int, IStudentProcessor&);
LET11ISTUDENTPROCESSOR_API double CalculateAverageAge(Student *group, int count);
LET11ISTUDENTPROCESSOR_API double CalculateAverageMark(Student *group, int count);