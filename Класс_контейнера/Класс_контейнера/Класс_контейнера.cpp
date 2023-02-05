#include<iostream>
#include"IntArray.h"

int main()
{
	//Объявление массива с 10 элементами
	IntArray array(10);
	//Заполните массив цифрами от 1 до 10
	for (int i{ 0 }; i < 10; ++i)
		array[i] = i + 1;

	//Изменение размера массива до 8 элементов
	array.resize(8);
	//Вставьте цифру 20 перед элементом с индексом 5
	array.insertBefore(20, 5);
	//Удаление элемента с индексом 3
	array.remove(3);
	//Добавьте 30 и 40 в конец и начало
	array.insertAtEnd(30);
	array.insertAtBeginning(40);
	//Еще несколько тестов для обеспечения построения копий
	//назначение массивов
	//не ломает вещи
	{
		IntArray b{ array };
		b = array;
		b = b;
		array = array;
	}
	//Распечатайте все цифры
	for (int i{ 0 }; i < array.getLength(); ++i)
		std::cout << array[i] << ' ';

	std::cout << '\n';
	return 0;

}