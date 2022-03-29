#include "Tree.h"
void Tree::DelNode(int number) {
	Node* delNode = getNodeByNumber(number, root);
	int numberOfChild = 0;
	for (size_t i = 0; i < SIZE; i++) {//определяем какую вершину удаляем 0 или 1
		if (delNode->parent->children[i]->number == number) {
			numberOfChild = i;
		}
	}

	if (delNode->childCount == 0) {//нет детей
		
		delNode->parent->childCount--;//уменьшаем количество детей у родительской варшины на одну
		delNode->parent->children[numberOfChild] = nullptr;//удаляем указатель на ребенка у родительской вершин
		delete delNode->parent->children[numberOfChild];//удаляем вершину из массива вершин
		delNode->parent = nullptr;//зануляем родителя у у даляемой вершины
		delete delNode->parent;//удаляем указатель на родительскую вершину
		delete delNode;//удаялем вершину
		

	}
	else if (delNode->childCount == 1) {//если один ребенок
		delNode->parent->children[numberOfChild] = nullptr;
		delNode->parent->children[numberOfChild] = delNode->children[0];//переназначили ребенка удаляемой вершины ребенком родительской вершины
		delNode->children[0]->parent = delNode->parent;//переопределяем родителя для ребенка удаялемой вершины
		delNode->childCount = 0;//уменьшаем количество детей у удаляемой вершины
		delete delNode->parent->children[numberOfChild];//удаляем указатель на дочернюю вершину у родителя
		delete delNode->parent;
		delete delNode;
	}
	else if ((delNode->childCount == 2) && (delNode->parent->childCount == 1)) {//если у удаляемой вершины 2 ребенка и у родительской один ребенок
		delNode->parent->childCount++;//увеличиваем количество детей на единицу
		delNode->parent->children[numberOfChild] = nullptr;
		delNode->parent->children[0] = delNode->children[0];//присваиваем левого ребенка в качестве левого ребенка у родителя
		delNode->parent->children[1] = delNode->children[1];//присваиваем правого ребенка в качестве правого ребнка у родителя 
		delNode->childCount = 0;
		delNode->children[0]->parent = delNode->parent;//присваиваем ребенку удаляемой вершины нового родителя
		delNode->children[1]->parent = delNode->parent;//присваиваем ребенку удаляемой вершины нового родителя
		delete[] delNode->children;//удаляем массив из детей у удаляемой вершины
		delete delNode->parent;//удаляем указатель на родительскую вершину у удаляемой вершины
		delete delNode;
	}
	else if ((delNode->childCount == 2) && (delNode->parent->childCount == 2)) {//если у удаляемой вершины 2 ребенка и у родительской вершины тоже 2 ребенка

		if (delNode->children[0] <= delNode->children[1]) {//если первая вершина меньше второй, то удаляем первую вершину

			delNode->parent->children[numberOfChild] = delNode->children[1];//определяем большего ребенка как второго ребенка родителя удаленной вершины
			delNode->children[1]->parent = delNode->parent;//назначаем у большей вершины родителя 
			delNode->childCount = 0;//обнуляем количество детей 
			if (delNode->children[0]->childCount != 0) {//если у удаляемой вершины есть дети, то вызываем рекурсию
				DelNode(delNode->children[0]->number);
			}
			else {
				delete delNode->children[0]->parent;//указатель на родителя первого ребенка
				delete delNode->children[1]->parent;//указатель на родителя второго ребенка
				delete delNode->parent;//удаляем указатель на родительскую вершину у удаляемой вершины 
				delete[] delNode->children;//удаляем массив 
				delete delNode->children[0];
				delete delNode->children[1];
			}
		}
		else {
			delNode->parent->children[numberOfChild] = delNode->children[0];//определяем большего ребенка как второго ребенка родителя удаленной вершины
			delNode->children[0]->parent = delNode->parent;//назначаем у большей вершины родителя 
			delNode->childCount = 0;//обнуляем количество детей 
			if (delNode->children[1]->childCount != 0) {//если у удаляемой вершины есть дети, то вызываем рекурсию
				DelNode(delNode->children[1]->number);
			}
			else {
				delete delNode->children[0]->parent;//указатель на родителя первого ребенка
				delete delNode->children[1]->parent;//указатель на родителя второго ребенка
				delete delNode->parent;//удаляем указатель на родительскую вершину у удаляемой вершины 
				delete[] delNode->children;//удаляем массив 
				delete delNode->children[0];
				delete delNode->children[1];
			}

		}
	}
}
void Tree::Node::delChild(Node* child)
{
	// Ваш код должен быть здесь
	if (child->childCount == 0) {
		return;
	}
	if (child->childCount == 1) {//если один ребенок
		DelNode(child->children[0]->number);
	}
	if (child->childCount == 2) {
		DelNode(child->children[0]->number);
		DelNode(child->children[1]->number);
	}

}