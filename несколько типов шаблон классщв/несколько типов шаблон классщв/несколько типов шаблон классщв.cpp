#include<iostream>
using namespace std;

//Шаблонный клас :
template <typename X, int n> class MyClass
{
	//Поле класса - массив
	X array[n];
public:
	// Конструктор класса :
	MyClass()
	{
		// Заполнение массива случайными значениями:
		for (int i = 0; i < n; i++)
		{
			array[i] = (X)(i * i);
		}
	}
	// Метод отображения массива
	void get()
	{
		for (int i = 0; i < n; i++)
			cout << array[i] << "";
		cout << endl;
	}
};

int main()
{
	const int n = 10; //Размер массива
	MyClass<int, n > a; // Создание обьекта
	a.get(); //Отображение массива

	return 0;
}