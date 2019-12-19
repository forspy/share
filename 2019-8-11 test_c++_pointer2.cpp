#include <iostream>
#include<string>
using namespace std;
string getname(void);
char *getname1();
int main()
{

	//c语言memmove(ptr,ptr2,90) memcopy(ptr,ptr2,字节数)  内存拷贝
	cout << "hello" << endl;//实质是cout能接住一个char型数组的首地址char str[5]="hello"
	char food[6] = "good";
	char food1[12] = "hiiiiiiiii";
	strcpy(food1, food);//strcpy会覆盖掉food中的字符，因为food1开辟的内存足够，但是即便是food1的内存开辟不足，在使用strcpy的时候也会重新开辟
	//总之strcpy取决于food的值而与food1的内存无关，food是怎么样的strcpy之后food1就是怎么样的。
	cout << food1 << endl;
	strcat(food1, food);//strcat会在后面加载字符串
	cout << food1 << endl;
	//定义一个结构
	struct things
	{
		string name;
		int good;
		int bad;
	};
	things grubnose = { "things",3,4 };
	things *pt = &grubnose;
	cout << grubnose.good << pt->bad << (*pt).good << endl;//三种使用结构体内成员值的做法
	things *ptr = new things;//创建一个结构体空间并指向它
	cout << "name" << endl;
	cin >> ptr->name;
	cout << ptr->name << endl;
	cout << (int*)ptr << endl; //(int*)ptr可以返回指针指向的地址
	delete ptr;//注意释放内存
			   //string类其实有内置的new和delete，所以string的字符串都是开辟在堆中的

	string nn;
	nn = getname();//指针对指针函数
	cout << nn << endl;
	char *p;
	p = getname1();//这样的调用很危险，尽可能在堆上开辟内存，这样调用不对，因为函数中是在栈上开辟的内存在函数结束之后会被释放

	cout << "filename=" << p[1] << endl;//
	char m[20] = "hello";
	char *pp = m;
	cout << m << pp << endl;
}

string getname()
{
	string temp;//temp已经是一个指针类型了
	cout << "getname" << endl;
	cin >> temp;
	return temp;
}
char *getname1()
{
	char filename[20] = "world";
	//cout << "filename" << endl;
	//cin >> filename;
	return filename;
}