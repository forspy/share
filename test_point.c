#include<stdio.h>
#include<stdlib.h>


//int *p;
main()
{
	int m;
	int *p=&m;
	printf("p指向的m的地址%d\n", p);
	printf("p指针变量里存放的值%d\n", *(p -3));//vs编译器栈内相邻变量指针位置差3个int变量大小，栈底地址大，栈顶地址小
	printf("%d\n", sizeof(char*));

	int a[] = { 1,2,3 };
	printf("%d\n", *(a+1));//a是一个地址且是首地址，a[0]是一个数
	printf("%d\n", a[1]);
	int *ptr;
	int k[] = { 11,22 };
	ptr = k;
	//ptr = (int*)malloc(100);
	//ptr[0] = 0;
	ptr[1] = 1;
	printf("%d\n", ptr);//ptr[0]相当于解引用了，单个ptr只表示首地址
	//free(ptr);
	//malloc的功能其实就相当于让指针指向一个数组，这样指针就可以移动了
}
