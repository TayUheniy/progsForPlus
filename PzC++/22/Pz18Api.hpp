#pragma once
#ifdef PZ18_EXPORTS
#define PZ18_API __declspec(dllexport)
#else
#define PZ18_API __declspec(dllimport)
#endif