#pragma once


class MinHeap
{
	int *harr;//��������� �� ������ ���������
	int capacity;//������������ ������ ����
	int heap_size;// ������� ����� ��������� ����

private:
	//������� ��������� ��� ��������� �������� � ������� �� ������� ����
	int parent(int i) { return(i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return(2 * i + 2); }

public:

	void MaxHeapify(int i);
	MaxHeapify(int capacity);
	MinHeap(int capacity);
	//������������� ������� ���� ��� ��������� � ������ �� �������
	void MinHeapify(int);
	// �������� ����� �� ������
	int extractMin();
	//��������� ������������ �������� - �����
	int getMin();
	// ������� ������ �����
	void insertKey(int k);

};