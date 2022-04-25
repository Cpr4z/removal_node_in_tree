#include "Tree.h"

void Tree::DelNode(int number) {
	Node* delNode = getNodeByNumber(number, root);
	int numberOfChild = 0;
	int prevCount = delNode->childCount;
	for (int i = 0; i < SIZE; i++) {//определяем номер индекса удаляемой вершины
		if (delNode->parent->children[i]->number == number) {
			numberOfChild = i;
		}
	}
	delNode->parent->children[numberOfChild] = nullptr;
	delNode->delChild(delNode);

	delNode->parent->childCount--;//уменьшаем колчиство детей у родителя на еденицу
	for (size_t i = 0; i < delNode->childCount; i++)
	{
		while (delNode->parent->childCount + i <= SIZE) {
			delNode->parent->children[delNode->parent->childCount + i] = delNode->children[i];
			delNode->parent->children[delNode->parent->childCount + i]->parent = delNode->parent;
		}
	}
	
	for (int i = SIZE - prevCount; i < delNode->childCount; i++)
	{
		delete delNode->children[i]->parent;
		delete delNode->children[i];

	}
	delete delNode->parent;
	delete delNode;
}

void Tree::Node::delChild(Node* child)
{
	// Ваш код должен быть здесь
	int numberOfChild = 0;
	for (int i = 0; i < SIZE; i++) {//определяем номер индекса удаляемой вершины
		if (child->parent->children[i]->number == number) {
			numberOfChild = i;
		}
	}
	for (size_t i = numberOfChild; i < child->childCount - 1; i++)//сдвигаем элементы влево на один начиная от удаляемого 
	{
		child->parent->children[i] = child->parent->children[i + 1];
	}
}