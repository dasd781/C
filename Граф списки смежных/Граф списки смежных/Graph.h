#pragma once
#define SIZE 10

class Graph
{
	struct Edge //��������� �����
	{
		int vertexWhere;// � ����� ������� �����
		int weight;//��� �����
		Edge() {}
		Edge(int vw, int w) : vertexWhere(vw), weight(w) {}
	};
	struct Vertex //��������� �������
	{
		int number;//����� �������
		Edge adj_vertexe[SIZE];//����� ������� �� �������
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
