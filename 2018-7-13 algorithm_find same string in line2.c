#include<stdio.h>
//ʵ�����һ����������ַ��������������
#define MAXLINE 1000
int getline(char line[],int max);
int strindex(char source[], char searchfor[]);
//char line[] = "would you please";
char pattern[] = "you";


main()
{
	char line[MAXLINE];

	//printf("%s", line);
	while (getline(line, MAXLINE) >= 0)
		
		//printf("%s",line);
		if (strindex(line, pattern) >= 0)
		{
			printf("%s", line);
		}
	
}

int getline(char line[],int lim)//ʵ���ַ���������
{
	int c, i;
	i = 0;
	while (--lim>0&&(c = getchar()) != EOF&&c != '\n')
	{
		line[i++] = c;
	}	
		if (c == '\n')
		{
			line[i++] = c;//ע��i++���ۼ������±�

			line[i] = '\0';

			return i;
		}
	
}

int strindex(char source[], char searchfor[])
{
	int i, j, k;
	for (i = 0; source[i] != '\0'; i++)
	{
		for (j = i, k = 0; source[j] == searchfor[k] && searchfor[k] != '\0'; j++, k++)
			;
		if (searchfor[k] == '\0'&&k > 0)
			return i;//�൱������/
	}
	return -1;
}