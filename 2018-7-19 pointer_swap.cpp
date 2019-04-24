#include <stdio.h>

void swap(int *a, int *b);

int main()
{
	int a, b;
	a = 1;
	b = 2;
	printf("%d %d\n", &a, &b);
	swap(&a, &b);
	printf("a=%d b=%d\n", a, b);
	printf("%d %d\n", &a, &b);
}

#if 0
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
#endif
//只交换了指针的地址，并没有交换指针
void swap(int *a, int *b)
{
	int *temp;
	temp = a;
	a = b;
	b = temp;
}
