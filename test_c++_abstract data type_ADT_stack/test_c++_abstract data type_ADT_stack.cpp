#include<iostream>
#include<cctype>
#include"stack.h"

int main()
{
	using namespace std;
	Stack st;//û�и�ֵ����ù��캯������ֵ
	char ch;
	long data;//��Ʒ����
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
			cin >> data;
			if (st.isfull())
				cout << "ջ�ϴ�����" << endl;
			else
				st.push(data);
			break;
		case 'd':
		case 'D':
			if (st.isempty())
				cout << "ջ�Ѿ����ˣ�û�ж������Ե���\n";
			else
			{
				st.pop(data);//ͨ�����øı�ʵ�ε�ֵ��������ͨ������ֵ
				cout << "������ֵΪ " << data << endl;
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