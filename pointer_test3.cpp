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
//ֻ������ָ��ĵ�ַ����û�н���ָ��
void swap(int *a, int *b)
{
	int *temp;
	temp = a;
	a = b;
	b = temp;
}
