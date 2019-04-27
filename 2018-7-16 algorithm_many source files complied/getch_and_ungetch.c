#include<stdio.h>
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