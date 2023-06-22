#pragma once
#include "Let10IMilitaryManApi.hpp"

LET10IMILITARYMAN_API extern int k;
class IMilitaryMan
{
public:
	LET10IMILITARYMAN_API  virtual ~IMilitaryMan(void) {}
	LET10IMILITARYMAN_API virtual void Serve()=0;
};

class Soldier: public IMilitaryMan
{
public:
	LET10IMILITARYMAN_API Soldier();
	LET10IMILITARYMAN_API ~Soldier();
	LET10IMILITARYMAN_API void Serve();
	LET10IMILITARYMAN_API int Count();

private:
	int _jobCount;
};

class Officer : public IMilitaryMan
{
public:
	LET10IMILITARYMAN_API Officer(int n, IMilitaryMan** ob);
	LET10IMILITARYMAN_API ~Officer();
	LET10IMILITARYMAN_API void Serve();
private:
	int countsub;
	IMilitaryMan** submission;
};