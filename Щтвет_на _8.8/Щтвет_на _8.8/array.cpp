#include"array.h"

//Конструктор
template <typename T>Array<T>::Array(unsigned size)
{
	_size = size;
	_data = new T[_size];
}
// Деструктор
template <typename T>Array<T>::~Array()
{
	delete[] _data;
}

//  Запись элемента в массив
template <typename T> void Array<T>::set(int index, T val)
{
	if (index >= 0 && index < _size)
		_data[index] = val;
}
//Получение элемента массива
template <typename T> size_t Array<T>::getSize()
{
	return _size;
}
// Конструктор копирования
template <typename T>Array<T>::Array(Array& a)
{
	_size = a._size;  // Копируем значение поля размера массива
	_data = new T[_size]; // Выделяем память для нового массива
	for (auto i = 0; i < _size; i++)
		_data[i] = a._data[i];// Копируем элементы массива
}
 // Оператор присваивания
template <typename T> Array<T>& Array<T>::operator=(Array& a)
{
	if (this != &a)
	{
		//Проверяем чтобы не присвоить массив сам в себя this
		// указатель на текущий обьект в памяти
		_size = a._size // Копируем значение поля размера массива
			delete [] _date; //освобождаем память от старого массива
		_data = new T[_size]; // Выделяем память в куче для нового массива
		for (auto i = 0; i < _size; i++)
			_data[i] = a._data[i]; // Копируем элементы массива
	}
	return *this; // Возвращаем указатель на новый обьектЫ
}

