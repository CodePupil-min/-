#include"AvlTree.h"
int main() {
	AvlTree* tree = new AvlTree();
	int cmd; Item it;
	do {
		cout << "---------\n"<<"0-exit" << endl;
		cout << "1-添加元素" << endl;
		cout << "2-删除元素" << endl;
		cout << "3-先序遍历" << endl;
		cout << "4-中序遍历" << endl;
		cout << "5-后序遍历" << endl;
		cout << "6-是否空树" << endl;
		cout << "7-节点个数" << endl;
		cout << "括号里的数表示深度，最大值为树根" << endl;
		cout << "cmd：";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cout << "add(input 0 to exit)" << endl;
			cin >> it.x;
			while (it.x != 0)
			{
				if (tree->InsertItem(&it))
					cout << "已插入" << it.x << endl;
				else
					cout << "已存在" << endl;
				cin >> it.x;
			}
			break;
		case 2:
			cout << "remove(input 0 to exit)" << endl;
			cin >> it.x;
			while (it.x != 0) {
				if (tree->DeleteItem(&it))
					cout << "已删除" << it.x << endl;
				else
					cout << "不存在" << endl;
				cin >> it.x;
			}
			break;
		case 3:
			cout << "Preorder Traversal Print" << endl;
			tree->PreorderTraversalPrint();
			cout << endl;
			break;
		case 4:
			cout << "Inorder Traversal Print" << endl;
			tree->InorderTraversalPrint();
			cout << endl;
			break;
		case 5:
			cout << "Postorder Traversal Print" << endl;
			tree->PostorderTraversalPrint();
			cout << endl;
			break;
		case 6:
			tree->IsEmpty() == 1 ? cout << "空\n" : cout << "非空\n";
			break;
		case 7:
			cout << tree->GetSize() << endl;
			break;
		default:
			break;
		}
	} while (cmd != 0);

	return 0;
}



