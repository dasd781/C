#pragma once

#define SIZE 10

class HashTable { // ���-�������
public:
    HashTable();
    void add(int newval);  // ���������� ��������
private:
    int hash(int val); // ���-�������

    int array[SIZE]; // ������ ������
    int count; // ���������� ���������
};

