#pragma once

//Обьявление шаблона класса Array
template <typename T> class Array
{
private:
	unsigned _size;   //Размер массива
	T* _data;    // Указатель на массив

public:
	Array(unsigned size);  // Размер массива
	virtual ~Array();   //Деструктор
	Array(Array& a);     //Конструктор копирования
	Array& operator=(Array& a);    //Оператор присваивания
	void set(int i, T val);  //Запись элемента в массив
	T get(int i);  //  Получение элемента массива
	unsigned getSize();   //Получения размера массива
};
