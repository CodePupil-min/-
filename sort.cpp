#include "sort.h"
#include<iostream>
#include<vector>
using namespace std;

sort::sort(int* a, int size) {
    this->DATA = a; this->SIZE = size;
}
void sort::print() {
    for (int i = 0; i < SIZE; i++)
        cout << DATA[i] << "\t";
}

//插入排序
void sort::insert_sort() {
    int j, key;//key存储每次要插入有序列的数据值
    for (int i = 1; i < SIZE; i++) {
        key = DATA[i]; 
        j = i-1;
        while (key <= DATA[j]) {
            DATA[j + 1] = DATA[j];
            j--;
            if (j < 0)break;
        }
        DATA[j + 1] = key;
    }
}

//希尔排序
void sort::shell_sort() {
    int j, key, k;//s[k]指希尔排序的增量
    int s[] = { 109,41,19,5,1 };//增量序列
    for (k = 0; s[k] >= SIZE; k++);//找到适合待排序数组的最大增量
    while (k < 5) {
        for (int i = s[k] + 1; i < SIZE; i++) {
            key = DATA[i];
            j = i - s[k];
            while (key <= DATA[j]) {
                DATA[j + s[k]] = DATA[j];
                j-=s[k];
                if (j < 0)break;
            }
            DATA[j + s[k]] = key;
        }
        k++;
    }
}

//选择排序
void sort::select_sort() {
    int i, j, k;
    int temp;
    for (i = 0; i < SIZE; i++) {
        k = i;
        for (j = i; j < SIZE; j++)
            if (DATA[k] > DATA[j])k = j;
        if (k != i) {
            temp = DATA[k];
            DATA[k] = DATA[i];
            DATA[i] = temp;
        }
    }
}

//冒泡排序
void sort::bubble_sort() {
    bool flog;
    for (int i = 0; i < SIZE; i++) {
        flog = true;
        for (int j = 0; j < SIZE - 1 - i; j++)
            if (DATA[j] > DATA[j + 1]) {
                swap(DATA[j], DATA[j + 1]);
                flog = false;
            }
        if (flog)break;//检测到有一次没进行交换则说明已经有序
    }
}

//归并排序 
void sort::merge_sort() { Merge_sort(0, SIZE - 1); }
void sort::Merge_sort(int left, int right) {
    int center = (left + right) / 2;
    if (left < right) {
        Merge_sort(left, center);
        Merge_sort(center + 1, right);
        merge(left, center, right);
    }
}
void sort::merge(int left, int center, int right) {
    vector<int>D(SIZE);//存合并后的序列
    int i = left, j = center + 1, k = left;
    while (i <= center && j <= right) {
        if (DATA[i] < DATA[j])D[k++] = DATA[i++];
        else D[k++] = DATA[j++];
    }
    while (i <= center)D[k++] = DATA[i++];
    while (j <= right)D[k++] = DATA[j++];
    for (k = left; k <= right; k++)
        DATA[k] = D[k];//将数据存回原数组
}

//快速排序
void sort::quick_sort() { Quick_sort(0, SIZE - 1); }
void sort::Quick_sort(int left, int right){
    //当只剩一个元素时退出递归
    if (left >= right)return;
    int i = left, j = right;
    int base = DATA[right];
    while (i < j) {
        //若将基准点放在最右边则从左边(i)开始，若在左边，则从右边(j)开始
        while ((i < j) && (DATA[i] <= base))i++;
        while ((i < j) && (DATA[j] >= base))j--;
        //找到左边大于基准和右边小于基准的进行交换
        if (i < j)swap(DATA[i], DATA[j]);
    }
    //i(j)位置的数据放到原基准处
    DATA[right] = DATA[j];
    //将基准最后放回到i或j的位置(最后i=j)
    DATA[j] = base;
    //左右子序列递归
    Quick_sort(left, j - 1);
    Quick_sort(j + 1, right);
}