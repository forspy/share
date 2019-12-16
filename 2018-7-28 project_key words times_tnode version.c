#include <stdio.h>
#include<ctype.h>//测试是否属于特定的类型
#include<string.h>//操作字符串
#include<stdlib.h>
#include<ctype.h>
//#include"getword.h"//必须在头文件夹新建或打开，复制粘贴无效
//功能：记录输入的文本，并按照二叉树的数据结构顺序返回不同单词的个数
#define MAXWORD 100
struct tnode {
	char *word;//指向单词的指针
	int count;//单词出现的次数
	struct tnode *left;//左子节点
	struct tnode *right;//右子节点
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

	if (p == NULL)//如果该单词是一个新节点
	{

		p = talloc();//创建一个新节点,分配内存，和定义int p变量。
		p->word = strdup(w);//功 能: 将字符串拷贝到新建的位置处,需要头文件<string.h>,返回一个指针,其核心函数为strcpy(p, s);
							//strdup()在内部调用了malloc()为变量分配内存，不需要使用返回的字符串时，需要用free()释放相应的内存空间，否则会造成内存泄漏。
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
	{
		p->count++;//->的优先级高
	}
	else if (cond < 0)//根据strcmp的结果放入左子树
	{
		p->left = addtree(p->left, w);
	}
	else//根据strcmp的结果放入右子树
	{
		p->right = addtree(p->right, w);
	}
	return p;
}

//打印二叉树，从左往中往右，递归
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
	return (struct tnode*)malloc(sizeof(struct tnode));//分配动态内存并初始化
													   //在动态分配内存的时候不知道数组的情况下用sizeof(struct tnode)分配一个节点
													   //1.maloc函数一般返回指向void类型的指针，利用强制转换的方式(struct tnode*)给该节点分配内存，void类型可以转换成其他类型
													   //2.malloc动态申请的内存是堆式的，而静态内存的空间是栈式的，一般我们的vs编译过程中变量是以栈的形式存入的
													   //3.动态内存的申请必须在函数内，以便于释放
}
//strdup函数的构造方式
char *strdup(char *s)
{
	char *p;

	p = (char *)malloc(strlen(s) + 1);//+1是为了在结尾上加字符'\0',为p分配内存并初始化
	if (p != NULL)
		strcpy(p, s);
	return p;
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