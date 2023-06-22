#include "stdafx.h"
#include "Class.h"


int k;
Soldier::Soldier()
{
	++k;
	_jobCount = 0;
	
}

Soldier::~Soldier()
{
	--k;
}

void Soldier::Serve()
{
	++_jobCount;
}

int Soldier::Count()
{
return _jobCount;

}

Officer::Officer(int n,IMilitaryMan** ob)
{
	countsub = n;
	submission = new IMilitaryMan*[countsub];
	memcpy(submission, ob, sizeof(IMilitaryMan*)*countsub);
	++k;
}

Officer::~Officer()
{
	for (int i = 0; i < countsub; ++i)
		delete submission[i];
	delete[] submission;
	--k;
}

void Officer::Serve()
{
	for (int i = 0; i < countsub; ++i)
		submission[i]->Serve();
}
