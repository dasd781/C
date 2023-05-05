#include<iostream>
#include"TrieNode.h"

// ���������� ����� ���� � ������� ������
TrieNode* getNewNode(void)
{
    // �������� ������ ��� ����� ����
    struct TrieNode* pNode = new TrieNode;

    // ������������� ���� ����� ����� � false
    pNode->isEndOfWord = false;

    // �������������� ����� ������� ����������
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}
// ���������� true ���� ���� ���� � ������, ����� false
bool search(struct TrieNode* root, string key)
{
    TrieNode* node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}
// ���������� true ���� root ����� ����, ����� false
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}
// ����������� ������� �������� ����� �� ������
TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
    // ���� ������ ������
    if (!root)
        return nullptr;
    // ���� ����� �� ����� �����
    if (depth == key.size()) {
        // ���� ���� ������ �� ����� �����
        // ������� ������� �����
        if (root->isEndOfWord)
            root->isEndOfWord = false;
        // ���� ���� �� �������� ���������, ������� ���
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // ���� �� ����� �� ����� ����� ��� ����������, 
    // ��� ��� ��� � ������, ���������� �������� ��� �������
    // ���������������� �������
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);
    // ���� � ����� ��� ��������� �����
    // (������ ������ ���� ��� �������� �������),
    // � �� �� ������������� ������ ������.
    if (isEmpty(root) && root->isEndOfWord == false) 
    {
        delete (root);
        root = nullptr;
    }
    // ���������� ����� ������
    return root;
}
