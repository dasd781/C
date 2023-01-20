#include<iostream>
using namespace std;

int main()

{
	// обявляем переменную value равную 88
	int value = 88;
	//обьявляем ссылку на value или псевдоним
	//value  и valueRef будут хранить одинаковые значения
	int& valueRef = value;

	//Напечатаются 88
	cout << value << endl;
	//  Также напечатается 88 так как valueRef является ссылкой на value
	cout << valueRef << endl;

	// изменяем значение valueRef
	valueRef = 99;
	// напечатается 99
	cout << valueRef << endl;
	// Также напечатается 99. значение value изменится когда мы поменяем velueRef
	cout << value << endl;

	// Изменяем значение value
	value = 55;
	// напечатается 55
	cout << value << endl;
	//Также напечатается 55 значение valueRef изменится когда поменяем value
	cout << valueRef << endl;
	return 0;
}
