#include<stdio.h>
int strlen(char *s);

int main()
{
	int i;
	char str[] = "hello world";
	//i = strlen(str);
	printf("%d", strlen(str));
}

int strlen(char *s)
{
	int n;
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}