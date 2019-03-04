#pragma once
#include<iostream>

class Vector;


class Vector
{
public:
	Vector();							// конструктор по умолчанию
	Vector(int _size);					// конструктор
	Vector(int source[], int _size);	// конструктор
	Vector(const Vector& source);		// конструктор копирования
	~Vector();							// деструктор
	void print() const;					// выводим массив
	Vector& push_back(int val);			// добавляем элемент в конец массива
	int pop_back();						// получаем последний элемент массива
	int& getElemAt(int index) const; 	// получаем элемент по индексу    
	int getSize() const;  				// получаем значение поля size
	static int getObjCount();			// статический геттер для поля objCount
	friend std::ostream& operator<<(std::ostream&, const Vector&);	// дружественная фукнция
	friend class TestFriend;										// дружественный класс

private:
	int* data;							// динамический массив с элементами
	int size;							// количество элементов в массиве
	int capacity;						// количество места в массиве
	static int objCount;				// кол-во активных векторов
};

class TestFriend
{
public:
	void FriendTesting(Vector& source)
	{
		source.size = 3;
	}

};
