#include<stdio.h>
//λ����Ӧ��
#define bit_de (1<<0)
#define bit_zhi (1<<1)
#define bit_ti (1<<2)
#define bit_mei (1<<3)
int main()
{
	//λ����  ��λ��  |�� &�� ~ȡ�� ^���
	int a = 7;
	int b = a << 1;//����һλ
	printf("%d\n", b);// ����1λ�൱��*2
	//���Ƶ�λ��������λ��������Ϊ���磺1100 0000��-64��>>����Ϊ��1110 0000��-1��ȡ�����൱��/2��unsigned������λΪ0��
	int c = a >> 1;
	printf("%d\n", c);
	//����������ֱ����������������㲹������
	//0.25 �Ķ�����
	//0.25*2=0.5----0
	//0.5*2=1-------1
	//�õ�0.01Ϊ������С��
	//�������������ֱ��������������������תԭ��
	int xiaoqiu = bit_de | bit_zhi | bit_ti | bit_mei;//��ʾС������������ϸ�
	int xiaoming = bit_de | bit_zhi | bit_ti ;
	if (xiaoqiu&bit_zhi)
		printf("���ǻ�\n");
	else
		printf("������\n");
	if (xiaoming&bit_mei)
		printf("��\n");
	else
		printf("����̫��\n");
}