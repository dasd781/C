#include"graph.h"
#include<iostream>

void Graph::width(int start)
{
	//иницилизация  очереди и списка посещенных
	int queue[SIZE];
	int queueCount = 0;

	bool visited[SIZE];
	for (int i = 0; i < SIZE; i++)
		visited[i] = false;

	queue[queueCount++] = start;

	//цикл по очереди
	while (queueCount > 0)
	{
		// заберем верхний элемент  выводим и удаляем из очереди
		int currentNum = queue[0];
		queueCount--;
		for (int i = 0; i < queueCount; i++)
			queue[i] = queue[i + 1];
		std::cout << " V " << currentNum << " -> ";
		visited[currentNum] = true;
		for (int i = 0; i, vertexCount; i++) 
		{
			int vnum = vertexes[i];
			if (are_adj(currentNum, vnum) && !visited[vnum])
			{
				queue[queueCount++] = vnum;
			}

		}
	}
}

/*

void Graph::depth(int start)
{
	bool visited[SIZE]; // список посещенных вершин
	for (int i = 0; i < SIZE; i++)
		visited[i] = false; // инициализируем как непосещенные
	depthInner(start, visited); // запуск алгоритма 

	std::cout << std::endl;
}

void Graph::depthInner(int current, bool visited[])
{
	std::cout << "v" << current << " -> "; // вывод текущей
	visited[current] = true; // помечаем как посещенную
	for (int i = 0; i < SIZE; i++)
	{
		if (edgeExists(current, i) && !visited[i])
			depthInner(i, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину

	}
}

/* Для проверки, существует ли ребро, нужно посмотреть значение элемента матрицы смежности с индексами номеров вершин (если есть ребро, он отличен от 0).
bool edgeExists(int v1, int v2)
{
	return matrix[v1][v2] != 0;
}

/*Для проверки, существует ли вершина, нужно проверить, есть ли ее номер в массиве vertexes.
bool vertexExists(int vnumber)
{
	for (int i = 0; i < vertexCount; i++)
		if (vertexes[i] == vnumber)
			return true;
	return false;
}
*/