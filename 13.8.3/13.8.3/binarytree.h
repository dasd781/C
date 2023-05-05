#ifndef __BYNARYTREE_H_
#define __BYNARYTREE_H_



#define SIZE 15

class BinaryTree {
public:
    struct Node { // ��������� ����
        Node(int d, Node* p = nullptr);
        ~Node();
        Node* parent; // ������������ ����

        Node* leftChild; // ����� ����
        Node* rightChild; // ������ ����

        int data; // ������ - ����� �����
    };

    BinaryTree();
    ~BinaryTree();

    void addInt(int newdata);

    void symmetricWalk(int output_array[]);
    void printInorder(Node* node, std::vector <int>& output);
private:

    Node* root; // �������� ����
};
#endif
