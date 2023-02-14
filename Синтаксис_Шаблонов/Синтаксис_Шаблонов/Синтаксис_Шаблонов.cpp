#include<iostream>
using namespace std;

/*int Add(int a, int b)
{
	int sum;
	sum = a + b;
	return sum;
}
float Add(float a, float b)
{
	float sum;
	sum = a + b;
	return sum;
}*/
template <typename T>//пример синтаксиса шаблона
T Add(T a, T b)
{
	T sum;
	sum = a + b;
	return sum;
}

int main()
{
	setlocale(LC_ALL, "");
	int x = 3;
	int y = 6;
	//вызываем шаблон
	cout << " Сложение целых чисел " << x << "и" << y << " равно " << Add<int>(x, y) << endl;

	float a = 2.5;
	float b = 3.7;
	//вызываем шаблон
	cout << "Сложение вещественных чисел " << a << "и" << b << "равно" << Add<float>(a, b) << endl;
	cout << Add<string>("First ", "Second") << endl;
	return 0;
}