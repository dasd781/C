#include<iostream>
using namespace std;

struct SomeData
{
	int a; //4 байта
	unsigned int b; //4 байта
	double c; //  8 байта
};

int main(int argc, char *argv[])
{
	//буфер на стеке
	unsigned char buffer[sizeof(int) * 10];
	// placement new в буфере
	for (int i = 0; i < 10; ++i)
	{
		int* pInt = new (buffer + sizeof(int) * i) int(i);
	}
	for (int i = 0; i < 10; ++i)
	{
		int* num = (int*)(buffer + sizeof(int) * i);
		cout << *num << endl;
	}
	//выделяем память в стеке под 10 обьектов типа SomeData
	unsigned char buff[sizeof(SomeData) * 10];
	// Обнуляем память
	memset(buff, 0, sizeof(SomeData) * 10);
	//получаем указатель на начало нашего буфера и преобразуем
	//  его в указатель на тип SomeData
	SomeData* cursor = (SomeData*)buff;
	// получаем указатель на структуру лежащую через 2 структуры
	SomeData* someData2 = cursor + 2;
	return 0;
}