#pragma once
#ifdef LET13_EXPORTS
#define LET13_API __declspec(dllexport)
#else
#define  LET13_API __declspec(dllimport)
#endif