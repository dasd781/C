#include<iostream>
using namespace std;

/*  Шаблонный класс
template<typename X = int> class MyClass
{
	X value;
public:
	MyClass(X m)
	{
		value = m;
	}
	void set(X m) { value = m; }
	void get()
	{
		cout << "Значение = " << value << endl;
	}
};

int main()
{
	// создание обьекта с int - полем :
	MyClass<> a(5);
	a.get();
	a.set(3);
	a.get();
	//  сщздание обьекта с char - полем :
	MyClass<char> b('X');
	b.get();
	b.set('Z');
	b.get();

	return 0;
} */

template <typename X> class MyClass
{
	X value;
public:
	MyClass(X m)
	{
		value = m;
	}
	void set(X m) { value = m; }
	void get()
	{
		cout << "Значение = " << value << endl;
	}
};
//Явная специализация шаблонного класса 
template <> class MyClass <int>
{
public:
	int value;
	MyClass()
	{
		value = 5;
	}
};
int main()
{
	setlocale(LC_ALL, "");

	// сщздание обьекта с  int - полем :
	MyClass<int>a;
	cout << "Значение = " << a.value << endl;
	a.value = 3;
	cout << "Значение = " << a.value << endl;
	//Создание обьектов с char - полем:
	MyClass<char> b('X');
	b.get();
	b.set('Z');
	b.get();

	return 0;
}