//Avl树
#pragma once
#ifndef AVLTREE_H_
#define AVLTREE_H_

#include<iostream>
#include<algorithm>
using namespace std;



//数据
typedef struct Item {
	int x;
}Item;
//树节点
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

//主体
class AvlTree {
private:
	int size;
	AvlTreeNode* tree_root;//根节点
	AvlTreeNode* LeftRotate(AvlTreeNode*);//左旋返回新树根
	AvlTreeNode* RightRotate(AvlTreeNode*);//右旋
	AvlTreeNode* LeftRightRotate(AvlTreeNode*);//先左后右
	AvlTreeNode* RightLeftRotate(AvlTreeNode*);//先右后左
	AvlTreeNode* SeekNode(const Item*);//查找元素返回该元素节点
	AvlTreeNode* InsertNode(AvlTreeNode* root, AvlTreeNode* new_node);//插入节点
	AvlTreeNode* DeleteNode(AvlTreeNode* root, const Item* item);//删除节点
	int GetHeight(const AvlTreeNode*);//取得树的深度
	int HightDiff(AvlTreeNode*);//返回左右子树的高度差(左-右)
	void PreorderTraversalPrint(AvlTreeNode*);//先序遍历
	void InorderTraversalPrint(AvlTreeNode*);//中序
	void PostorderTraversalPrint(AvlTreeNode*);//后序
public:
	AvlTree();
	int GetSize();
	bool InsertItem(const Item*);//插入元素
	bool IsExist(const Item*);//元素是否存在
	bool IsEmpty();//是否空树
	bool DeleteItem(const Item*);//删除元素
	void PreorderTraversalPrint();//先序遍历
	void InorderTraversalPrint();//中序
	void PostorderTraversalPrint();//后序
};


#endif // !AVLTREE_H_

