/*
Поместить узел u (корень дерева), с которого начинается поиск, в изначально пустую очередь.
Извлечь из начала очереди узел u:
Если узел u является искомым узлом (то есть ключи совпадают), то узел найден.
В противном случае в конец очереди добавляются дочерние узлы узла u, которые еще не находятся в очереди.
Если очередь пуста, то все узлы дерева были просмотрены, следовательно, такого узла в дереве нет.
Вернуться к пункту 2.

*/

const Node* AVL::bfs(const int& key) const
{
    if (_root == nullptr)
        return nullptr;
    // Создаем пустую очередь для добавления узлов с одинакового уровня -
    // имеющие одинаковую высоту
    std::queue<Node*> q;
    // кладем корень в очередь
    q.push(_root);
    while (q.empty() == false)
    {
        Node* node = q.front();
        q.pop();

        if (node->key == key)
            return node;

        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
}
// вставка нового узла в дерево
void AVL::insert(int&& key)
{
    Node* node = new Node(key);
    _root = insert(_root, node);
}

Node* AVL::insert(Node* root, Node* const node)
{
    if (!root)
        return node;

    if (node->key < root->key)
        root->left = insert(root->left, node);
    else
        root->right = insert(root->right, node);

    return balance(root);
}
//Поиск ближайшей вершины может быть выполнен по краю поддерева, 
//что сокращает сложность до O(log(N)).
Node* AVL::removemin(Node* node)
{
    if (!node->left)
        return node->right;

    node->left = removemin(node->left);

    return balance(node);
}

// поиск узла с минимальным ключом в дереве
// всегда будет в левом поддереве, из-за условия построения bst
Node* AVL::findmin(Node* node)
{
    return node->left ? findmin(node->left) : node;
}

void AVL::delete_node(const int& key)
{
    _root = delete_node(_root, key);
}

Node* AVL::delete_node(Node* node, const int& key)
{
    if (!node)
        return 0;

    if (key < node->key)
        node->left = delete_node(node->left, key);
    else if (key > node->key)
        node->right = delete_node(node->right, key);
    else //  k == p->key
    {
        Node* q = node->left;
        Node* r = node->right;
        delete node;

        if (!r)
            return q;

        Node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }

    return balance(node);
}
