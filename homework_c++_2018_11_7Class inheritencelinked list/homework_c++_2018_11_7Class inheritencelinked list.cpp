#include"Node.h"
#include<conio.h>
//����˼·������������һϵ�л���ָ�룬���ҵ���ӦID�Ľڵ��ʹ�û���ָ����ʳ��������ķ���
int main()
{
	init();
	char str='a';
	while (str != 'q')
	{
		appendHead();
		cout << "��q�˳�¼������������¼��" << endl;
		str = _getch();
	}
	search();
	cout << "��ʾ¼���������Ϣ" << endl;
	showAllNode();
}