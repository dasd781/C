#include<iostream>
using namespace std;

/*int main()
{
	int* a = (int*)2;
	cout << *a;//ошибка к обращению к памяти по недопустимому адресу
}*/

// ошибки сегментации возникают при работе с массивами
/*int main()
{
int arr[5];
	for (int i = 0; i < 6; ++i)
	{
		arr[i] = i;
	}
	return 0;
}*/
int main()
{
	int* p = (int*)malloc(8);
	*p = 10;

	free(p);

	*p = 20;// ОШИБКА: память для р уже освобождена
	return 0;
}