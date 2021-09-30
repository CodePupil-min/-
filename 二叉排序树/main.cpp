//test
#include"BSTree.h"
int main()
{
	Item it;
	Tree* tree = InitTree();
	printf("输入数据(0-exit)：");
	scanf_s("%d", &it.x);
	while (it.x !=0)
	{
		if (InTree(tree, &it))
			printf("%d已存在\n", it.x);
		else
		{
			AddItem(tree, &it);
			printf("已插入%d\n", it.x);
		}
		printf("-----------------------\n");
		printf("当前：");
		Show(tree->root);
		printf("\n-----------------------\n");
		printf("输入数据(0-exit)：");
		scanf_s("%d", &it.x);
	}
	printf("开始删除(0-exit)：");
	scanf_s("%d", &it.x);
	while (it.x != 0)
	{
		if (DeleteItem(tree, &it))
			printf("已删除%d\n", it.x);
		else
			printf("没有找到%d\n", it.x);
		printf("-----------------------\n");
		printf("当前：");
		Show(tree->root);
		printf("\n-----------------------\n");
		printf("输入数据(0-exit)：");
		scanf_s("%d", &it.x);
	}
	return 0;
}

