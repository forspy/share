#include<stdio.h>
//注释：        先CTRL + K + C

//取消注释： 先CTRL + K + U
#include<conio.h>
//getch不用按回车，getchar需要按回车
int main()
{
	char ch;
	printf("输入一个字符：");
	ch = getch();
	printf("\n你输入的字符是：'%c'\n", ch);
	return 0;
}

//#include<stdio.h>
//#include<conio.h>
//
//int main()
//{
//	char ch;
//	printf("输入一个字符：");
//	ch = getche();
//	printf("\n你输入的字符是：'%c'\n", ch);
//	return 0;
//}

//#include<stdio.h>
//#include<conio.h>
//
//int main()
//{
//	char ch;
//	printf("输入一个字符：");
//	ch = getchar();
//	printf("\n你输入的字符是：'%c'\n", ch);
//	return 0;
//}