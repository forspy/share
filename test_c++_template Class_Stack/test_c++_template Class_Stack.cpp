#include<iostream>
#include<cctype>
#include<string>
#include"stack.h"
//����ջ�Ĵ�����ʹ��
using namespace std;
int main()
{
	//ʵ����һ��ģ���࣬ʹ�þ���������滻����Type
	Stack<string> st;//û�и�ֵ����ù��캯������ֵ
	char ch;
	string str;//��Ʒ����,ԭ��Ϊlong data;
	cout << "����A����һ����Ʒ���룻����Dɾ��һ����Ʒ���룻����S��ʾ�嵥������Q�˳�" << endl;
	while (cin >> ch&&toupper(ch) != 'Q')//toupper()���������ǽ�Сд��ĸת��Ϊ��д��ĸ,����a��d��qҲ��ʶ��
	{
		while (cin.get() != '\n')//�������ض����ַ�Ϊ�´�������׼��
			continue;
		if (!isalpha(ch))
		{
			cout << "�������Ͳ�����������"<<endl;
			continue;
		}
		switch (ch)
		{
		case 'a':
		case 'A':
			cout << "������һ����Ʒ����" << endl;
			cin >> str;
			if (st.isfull())
				cout << "ջ�ϴ�����" << endl;
			else
				st.push(str);
			break;
		case 'd':
		case 'D':
			if (st.isempty())
				cout << "ջ�Ѿ����ˣ�û�ж������Ե���\n";
			else
			{
				st.pop(str);//ͨ�����øı�ʵ�ε�ֵ��������ͨ������ֵ
				cout << "������ֵΪ " << str << endl;
			}
			break;
		case 's':
		case 'S':
			st.show();
			break;
		}
		cout << "����A����һ����Ʒ���룻����Dɾ��һ����Ʒ���룻����S��ʾ�嵥������Q�˳�" << endl;
	}
	return 0;
}