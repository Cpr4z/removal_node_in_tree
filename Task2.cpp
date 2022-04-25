#include "Tree.h"
//Удаление узла
void Tree::delNode(int number){
    Node* node=getNodeByNumber(number,root);//нашли вершину для удаления
    Node* parent=node->parent;//нашли ее родителя
    //перебросили всех детей удаляемой вершины ее родителю
    for(int i=0;i<node->childCount;i++)
    {
        parent->addChild(node->children[i]);
    }
    node->childCount=0;//указали, что у удаляемой вершины больше нет детей
    parent->delChild(node);//удалили вершину
}
void Tree::Node::delChild(Node* child){
    int foundIndex=-1;
    for(int i=0;i<childCount;i++)
        if(children[i]==child)
            foundIndex=i;
    delete children[foundIndex];
    childCount--;
    for(int i=foundIndex;i<childCount;i++)
        children[i]=children[i+1];
}