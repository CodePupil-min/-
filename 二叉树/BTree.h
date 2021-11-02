#pragma once
#ifndef BTREE_H_
#define BTREE_H_

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BTree
{
public:
    //前中后遍历(迭代)
    vector<int> preorderTraversal(TreeNode* root);//前
    vector<int> inorderTraversal(TreeNode* root);//中
    vector<int> postorderTraversal(TreeNode* root);//后
    //(递归)
    vector<int> preorderRecursion(TreeNode* root);
    void preorder(TreeNode* root, vector<int>& list);
    vector<int> inorderRecursion(TreeNode* root);
    void inorder(TreeNode* root, vector<int>& list);
    vector<int> postorderRecursion(TreeNode* root);
    void postorder(TreeNode* root, vector<int>& list);
    //层序遍历(迭代)
    vector<vector<int>> levelOrder(TreeNode* root);
    //求最大深度
    int maxDepthR(TreeNode* root);//(递归)
    int maxDepthT(TreeNode* root);//(迭代)
};

#endif // !BTREE_H_