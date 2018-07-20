#include <stdio.h>

void strcpy1(char *s, char *t);
void strcpy(char *s, char *t);
int main()
{
	char s[] = "hello";
	char t[] = "hello world";
	strcpy1(s, t);//1.在char t[] = "world!";char s[] = "hello world!";的时候，显示world，即短内存付给长内存
	printf("%s", s);
	
}

void strcpy1(char *s, char *t)
{
	int i;
	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0')
	{
		s++;
		t++;
		
	}
}