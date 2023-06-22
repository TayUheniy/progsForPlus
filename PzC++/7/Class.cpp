#include "stdafx.h"
#include "Class.h"

Student::Student(char* fam, int y, int* m)
{
	family = _strdup(fam);
	years = y;
	marks = new int[5];
	for (int i = 0; i < 5; ++i)
		marks[i] = m[i];
}

Student::Student(const Student& ob): years(ob.years)
{
	family = _strdup(ob.family);
	marks = new int[5];
	for (int i = 0; i < 5; ++i)
		marks[i] = ob.marks[i];
}

Student::~Student()
{
	delete[] family;
	delete[] marks;
}

 Student& Student::operator=(const Student& ob)
{
	if (this == &ob)
		return *this;
	delete[] family;
	delete[] marks;
	family = _strdup(ob.family);
	marks = new int[5];
	for (int i = 0; i < 5; ++i)
		marks[i] = ob.marks[i];
	years = ob.years;
	
}
int  Student::Year() const
{
	return years;
}

int Student::operator[](int index) const
{
	return marks[index];
}
AverageAgeProcessor::AverageAgeProcessor()
{
	studentcount = 0;
	sumyears = 0;
}

void AverageAgeProcessor::Process(Student& student)
{
	
	++studentcount;
	sumyears += student.Year();
}


double AverageAgeProcessor::GetAverageAgeStudent() const
{
	return ((double)(2018 * studentcount) - sumyears) / (double)studentcount;
}

void ProcessStudents(Student* group, int studcount, IStudentProcessor& processor)
{
	for (int i = 0; i < studcount; ++i)
		processor.Process(group[i]);
}
double CalculateAverageAge(Student *group, int count )
{
	AverageAgeProcessor A;
	ProcessStudents(group, count, A);
	return A.GetAverageAgeStudent();

}
AverageMarkProcessor::AverageMarkProcessor()
{
	studentcount = 0;
	summark = 0;
	averagemark = 0;
	count = 0;
}

void AverageMarkProcessor::Process(Student& student)
{
	++count;
	++studentcount;
	for (int i = 0; i < 5; ++i)
	{
		summark += student[i];
	};
	averagemark = ((double)summark / (double)(studentcount*5));
}

double AverageMarkProcessor::GetAverageMarkStudent() const
{
	return averagemark;
}

double CalculateAverageMark(Student *group, int count)
{
	AverageMarkProcessor A;
	ProcessStudents(group, count, A);
	return A.GetAverageMarkStudent();

}

