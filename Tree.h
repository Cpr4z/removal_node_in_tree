#pragma once
#define SIZE 10

class Tree { // ����� ������
public:
    struct Node { // ��������� ����
        Node(int _number, Node* _parent = nullptr);
        ~Node();

        int number; // ����� �������

        Node* parent; // ������������ �������
        Node* children[SIZE]; // ������ �������� ������
        int childCount; // ���������� �����

        void addChild(Node* newChild);
        void delChild(Node* child);

        void dummy(void* param);
    };
    Tree();
    ~Tree();

    void setRoot(int number);
    void addNode(int parentNumber, int newNodeNumber);

    void DelNode(int nodeNumber);
    void dummy(int nodeNumber);

    

private:
    Node* getNodeByNumber(int number, Node* current);
    Node* root;
};
