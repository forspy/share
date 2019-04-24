#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100
#define NUMBER '0'
int getop(char[]);
void push(double);
double pop(voud);

main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case'+':
			push(pop() + pop());
			break;
		case'*':
			push(pop()*pop());
			break;
		case'-':
			op2 = pop();
			push(pop() - op2);
			break;
		case'/':
			op2 = pop();
			if (op2 != 0.0)
			{
				push(pop() / op2);
			}
			else
			{
				printf("error:zero divisor\n");
				break;
			}
		case'\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error");
			break;
		}
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

//push函数，把f压入值栈
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error:stack full");
}

//pop函数：弹出并返回栈顶的值
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error:stack empty\n");
		return 0.0;
	}
}
#include <ctype.h>

int getch(void);
void ungetch(int);
//getop:获取下一个运算符或数值操作数
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return(bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch");
	else
		buf[bufp++] = c;
}
//有些时候重新编译链接的时候出错需要把原debug里的exe删除重新生成






