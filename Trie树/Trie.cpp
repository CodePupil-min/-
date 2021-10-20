#include"Trie.h"

void WordDictionary::addWord(string word) {
    if (!this->isWord(word))return;
    TrieNode* node = this->root;
    for (char ch : word)
    {
        if (node->next[ch - 'a'] == nullptr)
            node->next[ch - 'a'] = new TrieNode();
        node = node->next[ch - 'a'];
    }
    node->is_end = true;
}
bool WordDictionary::search(string word)
{
    return this->find(0, word, this->root);
}

void WordDictionary::remove(string word)
{
    if (!this->search(word))return;
    TrieNode* node = this->root;
    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        if (node->next[ch - 'a'] != nullptr)
            node = node->next[ch - 'a'];
    }
    node->is_end = false;
}
bool WordDictionary::isWord(string word)
{
    for (char ch : word)
        if (ch - 'a' > 25 || ch - 'a' < 0)return false;
    return true;
}
//递归查找每个字符对应情况
bool WordDictionary::find(int pos, string& word, TrieNode* node)
{
    if (pos == word.size())
        return node->is_end;
    char ch = word[pos];
    if (ch == '.')//‘.’表示可以匹配所有字符，模拟特殊情况
    {
        for (int i = 0; i < 26; i++)
            if (node->next[i] != nullptr && find(pos + 1, word, node->next[i]))
                return true;
        return false;
    }
    else
    {
        if (node->next[ch - 'a'] != nullptr)
            return find(pos + 1, word, node->next[ch - 'a']);
        return false;
    }
}