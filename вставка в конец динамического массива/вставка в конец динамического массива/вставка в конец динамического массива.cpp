#include<iostream>


using namespace std;

class DynamicArray
{
public:

	DynamicArray()
	{
		allocedSize = 1;
		size = 0;
		array = new int[allocedSize];
	}
	~DynamicArray()
	{
		delete[] array;
	}
	void insert(int newval)
	{
		if (size == allocedSize)//проверка нужно ли выделить больше памяти
		{
			int* newMem = new int[allocedSize * 2];//выделили больше памяти

			for (int i = 0; i < size; i++) //скопировали старую память в новую
				newMem[i] = array[i];
			allocedSize *= 2;//зафиксировали новый размер выделенной памяти
			delete[] array;
			array = newMem;// посчитали старую память запомнили указатель на новую

		}
		array[size++] = newval;//добавили элемент в массиве
	}
	int get(int index)
	{
		return array[index];
	}
private:
	int allocedSize;//размер выделенной памяти
	int size;//колличество элементов в массиве
	int* array;
};

int main()
{
	DynamicArray darr;
	darr.insert(1);
	darr.insert(2);
	darr.insert(3);
	darr.insert(4);
	darr.insert(5);

	return 0;
}