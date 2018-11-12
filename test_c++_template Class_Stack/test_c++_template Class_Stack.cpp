#include<iostream>
#include<cctype>
#include<string>
#include"stack.h"
//抽象栈的创建和使用
using namespace std;
int main()
{
	//实例化一个模板类，使用具体的类型替换泛型Type
	Stack<string> st;//没有赋值会采用构造函数赋初值
	char ch;
	string str;//物品编码,原来为long data;
	cout << "输入A增加一项物品编码；输入D删除一项物品编码；输入S显示清单；输入Q退出" << endl;
	while (cin >> ch&&toupper(ch) != 'Q')//toupper()函数作用是将小写字母转换为大写字母,包括a，d，q也能识别
	{
		while (cin.get() != '\n')//清掉输入地多余字符为下次输入做准备
			continue;
		if (!isalpha(ch))
		{
			cout << "输入类型不符，请重试"<<endl;
			continue;
		}
		switch (ch)
		{
		case 'a':
		case 'A':
			cout << "请输入一项物品编码" << endl;
			cin >> str;
			if (st.isfull())
				cout << "栈上存满了" << endl;
			else
				st.push(str);
			break;
		case 'd':
		case 'D':
			if (st.isempty())
				cout << "栈已经空了，没有东西可以弹出\n";
			else
			{
				st.pop(str);//通过引用改变实参地值，而不是通过返回值
				cout << "弹出地值为 " << str << endl;
			}
			break;
		case 's':
		case 'S':
			st.show();
			break;
		}
		cout << "输入A增加一项物品编码；输入D删除一项物品编码；输入S显示清单；输入Q退出" << endl;
	}
	return 0;
}