#pragma once

//Структура узла дерева
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, если ключ является концом слова
	bool isEndOfWord;
};