#include<stdio.h>
#include<stdlib.h>
int* fun(int** walk);//����int** ����ָ���޸�һ��ָ���ָ��
int add(int x, int y);
int minus(int x, int y);
typedef int(*fun_name)(int, int);
int c_math(int x, int y, fun_name fun_name);
int main()
{
	int* p = NULL;
	p = fun(&p);
	*p = 123;

	int*(*ptr)(int**)=fun;//����һ������ָ��
	ptr(&p);//������ָ�������ָ��int* p=arr; p[2]..
	//���ú���ָ���typedefʵ�ֶԶ�������ĵ���
	printf("%d\n", c_math(10, 9, minus));
	printf("%d\n", c_math(10, 9, add));
	//����ָ�룺�ڻص�������ʹ�ý϶�
			  //������װ��ʱ��ʹ�ý϶�
			  //������̬���ʱ��ʹ�÷ǳ���

	//x��2 λ���ʾʹ��x����λ������100ֻȡ00������x��2Ϊ0
	//struct�Ĵ�С������Ͳ���,�Կռ任ʱ��
	struct test
	{
		char name1;
		//
		//
		//
		int a;
		char name2;
		char name3;
		//
		//
	};
	printf("%d\n", sizeof(struct test));
}

int* fun(int** walk)
{
	*walk = (int*)malloc(sizeof(int));
	return *walk;
}

int add(int x, int y)
{
	return x + y;
}

int minus(int x, int y)
{
	return x - y;
}

int c_math(int x, int y, fun_name fun_name)
{
	return fun_name(x, y);
}