#include<stdio.h>
#include<string.h>
void my_strcpy(char* dst, char* src);
int my_strcmp(char* lhs, char* rhs);
int main(int agrc,char* argv[])
{
	printf("%d\n", '\0');//������0���ַ�����'\0'����hello ��Ҫ6���ֽڴ洢
	printf("%d\n", '0');//�ַ�0 ----ascii��48
	char* p = "hello";
	//p[0] = 'p';//hello��һ�������ַ�����const�������ڴ�����ϣ������޸�
	char arr[30];
	char *str = "helloworld!!!";
	my_strcpy(arr, str);
	printf("%s\n", arr);
	char p1[30];
	char p2[30];
	scanf("%s %s", p1, p2);
	int t=my_strcmp(p1, p2);
	if (t == -1)
		printf("�����ַ�����һ��\n");
	else if(t == 0)
		printf("�����ַ���һ��\n");
	char arr1[30];
	strncpy(arr1, str, 2);//ֻ���������ַ�
	printf("%s\n", arr1);
	char* ptr2 = strdup("hello");//�ڶ��Ͽ����ڴ�
	printf("%s\n", ptr2);
	free(ptr2);
}

void my_strcpy(char* dst, char* src)
{
	while (*src != '\0')
	{
		*dst = *src;//����������ú�����������ͷ�ջ��ʲôҲû�ˣ������Ҫ*�ı��������������
		dst++;
		src++;
	}
	*dst = '\0';
}

int my_strcmp(char* lhs, char* rhs)
{
	if (strlen(lhs) != strlen(rhs))
		return -1;
	else
		while (*lhs != '\0'&&*lhs == *rhs)
		{
			lhs++;
			rhs++;
		}
	if (*lhs == '\0')
		return 0;
	else
		return -1;
}