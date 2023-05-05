#include"graph.h"
#include<iostream>

void Graph::depth(int start)
{
	// иницилизация
	bool visited[SIZE];
	for (int i = 0; i < SIZE; i++)
		visited[i] = false;
	// вызов рекурсии
	depthInner(start, visited);

}
void Graph::depthInner(int current, bool visited[])
{
	// выводим себя
	std::cout << "v" << current << " -> ";
	// запоминаем что проходили
	visited[current] = true;
	// зайти в смежную не посещенную
	for (int i = 0; i < SIZE; i++)
	{
		int vnum = vertexes[i];
		if (are_adj(current,vnum) && !visited[vnum])
		{
			depthInner(vnum, visited);
		}
	}

}