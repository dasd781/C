// Цикл do while очень похож на цикл while.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	while (i < 5)
	{
		cout << " Hellow world " << endl;
		i++;
	}
	int j = 0;
	{
		cout << "Enter a positiver number " << endl;
		cin >> j;
	} while (j < 0)
		cout << "You entered" << j << endl;
	return 0;

}
