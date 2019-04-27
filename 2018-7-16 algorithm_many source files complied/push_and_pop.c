#include<stdio.h>
#define MAXVAL 100

extern int sp;
extern double val[];
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
