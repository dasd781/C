#pragma once
#define SIZE 10

class Graph
{
	struct Edge //структура ребра
	{
		int vertexWhere;// в какую вершину ведет
		int weight;//вес ребра
		Edge() {}
		Edge(int vw, int w) : vertexWhere(vw), weight(w) {}
	};
	struct Vertex //структура вершины
	{
		int number;//номер вершины
		Edge adj_vertexe[SIZE];//ребра ведущие из вершины
		int edgeCount;
	};
public:
	Graph()
	{
		vertexCount = 0;
	}
private:
	Vertex vertexes[SIZE];
	int vertexCount;

};
/*
class Graph 
{ 
struct Edge { int v1; int v2; int weight;
}; 
Graph() { edgeCount = 0; }
private: 
Edge edges[SIZE * SIZE]; int edgeCount; 
};

*/
