#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//����ϵͳʱ��time(NULL)+���������srand()+�����rand()ʵ�������
//���û��ǰ��ļ����������̶�����ֵ;
//�������������������0-99֮���
main()
{
	double r;
	srand((unsigned)time(NULL));
	
	//r = (double)(rand() / (RAND_MAX + 1.0));
	for(int i=0;i<12;i++)
	//printf("%f\n", (double)rand());
	printf("%d\n", rand()%100);//ע��%
}