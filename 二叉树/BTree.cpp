#include "BTree.h"

//前中后遍历
//循环
//前序 中->左->右
vector<int> BTree::preorderTraversal(TreeNode* root)
{
	vector<int>list;
	stack<TreeNode*>st;
	if (root == nullptr)return list;
	st.push(root);
	while (!st.empty())
	{
		root = st.top();
		st.pop();
		list.push_back(root->val);//中
		if (root->right != nullptr)st.push(root->right);//右树先入栈
		if (root->left != nullptr)st.push(root->left);//左
	}
	return list;
}
//中序 左->中->右
vector<int> BTree::inorderTraversal(TreeNode* root)
{
	vector<int>list;
	stack<TreeNode*>st;
	while (root != nullptr || !st.empty())
	{
		if (root != nullptr)
		{
			//左边先全入栈
			st.push(root);
			root = root->left;
		}
		else
		{
			//再读中间和右边
			root = st.top();
			st.pop();
			list.push_back(root->val);
			root = root->right;
		}
	}
	return list;
}
//后序 左->右->中
//中->右->左  逆序  左->右->中 
vector<int> BTree::postorderTraversal(TreeNode* root)
{
	vector<int>list;
	stack<TreeNode*>st;
	if (root == nullptr)return list;
	st.push(root);
	while (!st.empty())
	{
		root = st.top();
		st.pop();
		list.push_back(root->val);
		if (root->left != nullptr)st.push(root->left);
		if (root->right != nullptr)st.push(root->right);
	}
	reverse(list.begin(), list.end());
	return list;
}

//递归
vector<int> BTree::preorderRecursion(TreeNode* root)
{
	vector<int>list;
	preorder(root, list);
	return list;
}
vector<int> BTree::inorderRecursion(TreeNode* root)
{
	vector<int>list;
	inorder(root, list);
	return list;
}
vector<int> BTree::postorderRecursion(TreeNode* root)
{
	vector<int>list;
	postorder(root, list);
	return list;
}

void BTree::preorder(TreeNode* root, vector<int>& list)
{
	if (root == nullptr)return;
	list.push_back(root->val);
	preorder(root->left,list);
	preorder(root->right,list);
}
void BTree::inorder(TreeNode* root, vector<int>& list)
{
	if (root == nullptr)return;
	inorder(root->left, list);
	list.push_back(root->val);
	inorder(root->right, list);
}
void BTree::postorder(TreeNode* root, vector<int>& list)
{
	if (root == nullptr)return;
	postorder(root->left, list);
	postorder(root->right, list);
	list.push_back(root->val);
}
//层序遍历
//用队列实现
vector<vector<int>> BTree::levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	vector<vector<int>>list;
	if (root == nullptr) return list;
	q.push(root);
	while (!q.empty()) {
		int len = q.size();
		vector<int>v;
		TreeNode* node;
		for (int i = 0; i < len; i++) {
			node = q.front();
			v.push_back(node->val);
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
			q.pop();
		}
		list.push_back(v);
	}
	return list;
}

//求最大深度
//递归
int BTree::maxDepthR(TreeNode* root) 
{
	if (root == nullptr)return 0;
	int l = maxDepthR(root->left);
	int r = maxDepthR(root->right);
	return l > r ? l + 1 : r + 1;
}
//迭代（层序遍历）
int BTree::maxDepthT(TreeNode* root)
{
	queue<TreeNode*> q;
	if (root == nullptr) return 0;
	int res = 0;
	q.push(root);
	while (!q.empty()) {
		int len = q.size();
		res += 1;
		TreeNode* node;
		for (int i = 0; i < len; i++) {
			node = q.front();
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
			q.pop();
		}
	}
	return res;
}
