#include "Module.h"


Module& Module::operator++()
{
	++moduleSize;//�������� ������ ������
	return *this;// ���������� ������� ���������� ���� ������
}
Module& Module::operator --()
{
	--moduleSize;//�������� ������ ������
	return this; //  ���������� ������
}