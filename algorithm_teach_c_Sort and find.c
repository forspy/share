#include<stdio.h>

/*
��������find
���ܣ��������в���һ����Ҫ������
������arr������Ԫ��,size�������С��data��Ҫ���ҵ�Ԫ��
*/
//��������
int find(int arr[], int size, int data)
{
	int i = 0;
	for (; i < size; i++)
	{
		if (data == arr[i])
			return i;
	}
	return -1;
}
//���ֲ���Ҫ����������
//ʱ�临��ȿ����ѭ������
//�����С����
int half_find(int arr[],int size,int data)
{
	int left = 0;
	int right = size - 1;
	

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == data)
			return mid;//����λ��
		else if (arr[mid] > data)
			right = mid - 1;
		else if (arr[mid] < data)
			left = mid + 1;
	}
	return -1;//û���ҵ�
}
//ð���㷨������
// ��ʼ ��1 0 3 5 9 2 4
//��һ�Σ�0 1 3 5 2 4 9 ����������
//�ڶ��Σ�0 1 3 2 4 5 9 ������δ��
void buble_sort(int arr[], int size)
{
	//
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
			

	}
}
//ѡ������
//  ԭʼ��1 10 3 5 9 6 0 4
//��һ�Σ�10 1 3 5 9 6 0 4  ���ҵ����ĺ͵�һ������
//�ڶ��Σ�10 9 3 5 1 6 0 4  ���ҵ��δ�ĺ͵ڶ�������
//�����Σ�10 9 6 5 1 3 0 4
//���ĴΣ�10 9 6 5 3 1 0 4
//����Σ�10 9 6 5 4 1 0 3
//�����Σ�10 9 6 5 4 3 0 1
//���ߴΣ�10 9 6 5 4 3 1 0

void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
//��������
void qsort(int v[], int left, int right)
{
	int i, last;
	if (left > right)//����Ҫ�ţ�һ���Ͳ�������
		return;
	swap(v, left, (left + right) / 2);//�Ȱ��м��left�Ļ�һ��
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if (v[i]< v[left])
			swap(v, ++last, i);
	}
	swap(v, left, last);//������
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}
//ѡ������
void selectsort(int arr[], int size)
{
	int min = 0;
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i; j < size - 1; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
//��������(����)
//  ԭʼ��1 10 3 5 9 6 0 4
//��һ�Σ�1 10 3 5 9 6 0 4 �Ȱ�ǰ�������Ű�
//�ڶ��Σ�1 3 10 5 9 6 0 4 �ٰ�ǰ�����ź�
//�����Σ�1 3 5 10 9 6 0 4
void insertsort(int arr[], int size)
{
	int temp;
	for (int i = 1; i < size - 1; i++)
	{
		temp = arr[i];//�ȱ���Ҫ���������
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (temp < arr[j])
				arr[j + 1] = arr[j];//�����ƶ�һλ
			else
				break;
		}
		arr[j + 1] = temp;
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("��0��ʼ��%d��\n",find(arr, 10, 6));
	printf("��0��ʼ��%d��\n", half_find(arr, 10, 9));
	int arr1[10] = { 1,4,5,2,35,7,2434,12,9,6 };
	//buble_sort(arr1, 10);
	//insertsort(arr1, 10);
	qsort(arr1, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
}