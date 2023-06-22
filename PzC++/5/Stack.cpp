#include "stdafx.h"
#include "Stack.h"


int lenghtstr(char* c)
{
	int k = 0;
	while (*(c + k))
		++k;
	return k;
}

IntStack::IntStack(int N)
{
	 mas = new int[N] {};
	 stacktop = -1;
	 maxelement = N;
}

//IntStack::IntStack(const IntStack &ob): stacktop(ob.stacktop), maxelement(ob.maxelement)
//{
//	mas = new int[maxelement];
//	for (int i = 0; i <= stacktop; ++i)
//		mas[i] = ob.mas[i];
//}

IntStack::~IntStack()
{
	delete[] mas;
}

void IntStack::push(int elem)
{
	++stacktop;
	if (stacktop >= maxelement)
		throw StackOverflow();
	mas[stacktop] = elem;

}

int IntStack::top()
{
	if (stacktop == -1)
		throw StackIsEmpty();
	return mas[stacktop];
}

int IntStack::pop()
{
	if (stacktop == -1)
		throw StackIsEmpty();
	--stacktop;
	return mas[stacktop+1];
}

int IntStack::capacity() const
{
	return  maxelement;
}

bool IntStack::empty() const
{
	return stacktop == -1;
}

int IntStack::size() const
{
	return  stacktop + 1;
}






StringStack::StringStack(int capacity)
{
	mas = new char *[capacity] {};
	stacktop = -1;
	maxelement = capacity;
}

StringStack::~StringStack()
{
	for (int i = 0; i <= stacktop; ++i)
		delete[] mas[i];
	delete[] mas;
}

void StringStack::push(char* elem)
{
	if (stacktop >= maxelement)
		throw StackOverflow();
	++stacktop;
	/*size_t l = strlen(elem);
	mas[stacktop] = new char[l + 1];
	strcpy(mas[stacktop],elem);*/
	mas[stacktop] = _strdup(elem);
}

const char* StringStack::top()
{
	if (stacktop == -1)
		throw StackIsEmpty();
	return mas[stacktop];
}

char* StringStack::pop()
{
	if (stacktop == -1)
		throw StackIsEmpty();
	--stacktop;
	return mas[stacktop+1];
}

int StringStack::capacity() const
{
	return  maxelement;
}

bool StringStack::empty() const
{
	return stacktop == -1;
	
}

int StringStack::size() const
{
	return  stacktop + 1;
}

