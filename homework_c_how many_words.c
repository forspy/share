#include<stdio.h>
#include<string.h>
int how_many_words(char* p);
int isletter(char c);
int main()
{
	//char words[100] = "       he  llo    worl  d !! ";
	char words[100];
	printf("请输入一行字符串\n");
	gets_s(words, 99);
	printf("有%d个单词\n",how_many_words(words));
	//printf("%d\n", !0);!会把0变成1，把非0的数变成0
}
int how_many_words(char* p)
{
	int len = strlen(p);//strlen对指针也可以，不一定要实体数组
	int j=0;
	for (int i = 0; i < len; i++)//
	{
		if (isletter(p[i]) && (!isletter(p[i + 1])))
			j++;
	}
	return j;
}
int isletter(char c)
{
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		return 1;
	else
		return 0;
}