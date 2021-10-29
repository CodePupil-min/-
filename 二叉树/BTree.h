#pragma once
#ifndef BTREE_H_
#define BTREE_H_

//二叉树的递归和非递归两种遍历方式
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
class BTree
{
public:
    //栈，遍历
    vector<int> preorderTraversal(TreeNode* root);//前
    vector<int> inorderTraversal(TreeNode* root);//中
    vector<int> postorderTraversal(TreeNode* root);//后
    //递归
    vector<int> preorderRecursion(TreeNode* root);
    vector<int> inorderRecursion(TreeNode* root);
    vector<int> postorderRecursion(TreeNode* root);
private:
    void preorder(TreeNode* root,vector<int>&list);
    void inorder(TreeNode* root, vector<int>& list);
    void postorder(TreeNode* root, vector<int>& list);
};

#endif // !BTREE_H_



