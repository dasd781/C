#include"HashTable.h"

HashTable::HashTable() 
{
    count = 0;
    // ������������� -1, ����������, ��� ������ �������� ���
    for (int i = 0; i < SIZE; i++)
        array[i] = -1;
}
int HashTable::hash(int val) {
    return val;
}
void HashTable::add(int newval) {
    int hash_val = hash(newval); // ��������� ������, ���� �������
    array[hash_val] = newval; // ��������
    count++;
}