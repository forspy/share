#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//����ϵͳʱ��time(NULL)+���������srand()+�����rand()ʵ�������
//���û��ǰ��ļ����������̶�����ֵ;
//���������������
main()
{
	double d = 0.0;
	srand((unsigned)time(NULL));

	//r = (double)(rand() / (RAND_MAX + 1.0));
	for (int i = 0; i < 12; i++)
	{
		//d = ((double)rand()) / RAND_MAX;
		printf("%d\n", rand() % 10);//������Բ���0-9  rand()%10 ��ʾ����10�༸
									//printf("%f\n", d);//������Ч��һ��0-1
	}
}