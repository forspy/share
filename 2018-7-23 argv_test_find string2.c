
#include<stdio.h>
#include<string.h>
#define MAXLINE 10000

int getline(char line[], int max);

/*find��������ӡ���һ������ָ����ģʽƥ�����*/
main(int argc, int *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage:find pattern\n");
	else
	{
		while (getline(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL)
			{
				printf("%s", line);
				found++;
			}
	}
	return found;
}


/*getline:�������ַ����洢��s�У������������ַ����ĳ���*/
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
//����cmd�󣬽���·�������룺"argv_test_find string2.exe" a��ע��ֻ��һ�������������ܣ���ӡ�����в��������ַ���
//����main�������ܱ������������ã� ��˲������ڳ����ڲ�ȡ��ʵ��ֵ����ô���ںδ���ʵ��ֵ����main�������β���? 
//ʵ����,main�����Ĳ���ֵ�ǴӲ���ϵͳ�������ϻ�õġ�������Ҫ����һ����ִ���ļ�ʱ����DOS��ʾ���¼����ļ�����
//������ʵ�ʲ������ɰ���Щʵ�δ��͵�main���β���ȥ��