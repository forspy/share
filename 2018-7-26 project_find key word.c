#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))//数组的总大小/单个数组元素的大小=项数
#define MAXWORD 100
//功能：用于实现对于一段话中几个关键字的统计，关键字用结构体声明
//方法：1.先设好要查的关键字 2.利用getch/ungetch输入文本 3.利用二分法搜索匹配的关键词并计数 4.输出出现的关键词以及次数
struct key {
	char *word;
	int count;
}keytab[] = {
	{ "auto",0 },
	{ "break",0 },
	{ "case",0 },
	{ "char",0 },
	{ "const",0 },
	{ "continue",0 },
	{ "default",0 },
	{ "unsigned",0 },
	{ "void",0 },
	{ "volatitle",0 },
	{ "while",0 }
};

int getword(char *word, int lim);
int binsearch(char *word, struct key tab[], int n);


int main()
{
	int n;
	char word[MAXWORD];
	int count = 0;
	while (getword(word, MAXWORD) != EOF&&count < 10)
	{
		count++;
		if (isalpha(word[0]))
		{
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
		}
	}
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s", keytab[n].count, keytab[n].word);//4d%表示以4位整数输出
	return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)//strcmp参数为指针指向字符串数组,可以通过解引用的方式比较*word==*tab[mid].word
			high = mid - 1;
		else if ((cond > 0))
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
//文本输入块
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("too many characters\n");
	else
		buf[bufp++] = c;
}

int getword(char *word, int lim)//表示参数指针word指向主函数里的word字符串数组
{
	int c, getch(void);
	void ungetch(int);//功能：用于去掉单词尾部空格
					  //char *w;
					  //w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*word++ = c;
	if (!isalpha(c)) {
		*word = '\0';
		return c;
	}
	for (; --lim>0; word++)
		if (!isalnum(*word = getch()))
		{
			ungetch(*word);
			break;
		}
	*word = '\0';
	return word[0];
}
