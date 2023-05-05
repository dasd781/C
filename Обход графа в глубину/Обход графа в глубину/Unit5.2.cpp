#include"graph.h"
#include<iostream>

void Graph::width(int start)
{
	//������������  ������� � ������ ����������
	int queue[SIZE];
	int queueCount = 0;

	bool visited[SIZE];
	for (int i = 0; i < SIZE; i++)
		visited[i] = false;

	queue[queueCount++] = start;

	//���� �� �������
	while (queueCount > 0)
	{
		// ������� ������� �������  ������� � ������� �� �������
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
	bool visited[SIZE]; // ������ ���������� ������
	for (int i = 0; i < SIZE; i++)
		visited[i] = false; // �������������� ��� ������������
	depthInner(start, visited); // ������ ��������� 

	std::cout << std::endl;
}

void Graph::depthInner(int current, bool visited[])
{
	std::cout << "v" << current << " -> "; // ����� �������
	visited[current] = true; // �������� ��� ����������
	for (int i = 0; i < SIZE; i++)
	{
		if (edgeExists(current, i) && !visited[i])
			depthInner(i, visited); // ���� ���������� ����� � ������� �� ����������, �� ������� �� ���� � ������� �������

	}
}

/* ��� ��������, ���������� �� �����, ����� ���������� �������� �������� ������� ��������� � ��������� ������� ������ (���� ���� �����, �� ������� �� 0).
bool edgeExists(int v1, int v2)
{
	return matrix[v1][v2] != 0;
}

/*��� ��������, ���������� �� �������, ����� ���������, ���� �� �� ����� � ������� vertexes.
bool vertexExists(int vnumber)
{
	for (int i = 0; i < vertexCount; i++)
		if (vertexes[i] == vnumber)
			return true;
	return false;
}
*/