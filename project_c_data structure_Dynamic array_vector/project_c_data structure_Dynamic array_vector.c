#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vector_array.h"

int main()
{
	struct vector_array array;
	//定义这个动态数组的类型
	vector_def(&array, sizeof(int));//定义array数组为int类型
	
	//往动态数组上存放元素
	int value = 4;
	vector_push(&array,&value);
	value = 8;
	vector_push(&array, &value);
	value = 16;
	vector_push(&array, &value);
	//获取第i个数的内存地址（int类型）从第0个数开始
	int* ptr=NULL;
	ptr = vector_at(&array, 0);
	printf("%d\n", *ptr);
	ptr = vector_at(&array, 1);
	printf("%d\n", *ptr);
	ptr = vector_at(&array, 2);
	printf("%d\n", *ptr);
	//获取数组存放内存的首地址
	int* p=NULL;
	p = vector_begin(&array);
	for (int i = 0; i < array.elem_count; i++)
		printf("%d\n", p[i]);
	//擦除某个元素
	vector_erase(&array, 2, 1);//从第2个元素开始弹出一个
	printf("-----------\n");
	for (int i = 0; i < array.elem_count; i++)
		printf("%d\n", p[i]);
	printf("-----------\n");
	int last;
	vector_popback(&array, &last);
	printf("%d\n", last);

	//弹出所有元素
	vector_popall(&array);//其实没有弹出，只是不显示了
	printf("-----------\n");
	for (int i = 0; i < 3; i++)
		printf("%d\n", p[i]);

	//---------------------------------------------
	//释放堆上的动态内存,并清零
	vector_clear(&array);

}