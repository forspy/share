#include<stdio.h>

main()
{
	int i,j;
	double power,val;
	int s[3] = { 1,2,3 };
		
		printf("%d\n",s[0]);
		char ss[4] = { '1','2','3','\0' };//字符串数组赋值
		printf("%c\n", ss[0]);
		printf("%s\n", ss);
		char p[] = "hello";//c语言初始化格式等价于p[0]='h',p[1]='e',...
		printf("%s\n", p);
		char pp[] = "123";//C语言初始化格式
		printf("%s\n", pp);
		char *m;//1.可以把字符串赋值给指针mm 2.指针的值是地址 3.数组的值是常量
		m = "123";//双引号做了三件事1.开辟一个空间2.在字符串结尾加上'\0' 3.返回地址
		//字符串常量”hello”出现在一个表达式中时，”hello”表达式使用的值就是这些字符所存储的地址（在常量区），而不是这些字符本身。
		printf("%s\n", m);
		/*tips：运算符的左边应该是一个“左值”。所谓“左值”就是指在程序中占用内存空间、可以被修改的量, 比如各种变量。

			在使用指针的时候，指针可以自增，而数组名不能自增

			编译器给数组分配了空间，数组a的地址就表示一个常量了，让常量自增这肯定是不行的。*/


	//power = 1.0;//默认double/float输出都为1.000000
	//printf("%f", power);
	/*for (i = 0; i < 3; i++)
	{
		power *= 10.0;
	}*/
	//ctrl+k+c批量注释ctrl+k+u取消注释
	/*printf("%f", power);
	for (j = 0; j < 3; j++)
	{
		val = 10.0*val + (s[j] - '0');
	}*/

}