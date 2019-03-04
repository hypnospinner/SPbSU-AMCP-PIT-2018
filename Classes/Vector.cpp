#include "Vector.h"
#include <iostream>

int Vector::objCount = 0;

Vector::Vector()
{
	objCount++;
	data = new int[1];
	capacity = 1;
	size = 0;
}

Vector::Vector(int _size)
{
	objCount++;
	if (_size < 0)
		throw "size is less than 0";
	capacity = _size;
	size = 0;
	data = new int[capacity];
}

Vector::Vector(int source[], int _size)
{
	objCount++;
	if (_size < 0)
		throw "size is less than 0";
	capacity = _size;
	size = capacity;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = source[i];
}

Vector::Vector(const Vector& source) : size(source.size), capacity(source.capacity)
{
	objCount++;
	data = new int[capacity];
	for (int i = 0; i < size; ++i)
		data[i] = source.data[i];
}

Vector::~Vector()
{
	objCount--;
	delete[] data;
}

void Vector::print() const
{
	for (int i = 0; i < size; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

Vector& Vector::push_back(int val)
{
	if (size < capacity)
	{
		data[size++] = val;
		return *this;
	}
	capacity *= 2;
	
	int* tmp = new int[capacity];
	
	for (int i = 0; i < size; ++i)
		tmp[i] = data[i];
	
	tmp[size++] = val;
	
	delete[] data;
	
	data = tmp;

	return *this;
}

int Vector::pop_back()
{
	if (size == 0)
		throw "Emty Vector";
	return data[--size];
}

int& Vector::getElemAt(int index) const
{
	if (index < 0 || index > size - 1)
		throw "out of range";
	return data[index];
}

int Vector::getSize() const
{
	return size;
}

int Vector::getObjCount()
{
	return objCount;
}
