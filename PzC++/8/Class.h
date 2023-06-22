#pragma once
template<typename T>
class Array
{
public:
	Array(int);
	Array() { std::cout << "CTOR DEFAULT \n"; }
	
	Array(const Array& );
	
	~Array();
	
	Array& operator= (const Array& );
	

	Array(Array &&ob);
	

	void push_back(T);
	

	T &operator[](int) const;



		int capacity() const;
	

		int size() const;
	
		T* begin();
		

		const T * begin() const;
	

		T* end();
	

		const T* end() const;
	
private:
	int max;
	T* mass;
	int top;
	void resize()
	{
		T* newmass = new T[2*max]{};
		for (int i = 0; i < top+1; ++i)
			newmass[i] = mass[i];
		max *= 2;
		delete[] mass;
		mass = newmass;
	}
};

template<typename T>
Array<T>::Array(int a)
{
	max = a;
	mass = new T[max]{};
	top = -1;
	std::cout << "CTOR PARAM \n";
}
template<typename T>
Array<T>::Array(const Array<T>& ob) :max(ob.max), top(ob.top)
{
	mass = new T[max]{};
	for (int i = 0; i < max; ++i)
		mass[i] = ob.mass[i];
	std::cout << "CTOR COPY \n";
}
template<typename T>
Array<T>::~Array()
{
	delete[] mass;
}
template<typename T>
Array<T>& Array<T>::operator= (const Array<T>& ob)
{
	if (this == &ob)
		return *this;
	delete[] mass;
	max = ob.max;
	mass = new T[max]{};
	for (int i = 0; i < max; ++i)
		mass[i] = ob.mass[i];
	top = ob.top;
	return *this;
}
template<typename T>
Array<T>::Array(Array<T> &&ob) :max(ob.max), top(ob.top)
{
	mass = ob.mass;
	ob.mass = nullptr;
	ob.max = 0;
	ob.top = -1;
	std::cout << "CTOR MOVE \n";
}
template<typename T>
void Array<T>::push_back(T a)
{
	++top;
	if (top >= max)
		resize();
	mass[top] = a;
}
template<typename T>
T& Array<T>::operator[](int index) const
{
	if (index >= max || index < 0)
		throw std::runtime_error("bad sizes");
	return mass[index];
}

template<typename T>
int Array<T>::capacity() const
{
	return max;
}
template<typename T>
int Array<T>::size() const
{
	return top + 1;
}
template<typename T>
T* Array<T>::begin()
{
	return &mass[0];
}

template<typename T>
const T* Array<T>::begin() const
{
	return &mass[0];
}
template<typename T>
T* Array<T>::end() 
{
	return &mass[top + 1];
}
template<typename T>
const T* Array<T>::end() const
{
	return &mass[top + 1];
}