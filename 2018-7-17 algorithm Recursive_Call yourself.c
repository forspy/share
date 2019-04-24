#include<stdio.h>
void printed(int n);
main()
{
	int m = 123;
	printed(m);
}
void printed(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printed(n / 10);
	putchar(n % 10 + '0');
}