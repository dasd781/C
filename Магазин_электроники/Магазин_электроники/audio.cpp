#include"audio.h"

audio::audio(int disk) : _disk(disk)
{
}
void audio::Show()
{
	cout << "������� ������������ ������ : " << _disk << endl;
}
kolonka::kolonka(int disk, string color) : audio( disk ), _color(color)
{
}
void kolonka::Show()
{
	cout << _color << "������������ � ���������� ������ - 1 ��." << _disk << endl;
}
pleir::pleir(int disk, int headphone) : audio(disk), _headphone(headphone)
{
}
void pleir::Show()
{
	cout << "������������ � ���������� :" << _headphone << "����������� �������" << _disk << endl;
}
