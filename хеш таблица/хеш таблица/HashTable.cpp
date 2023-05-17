#include"HashTable.h"

HashTable::HashTable() 
{
    count = 0;
    // инициализация -1, означающая, что такого элемента нет
    for (int i = 0; i < SIZE; i++)
        array[i] = -1;
}
int HashTable::hash(int val) {
    return val;
}
void HashTable::add(int newval) {
    int hash_val = hash(newval); // вычислили индекс, куда положим
    array[hash_val] = newval; // положили
    count++;
}