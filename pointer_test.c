#include <stdio.h>

main()
{
	int n=100;//4���ֽڣ�float 4 ���ֽ� double 8���ֽ�
    int m=101;
	int*n1 = &n;
	int*m1 = &m;
	printf("%d\n", &n);//������Ϊ9435068
	printf("%p\n", &n);//ʮ������00AFF718,&Ϊ���ַ����ָ�루��ַ���ı�׼�������ʽ%p
	printf("%d\n", &m);//������Ϊ9435056����һ�������ڴ��ַ����һ����12��
	//������ջ���洢����ַ���մӴ�С���У�����֮��ļ����8���ֽھ�������intλ�����Ա�����ָ�루�׵�ַ������3��intλ,��ָ����������Ϳ�����ָ������ڴ�
	int*pp = &n;
	printf("pp:%d\n", pp);
	printf("n:%d\n", *pp);
	printf("m��:%d\n", *(pp-3));//?�����,*()����������ֻ����ָ��ֻ������ַ�ķ�����Ҫʵ�����ѽ����*��ָ�루��ַ������Ӧ�ľ����������
	
	printf("m:%d\n", *(n1 - 3));
	*(pp) = 10086;//������n�ĵ�ַ
	printf("n:%d\n", n);
	int*p = &n;//��ָ��p������n�ĵ�ַ���׵�ַ��,��pΪָ�����
	int array[5] = { 1,2,3,4,5 };
	int i;
	for (i = 0; i < 5; ++i)//������i++����++i��array[i]���Ǵ�0��ʼ����++������forѭ��ĩβ��Ч
	{
		printf("��%d����%d\n",i, array[i]);
	}
	int *p1 = &array[0];//ָ��ָ������ĵ�һ��Ԫ��
	//�����ջ�Ѵ����ǽ������е�
	printf("�����3��Ԫ����%d\n", *(p1 + 2));
	//����һ����ά����
	int array2[5][5] =
	{
		{  1, 2, 3, 4, 5 },
		{ 11,12,13,14,15 },
		{ 21,22,23,24,25 },
		{ 31,32,33,34,35 },
		{ 41,42,43,44,45 },
	};//ʵ�����ڴ��Ͽ��ٵ���һά����00(1) 01(2) 02(3) 03(4) 04(5) 10(6) 11(7) 12(8) 13(9) 14(10) 20(11) 21(12)..
	int* a2 = &array2[0][0];
	printf("%d\n", array2[1][3]);//14
	printf("%d\n", *(a2+1*5+3));//��ά�����ָ�����
	int(*pa)[5] = &array;//����һ��ָ�����顯��ָ�룿��������ѽ�����ǵģ��õ�һ������ָ��,paΪ����������ָ��������׵�ַ
	printf("%d\n", *((int*)(pa+1)-2));//���������ָ�����㣬�����õķ���д������ָ���е�ĳ����
	printf("%d\n", *((int*)pa));//��int*��pa��õ�paָ����ĵ�һ��Ԫ�ص�λ��
	
	





}