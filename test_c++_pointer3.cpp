#include<iostream>
using namespace std;
char *getname(void);
void strcpy(char* s, char* t);
int main()
{
	char *p1;
	char name[20] = "hello";
	//p1 = NULL;可以先指向空
	p1 = name;
	cout << "p1= " << p1 << endl;//输出:"hello"
	//char *p2 = getname();
	
	//cout << "p2= " << *(p2+1) << endl;//输出:"e",问题是filename这个数组已经被释放了，为什么还能对它进行指针操作？
	char *p2 = getname();
	cout << p2 << endl;
	delete[] p2;
}

char *getname(void)
{
	char filename[20] = "hello";
	//return filename;
	//如果想使用子函数里的变量，需要开辟一个堆上的内存
	char *ptr = new char[strlen(filename)+1];//必须要给动态数组指定长度
	strcpy(ptr, filename);//要在堆上建立一个数组必须逐字拷贝，应为栈上的数组会被释放，所以必须拷贝原件，只有指针没用
	//ptr = filename;
	return ptr;
}

//strcpy原理：
void strcpy(char* s, char* t)
{
	while ((*s = *t) != '\0')//先将*t的值赋给*s然后判断是不是='\0'
	{
		s++;
		t++;
	}
}