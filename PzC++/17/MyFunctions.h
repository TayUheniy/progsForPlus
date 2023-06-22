#pragma once
#include "Pz12Api.hpp"

struct st
{
char c; struct st *next;
};
PZ12_API struct st *push(struct st*, char);
PZ12_API char DEL(struct st **);
PZ12_API int Prioritet(char);
PZ12_API std::string InPolish(const char*);
struct newst
{
public:
	char _value[100];
	int _prioritet;
	newst * _next;
};
PZ12_API int fp(char* );
PZ12_API void push(newst*);
PZ12_API void push(char*, int );
PZ12_API newst * pop();
PZ12_API std::string OutPolish(char*);
PZ12_API std::string Transform(char*);