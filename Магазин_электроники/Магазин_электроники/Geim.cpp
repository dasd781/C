#include"Geim.h"

Geim::Geim(int disk, int transxlukator) : audio(disk), Video(_sound)
{
}
void Geim::Show()
{
	cout << "������������� ����������" << "����" << _disk << endl;
}
