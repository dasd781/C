#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <cstddef>

// Prototype of a utility function to swap two integers 
void swap(int* x, int* y);

// A class for Min Heap 
class MaxHeap
{
    int* harr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap

private:
    // to get index of parent, left child, right child of node at index i 
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

public:
    MaxHeap(int capacity);
    ~MaxHeap();
    // Восстановление свойства кучи для поддерва с корнем по индексу 
    void MaxHeapify(int);
    // to extract the root which is the minimum element 
    int extractMax();
    // Returns the minimum key (key at root) from min heap 
    int getMax() { return harr[0]; }

    // Inserts a new key 'k' 
    void insertKey(int k);
    void buildHeap(int arr[], size_t size);
    size_t getCount();
    void printHeap();
    int* getHeap();
};

#endif // MAXHEAP_H
