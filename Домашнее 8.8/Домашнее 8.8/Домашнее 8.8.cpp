#pragma once
#include "Array.h"
#include "Array.cpp"

int main() {
	COLOR_GREEN_TEXT
		/*******************************************************/
		Array<double> a(5);
	a.setSize(7, 2);
	for (size_t i = 0; i < 7; i++)
	{
		a.addElement(rand() % 10);
	}
	a.showArray();
	/*******************************************************/
	cout << "GetElement = " << a.getAt(5) << endl;
	/*******************************************************/
	a.setAt(3, 99);
	a.showArray();
	a.setAt(3, 99);
	a.setAt(1, 89);
	a.setAt(10, 59);
	a.showArray();
	/*******************************************************/
	a.addElement(rand() % 10);
	a.showArray();
	a.addElement(rand() % 10);
	a.addElement(rand() % 10);
	a.showArray();
	/*******************************************************/
	cout << "a[] = " << a[7] << endl;
	/*******************************************************/
	cout << *(a.getData() + 1) << endl;
	/*******************************************************/
	a.insertAt(2, 22);
	a.showArray();
	/*******************************************************/
	a.freeExtra();
	a.showArray();
	/*******************************************************/
	Array<double> b(1);
	b.setSize(3, 2);
	b.addElement(5);
	b.addElement(10);
	b.addElement(25);
	b.showArray();
	/*******************************************************/
	a.Append(b);
	a.addElement(1256);
	a.addElement(854);
	cout << endl;
	cout << endl;
	cout << endl;
	a.showArray();
	/*******************************************************/
	Array<double> c(10);
	c.setSize(5, 3);
	c = a;
	cout << endl;
	cout << endl;
	cout << endl;
	c.showArray();
	/*******************************************************/
	STOP
		return 0;
}