#include<iostream>
#include<cstdlib>
#include<ctime>
#include"stack.h"
#include<conio.h>
const int Num = 5;
using namespace std;
int main()
{
	//基本流程是这样的，首先判断栈是不是满的，如果满了就返回未接收的指针数组；如果没满就利用随机数判断：
	//如果随机数为偶数就接受并压入栈中，如果随机数为奇数就弹出并返回未接收的指针数组
	srand(unsigned(time(NULL)));//种下一个随机数种子
	cout << "请输入栈的大小" << endl;
	int stacksize;
	cin >> stacksize;
	Stack<char*>st(stacksize);//默认构造初始化st对象
	char* in[Num] = { "xiaoming","xiaohong","xiaowang" ,"xiaozhang","xiaohua" };//创建一个指针数组
	char* out[Num] = { 0 };//创建一个用于接收pop的指针数组
	int processed = 0;//记录栈满了的弹出个数，即out的计数器
	int nextin = 0;
	char ch;
	cout << "输入q退出" << endl;
	while(ch=_getch()!='q')
	{
		if (!st.isfull() && nextin < Num)
		{
			st.push(in[nextin++]);
			cout << "输入q退出" << endl;
		}
		else
			break;
	}
	for (int i = 0; i < 2; i++)
	{
		st.pop(out[i]);
	}
	cout << "out:" << endl;
	for (int i = 0; i < Num; i++)
	{
		if (out[i])
			cout << out[i] << endl;
	}
	cout << "in:" << endl;
	st.show();
}
