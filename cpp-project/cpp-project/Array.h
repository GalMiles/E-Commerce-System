#ifndef __ARRAY_H
#define __ARRAY_H

#include <iostream>
using namespace std;

template<class T>
class Array
{
public:
	Array(int size = 1, char delimiter = ' ');
	Array(const Array& other);
	~Array();

	const Array& operator=(const Array& other);
	const Array& operator+=(const T& newVal);

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0; i < arr.logSize; i++)
		{
			os << arr.arr[i] << arr.delimiter;
		}
		return os;
	}

private:
	int logSize;
	int phySize;
	char delimiter;
	T* arr;

};


template<class T>
Array<T>::Array(int maxSize, char delimiter) : phySize(maxSize), logSize(0), delimiter(delimiter)
{
	arr = new T[phySize];
}

template<class T>
Array<T>::Array(const Array& other) : arr(NULL)
{
	*this = other;
}

template<class T>
Array<T>::~Array()
{
	delete[]arr;
}

template<class T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != other)
	{
		delete[]arr;
		phySize = other.phySize;
		logSize = other.logSize;
		delimiter = other.delimiter;
		arr = new T[logSize];
		for (int i = 0; i < logSize; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	return *this;
}

template<class T>
const Array<T>& Array<T>::operator+=(const T& newVal)
{
	if (logSize < phySize)
	{
		arr[logSize++] = newVal;
	}
	return *this;
}
#endif
