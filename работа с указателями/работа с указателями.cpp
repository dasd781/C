#include <iostream>

using namespace std;

int main()
{
	int value = 10;
	int* valuePtr = &value;
	// Напечатается адрес переменной value - 0xf2f3c4(*)
	cout << &value << endl;
	// Напечается значение переменной valuePtr - 0xf2f3c4, оно равно адресу переменной value
	cout << valuePtr << endl;
	// Разыменовываем указатель valuePtr, напечатается значение которое лежит по адресу 0xf2f3c4
	// то есть значение переменной value - 10
	cout << *valuePtr << endl;
	// Печатаем значение value, тут все как обычно
	cout << value << endl;

	// При помощи разыменования перезаписываем значение находящееся по адресу 0xf2f3c4
	*valuePtr = 99;
	// Напечается значение переменной valuePtr он до сих пор указывает на адрес value - 0xf2f3c4
	cout << valuePtr << endl;
	// Напечатается адрес переменной value, он так же не изменился (0xf2f3c4)
	cout << &value << endl;
	// Разыменовываем указатель valuePtr, напечатается значение которое лежит по адресу 0xf2f3c4
	// Так как выше мы его перезаписали, напечатается 99
	cout << *valuePtr << endl;
	// Печатаем значение переменной value, оно так же перезаписалось, так как valuePtr указывает на адрес переменной value
	cout << value << endl;

	return 0;
}
