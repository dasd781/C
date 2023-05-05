#pragma once

struct Node
{
	int key;
	Node* left;
	Node* right;
	size_t height;

	Node(int& k) { key = k; left = right = nullptr; height = 0; }
	Node(int&& k) { key = k; left = right = nullptr; height = 0; }

};