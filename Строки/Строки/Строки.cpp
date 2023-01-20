#include<iostream>
using namespace std;
//подщет количества заглавных букв  в строке
int main()
{
	setlocale(LC_ALL, "");
	char stroka[] = { "AaBbCcDdEeFfGgggg" };//строка в которой будем проводить вычесления
	int size = sizeof(stroka) / sizeof(stroka[0]); //вычесляем длинну массива
	int count = 0;

	for (int i = 0; i < size; ++i)
	{
		if (stroka[i] >= 'A' && stroka[i] <= 'Z')//проверяем является ли буква заглавной
		{
			++count;
		}
	}
	cout << "Колличество заглавных букв " << count;
	return 0;
}
