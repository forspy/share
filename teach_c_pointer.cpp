#include<stdio.h>
#include<string.h>
int main()
{
	int a=1;
	void* p = &a;
	int* ptr = &a;
	printf("%d\n", *(char*)p);//��a���ڴ�ֻ��ǰ1���ֽ�ʱ��ʵȡ(char*)���Ƚس�����ֵ��(int*���س�����ֵʱһ����
	printf("%d\n", *(int*)p);
	printf("%d\n", *ptr);
	//int����ռ4�ֽڣ�һ���ֽھ���һ�����(��ַ)��void *�洢һ��int���͵�ַû�����⣬����ȥ���������ַ����ڴ������Ҫ��ַ����Ҫ��С
	//printf("%d\n", *p);
		//��ַ�Ĵ�ӡ��%p
	int* j, k;//����ֻ������һ��ָ��
	char* pp = "aaaaa";
	printf("%d", strlen(pp));//�ַ�������Ч����
}