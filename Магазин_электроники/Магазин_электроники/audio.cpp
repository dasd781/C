#include"audio.h"

audio::audio(int disk) : _disk(disk)
{
}
void audio::Show()
{
	cout << "Базовая комплектация диском : " << _disk << endl;
}
kolonka::kolonka(int disk, string color) : audio( disk ), _color(color)
{
}
void kolonka::Show()
{
	cout << _color << "Поставляется с програмным диском - 1 шт." << _disk << endl;
}
pleir::pleir(int disk, int headphone) : audio(disk), _headphone(headphone)
{
}
void pleir::Show()
{
	cout << "Поставляется с наушниками :" << _headphone << "Квадратными дисками" << _disk << endl;
}
