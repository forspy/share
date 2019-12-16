#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))//数组的总大小/单个数组元素的大小=项数
#define MAXWORD 100
//功能：用于实现对于一段话中几个关键字的统计，关键字用结构体声明
//方法：1.先设好要查的关键字 2.利用getch/ungetch输入文本 3.利用二分法搜索匹配的关键词并计数 4.输出出现的关键词以及次数

//在vs下EOF的输入方式为ctrl+c
//搜索关键函数为strcmp(指针,指针)
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
struct key *binsearch(char *word, struct key tab[], int n);
main()
{
	char word[MAXWORD];
	struct key *p;

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((p = binsearch(word, keytab, NKEYS)) != NULL)
				p->count++;
	for (p = keytab; p < keytab + NKEYS; p++)
		if (p->count > 0)
			printf("%d %s\n", p->count, p->word);
	return 0;
}


struct key * binsearch(char * word, struct key tab[], int n)
{
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
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