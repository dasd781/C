#include"graph.h"

Graph::Graph()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = 0;
	vertexCount = 0;
}
void Graph::addVertex(int vnumber)
{
	vertexes[vertexCount++] = vnumber;
}
void Graph::addEdge(int v1, int v2, int weight)
{
	matrix[v1][v2] = weight;
	matrix[v2][v1] = weight;
}
bool Graph::are_adj(int v1, int v2)
{
	return matrix[v1][v2] = 0;
}