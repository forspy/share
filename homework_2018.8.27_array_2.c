#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int compare(int* p);
int main()
{
	srand((unsigned)time(NULL));
	int arr[10];
	
	for (int i=0; i < 10; i++)
		arr[i] = rand() % 11;
	int repeat=0;
	repeat = compare(arr);
	while (repeat != -1)
	{
		arr[repeat]= rand() % 11;
		repeat = compare(arr);
	}
	printf("0-10内不重复的随机数为\n");
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
		
}

int compare(int* p)
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = i+1; j < 10; j++)
		{
			if (p[i] == p[j])
				return i;
		}
			
	}
	return -1;
}