#pragma once


class MinHeap
{
	int *harr;//указатель на массив элементов
	int capacity;//максимальный размер кучи
	int heap_size;// текущее число элементов кучи

private:
	//функции помощники для получения родителя и сыновей по индексу узла
	int parent(int i) { return(i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return(2 * i + 2); }

public:

	void MaxHeapify(int i);
	MaxHeapify(int capacity);
	MinHeap(int capacity);
	//Востановление свойств кучи для поддерева с корнем по индексу
	void MinHeapify(int);
	// Удаление корня из дерева
	int extractMin();
	//Получение минимального элемента - корня
	int getMin();
	// Вставка нового ключа
	void insertKey(int k);

};