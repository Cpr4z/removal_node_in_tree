#include "Tree.h"
Tree::Node::Node(int _number, Node* _parent) :
    number(_number),
    parent(_parent),
    childCount(0) {

}
//
Tree::Node::~Node() {
    for (int i = 0; i < childCount; i++)
    {
        delete children[i];
    }
}
//
void Tree::Node::addChild(Node* newChild) {
    children[childCount++] = newChild;
}
//
Tree::Tree() {
    root = nullptr;
}
//
Tree::~Tree() {
    if (root != nullptr)
    {
        delete root;
    }
}
//
void Tree::setRoot(int number) {
    if (root != nullptr)
    {
        delete root;
        root = nullptr;
    }
    root = new Node(number);
}
//
void Tree::addNode(int parentNumber, int newNodeNumber)
{
    Node* parentNode = getNodeByNumber(parentNumber, root);
    Node* newNode = new Node(newNodeNumber, parentNode);
    parentNode->addChild(newNode);
}
//
Tree::Node* Tree::getNodeByNumber(int number, Node* current) {
    if (current->number == number)
        return current;
    for (int i = 0; i < current->childCount; i++)
    {
        Node* found = getNodeByNumber(number, current->children[i]);
        if (found)
            return found;
    }
    return nullptr;
}
