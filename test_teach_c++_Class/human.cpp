#include<iostream>
#include<cstring>
#include<cstdlib>

#include"human.h"
using namespace std;
human::human()
{
	head = 1;
	body = 2;
	hand = 3;
	foot = 4;
}

void human::walk(int head,int b,int c,int d)//ע�ⲻҪ��ʵ���е��β���ͬ���Ա����ͬ
{
	//ͷ
	this->head = head;//��Ҫ������ʹ��this������ֲ����������Ա��������ʾд����this������һ��ecx�Ĵ����������浱ǰ����ĵ�ַ
	//����
	body = b;
	//��
	hand=c;
	//��
	foot=d;
}
void human::show()
{
	//ͷ
	cout << head << endl;
	//����
	cout << body << endl;
	//��
	cout << hand << endl;
	//��
	cout << this->foot << endl;//ʵ���ϴ���һ��thisָ��ָ��ǰ����
}