#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//����ϵͳʱ��time(NULL)+���������srand()+�����rand()ʵ�������
//���û��ǰ��ļ����������̶�����ֵ;
//�������������������0-99֮���
//���������������
main()
{
	
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		double temp = (rand() % 11)/10.0;//(0-10�����)/10.0=0-1�������
		printf("%lf\n", temp);
	}
	////r = (double)(rand() / (RAND_MAX + 1.0));
	//for (int i = 0; i<12; i++)
	//	//printf("%f\n", (double)rand());
	//	printf("%d\n", rand() % 100);//ע��%
	//for (int i = 0; i < 12; i++)
	//{
	//	//d = ((double)rand()) / RAND_MAX;
	//	printf("%d\n", rand() % 10);//������Բ���0-10
	//								//printf("%f\n", d);//������Ч��һ��0-1
	//}
}