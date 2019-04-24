#include <stdio.h>

main()
{
	int c,i, nwhite, nother, ndigit[10];
	
	nwhite = nother = 0;
	int num = 0;
	for (i = 0; i < 10; i++)
	{
		ndigit[i] = 0;
	}
	while ((c = getchar()) != EOF && num<=10)
	{
		
		switch (c)
		{
		case'0': case'1':case'2':case'3':case'4':
		case'5': case'6':case'7':case'8':case'9':
			ndigit[c - '0']++;//使得对应数字的计数加1
			break;
		case' ':case'\n':case'\t':
			nwhite++;//使得空白字符加1
			break;
		default:
			nother++;
			break;
		}
		num++;
	}
	printf("digits =");
	for (i = 0; i < 10; i++)
	{
		printf(" %d", ndigit[i]);
	}
		printf(", white space =%d,other= %d\n", nwhite, nother);
		return 0;
	
}