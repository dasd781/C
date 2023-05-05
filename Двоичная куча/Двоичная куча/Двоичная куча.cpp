#include<iostream>
#include"MaxHeap.h"
#include"MinHeap.h"

using namespace std;


int main()
{
	int n, inp;
	string line;
	MaxHeap h(20);
	cout << "n: "; cin >> n; cout << "Add meg a listat: \n";
	for (int i = 0; i < n; i++)
	{
		cin >> inp; h.insertKey(inp);
	}

	cout << "remMax | insert: "; cin >> line;
	if (!line.compare("remMax"))
		h.extractMax();
	if (!line.compare("insert"))
	{
		cout << "Ird be a szamot: "; cin >> inp;
		h.insertKey(inp);
	}

	std::cout << h;
	return 0;
}