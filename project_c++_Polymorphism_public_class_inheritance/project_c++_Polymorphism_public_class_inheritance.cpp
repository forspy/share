#include"accout.h"
#include<iostream>

int main()
{
	Brass xiaowang("xiaowang", 12345, 4000.0);
	xiaowang.ViewAcct();
	xiaowang.WithDraw(4200);
	BrassPlus xiaoming("xiaoming", 11000, 2000.0);
	xiaoming.ViewAcct();
	xiaoming.Deposit(1000);
	xiaoming.WithDraw(3200);
	xiaoming.ViewAcct();
	//�����Ķ�̬�Է������ɶ�����õ�
	//����Ҫ����Brass��BrassPlus���˻���ʹ�����������棬�������е�Ԫ�����ͱ���һ�£����Դ�����һ�������ָ������
	//��Ϊ����ָ������Brassָ��ȿ���ָ��Brass����Ҳ����ָ��BrassPlus������������ʹ��һ��ָ����������ʾ�������͵Ķ�����Ƕ�̬��
	const int CLIENTS = 3;
	Brass* p_clients[CLIENTS];//����һ��ָ������
	p_clients[0] = new Brass("xiaozhang", 11111, 5000);
	p_clients[1] = new BrassPlus("xiaohong", 00001, 6666);
	p_clients[2] = new BrassPlus(*p_clients[0]);//�������ж��������
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];//�����������������ľ�ֻ�����Brass����������������ľͽ�����ָ��ָ��������������BrassPlus
	}
}