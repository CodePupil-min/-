/*��������*���ȶ���************/
/*ϣ������*�����ȶ���************/
/*ѡ������*�����ȶ���************/
/*�鲢����*���ȶ���************/
/*ð������*���ȶ���************/
/*��������*�����ȶ���**********/
#ifndef _SORT_
#define _SORT_

#pragma once
 class  sort
{
public:
	//Data������a��ַ��SIZE�泤��
	sort(int* a, int size);
	void print();
	//�ӿ�
	void insert_sort(); //��������
	void shell_sort();//ϣ������
	void select_sort();//ѡ������
	void bubble_sort();//ð������
	void merge_sort();//�鲢����
	void quick_sort();//��������
private:
	int* DATA;
	int SIZE;
	void merge(int left, int center, int right);//���������ĺϲ�(�ڹ鲢��������)
	//���庯��
	void Quick_sort( int left, int right);//�����������ʵ��
	void Merge_sort( int left, int right);//�鲢�������ʵ��
};
#endif // !_SORT_

