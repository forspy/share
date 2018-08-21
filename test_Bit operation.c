#include<stdio.h>
//位运算应用
#define bit_de (1<<0)
#define bit_zhi (1<<1)
#define bit_ti (1<<2)
#define bit_mei (1<<3)
int main()
{
	//位运算  按位：  |或 &与 ~取反 ^异或
	int a = 7;
	int b = a << 1;//左移一位
	printf("%d\n", b);// 左移1位相当于*2
	//右移低位舍弃，高位保留符号为（如：1100 0000）-64，>>右移为，1110 0000，-1，取反，相当于/2（unsigned负数高位为0）
	int c = a >> 1;
	printf("%d\n", c);
	//正数的运算直接相减，负数的运算补码运算
	//0.25 的二进制
	//0.25*2=0.5----0
	//0.5*2=1-------1
	//得到0.01为二进制小数
	//二进制相减正数直接相减，负数补码相加再转原码
	int xiaoqiu = bit_de | bit_zhi | bit_ti | bit_mei;//表示小邱德智体美都合格
	int xiaoming = bit_de | bit_zhi | bit_ti ;
	if (xiaoqiu&bit_zhi)
		printf("有智慧\n");
	else
		printf("还不行\n");
	if (xiaoming&bit_mei)
		printf("美\n");
	else
		printf("还不太美\n");
}