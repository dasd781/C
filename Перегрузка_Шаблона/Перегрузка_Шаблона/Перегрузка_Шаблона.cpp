#include<iostream>
using namespace std;

//Шаблонная функция
template <typename X, typename Y> void show(X x, Y y)
{
	cout << "Первый аргумент : " << x << endl;
	cout << "Второй аргумент : " << y << endl;
}
// Изменяем прототип и тело функции 
template <typename X> void show(X x)
{
	cout << "Аргумент функции :" << endl;
}
int main()
{
	setlocale(LC_ALL, "");

	show(1, 'a');//Вызов шаблонной функции с двумя
	show(2);// Вызов шаблонной функции с одним

	return 0;

}
/*
#include <iostream>
using namespace std;

//  Обычная функция
void show(int x, int y)
{

    cout << "Это вызов обычной (нешаблонной) функции" << endl;
}

// Шаблонная функция
template <typename X, typename Y> void show(X x, Y y)
{

    cout << "Это вызов шаблонной неспециализированной функции" << endl;
}


//  Специализация шаблонной функции для типов <int, int>
template <> void show(int x, int y)
{

    cout << "Это вызов шаблонной специализированной функции" << endl;
}


int main()
{

    setlocale(LC_ALL, "");

    show(2, 5);             // вызовется обычная функция
    show<int, int>(2, 5);   // вызовется шаблонная специализированная функция
    show('a', 'b');         // вызовется шаблонная функция
    return 0;
}
*/