#define _CRT_SECURE_NO_WARNINGS//д�ڿ�ͷ
#include<stdio.h>
#include<string.h>

int main()
{
	union test
	{
		char name;
		int age;
	};//�����壬ֻ�������һ�����ڴ��С�����ֵ

	enum AUTIO_TYPE
	{
		FLV,//��һ��û�и�ֵ��Ϊ0
		WAV=1,
		MP3=2,
		AMR=3,
		OGG//û�и�ֵ�൱����һ��ֵ+1
	};//�൱�������궨��

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