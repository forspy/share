#include<stdio.h>

void qsort(int v[], int left, int right);//��ָ��λ�ÿ�ʼ��������
main()
{
	int a[9] = { 4,5,8,7,6,9,2,1,3 };
	int left = 0;
	int right = 8;
	int i;
	qsort(a, left, right);
	for (i = 0; i <= 8; i++)
		printf("%d", a[i]);
	return 0;
}

void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);
	if (left >= right)//����Ҫ�ţ�һ���Ͳ�������
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if (v[i]< v[left])
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}