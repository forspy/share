#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS (sizeof(keytab)/sizeof(keytab[0]))//������ܴ�С/��������Ԫ�صĴ�С=����
#define MAXWORD 100
//���ܣ�����ʵ�ֶ���һ�λ��м����ؼ��ֵ�ͳ�ƣ��ؼ����ýṹ������
//������1.�����Ҫ��Ĺؼ��� 2.����getch/ungetch�����ı� 3.���ö��ַ�����ƥ��Ĺؼ��ʲ����� 4.������ֵĹؼ����Լ�����

//��vs��EOF�����뷽ʽΪctrl+c
//�����ؼ�����Ϊstrcmp(ָ��,ָ��)
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
	for (; --lim>0; word++)
		if (!isalnum(*word = getch()))
		{
			ungetch(*word);
			break;
		}
	*word = '\0';
	return word[0];
}