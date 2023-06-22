#pragma once
typedef double(*FPT)(double x);
double func(double x);
bool proverka(double x0, double x1);
double solutionofuravn(FPT func, double x0, double x1, double e);
int lenght(const char* a);
long long perevod(const char* a);
char minc(char a, char b, char c);
int minc(int a, int b, int c);
long long minc(long long a, long long b, long long c);
