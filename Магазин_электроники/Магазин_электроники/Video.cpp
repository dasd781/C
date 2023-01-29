#include"Video.h"

Video::Video(int sound) : _sound(sound)
{
}
void Video::Show()
{
	cout << "������ ���� :" << _sound << endl;
}
Camera::Camera(int sound, int focus) : Video(sound), _focus(focus)
{
}
void Camera::Show()
{
	cout << "����������� �����" << _focus << "������� �����" << _sound << endl;
}
television_set::television_set(int sound, string wifi) : Video(sound), _wifi(wifi)
{
}
void television_set::Show()
{
	cout << "�������� �����" << _sound << "�������� wifi" << _wifi << endl;
}