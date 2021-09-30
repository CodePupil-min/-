//二叉排序树(binary sort tree)
#pragma once
#ifndef BSTREE_H_
#define BSTREE_H_
#include<stdio.h>
#include<stdlib.h>

typedef struct Item {
	int x;
}Item;

typedef struct Node {
	int num;//树中相同节点的个数
	Item item;//data
	Node* left;
	Node* right;
}TNode;

typedef struct Tree {
	TNode* root;
	int size;
}Tree;

Tree* InitTree();
void AddItem(Tree* tree, const Item* item);//添加
bool IsEmpty(const Tree* tree);//判空
int GetSize(const Tree* tree);//获取节点个数
bool DeleteItem(Tree* tree, const Item* item);//删除
void Show(const TNode* root);//打印
bool InTree(const Tree* tree, const Item* item);//判断是否存在

#endif BSTREE_H_
