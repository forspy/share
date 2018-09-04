#include<stdio.h>
#include<string.h>
int main()
{
	int a=1;
	void* p = &a;
	int* ptr = &a;
	printf("%d\n", *(char*)p);//当a的内存只有前1个字节时其实取(char*)长度截出来的值和(int*）截出来的值时一样的
	printf("%d\n", *(int*)p);
	printf("%d\n", *ptr);
	//int类型占4字节，一个字节就是一个编号(地址)。void *存储一个int类型地址没有问题，但是去访问这个地址里的内存除了需要地址还需要大小
	//printf("%d\n", *p);
		//地址的打印用%p
	int* j, k;//这样只定义了一个指针
	char* pp = "aaaaa";
	printf("%d", strlen(pp));//字符串的有效长度
}