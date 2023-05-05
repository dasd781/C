
#definvftrix[e SIZE 10

class Graph
{
public:
	Graph()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < SIZE; j++)
				matrix[i][j] = 0;
		vertexCount = 0;
	}
private:
	int matrix[SIZE][SIZE];//матрица смежности

	int vertexes[SIZE];//хранилище вершин
	int vertexCount;//количество добавленных вершин
};

//добавление вершины
void Graph::addVertex(int vnumber)
{
	vertexes[vertexCount++] = vnumber;
}
//добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
	matrix[v1][v2] = weight;
	matrix[v2][v1] = weight;
}

int main()
{
	//создаем обьект
	Graph g;
	//добавляем вершины
	g.addVertex(0)
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);

	//добавляем ребра
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 2, 8);
	g.addEdge(0, 3, 11);

	return 0;

}

/*



*/