#include"Node.h"
#include<conio.h>
//基本思路是利用链表储存一系列基类指针，在找到对应ID的节点后使用基类指针访问抽象类对象的方法
int main()
{
	init();
	char str='a';
	while (str != 'q')
	{
		appendHead();
		cout << "按q退出录入其他键继续录入" << endl;
		str = _getch();
	}
	search();
	cout << "显示录入的所有信息" << endl;
	showAllNode();
}