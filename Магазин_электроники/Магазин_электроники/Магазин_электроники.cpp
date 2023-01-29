#include<iostream>
#include"audio.h"
#include"Geim.h"
#include"Video.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Texnic* grocery[5];

	grocery[0] = new kolonka(2,string("Хороший звук"));
	grocery[1] = new pleir(2, 1);
	grocery[2] = new Geim(1, 2);
	grocery[3] = new Camera(1,1);
	grocery[4] = new television_set(3, string("сигнал"));

	bool open = true;
	while (open)
	{
		cout << "Выберете товар : 1 - Колонка, 2 - Плеер, 3 - Приставка, 4 - Камера, 5 - Телевизор" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			grocery[0]->Show();
			break;

		case 2:
			grocery[1]->Show();
			break;

		case 3:
			grocery[2]->Show();
			break;

		case 4:
			grocery[3]->Show();
			break;

		case 5:
			grocery[4]->Show();
			break;

		case 0:
			open = false;
			break;

		default:
			cout << "Выберете технику от 1 до 5 или 0 чтобы выйте" << endl;

		}

	}
	delete grocery[0];
	delete grocery[1];
	delete grocery[2];
	delete grocery[3];
	delete grocery[4];



}
