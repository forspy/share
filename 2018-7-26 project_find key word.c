#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))//������ܴ�С/��������Ԫ�صĴ�С=����
#define MAXWORD 100
//���ܣ�����ʵ�ֶ���һ�λ��м����ؼ��ֵ�ͳ�ƣ��ؼ����ýṹ������
//������1.�����Ҫ��Ĺؼ��� 2.����getch/ungetch�����ı� 3.���ö��ַ�����ƥ��Ĺؼ��ʲ����� 4.������ֵĹؼ����Լ�����
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


main()
{
	int n;
	char word[MAXWORD];
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s", keytab[n].count, keytab[n].word);//4d%��ʾ��4λ�������
	return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low,high,mid;

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)//strcmp����Ϊָ��ָ���ַ�������,����ͨ�������õķ�ʽ�Ƚ�*word==*tab[mid].word
			high = mid - 1;
		else if ((cond > 0))
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
//�ı������
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

int getword(char *word, int lim)//��ʾ����ָ��wordָ�����������word�ַ�������
{
	int c, getch(void);
	void ungetch(int);//���ܣ�����ȥ������β���ո�
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
	for (;--lim>0;word++)
		if (!isalnum(*word = getch()))
		{
			ungetch(*word);
			break;
		}
	*word = '\0';
	return word[0];
}

