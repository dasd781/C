#include"Geim.h"

Geim::Geim(int disk, int transxlukator) : audio(disk), Video(_sound)
{
}
void Geim::Show()
{
	cout << "Комплектовано наушниками" << "Диск" << _disk << endl;
}
