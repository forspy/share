#include"AcctABC.h"
const int CLIENTS = 2;
int main()
{
	AcctABC* p_clients[CLIENTS];//����һ���������ָ������
	p_clients[0] = new Brass("С��", 12345, 3000.0);
	p_clients[1] = new BrassPlus("С��",11222,4000.0);//�������Ĭ��͸֧���޺�����//��������Ĭ�ϵĹ��캯���������Brass&&��ʲô��˼��
	
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();//�ֱ���ö������͵��麯������
		cout << endl;
	}
	p_clients[1]->WithDraw(4500);
	p_clients[1]->ViewAcct();
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}
}