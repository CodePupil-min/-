#include"BSTree.h"

/*
关于二叉排序树的一些基本操作，包括添加、查找、判空、删除等，重点在于删除

缺点：在删除的时候直接将要删除节点的右枝嫁接在其左枝后面子树上，导致树的深度变大，
从而使在进行查找等操作时效率变慢，树的形态也不均匀。

解决方法：在删除后将树在某个合适的节点进行合理的翻转（AVLTree）。
*/
typedef struct Pair {
	TNode* parent;
	TNode* child;
}Pair;

void AddNode(TNode* new_node, TNode* root);
void DeleteNode(TNode** pNode);
Pair SeekItem(const Tree* tree, const Item* item);
bool ToLeft(const Item* new_item, const Item* old_item);
bool ToRight(const Item* new_item, const Item* old_item);
bool IsSame(const Item* new_item, const Item* old_item);

Tree* InitTree()
{
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;
	tree->size = 0;
	return tree;
}
//添加元素（外部接口）
void AddItem( Tree* tree,const Item* item)
{
	TNode* new_node = (TNode*)malloc(sizeof(TNode));
	new_node->num = 1;
	new_node->item = *item;
	new_node->left = NULL;
	new_node->right = NULL;
	tree->size++;
	if (tree->root == NULL)
		tree->root = new_node;
	else
		AddNode(new_node, tree->root);
}

//判空
bool IsEmpty(const Tree* tree)
{
	if (tree->root == NULL)
		return true;
	else
		return false;
}

//返回长度
int GetSize(const Tree* tree)
{
	return tree->size;
}

bool DeleteItem( Tree* tree, const Item* item)
{
	Pair look;
	look = SeekItem(tree, item);
	//树为空
	if (look.child == NULL)
		return false;
	//要删除的节点为根节点
	if (look.parent == NULL)
		DeleteNode(&tree->root);
	//其他情况
	else if (look.parent->left == look.child)
		DeleteNode(&(look.parent->left));
	else if (look.parent->right == look.child)
		DeleteNode(&(look.parent->right));
	tree->size--;
	return true;
}

//中序遍历
void Show(const TNode* root)
{
	if (root == NULL)return;
	Show(root->left);
	printf("%d    ", root->item.x);
	Show(root->right);
}

//某个值是否在树中
bool InTree(const Tree* tree, const Item* item)
{
	return SeekItem(tree, item).child == NULL ? false: true;
}

//往树中添加节点
void AddNode(TNode* new_node, TNode* root)
{
	if (IsSame(&new_node->item, &root->item))
	{
		free(new_node);
		root->num++;
		return;
	}
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			//left不为空时继续处理左子树
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else
	{
		printf("AddNode()发生错误");
		exit(0);
	}
}

Pair SeekItem(const Tree* tree, const Item* item)
{
	Pair look;
	look.parent = NULL;
	look.child = tree->root;
	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		//找到
		if (IsSame(item ,&(look.child->item)))
			break;
		//向左找
		if (ToLeft(item,&(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		//向右
		else if (ToRight(item ,&(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
	}
	//找到后的节点存储在look.child里
	return look;
}
//删除节点
//参数为要删除节点的父节点中指向要删除节点指针的地址
//因为要对节点指针进行操作，所以用二重指针
void DeleteNode(TNode **pNode)
{
	TNode* temp;
	//当要删除的节点没有左右子树时
	if ((*pNode)->left == NULL && (*pNode)->right == NULL)
	{
		temp = *pNode;
		*pNode = NULL;
		free(temp);
		return;
	}
	//要删除的节点没有左子树但有右子树
	if ((*pNode)->left == NULL && (*pNode)->right != NULL)
	{
		temp = *pNode;
		*pNode = (*pNode)->right;
		free(temp);
	}
	//无右有左
	else if((*pNode)->right==NULL && (*pNode)->left != NULL)
	{
		temp = *pNode;
		*pNode = (*pNode)->left;
		free(temp);
	}
	//左右都有
	else
	{
		//主要思路：先从要删除节点的左子树开始一直向右直至找到一个右孩子为空的子树，然后
		//将被删除节点的右子树嫁接到该子树空着的右枝上。
		for (temp = (*pNode)->left; temp->right != NULL; temp = temp->right);
		temp->right = (*pNode)->right;
		temp = *pNode;
		*pNode = (*pNode)->left;
		free(temp);
	}
}

//若数据类型发生变化，则修改以下函数即可

//如果不满足条件则返回false
//将要添加的项和根项比较，如果小于且还有左子树的话则继续向左遍历
bool ToLeft(const Item* new_item, const Item* old_item)
{
	if (new_item->x < old_item->x)
		return true;
	else
		return false;

}
//将要添加的项和根项比较，如果大于且还有右子树的话则继续向左遍历
bool ToRight(const Item* new_item, const Item* old_item)
{
	if (new_item->x > old_item->x)
		return true;
	else
		return false;
}
//验证是否相等
bool IsSame(const Item* new_item, const Item* old_item)
{
	if (new_item->x == old_item->x)
		return true;
	else
		return false;
}


