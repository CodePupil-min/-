#include"AvlTree.h"

bool IsSame(const Item* old_item, const Item* new_item)
{
	if (old_item == NULL || new_item == NULL)
		return false;
	if (new_item->x == old_item->x)
		return true;
	else
		return false;
}
bool ToLeft(const Item* old_item, const Item* new_item)
{
	if (old_item == NULL || new_item == NULL)
		return false;
	if (new_item->x < old_item->x)
		return true;
	else
		return false;
}
bool ToRight(const Item* old_item, const Item* new_item)
{
	if (old_item == NULL || new_item == NULL)
		return false;
	if (new_item->x > old_item->x)
		return true;
	else
		return false;
}

AvlTree::AvlTree()
{
	this->tree_root = NULL;
	this->size = 0;
}

int AvlTree::GetHeight(const AvlTreeNode* node)
{
	return node != NULL ? node->Height : -1;
}
int AvlTree::HightDiff(AvlTreeNode* root)
{
	return GetHeight(root->left) - GetHeight(root->right);
}
//旋转操作中所有的参数都是待插入子树的祖父节点
/*
                                   S
                          L                  R
                    L           R      L          R    
                    |           |      |          |
                    1           2      3          4
四种情况分别对应以上的四个数字，参数是S,旋转后的新根节点是S的左右子树
*/
AvlTreeNode* AvlTree::LeftRotate(AvlTreeNode* old_root)
{
	//转过来
	AvlTreeNode* new_root = old_root->right;
	AvlTreeNode* left_child = new_root->left;
	new_root->left = old_root;
	old_root->right = left_child;
	//更新old_root高度
	old_root->Height = max(GetHeight(old_root->left), GetHeight(old_root->right)) + 1;

	//new_root->Height = max(GetHeight(new_root->left), GetHeight(new_root->right)) + 1;
	//返回新根节点
	return new_root;
}
AvlTreeNode* AvlTree::RightRotate(AvlTreeNode* old_root)
{
	//转过来
	AvlTreeNode* new_root = old_root->left;
	AvlTreeNode* right_child = new_root->right;
	new_root->right = old_root;
	old_root->left = right_child;
	//更新old_root高度
	old_root->Height = max(GetHeight(old_root->left), GetHeight(old_root->right)) + 1;
	//new_root->Height = max(GetHeight(new_root->left), GetHeight(new_root->right)) + 1;
	//返回新根节点
	return new_root;
}
AvlTreeNode* AvlTree::LeftRightRotate(AvlTreeNode* old_root)
{
	//先左旋其右孩子，再右旋其本身
	old_root->left = LeftRotate(old_root->left);
	AvlTreeNode* new_root = RightRotate(old_root);
	return new_root;
}
AvlTreeNode* AvlTree::RightLeftRotate(AvlTreeNode* old_root)
{
	old_root->right = RightRotate(old_root->right);
	AvlTreeNode* new_root = LeftRotate(old_root);
	return new_root;
}
AvlTreeNode* AvlTree::InsertNode(AvlTreeNode* root, AvlTreeNode* new_node)
{
	//传进来空地址直接返回新节点
	if (root == NULL)
		return new_node;
	//一样的元素直接返回原来的root
	if (IsSame(&root->item, &new_node->item))
	{
		delete new_node;
		this->size--;
		return root;
	}
	//向左插入
	if (ToLeft(&root->item, &new_node->item))
	{
			root->left=InsertNode(root->left, new_node);
	}
	else
	{
			root->right=InsertNode(root->right, new_node);
	}
	//要进入以下代码，新插入的节点一定在root的孙子节点或者以下
	//左边高于右边
	if (HightDiff(root) > 1)
	{
		//如果继续向左走对root进行右旋
		if (ToLeft(&root->left->item, &new_node->item))
			root = RightRotate(root);
		//向右走就先左旋再右旋
		else 
			root = LeftRightRotate(root);
	}
	else if (HightDiff(root) < -1)
	{
		if (ToRight(&root->right->item, &new_node->item))
			root = LeftRotate(root);
		else
			root = RightLeftRotate(root);
	}
	//更新旋转后的新根节点的高度
	//如果没有旋转则在插入后更新父节点的高度
	root->Height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	return root;//返回根节点
}
AvlTreeNode* AvlTree::DeleteNode(AvlTreeNode* root,const Item* item)
{
	if (root == NULL)
		return NULL;
	if (IsSame(&root->item, item))
	{
		if (root->left == NULL)
		{
			AvlTreeNode* temp = root;
			root = root->right;
			delete temp;
			this->size--;
			return root;
		}
		//左子树存在，从右子树的左子树一直向下找到最后一个进行替换
		else
		{
			AvlTreeNode* temp = root->left;
			while (temp->right != NULL)
				temp = temp->right;
			root->item = temp->item;
			root->left = DeleteNode(root->left, &temp->item);
		}
	}
	else if (ToLeft(&root->item, item))
		root->left= DeleteNode(root->left,item);
	else if(ToRight(&root->item, item))
		root->right = DeleteNode(root->right, item);
	//删除后
	//删除节点在右子树上
	if (HightDiff(root) > 1)
	{
		//比较左子树的子树高度
		//左边高一点直接右旋
		if (HightDiff(root->left)>=0)
			root = RightRotate(root);
		//右边高一点就先左旋再右旋
		else
			root = LeftRightRotate(root);
	}
	//删除节点在左子树上
	else if (HightDiff(root) < -1)
	{
		//比较右子树的子树高度
		//右边高一点直接左旋
		if (HightDiff(root->right) <= 0)
			root = LeftRotate(root);
		//左边高一点就先右旋再左旋
		else
			root = RightLeftRotate(root);
	}
	//更新旋转后的新根节点的高度
	//如果没有旋转则在删除后更新父节点的高度
	root->Height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	return root;//返回根节点
}
AvlTreeNode* AvlTree::SeekNode(const Item* item)
{
	AvlTreeNode* temp = this->tree_root;
	if (temp == NULL)
		return NULL;
	while (temp != NULL)
	{
		if (IsSame(&temp->item, item))
			break;
		else if (ToLeft(&temp->item, item))
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}
void AvlTree::PreorderTraversalPrint(AvlTreeNode* root)
{
	if (root == NULL)return;
	cout << root->item.x << "(" << root->Height << ")\t";
	PreorderTraversalPrint(root->left);
	PreorderTraversalPrint(root->right);
}
void AvlTree::InorderTraversalPrint(AvlTreeNode* root)
{
	if (root == NULL)return;
	InorderTraversalPrint(root->left);
	cout << root->item.x << "(" << root->Height << ")\t";
	InorderTraversalPrint(root->right);
}
void AvlTree::PostorderTraversalPrint(AvlTreeNode* root)
{
	if (root == NULL)return;
	PostorderTraversalPrint(root->left);
	PostorderTraversalPrint(root->right);
	cout << root->item.x << "(" << root->Height << ")\t";
}
//外部接口
bool AvlTree::InsertItem(const Item* item)
{
	AvlTreeNode* new_node = new AvlTreeNode(item);
	this->size++;
	int x = this->size;
	this->tree_root=this->InsertNode(tree_root, new_node);
	if (x == this->size)
		return true;
	return false;
}
bool AvlTree::DeleteItem(const Item* item)
{
	int x = this->size;
	this->tree_root = DeleteNode(this->tree_root, item);
	if (x == this->size)
		return false;
	return true;
}
bool AvlTree::IsExist(const Item* item)
{
	if (SeekNode(item) != NULL)
		return true;
	else
		return false;
}
bool AvlTree::IsEmpty(const Item* item)
{
	if (tree_root == NULL)
		return true;
	return false;
}
void AvlTree::PreorderTraversalPrint(){ PreorderTraversalPrint(tree_root); }
void AvlTree::InorderTraversalPrint() { InorderTraversalPrint(tree_root); }//中序
void AvlTree::PostorderTraversalPrint() { PostorderTraversalPrint(tree_root); }
