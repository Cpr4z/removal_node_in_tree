#include "Tree.h"
void Tree::DelNode(int number) {
	Node* delNode = getNodeByNumber(number, root);
	int numberOfChild = 0;
	for (size_t i = 0; i < SIZE; i++) {//���������� ����� ������� ������� 0 ��� 1
		if (delNode->parent->children[i]->number == number) {
			numberOfChild = i;
		}
	}

	if (delNode->childCount == 0) {//��� �����
		
		delNode->parent->childCount--;//��������� ���������� ����� � ������������ ������� �� ����
		delNode->parent->children[numberOfChild] = nullptr;//������� ��������� �� ������� � ������������ ������
		delete delNode->parent->children[numberOfChild];//������� ������� �� ������� ������
		delNode->parent = nullptr;//�������� �������� � � �������� �������
		delete delNode->parent;//������� ��������� �� ������������ �������
		delete delNode;//������� �������
		

	}
	else if (delNode->childCount == 1) {//���� ���� �������
		delNode->parent->children[numberOfChild] = nullptr;
		delNode->parent->children[numberOfChild] = delNode->children[0];//������������� ������� ��������� ������� �������� ������������ �������
		delNode->children[0]->parent = delNode->parent;//�������������� �������� ��� ������� ��������� �������
		delNode->childCount = 0;//��������� ���������� ����� � ��������� �������
		delete delNode->parent->children[numberOfChild];//������� ��������� �� �������� ������� � ��������
		delete delNode->parent;
		delete delNode;
	}
	else if ((delNode->childCount == 2) && (delNode->parent->childCount == 1)) {//���� � ��������� ������� 2 ������� � � ������������ ���� �������
		delNode->parent->childCount++;//����������� ���������� ����� �� �������
		delNode->parent->children[numberOfChild] = nullptr;
		delNode->parent->children[0] = delNode->children[0];//����������� ������ ������� � �������� ������ ������� � ��������
		delNode->parent->children[1] = delNode->children[1];//����������� ������� ������� � �������� ������� ������ � �������� 
		delNode->childCount = 0;
		delNode->children[0]->parent = delNode->parent;//����������� ������� ��������� ������� ������ ��������
		delNode->children[1]->parent = delNode->parent;//����������� ������� ��������� ������� ������ ��������
		delete[] delNode->children;//������� ������ �� ����� � ��������� �������
		delete delNode->parent;//������� ��������� �� ������������ ������� � ��������� �������
		delete delNode;
	}
	else if ((delNode->childCount == 2) && (delNode->parent->childCount == 2)) {//���� � ��������� ������� 2 ������� � � ������������ ������� ���� 2 �������

		if (delNode->children[0] <= delNode->children[1]) {//���� ������ ������� ������ ������, �� ������� ������ �������

			delNode->parent->children[numberOfChild] = delNode->children[1];//���������� �������� ������� ��� ������� ������� �������� ��������� �������
			delNode->children[1]->parent = delNode->parent;//��������� � ������� ������� �������� 
			delNode->childCount = 0;//�������� ���������� ����� 
			if (delNode->children[0]->childCount != 0) {//���� � ��������� ������� ���� ����, �� �������� ��������
				DelNode(delNode->children[0]->number);
			}
			else {
				delete delNode->children[0]->parent;//��������� �� �������� ������� �������
				delete delNode->children[1]->parent;//��������� �� �������� ������� �������
				delete delNode->parent;//������� ��������� �� ������������ ������� � ��������� ������� 
				delete[] delNode->children;//������� ������ 
				delete delNode->children[0];
				delete delNode->children[1];
			}
		}
		else {
			delNode->parent->children[numberOfChild] = delNode->children[0];//���������� �������� ������� ��� ������� ������� �������� ��������� �������
			delNode->children[0]->parent = delNode->parent;//��������� � ������� ������� �������� 
			delNode->childCount = 0;//�������� ���������� ����� 
			if (delNode->children[1]->childCount != 0) {//���� � ��������� ������� ���� ����, �� �������� ��������
				DelNode(delNode->children[1]->number);
			}
			else {
				delete delNode->children[0]->parent;//��������� �� �������� ������� �������
				delete delNode->children[1]->parent;//��������� �� �������� ������� �������
				delete delNode->parent;//������� ��������� �� ������������ ������� � ��������� ������� 
				delete[] delNode->children;//������� ������ 
				delete delNode->children[0];
				delete delNode->children[1];
			}

		}
	}
}
void Tree::Node::delChild(Node* child)
{
	// ��� ��� ������ ���� �����
	if (child->childCount == 0) {
		return;
	}
	if (child->childCount == 1) {//���� ���� �������
		DelNode(child->children[0]->number);
	}
	if (child->childCount == 2) {
		DelNode(child->children[0]->number);
		DelNode(child->children[1]->number);
	}

}