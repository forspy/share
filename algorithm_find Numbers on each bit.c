#include <stdio.h>
void find_bit_num(int , int );
int main()
{
	int i = 1;
	printf("������һ������������ĸ���λ��\n");
	int number;
	scanf("%d", &number);
	printf("������\n");
	find_bit_num(number,i);
}
//���ģ��ݹ����
void find_bit_num(int value,int num)
{
	int temp = value;
	value = value / 10;//�㷨
	int bit_num = temp - 10 * value;
	printf("��%dλ��%d\n", num, bit_num);
	num++;
	if (value > 0)
		find_bit_num(value,num);
	
}