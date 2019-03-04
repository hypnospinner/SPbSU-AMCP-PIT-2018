#pragma once
#include<iostream>

class Vector;


class Vector
{
public:
	Vector();							// ����������� �� ���������
	Vector(int _size);					// �����������
	Vector(int source[], int _size);	// �����������
	Vector(const Vector& source);		// ����������� �����������
	~Vector();							// ����������
	void print() const;					// ������� ������
	Vector& push_back(int val);			// ��������� ������� � ����� �������
	int pop_back();						// �������� ��������� ������� �������
	int& getElemAt(int index) const; 	// �������� ������� �� �������    
	int getSize() const;  				// �������� �������� ���� size
	static int getObjCount();			// ����������� ������ ��� ���� objCount
	friend std::ostream& operator<<(std::ostream&, const Vector&);	// ������������� �������
	friend class TestFriend;										// ������������� �����

private:
	int* data;							// ������������ ������ � ����������
	int size;							// ���������� ��������� � �������
	int capacity;						// ���������� ����� � �������
	static int objCount;				// ���-�� �������� ��������
};

class TestFriend
{
public:
	void FriendTesting(Vector& source)
	{
		source.size = 3;
	}

};
