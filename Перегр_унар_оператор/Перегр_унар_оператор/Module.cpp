#include "Module.h"


Module& Module::operator++()
{
	++moduleSize;//изменяем размер модуля
	return *this;// возвращаем текущий измененный выше обьект
}
Module& Module::operator --()
{
	--moduleSize;//изменили размер модуля
	return this; //  возвращаем обьект
}