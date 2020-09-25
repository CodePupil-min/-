//Avl��
#pragma once
#ifndef AVLTREE_H_
#define AVLTREE_H_

#include<iostream>
#include<algorithm>
using namespace std;



//����
typedef struct Item {
	int x;
}Item;
//���ڵ�
struct AvlTreeNode {
	Item item;
	int Height;
	AvlTreeNode* left;
	AvlTreeNode* right;
	AvlTreeNode(const Item *item) {
		this->item = *item;
		this->Height = 0;
		left = NULL;
		right = NULL;
	}
};

//����
class AvlTree {
private:
	int size;
	AvlTreeNode* tree_root;//���ڵ�
	AvlTreeNode* LeftRotate(AvlTreeNode*);//��������������
	AvlTreeNode* RightRotate(AvlTreeNode*);//����
	AvlTreeNode* LeftRightRotate(AvlTreeNode*);//�������
	AvlTreeNode* RightLeftRotate(AvlTreeNode*);//���Һ���
	AvlTreeNode* SeekNode(const Item*);//����Ԫ�ط��ظ�Ԫ�ؽڵ�
	AvlTreeNode* InsertNode(AvlTreeNode* root, AvlTreeNode* new_node);//����ڵ�
	AvlTreeNode* DeleteNode(AvlTreeNode* root, const Item* item);//ɾ���ڵ�
	int GetHeight(const AvlTreeNode*);//ȡ���������
	int HightDiff(AvlTreeNode*);//�������������ĸ߶Ȳ�(��-��)
	void PreorderTraversalPrint(AvlTreeNode*);//�������
	void InorderTraversalPrint(AvlTreeNode*);//����
	void PostorderTraversalPrint(AvlTreeNode*);//����
public:
	AvlTree();
	bool InsertItem(const Item*);//����Ԫ��
	bool IsExist(const Item*);//Ԫ���Ƿ����
	bool IsEmpty(const Item*);//�Ƿ����
	bool DeleteItem(const Item*);//ɾ��Ԫ��
	void PreorderTraversalPrint();//�������
	void InorderTraversalPrint();//����
	void PostorderTraversalPrint();//����
};


#endif // !AVLTREE_H_

