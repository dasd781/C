#pragma once

//��������� ���� ������
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, ���� ���� �������� ������ �����
	bool isEndOfWord;
};