#pragma once
#ifdef PZ12_EXPORTS
#define PZ12_API __declspec(dllexport)
#else
#define  PZ12_API __declspec(dllimport)
#endif