#pragma once
#include<iostream>
using namespace std;

class Fruit
{
public:
	Fruit(int sugar) : _sugar(sugar)
	{
	}
	void Show()
	{
		cout << "Basic Fruit sugar :" << _sugar << endl;
	}
//private:
protected:


	int _sugar;
};

