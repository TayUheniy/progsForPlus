#pragma once
template <typename IterType, typename T, typename PredType = std::less<T> >
IterType BinarySearch(IterType begin, IterType end, T value, PredType pred = PredType())
{
	IterType theend = end;
	IterType last = end;
	if (begin == end)
		return end;
	advance(last, -1);
	if (*begin>value || value > *last)
		return end;
	auto count = distance(begin, end);
	while (count!=0)
	{
		 count = distance(begin, end);
		 IterType midle = begin;
		advance(midle, count/2);
		if (value == *midle)
			return midle;
		if (pred (value,*midle) )
		{
			end = midle;
		}
		if (pred(*midle, value))
		{
			begin = midle;
			advance(begin, 1);
		}
	}
	return theend;
}

template <typename IterType, typename T, typename PredType = std::less<T> >
IterType RecursiveBinarySearch(IterType begin, IterType end, T value, PredType pred = PredType())
{
	IterType ones;
	IterType midle = begin;
	IterType last = end;
	if (begin == end)
		return end;
	advance(last, -1);
	if (*begin>value || value > *last)
		return end;
	auto count = distance(begin, end);
	advance(midle, count/2);
	if (value == *midle)
		return midle;
	if (pred(value, *midle))
		{
			ones=RecursiveBinarySearch(begin, midle, value, pred);
			if (ones == midle)
				 ones=end;
			return ones;
		}
	else
		return RecursiveBinarySearch(midle, end, value, pred);
	
	return end;
}