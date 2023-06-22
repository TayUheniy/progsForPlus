#pragma once
#ifdef PZ17_EXPORTS
#define PZ17_API __declspec(dllexport)
#else
#define PZ17_API __declspec(dllimport)
#endif