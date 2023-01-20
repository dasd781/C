#include<iostream>
using namespace std;

int main()
{
	int c;

	cout << "Выберите фрукт : 1 - яблоко, 2 - фпельсин, 3 - груша ";
	cin >> c;

	switch (c)
	{
	case 1 :
		cout << "Вы выбрали яблоко" << endl;
		break;
	case 2:
		cout << "Вы выбрали апельсин " << endl;
		break;
	case 3:
		cout <<  "Вы выбрали грушу " << endl;
		break;
	default:
		cout << "Вы не выбрали не один из перечисленных фруктов " << endl;
		break;

	}
	return 0;

}
