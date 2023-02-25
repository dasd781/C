#include "mstring.h"
#include<iostream>
using namespace std;

void swap(mstring& str1, mstring& str2)
{
	mstring temp = str1;//  создаем копию обьекта а
	str1 = str2;
	str2 = temp;
}

int main()

	{
		mstring string1("string1");
		mstring string2("string2");
		swap(string1, string2);

		return 0;
	


	/*	void move_swap(mstring & a, mstring & b)  Перепишем реализацию функции swap, так, чтобы применялись конструкторы перемещения:
		{
			mstring temp = move(a);
			a = move(b);
			b = move(temp);
		} */

		+