#include <stdio.h>
void find_bit_num(int , int );
int main()
{
	int i = 1;
	printf("请输入一个数，输出它的各个位数\n");
	int number;
	scanf("%d", &number);
	printf("从左到右\n");
	find_bit_num(number,i);
}
//核心，递归输出
void find_bit_num(int value,int num)
{
	int temp = value;
	value = value / 10;//算法
	int bit_num = temp - 10 * value;
	printf("第%d位是%d\n", num, bit_num);
	num++;
	if (value > 0)
		find_bit_num(value,num);
	
}