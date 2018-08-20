#include<stdio.h>
#include<string.h>
void my_strcpy(char* dst, char* src);
int my_strcmp(char* lhs, char* rhs);
int main(int agrc,char* argv[])
{
	printf("%d\n", '\0');//二进制0，字符串以'\0'结束hello 需要6个字节存储
	printf("%d\n", '0');//字符0 ----ascii码48
	char* p = "hello";
	//p[0] = 'p';//hello是一个常量字符串是const，定义在代码段上，不能修改
	char arr[30];
	char *str = "helloworld!!!";
	my_strcpy(arr, str);
	printf("%s\n", arr);
	char p1[30];
	char p2[30];
	scanf("%s %s", p1, p2);
	int t=my_strcmp(p1, p2);
	if (t == -1)
		printf("两个字符串不一样\n");
	else if(t == 0)
		printf("两个字符串一样\n");
	char arr1[30];
	strncpy(arr1, str, 2);//只拷贝两个字符
	printf("%s\n", arr1);
	char* ptr2 = strdup("hello");//在堆上开辟内存
	printf("%s\n", ptr2);
	free(ptr2);
}

void my_strcpy(char* dst, char* src)
{
	while (*src != '\0')
	{
		*dst = *src;//如果不解引用函数运行完后释放栈就什么也没了，因此需要*改变主函数里的数组
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