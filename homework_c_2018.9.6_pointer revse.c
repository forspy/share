#include<stdio.h>
#include<string.h>
void revse_print(char* ptr,int size);
int main()
{
	
	char* p = "danny";
	revse_print(p+4,strlen(p));
	for (int i = 1; i > 0; --i)//i--在for循环一轮末尾--，--i也是在末尾--，所以for循环都是在循环末尾对i操作
		printf("%d", i);
	printf("\n");
	int j = 1;
	while (j--)//j--在（）内先判断后--，--j在（）内先--后判断，都是在（）内完成，区别for
		printf("%d", j);
	printf("\n");
}

void revse_print(char* ptr,int size)
{
	for (int i = size; i > 0; ptr--,i--)
		printf("%c",*ptr);
	printf("\n");
}
