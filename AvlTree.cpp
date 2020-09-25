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
//��ת���������еĲ������Ǵ������������游�ڵ�
/*
                                   S
                          L                  R
                    L           R      L          R    
                    |           |      |          |
                    1           2      3          4
������������Ӧ���ϵ��ĸ����֣�������S,��ת����¸��ڵ���S����������
*/
AvlTreeNode* AvlTree::LeftRotate(AvlTreeNode* old_root)
{
	//ת����
	AvlTreeNode* new_root = old_root->right;
	AvlTreeNode* left_child = new_root->left;
	new_root->left = old_root;
	old_root->right = left_child;
	//����old_root�߶�
	old_root->Height = max(GetHeight(old_root->left), GetHeight(old_root->right)) + 1;

	//new_root->Height = max(GetHeight(new_root->left), GetHeight(new_root->right)) + 1;
	//�����¸��ڵ�
	return new_root;
}
AvlTreeNode* AvlTree::RightRotate(AvlTreeNode* old_root)
{
	//ת����
	AvlTreeNode* new_root = old_root->left;
	AvlTreeNode* right_child = new_root->right;
	new_root->right = old_root;
	old_root->left = right_child;
	//����old_root�߶�
	old_root->Height = max(GetHeight(old_root->left), GetHeight(old_root->right)) + 1;
	//new_root->Height = max(GetHeight(new_root->left), GetHeight(new_root->right)) + 1;
	//�����¸��ڵ�
	return new_root;
}
AvlTreeNode* AvlTree::LeftRightRotate(AvlTreeNode* old_root)
{
	//���������Һ��ӣ��������䱾��
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
	//�������յ�ֱַ�ӷ����½ڵ�
	if (root == NULL)
		return new_node;
	//һ����Ԫ��ֱ�ӷ���ԭ����root
	if (IsSame(&root->item, &new_node->item))
	{
		delete new_node;
		this->size--;
		return root;
	}
	//�������
	if (ToLeft(&root->item, &new_node->item))
	{
			root->left=InsertNode(root->left, new_node);
	}
	else
	{
			root->right=InsertNode(root->right, new_node);
	}
	//Ҫ�������´��룬�²���Ľڵ�һ����root�����ӽڵ��������
	//��߸����ұ�
	if (HightDiff(root) > 1)
	{
		//������������߶�root��������
		if (ToLeft(&root->left->item, &new_node->item))
			root = RightRotate(root);
		//�����߾�������������
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
	//������ת����¸��ڵ�ĸ߶�
	//���û����ת���ڲ������¸��ڵ�ĸ߶�
	root->Height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	return root;//���ظ��ڵ�
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
		//���������ڣ�����������������һֱ�����ҵ����һ�������滻
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
	//ɾ����
	//ɾ���ڵ�����������
	if (HightDiff(root) > 1)
	{
		//�Ƚ��������������߶�
		//��߸�һ��ֱ������
		if (HightDiff(root->left)>=0)
			root = RightRotate(root);
		//�ұ߸�һ���������������
		else
			root = LeftRightRotate(root);
	}
	//ɾ���ڵ�����������
	else if (HightDiff(root) < -1)
	{
		//�Ƚ��������������߶�
		//�ұ߸�һ��ֱ������
		if (HightDiff(root->right) <= 0)
			root = LeftRotate(root);
		//��߸�һ���������������
		else
			root = RightLeftRotate(root);
	}
	//������ת����¸��ڵ�ĸ߶�
	//���û����ת����ɾ������¸��ڵ�ĸ߶�
	root->Height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	return root;//���ظ��ڵ�
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
//�ⲿ�ӿ�
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
void AvlTree::InorderTraversalPrint() { InorderTraversalPrint(tree_root); }//����
void AvlTree::PostorderTraversalPrint() { PostorderTraversalPrint(tree_root); }
