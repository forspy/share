#include <stdio.h>
#include<ctype.h>//�����Ƿ������ض�������
#include<string.h>//�����ַ���
#include<stdlib.h>
#include<ctype.h>
//#include"getword.h"//������ͷ�ļ����½���򿪣�����ճ����Ч
//���ܣ���¼������ı��������ն����������ݽṹ˳�򷵻ز�ͬ���ʵĸ���
#define MAXWORD 100
struct tnode {
	char *word;//ָ�򵥴ʵ�ָ��
	int count;//���ʳ��ֵĴ���
	struct tnode *left;//���ӽڵ�
	struct tnode *right;//���ӽڵ�
};
struct tnode *addtree(struct tnode *p, char *w);
void treeprint(struct tnode *);
int getword(char *, int);

main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}
//sd

struct tnode *talloc(void);
char *strdup(char *s);

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL)//����õ�����һ���½ڵ�
	{

		p = talloc();//����һ���½ڵ�,�����ڴ棬�Ͷ���int p������
		p->word = strdup(w);//�� ��: ���ַ����������½���λ�ô�,��Ҫͷ�ļ�<string.h>,����һ��ָ��,����ĺ���Ϊstrcpy(p, s);
							//strdup()���ڲ�������malloc()Ϊ���������ڴ棬����Ҫʹ�÷��ص��ַ���ʱ����Ҫ��free()�ͷ���Ӧ���ڴ�ռ䣬���������ڴ�й©��
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
	{
		p->count++;//->�����ȼ���
	}
	else if (cond < 0)//����strcmp�Ľ������������
	{
		p->left = addtree(p->left, w);
	}
	else//����strcmp�Ľ������������
	{
		p->right = addtree(p->right, w);
	}
	return p;
}

//��ӡ�������������������ң��ݹ�
void treeprint(struct tnode *p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));//���䶯̬�ڴ沢��ʼ��
													   //�ڶ�̬�����ڴ��ʱ��֪��������������sizeof(struct tnode)����һ���ڵ�
													   //1.maloc����һ�㷵��ָ��void���͵�ָ�룬����ǿ��ת���ķ�ʽ(struct tnode*)���ýڵ�����ڴ棬void���Ϳ���ת������������
													   //2.malloc��̬������ڴ��Ƕ�ʽ�ģ�����̬�ڴ�Ŀռ���ջʽ�ģ�һ�����ǵ�vs��������б�������ջ����ʽ�����
													   //3.��̬�ڴ����������ں����ڣ��Ա����ͷ�
}
//strdup�����Ĺ��췽ʽ
char *strdup(char *s)
{
	char *p;

	p = (char *)malloc(strlen(s) + 1);//+1��Ϊ���ڽ�β�ϼ��ַ�'\0',Ϊp�����ڴ沢��ʼ��
	if (p != NULL)
		strcpy(p, s);
	return p;
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