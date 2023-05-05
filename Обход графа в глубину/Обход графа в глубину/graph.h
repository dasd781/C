
#ifndef _GRAPH_
#define _GRAPH_

#define SIZE 10

class Graph
{
public:
	Graph();

	void addVertex(int vnumber);
	void addEdge(int v1, int v2, int weight = 1);

	void depth(int start);
	void width(int start);

private:
	void depthInner(int current, bool visited[]);
	bool are_adj(int v1, int v2);

	int matrix[SIZE][SIZE];

	int vertexes[SIZE];
	int vertexCount;

};
#endif
