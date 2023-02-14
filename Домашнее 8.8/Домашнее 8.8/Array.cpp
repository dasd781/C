#pragma once
#include "Array.h"

template<class T>
Array<T>::Array(int SIZE) // CONSTRUCTOR
{
	this->grow = 1;
	this->SIZE = SIZE + grow;
	this->preSIZE = SIZE;
	this->count = 0;
	this->arr = new T[this->SIZE]();
}

template<class T>
Array<T>::Array(const Array& other) // CONSTRUCTOR COPY
{
	this->SIZE = other.SIZE;
	this->arr = new T[this->SIZE];
	for (size_t i = 0; i < this->SIZE; i++)
	{
		this->arr[i] = other.arr[i];
	}
}

template<class T>
Array<T>::~Array() // DESTRUCTOR
{
	delete[] arr;
	arr = NULL;
}

template<class T>
int Array<T>::getSize() // GET SIZE
{
	return this->SIZE;
}

template<class T>
void Array<T>::setSize(int SIZE, int grow) //SET SIZE
{
	if (grow > 0)
		this->grow = grow;
	this->SIZE = SIZE + this->grow;

	if (this->SIZE > this->preSIZE)
	{
		T* buf = new T[this->SIZE]();
		for (size_t i = 0; i < this->preSIZE; i++)
		{
			buf[i] = arr[i];
		}
		delete[] arr;
		arr = new T[this->SIZE]();
		for (size_t i = 0; i < this->SIZE; i++)
		{
			arr[i] = buf[i];
		}
		delete[] buf;
		this->preSIZE = this->SIZE;
	}
	else
	{
		T* buf = new T[this->SIZE]();
		for (size_t i = 0; i < this->SIZE - this->grow; i++)
		{
			buf[i] = arr[i];
		}
		delete[] arr;
		arr = new T[this->SIZE]();
		for (size_t i = 0; i < this->SIZE; i++)
		{
			arr[i] = buf[i];
		}
		delete[] buf;
		this->preSIZE = this->SIZE;
		this->count = this->SIZE - this->grow;
	}
}

template<class T>
void Array<T>::addElement(T element) // ADD ELEMENT
{
	if (count < this->SIZE)
	{
		this->arr[count] = element;
		count++;
	}
	else
	{
		this->SIZE = this->SIZE + this->grow + 1;
		T* buf = new T[this->SIZE]();
		for (size_t i = 0; i < this->SIZE - this->grow; i++)
		{
			buf[i] = arr[i];
		}
		delete[] arr;
		arr = new T[this->SIZE]();
		for (size_t i = 0; i < this->SIZE; i++)
		{
			arr[i] = buf[i];
		}
		delete[] buf;
		buf = NULL;
		arr[count] = element;
		count++;
	}
}

template<class T>
int Array<T>::getUpperBound() //GET UPPER BOUND
{
	return count - 1;
}

template<class T>
bool Array<T>::isEmpty() // CHECK EMPTY NO YES?
{
	if (count == 0)
		return false;
	else
		return count;
}

template<class T>
void Array<T>::freeExtra() // FREE EXTRA
{
	T* buf = new T[this->SIZE - this->grow]();
	for (size_t i = 0; i < this->SIZE - this->grow; i++)
	{
		buf[i] = arr[i];
	}
	delete[] arr;
	arr = new T[this->SIZE - this->grow]();
	for (size_t i = 0; i < this->SIZE - this->grow; i++)
	{
		arr[i] = buf[i];
	}
	this->SIZE = this->SIZE - this->grow;
}

template<class T>
void Array<T>::removeAll() // CLEAR ALL
{
	delete[] arr;
	arr = NULL;
	this->SIZE = 0;
	this->preSIZE = 0;
	this->grow = 0;
	this->count = 0;
}

template<class T>
T Array<T>::getAt(int index) // GET AT
{
	if (index <= count)
		return arr[index - 1];
	else
		return false;
}

template<class T>
void Array<T>::setAt(int index, T element) // SET AT
{
	if (index <= count)
	{
		int iteration = 0;
		bool flag = true;
		T* buf = new T[SIZE + 1]();
		for (size_t i = 0; i < SIZE; i++)
		{
			if (i != index)
			{
				buf[iteration] = arr[i];
				iteration++;
			}
			if (i == index && flag == true)
			{
				buf[iteration] = element;
				iteration++;
				buf[iteration] = arr[i];
				iteration++;
				flag = false;
			}
		}
		delete[] arr;
		arr = new T[SIZE + 1]();
		this->SIZE++;
		count++;
		for (size_t i = 0; i < this->SIZE; i++)
		{
			arr[i] = buf[i];
		}
		delete[] buf;
	}
}

template<class T>
T& Array<T>::operator[](int index) // OVERLOAD OPERATOR []
{
	if (index <= count)
		return this->arr[index];
	else
		return this->arr[count];
}

template<class T>
void Array<T>::Append(Array<T> ob) // APPEND 
{
	int temp = this->SIZE + ob.getSize();
	int iteration = 0;
	T* buf = new T[temp]();
	for (size_t i = 0; i < this->SIZE; i++)
	{
		buf[i] = arr[i];
		iteration++;
	}
	for (size_t i = 0; i < ob.SIZE; i++)
	{
		buf[iteration] = ob.arr[i];
		iteration++;
	}
	delete[] this->arr;
	this->arr = new T[temp]();
	for (size_t i = 0; i < temp; i++)
	{
		this->arr[i] = buf[i];
	}
	this->SIZE = temp;
	this->count = (this->SIZE - this->grow);
	delete[] buf;
}

template<class T>
T* Array<T>::getData() // GET POINTER ARR
{
	return arr;
}

template<class T>
void Array<T>::insertAt(int index, T element) // INSERT AT
{
	if (index <= count)
	{
		arr[index] = element;
	}
}

template<class T>
void Array<T>::showArray()
{
	for (size_t i = 0; i < this->SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& ob1) // OVERLOAD OPERATOR = 
{
	this->SIZE = ob1.SIZE;
	delete[] this->arr;
	this->arr = new T[this->SIZE];
	for (size_t i = 0; i < this->SIZE; i++)
	{
		this->arr[i] = ob1.arr[i];
	}
	return *this;
}