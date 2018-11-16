#include"queuetp.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	QueueTP<string> cs(5);//队列的大小
	string temp;

	while (!cs.isfull())
	{
		cout << "请输入姓名等待服务..." << endl;
		getline(cin, temp);
		cs.enqueue(temp);//插入队列中
	}
	cout << "队列已满，请等待" << endl;

	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "现在" << temp << "服务完毕" << endl;
	}
}