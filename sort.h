/*插入排序法*（稳定）************/
/*希尔排序法*（不稳定）************/
/*选择排序法*（不稳定）************/
/*归并排序法*（稳定）************/
/*冒泡排序法*（稳定）************/
/*快速排序法*（不稳定）**********/
#ifndef _SORT_
#define _SORT_

#pragma once
 class  sort
{
public:
	//Data存数组a地址，SIZE存长度
	sort(int* a, int size);
	void print();
	//接口
	void insert_sort(); //插入排序
	void shell_sort();//希尔排序
	void select_sort();//选择排序
	void bubble_sort();//冒泡排序
	void merge_sort();//归并排序
	void quick_sort();//快速排序
private:
	int* DATA;
	int SIZE;
	void merge(int left, int center, int right);//两个有序表的合并(在归并排序中用)
	//具体函数
	void Quick_sort( int left, int right);//快速排序具体实现
	void Merge_sort( int left, int right);//归并排序具体实现
};
#endif // !_SORT_

