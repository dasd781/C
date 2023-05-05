#include<iostream>
#include"TrieNode.h"

// Возвращает новый узел с пустыми детьми
TrieNode* getNewNode(void)
{
    // Выделяем память под новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым указателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}
// Возвращает true если ключ есть в дереве, иначе false
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
// Возвращает true если root имеет лист, иначе false
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}
// Рекурсивная функция удаления ключа из дерева
TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
    // Если дерево пустое
    if (!root)
        return nullptr;
    // Если дошли до конца ключа
    if (depth == key.size()) {
        // Этот узел больше не конец слова
        // поэтому снимаем метку
        if (root->isEndOfWord)
            root->isEndOfWord = false;
        // Если ключ не является префиксом, удаляем его
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // Пока не дошли до конца ключа или определили, 
    // что его нет в дереве, рекурсивно вызываем для ребенка
    // соответствующего символа
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);
    // Если у корня нет дочернего слова
    // (удален только один его дочерний элемент),
    // и он не заканчивается другим словом.
    if (isEmpty(root) && root->isEndOfWord == false) 
    {
        delete (root);
        root = nullptr;
    }
    // возвращаем новый корень
    return root;
}
