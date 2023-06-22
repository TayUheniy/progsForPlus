#pragma once
#include "Let9StackApi.hpp"
using namespace std;

class StackOverflow : public exception
{
public:
	StackOverflow() throw()
		: exception("Стек уже полон")
	{
	}
	
};

class StackIsEmpty : public exception
{
public:
	StackIsEmpty() throw()
		:exception("Стек пуст")
	{
	}

};

LET9STACK_API int lenghtstr(char* c);

class IntStack
{
public:
	LET9STACK_API IntStack(int);
	//LET9STACK_API IntStack(const IntStack &ob);
	LET9STACK_API ~IntStack();
	LET9STACK_API void push(int elem);
	LET9STACK_API int top();
	LET9STACK_API int pop();
	LET9STACK_API int capacity() const;
	LET9STACK_API bool empty() const;
	LET9STACK_API int size() const;
private:

	int  stacktop;
	int maxelement;
	int* mas;

	IntStack(const IntStack &) {}
	IntStack& operator=(const IntStack&) { return *this; }
};

class StringStack
{
public:
	LET9STACK_API StringStack(int);
	LET9STACK_API ~StringStack();
	LET9STACK_API void push(char *elem);
	LET9STACK_API const char* top();
	LET9STACK_API char* pop();
	LET9STACK_API int capacity() const;
	LET9STACK_API bool empty() const;
	LET9STACK_API int size() const;
private:
	char** mas;
	int  stacktop;
	int maxelement;
};