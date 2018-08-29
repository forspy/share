#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	char arr[10];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 10 + 48;
	}
	for (int i = 0; i < 10; i++)//其实不需要用%d输出就是int，用%c或%s输出就是char，一个数比如48，用int a=48；用char a=48;a也是48只是输出的时候如果
		//是%c就是'0',如果是%d就是48，如果是%x就是十六进制30
		printf("char类型%c的int值为%d\n", arr[i], (int)arr[i]);//将char直接转化成int（int需要先-'0'再转化成char）
	
	
}
