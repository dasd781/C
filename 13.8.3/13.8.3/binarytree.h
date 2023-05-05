#ifndef __BYNARYTREE_H_
#define __BYNARYTREE_H_



#define SIZE 15

class BinaryTree {
public:
    struct Node { // структура узла
        Node(int d, Node* p = nullptr);
        ~Node();
        Node* parent; // родительский узел

        Node* leftChild; // левый узел
        Node* rightChild; // правый узел

        int data; // данные - целое число
    };

    BinaryTree();
    ~BinaryTree();

    void addInt(int newdata);

    void symmetricWalk(int output_array[]);
    void printInorder(Node* node, std::vector <int>& output);
private:

    Node* root; // корневой узел
};
#endif
