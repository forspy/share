#include<stdio.h>
//ʵ�����һ����������ַ��������������
int strindex(char source[], char searchfor[]);
char line[] = "would you please";
char pattern[] = "you";


main()
{
	//printf("%s", line);
	if (strindex(line, pattern) >= 0)
	{
		printf("%s", line);
	}
}

int strindex(char source[], char searchfor[])
{
	int i, j, k;
	for (i = 0; source[i] != '\0'; i++)
	{
		for (j = i, k = 0; source[j] == searchfor[k]&&searchfor[k]!='\0'; j++, k++)
			;
		if (searchfor[k] == '\0'&&k > 0)
			return i;
	}
	return -1;
}