#include<stdio.h>
#include<string.h>
int how_many_words(char* p);
int isletter(char c);
int main()
{
	//char words[100] = "       he  llo    worl  d !! ";
	char words[100];
	printf("������һ���ַ���\n");
	gets_s(words, 99);
	printf("��%d������\n",how_many_words(words));
	//printf("%d\n", !0);!���0���1���ѷ�0�������0
}
int how_many_words(char* p)
{
	int len = strlen(p);//strlen��ָ��Ҳ���ԣ���һ��Ҫʵ������
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