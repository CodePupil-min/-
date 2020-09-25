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

//��������
void sort::insert_sort() {
    int j, key;//key�洢ÿ��Ҫ���������е�����ֵ
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

//ϣ������
void sort::shell_sort() {
    int j, key, k;//s[k]ָϣ�����������
    int s[] = { 109,41,19,5,1 };//��������
    for (k = 0; s[k] >= SIZE; k++);//�ҵ��ʺϴ�����������������
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

//ѡ������
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

//ð������
void sort::bubble_sort() {
    bool flog;
    for (int i = 0; i < SIZE; i++) {
        flog = true;
        for (int j = 0; j < SIZE - 1 - i; j++)
            if (DATA[j] > DATA[j + 1]) {
                swap(DATA[j], DATA[j + 1]);
                flog = false;
            }
        if (flog)break;//��⵽��һ��û���н�����˵���Ѿ�����
    }
}

//�鲢���� 
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
    vector<int>D(SIZE);//��ϲ��������
    int i = left, j = center + 1, k = left;
    while (i <= center && j <= right) {
        if (DATA[i] < DATA[j])D[k++] = DATA[i++];
        else D[k++] = DATA[j++];
    }
    while (i <= center)D[k++] = DATA[i++];
    while (j <= right)D[k++] = DATA[j++];
    for (k = left; k <= right; k++)
        DATA[k] = D[k];//�����ݴ��ԭ����
}

//��������
void sort::quick_sort() { Quick_sort(0, SIZE - 1); }
void sort::Quick_sort(int left, int right){
    //��ֻʣһ��Ԫ��ʱ�˳��ݹ�
    if (left >= right)return;
    int i = left, j = right;
    int base = DATA[right];
    while (i < j) {
        //������׼��������ұ�������(i)��ʼ��������ߣ�����ұ�(j)��ʼ
        while ((i < j) && (DATA[i] <= base))i++;
        while ((i < j) && (DATA[j] >= base))j--;
        //�ҵ���ߴ��ڻ�׼���ұ�С�ڻ�׼�Ľ��н���
        if (i < j)swap(DATA[i], DATA[j]);
    }
    //i(j)λ�õ����ݷŵ�ԭ��׼��
    DATA[right] = DATA[j];
    //����׼���Żص�i��j��λ��(���i=j)
    DATA[j] = base;
    //���������еݹ�
    Quick_sort(left, j - 1);
    Quick_sort(j + 1, right);
}