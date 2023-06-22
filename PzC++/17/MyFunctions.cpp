#include "stdafx.h"
#include "MyFunctions.h"


int Prioritet(char str)
{
	switch (str)
	{
	case '/':
		return 6;
	case '*':
		return 5;
	case '-':
		return 3;
	case '+':
		return 2;
	case '(':
		return 1;
	}
	return 0;
} 

char DEL(struct st** HEAD)
{
	struct st *PTR;
	char a;
	if (*HEAD == NULL) return '\0';
	PTR = *HEAD;
	a = PTR->c;
	*HEAD = PTR->next;
	free(PTR);
	return a;
}

struct st *push(struct st *HEAD, char a)
{
	struct st *PTR = new st;
	PTR->c = a;
	PTR->next = HEAD;
	return PTR;
}

std::string InPolish(const char* str)
{
	struct st *OPERS = NULL;
	char* Vir = _strdup(str);
	std::string outstring{};
	int k(0);
	while (Vir[k] != '\0'&&Vir[k] != '=')
	{
		if (Vir[k] == ')')
		{
			while ((OPERS->c) != '(')
			{
			outstring += DEL(&OPERS);
			outstring += ' ';
			}
			DEL(&OPERS);
		}
		if ((Vir[k] >= 'a'&&Vir[k] <= 'z') || (Vir[k] >= '1' && Vir[k] <= '9'))
		{
			for (; (Vir[k] >= 'a'&& Vir[k] <= 'z') || (Vir[k] >= '1' && Vir[k] <= '9') && Vir[k]; ++k)
				outstring += Vir[k];
			--k;
			outstring += ' ';
		}
		if (Vir[k] == '(')
		OPERS = push(OPERS, '(');
		if (Vir[k] == '+' || Vir[k] == '-' || Vir[k] == '/' || Vir[k] == '*')
		{
			if (OPERS == NULL)
				OPERS = push(OPERS, Vir[k]);
			else
				if (Prioritet(OPERS->c) < Prioritet(Vir[k]))
					OPERS = push(OPERS, Vir[k]);
				else
				{
					while ((OPERS != NULL) && (Prioritet(OPERS->c) >= Prioritet(Vir[k])))
					{
						outstring += DEL(&OPERS);
						outstring += ' ';
					}
					OPERS = push(OPERS, Vir[k]);
				}
		}
		++k;
	}
	while (OPERS != NULL)
	{
		outstring += DEL(&OPERS);
		outstring += ' ';
	}
	
	return outstring;
};

newst *head;
std::string OutPolish(char * str)
{
	std::string result{};
	char newsimb;
	char temp[100]{ 0 };
	int i = 0;
	newst *left, *right;
	int priority;
	while (*str)
	{
		newsimb = *str;
		if ((newsimb >= '0' && newsimb <= '9') || (newsimb >= 'a' && newsimb <= 'z'))
		{
			temp[i] = newsimb;
			temp[++i] = '\0';
		}

		if (newsimb == ' ')
		{
			if (i != 0)
			{
				push(temp, 0);
				i = 0;
			}
			temp[0] = '\0';
		}

		if (newsimb == '+' || newsimb == '-' || newsimb == '*' || newsimb == '/')
		{
			left = pop();
			right = pop();
			priority = fp(str);
			if (right->_prioritet && (right->_prioritet < priority) && !(priority - right->_prioritet == 1))
			{
				temp[0] = '(';
				temp[1] = '\0';
				right->_value[strlen(right->_value) + 2] = '\0';
				right->_value[strlen(right->_value) + 1] = newsimb;
				right->_value[strlen(right->_value)] = ')';
			}

			else
			{
				right->_value[strlen(right->_value) + 1] = '\0';
				right->_value[strlen(right->_value)] = newsimb;
			}
			strcat_s(temp, right->_value);

			if (left->_prioritet && left->_prioritet < priority)
			{
				strcat_s(temp, "(");
				left->_value[strlen(left->_value) + 1] = '\0';
				left->_value[strlen(left->_value)] = ')';
			}

			strcat_s(temp, left->_value);
			strcpy_s(right->_value, temp);
			delete left;
			right->_prioritet = priority;
			push(right);
		}
		++str;
	}
	char* buffer = (pop())->_value;
	result = buffer;
	return result;
}

int fp(char* str)
{
	char simv = *str;
	if (simv == '+' || simv == '*')
		return Prioritet(simv);
	--str;
	while (!(*str >= '0' && *str <= '9') && !(*str >= 'a' && *str <= 'z'))
	{
		if (*str == simv && (*str == '-' || *str == '/'))
			return Prioritet(simv) + 1;
		--str;
	}
	return  Prioritet(simv);
}


void push(newst *t)
{
	t->_next = head;
	head = t;
}

void push(char *str, int prior)
{
	newst *t = new newst;
	strcpy_s(t->_value, str);
	t->_prioritet = prior;
	t->_next = head;
	head = t;
}

newst * pop()
{
	newst *t;
	if (head == NULL)
		return NULL;
	t = head;
	head = t->_next;
	return t;
}

std::string Transform(char* str)
{
	std::string a=InPolish(str);
	return OutPolish((char*)a.c_str());
}