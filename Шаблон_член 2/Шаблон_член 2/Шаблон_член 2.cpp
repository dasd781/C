#include<iostream>
using namespace std;

//  Базовый шаблон класса
template <typename X> class First
{
public:
	X a;
	First(X arg)
	{
		a = arg;
	}
};
//  Производный шаблонный клас
template <typename X, typename Y> class Second :public First <X>
{
	Y b;
	void show()
	{
		cout << "a = " << this->a << endl;
		cout << "b = " << this->b << endl;
	}
	Second(X arg1, Y arg2) : First<X>(arg1)
	{
		b = arg2;
	}
};

	int main()
	{
		Second<int, char> obj(5, 'Z');
		obj.show();

		return 0;
	}