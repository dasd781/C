#include<iostream>
using namespace std;

//Шаблонный класс
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
		cout << " Значение = " << value << endl;
	}

};
int main()
{
	setlocale(LC_ALL, "");

	//Сщздание обьекта int - полем
	MyClass<int> a(5);
	a.get();
	a.set(3);
	a.get();
	//Создание обьекта с char-полем
	MyClass<char> b('X');
	b.get();
	b.set('Z');
	b.get();

	return 0;

}