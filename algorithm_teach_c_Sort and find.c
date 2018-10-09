#include<stdio.h>

/*
��������find
���ܣ��������в���һ����Ҫ������
������arr������Ԫ��,size�������С��data��Ҫ���ҵ�Ԫ��
*/
//����
void swap(int* v, int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
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
int half_find(int arr[], int size, int data)
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
//ð���㷨������ʱ�临�Ӷ�ΪO(n^2����Ҫ����n��һ��n������Ϊn^2
// ��ʼ ��1 0 3 5 9 2 4
//��һ�Σ�0 1 3 5 2 4 9 ����������
//�ڶ��Σ�0 1 3 2 4 5 9 ������δ��
void buble_sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)//���ֻ��ʾ��������
	{
		for (int j = 0; j < size - 1 - i; j++)//�ڲ�ʼ�մ������±�0��ʼ
		{
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}
}

//��������(����) ʱ�临�Ӷ�ΪO(nlog2n),�������O��n^2����ÿ�ζ�����һ����һ��û��Ԫ�ؾ���Ҫn����
void qsort(int* v, int left, int right)
{
	int i, last,mid;
	if (left > right)//����Ҫ�ţ�һ���Ͳ�������
		return;
	mid = (left + right) / 2;
	swap(v, left, mid);//�Ȱ��м��left�Ļ�һ��
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if (v[i] < v[left])
		{
			last++;
			swap(v, last, i);//lastָ��Ҫ�����м�ֵ����Щ���������Ǻ�С���м�ֵ��������λ��
		}
	}
	swap(v, left, last);//������
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

//ѡ������
//  ԭʼ��1 8 3 5 9 6 0 4
//��һ��: 0 8 3 5 9 6 1 4  ���ҵ���С�ĺ͵�һ������
//�ڶ���: 0 1 3 5 9 6 8 4 ���ҵ���С�ĺ͵ڶ�������

void selectsort(int* arr, int size)
{
	int min;
	int temp;
	for (int i = 0; i < size ; i++)
	{
		min = i;//ע��ÿ��min��Ҫ�ȵ���Ҫ��������ĵ�һ��Ԫ��
		for (int j = i; j <size ; j++)//ע��jҪȡ����������һ��ֵ����Ҫj<size
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
void insertsort(int* arr, int size)
{
	int temp;
	for (int i = 1; i < size ; i++)
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
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("��0��ʼ��%d��\n", find(a, 10, 6));
	printf("��0��ʼ��%d��\n", half_find(a, 10, 9));
	int arr[10] = { 1,4,5,2,35,7,2434,12,9,6};
	//selectsort(arr, 10);//ѡ������
	//buble_sort(arr, 10);//ð������
	//insertsort(arr, 10);//��������
	qsort(arr, 0, 9);//��������
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}