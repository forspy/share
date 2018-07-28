#include<stdio.h>
#include<stdlib.h>

#include "calc.h"
#define MAXOP 100

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




//有些时候重新编译链接的时候出错需要把原debug里的exe删除重新生成






