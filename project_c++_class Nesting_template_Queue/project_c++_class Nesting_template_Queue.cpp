#include"queuetp.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	QueueTP<string> cs(5);//���еĴ�С
	string temp;

	while (!cs.isfull())
	{
		cout << "�����������ȴ�����..." << endl;
		getline(cin, temp);
		cs.enqueue(temp);//���������
	}
	cout << "������������ȴ�" << endl;

	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "����" << temp << "�������" << endl;
	}
}