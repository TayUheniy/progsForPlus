                                                                                                                                                                                                                                                                                                                         #include "stdafx.h"
#include "MyFunctions.h"
size_t count_of_correct_elements(size_t arr[], int N, size_t a, size_t b)
{
	size_t lenght = 0;
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] <= b && arr[i] >= a)
			++lenght;
	}
	return lenght;
}
