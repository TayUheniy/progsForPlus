#pragma once
#include "Pz13Api.hpp"
using namespace std;
template<typename T>
class Set
{
public:
	Set() = default;
	Set(int capacity);
	Set(const Set&);
	~Set();
	Set& operator= (const Set&);
	bool push_back(T a);
	void remove();
	Set operator+ (const Set&);
	Set operator* (const Set&);
	Set operator- (const Set&);
	friend std::ostream& operator <<(std::ostream &stream, const Set& ob)
	{
		stream << "capacity: " << ob._capacity << endl;
		stream << "size: " << ob._size << endl;
		stream << "members: " << endl;
		for (int i = 0; i < ob._size; ++i)
			stream << ob._ptr[i] << ' ';
		return stream;
	}
	template<typename F>
	T& searchmax( F Fun);
private:
	T* _ptr;
	int _capacity;
	int _size;
};

class Rings
{
public:
	PZ13_API Rings() = default;
	PZ13_API Rings(double r, double R); 
	PZ13_API Rings(const Rings& ob):_r(ob._r),  _R(ob._R), _S(ob._S){}
	PZ13_API ~Rings() {};
	PZ13_API Rings& operator= (const Rings&);
	PZ13_API friend bool operator==(const Rings& left, const Rings& right) 
	{
		if ((left._R != right._R) || (left._r != right._r))
			return false;
		return true;
	}
	PZ13_API friend bool operator!=(const Rings& left, const Rings& right)
	{
		return  !(operator==(left, right));
	}
	PZ13_API double Area() ;
	PZ13_API friend std::ostream& operator <<(std::ostream &stream, const Rings& ob)
	{
		stream << "small radius: " << ob._r << endl;
		stream << "big radius: " << ob._R << endl;
		stream << "area: " << ob._S << endl;
		return stream;
	}
private:
	double _r;
	double _R;
	double _S;
};



class Preditionint
{
public:
	bool operator()(int x,int  y);
};

class Preditiondouble
{
public:
	bool operator()(double x, double  y);
};

class Preditionrings
{
public:
	bool operator()(Rings x, Rings y);
};

template<typename T> 
template<typename F>T &Set<T>::searchmax(F Fun)
{
	auto &max = _ptr[0];
	for (int i = 0; i < _size; ++i)
		if (Fun(_ptr[i], max))
			max = _ptr[i];
	return max;
}

template<typename T>
Set<T>::Set(int capacity)
{
	_capacity = capacity;
	_ptr = new T[_capacity];
	_size=0;
}

template<typename T>
Set<T>::Set(const Set<T>& ob) :_size(ob._size), _capacity(ob._capacity)
{
	_ptr = new T[_capacity];
	for (int i = 0; i < _capacity; ++i)
		_ptr[i] = ob._ptr[i];
}

template<typename T>
Set<T>::~Set()
{
	delete[] _ptr;
}

template<typename T>
bool Set<T>::push_back(T a)
{
	for (int i = 0; i < _size; ++i)
		if (_ptr[i] == a)
			return false;
	if (_size >= _capacity)
		throw std::runtime_error("bad sizes");
	_ptr[_size] = a;
	++_size;
	return true;
}

template<typename T>
void  Set<T>::remove()
{
	if (_size == 0)
		throw std::runtime_error("bad sizes");
	--_size;
}

bool Preditionint::operator()(int x, int y)
{
		return (x > y);
}

bool Preditiondouble::operator()(double x, double y)
{
	return (x*x > y*y);
}
bool Preditionrings::operator()(Rings x, Rings y)
{
		return (x.Area() > y.Area());
}

template<typename T>
Set<T>& Set<T>::operator= (const Set<T>& ob)
{
	if (this == &ob)
		return *this;
	delete[] _ptr;
	_size=ob._size;
	_capacity=ob._capacity;
	_ptr = new T[_capacity];
	for (int i = 0; i < _capacity; ++i)
		_ptr[i] = ob._ptr[i];
	return *this;
}
template<typename T>
Set<T> Set<T>::operator+(const Set<T> &right)
{
	Set<T> New(_capacity + right._capacity);
	New._size = _size;
	for (int i = 0; i < _size;++i)
			New._ptr[i] = _ptr[i];
	for (int i = 0; i < right._size; ++i)
	{
		int count = 0;
		for (int j = 0; j < _size; ++j)
			if (right._ptr[i] == New._ptr[j])
				++count;
		if (count == 0)
			New._ptr[i + _size] = right._ptr[i];
	}
	return New;
}

template<typename T>
Set<T> Set<T>::operator*(const Set<T> &right)
{
	Set<T> New(_capacity + right._capacity);
	for (int i = 0; i < right._size; ++i)
		for (int j = 0; j < _size; ++j)
			if (right._ptr[i] == _ptr[j])
			{
				New._ptr[New._size] = right._ptr[i];
				++New._size;
			}
	return New;
}

template<typename T>
Set<T> Set<T>::operator-(const Set<T> &right)
{
	if (_capacity <= right._capacity)
		throw std::runtime_error ("bad capacity");
	if (_size <= right._size)
		throw std::runtime_error("bad size");
	Set<T> New(_capacity);
	for (int i = 0; i < _size; ++i)
	{
		int count = 0;
		for (int j = 0; j < right._size; ++j)
			if (right._ptr[j] == _ptr[i])
				++count;
		if (count == 0)
		{
			New._ptr[New._size] = _ptr[i];
			++New._size;
		}
	}
	return New;
}

