#include <stdio.h>
#define SIZE 3

int bubble_max(int a[], int n);
void swap(int *a, int *b);

int main(int agrc, char *argv[])
{
	int a[SIZE];
	printf("�������������Ƚϴ�С\n");
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	
	int max = bubble_max(a, SIZE);

	printf("����Ϊ\n");
	for (int i = 0; i < 3; i++)
		printf("%d ", a[i]);
	printf("\n");
    printf("�����Ϊ\n");
	printf("%d\n",max);
}


int bubble_max(int a[],int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j + 1])
			swap(&a[j], &a[j + 1]);
	
	return a[n - 1];
}

void swap(int *a, int *b)
{
	int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	
}