#pragma once
#ifdef PZ13_EXPORTS
#define PZ13_API __declspec(dllexport)
#else
#define  PZ13_API __declspec(dllimport)
#endif