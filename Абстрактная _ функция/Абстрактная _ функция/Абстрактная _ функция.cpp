//Абстрактная функция
 /*class IFood
{
public:
	virtual void Show() = 0;
	virtual ~IFood() = default;
};
//Деструктор чистой виртуальной функции
class AbstractClass
{
public:
	virtual ~AbstractClass() = 0;
	int _data;
};
AbstractClass::~AbstractClass() = default; */

#include<iostream>
using namespace std;

class AbstractClass
{
public:
	virtual ~AbstractClass() = 0;

};