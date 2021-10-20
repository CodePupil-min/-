#pragma once
#ifndef TRIE_H_
#define TRIE_H_
#include<iostream>
using namespace std;
struct TrieNode
{
    bool is_end;//是否结尾
    TrieNode* next[26] = { nullptr };//26个字母
    TrieNode() {
        is_end = false;
    }
};
class WordDictionary {

public:
    WordDictionary() {
        this->root = new TrieNode();
    }
    void addWord(string word);//添加单词
    bool search(string word);//查找
    void remove(string word);//删除
private:
    bool isWord(string word);//是否合法
    bool find(int pos, string& word, TrieNode* node);//具体查找函数
    TrieNode* root;
};

#endif // !TRIE_H_
