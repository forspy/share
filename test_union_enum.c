#define _CRT_SECURE_NO_WARNINGS//写在开头
#include<stdio.h>
#include<string.h>

int main()
{
	union test
	{
		char name;
		int age;
	};//联合体，只会存其中一个，内存大小是最大值，共用一块内存空间~~

	enum AUTIO_TYPE
	{
		FLV,//第一个没有赋值设为0
		WAV=1,
		MP3=2,
		AMR=3,
		OGG//没有赋值相当于上一个值+1
	};//相当于批量宏定义

	struct sex
	{
		int type;
		union xingbie
		{
			char man[10];
			char women[10];
		}nn;
	};

	struct sex  nanren;
	nanren.type = 0;
	strcpy(nanren.nn.man, "nanren");

	struct sex nvren;
	nvren.type = 1;
	strcpy(nvren.nn.women, "nvren");

	printf("%s\n%s\n", nanren.nn.man, nvren.nn.women);
}
