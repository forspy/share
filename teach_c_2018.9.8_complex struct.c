#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	double* a[10] ;//指针数组
	double arr[3];
	double(*p)[3];//数组指针，指向数组的指针
	p = &arr;//&表示整个数组的地址
	printf("%p %p\n", p, p + 1);//00C4F9D0 00C4F9E8 差24
	char* ptr = (char*)malloc(sizeof(char) * 100);
	//p = "hello";//这样就丢失了指向堆的内存，造成了内存泄漏
	strcpy(ptr, "hello");//这样就可以方便地对堆操作
	free(ptr);
}