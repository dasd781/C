#include"MinHeap.h"
#include"MaxHeap.h"
#include<iostream>

using namespace std;

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	//проверяем свойство для левого поддерева
	if (l < heap_size && harr[l] < harr[i])
		smallest = r;

	//проверяем свойство для правого поддерева
	if (l < heap_size && harr[r] < harr[smallest])
		smallest = r;

	//если не выполнено обмениваем с родителем
	//вызываем снова для индекса не удовлетворяющего условию
	if (smallest != i)
	{
		swap (&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}
void MaxHeap::MaxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] > harr[i])
		smallest = l;
	if (r < heap_size && harr[r] > harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MaxHeapify(smallest);
	}
}
void MaxHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		std::cout << "Overflow" << std::endl;
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;


	while (i != 0 && harr[parent(i)] < harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
	// ваш код
}
// Удаление минимального элемента (корня) из min heap
int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;

	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Сохраняем минимальное значение, и удаляем его из кучи
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;

	// Восстанавливаем свойство
	MinHeapify(0);
	return root;
}
// Удаление минимального элемента (корня) из min heap 
int MaxHeap::extractMax()
{
	// ваш код
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MaxHeapify(0);

	return root;

}
MinHeap MinHeap::buildHeap(int* arr, size_t size)
{
	MinHeap h(size);
	h.heap_size = size;
	copy(arr, arr + size, h.harr);
	for (int i = size / 2; i >= 0; i--)
	{
		h.MinHeapify(i);
	}

	return h;
}

void heapSort(int*& arr, size_t size)
{
	// Строим кучу
	MinHeap h = MinHeap::buildHeap(arr, size);
	for (size_t i = 0; i < size; i++)
	{
		// Извлекаем корень
		arr[i] = h.extractMin();
		// Восстанавливаем свойство
		h.MinHeapify(0);
	}
}