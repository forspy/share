#include<stdio.h>
#include<stdlib.h>


//int *p;
main()
{
	int m;
	int *p=&m;
	printf("pָ���m�ĵ�ַ%d\n", p);
	printf("pָ��������ŵ�ֵ%d\n", *(p -3));//vs������ջ�����ڱ���ָ��λ�ò�3��int������С��ջ�׵�ַ��ջ����ַС
	printf("%d\n", sizeof(char*));

	int a[] = { 1,2,3 };
	printf("%d\n", *(a+1));//a��һ����ַ�����׵�ַ��a[0]��һ����
	printf("%d\n", a[1]);
	int *ptr;
	int k[] = { 11,22 };
	ptr = k;
	//ptr = (int*)malloc(100);
	//ptr[0] = 0;
	ptr[1] = 1;
	printf("%d\n", ptr);//ptr[0]�൱�ڽ������ˣ�����ptrֻ��ʾ�׵�ַ
	//free(ptr);
	//malloc�Ĺ�����ʵ���൱����ָ��ָ��һ�����飬����ָ��Ϳ����ƶ���
}
