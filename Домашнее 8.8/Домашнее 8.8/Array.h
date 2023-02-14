#pragma once
#include "H.h"


template<class T>
class Array
{
public:
	Array(int SIZE);
	Array(const Array& other);
	~Array();
	int getSize();
	void setSize(int SIZE, int grow = 1);
	void addElement(T element);
	int getUpperBound();
	bool isEmpty();
	void freeExtra();
	void removeAll();
	T getAt(int index);
	void setAt(int index, T element);
	T& operator[](int index);
	void Append(Array ob);
	T* getData();
	void insertAt(int index, T element);
	void showArray();
	Array& operator=(const Array& ob1);
private:
	T* arr;
	int SIZE;
	int preSIZE;
	int count;
	int grow;
};

