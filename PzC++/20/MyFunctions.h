#pragma once

class Region
{
public:
	Region()  = default;
	Region(std::string nameregion, std::string namecapital, double S, unsigned int countpeople, double moneyzp): _S(S), _countpeople(countpeople), _moneyzp(moneyzp)
	{
		_nameregion = nameregion;
		_namecapital = namecapital;
	}
	~Region() 
	{
		
	}
	Region(const Region& ob) :_S(ob._S), _countpeople(ob._countpeople), _moneyzp(ob._moneyzp)
	{
		_nameregion = ob._nameregion;
		_namecapital = ob._namecapital;
	}
	Region(Region &&ob):_S(ob._S), _countpeople(ob._countpeople), _moneyzp(ob._moneyzp)
	{
		_nameregion = ob._nameregion;
		_namecapital = ob._namecapital;
		ob._nameregion = {};
		ob._namecapital = {};
		ob._S = 0;
		ob._countpeople = 0;
		ob._moneyzp = 0;
	}
	Region& operator= (const Region& ob)
	{
		if (this == &ob)
			return *this;
		_S = ob._S;
		_countpeople = ob._countpeople; 
		_moneyzp = ob._moneyzp;
		_nameregion = ob._nameregion;
		_namecapital = ob._namecapital;
		return *this;
	}
	friend bool operator==(const Region& left, const Region& right)
	{
		return (left._countpeople==right._countpeople && left._moneyzp==right._moneyzp && left._S==right._S && left._namecapital == right._namecapital && left._nameregion == right._nameregion);
	}
	friend bool operator!=(const Region& left, const Region& right)
	{
		return !(operator==(left, right));
	}

	std::string _nameregion;
	std::string _namecapital;
	double _S;
	unsigned int _countpeople;
	double _moneyzp;

};

class SpisokRegion
{
public:
	void push_back(Region &ob)
	{
		_regions.push_back(ob);
	}
	void pop_back()
	{
		_regions.pop_back();
	}
	void remove(const Region& ob)
	{
		std::vector <Region>::iterator be = _regions.begin();
		for (size_t i = 0; i < _regions.size();++i)
		{
			if (*be == ob)
			{
				_regions.erase(be);
				return;
			}
			++be;
		}
		return;
	}
	void zamena(const Region& ob, const Region& men)
	{
		std::vector <Region>::iterator be = _regions.begin();
		for (size_t i = 0; i < _regions.size(); ++i)
		{
			if (*be == ob)
			{
				*be = men;
				return;
			}
			++be;
		}
		return;
	}
	friend bool operator==(const SpisokRegion& left, const SpisokRegion& right)
	{
		return (left._regions == right._regions);
	}
	friend bool operator!=(const SpisokRegion& left, const SpisokRegion& right)
	{
		return !(operator==(left, right));
	}
	std::vector<Region> _regions;
};
template<typename ItType, typename F>
void sor(ItType begin, ItType end, F Func)
{
	ItType min=begin;
	ItType last = end;
	advance(last, -1);
	for (ItType be = begin; be < last; ++be)
	{
		ItType f = be;
		advance(f, 1);
		min = be;
		for (ItType s = f; s < end; ++s)
		{
			if (Func(*s, *min))
				min = s;
		}
		std::iter_swap(min, be);
	}
}

template<typename ItType, typename F, typename T>
std::list<T> otbor(ItType begin, ItType end, T srav, F Func)
{
	std::list<T> resz;
	ItType be = begin;
	ItType en = end;
	while (be != en)
	{
		if (Func(*be, srav))
			resz.push_back(*be);
		++be;
	}
	return resz;
}

template<typename ItType, typename F, typename T>
std::list<T> otbork(ItType begin, ItType end, T srav, F Func, int k)
{
	std::list<T> resz;
	ItType be = begin;
	ItType en = end;
	int count = 0;
	while (be != en && count < k )
	{
		if (Func(*be, srav))
			resz.push_back(*be);
		++be;
		++count;
	}
	return resz;
}


template<typename ItType, typename F>
Region& sear(ItType begin, ItType end, F Func)
{
	Region &min=*begin;
	ItType be = begin;
	ItType en = end;
	while (be != en)
	{
		if (Func(*be, min))
			min = *be;
		++be;
	}
	return min;
}

template <typename IterType, typename T, typename F >
IterType BinarySearch(IterType begin, IterType end, T value, F pred)
{
	IterType theend = end;
	IterType last = end;
	if (begin == end)
		return end;
	advance(last, -1);
	if (*begin>value || value > *last)
		return end;
	auto count = distance(begin, end);
	while (count != 0)
	{
		count = distance(begin, end);
		IterType midle = begin;
		advance(midle, count / 2);
		if (value == *midle)
			return midle;
		if (pred(value, *midle))
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

template<typename ItType,typename T>
T sum4(ItType begin, ItType end)
{
	ItType be = begin;
	ItType en = end;
	T sum(0);
	int count = 1;
	while (be != en)
	{
		if (count % 4 == 0)
			sum += *be;
		++count;
		++be;
	}
	return sum;
}


template<typename ItType>
std::string sum4(ItType begin, ItType end)
{
	ItType be = begin;
	ItType en = end;
	std::string sum{};
	int count = 1;
	while (be != en)
	{
		if (count % 4 == 0)
			sum += *be;
		++count;
		++be;
	}
	return sum.c_str();
}

class PredArea
{
public:
	bool operator()(Region x, Region  y)
	{
		return (x._S < y._S);
	}
};
class Predcountpeop
{
public:
	bool operator()(Region x, Region  y)
	{
		return (x._countpeople < y._countpeople);
	}
};

class Predzp
{
public:
	bool operator()(Region x, Region  y)
	{
		return (x._moneyzp < y._moneyzp);
	}
};

class Prednamereg
{
public:
	bool operator()(Region x, Region  y)
	{
		return (x._nameregion < y._nameregion);
	}
};

class Predint
{
public:
	bool operator()(int x, int  y)
	{
		return (x < y);
	}
};

class Predstring
{
public:
	bool operator()(std::string x, std::string  y)
	{
		return (x < y);
	}
};

class Preddouble
{
public:
	bool operator()(double x, double y)
	{
		return (x < y);
	}
};


