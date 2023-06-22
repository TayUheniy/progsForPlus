#pragma once
#ifdef LET16_EXPORTS
#define LET16_API __declspec(dllexport)
#else
#define LET16_API __declspec(dllimport)
#endif