#include<iostream>
#include<cstdlib>
#include<ctime>
#include"stack.h"
#include<conio.h>
const int Num = 5;
using namespace std;
int main()
{
	//���������������ģ������ж�ջ�ǲ������ģ�������˾ͷ���δ���յ�ָ�����飻���û��������������жϣ�
	//��������Ϊż���ͽ��ܲ�ѹ��ջ�У���������Ϊ�����͵���������δ���յ�ָ������
	srand(unsigned(time(NULL)));//����һ�����������
	cout << "������ջ�Ĵ�С" << endl;
	int stacksize;
	cin >> stacksize;
	Stack<char*>st(stacksize);//Ĭ�Ϲ����ʼ��st����
	char* in[Num] = { "xiaoming","xiaohong","xiaowang" ,"xiaozhang","xiaohua" };//����һ��ָ������
	char* out[Num] = { 0 };//����һ�����ڽ���pop��ָ������
	int processed = 0;//��¼ջ���˵ĵ�����������out�ļ�����
	int nextin = 0;
	char ch;
	cout << "����q�˳�" << endl;
	while(ch=_getch()!='q')
	{
		if (!st.isfull() && nextin < Num)
		{
			st.push(in[nextin++]);
			cout << "����q�˳�" << endl;
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