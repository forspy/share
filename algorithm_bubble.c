#include <stdio.h>
#define SIZE 3

int bubble_max(int a[], int n);
void swap(int *a, int *b);

int main(int agrc, char *argv[])
{
	int a[SIZE];
	printf("请输入三个数比较大小\n");
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	
	int max = bubble_max(a, SIZE);

	printf("排序为\n");
	for (int i = 0; i < 3; i++)
		printf("%d ", a[i]);
	printf("\n");
    printf("最大数为\n");
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