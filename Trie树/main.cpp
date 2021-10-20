//test
#include"Trie.h"
using namespace std;
int main() {
	WordDictionary* wd = new WordDictionary();
	int cmd;
	string word;
	do {
		cout << "---------\n" << "Enter exit to quit" << endl;
		cout << "1-添加  "<< "2-删除  " << "3-查找" << endl;
		cout << "cmd：";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cout << "输入单词：";
			cin >> word;
			while (word.compare("exit")!=0)
			{
				wd->addWord(word);
				if (wd->search(word))
					cout << "已插入" << endl;
				cout << "输入单词：";
				cin >> word;
			}
			break;
		case 2:
			cout << "输入单词：";
			cin >> word;
			while (word.compare("exit") != 0)
			{
				wd->remove(word);
				if (!wd->search(word))
					cout << "已删除" << endl;
				cout << "输入单词：";
				cin >> word;
			}
			break;
		case 3:
			cout << "输入单词：";
			cin >> word;
			while (word.compare("exit") != 0)
			{
				if (wd->search(word))
					cout << "存在" << endl;
				else
					cout << "不存在" << endl;
				cout << "输入单词：";
				cin >> word;
			}
			break;
		default:
			break;
		}
	} while (cmd != 0);

	return 0;
}
