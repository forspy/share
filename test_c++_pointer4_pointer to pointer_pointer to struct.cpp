#include <iostream>

int main()
{
	using namespace std;
	struct anti
	{
		int year;
	};

	anti s01, s02, s03;
	anti *p1 = &s01;//����
	anti trio[3];//�����ṹ����
	trio[0].year = 1990;//��ʽ�����飨ʵ�������.��Ա   ��Ҫ
	(trio + 1)->year = 2000;//��ʽ��ָ��(��ַ)->��Ա    ������Ҫ 
	//����(*(trio + 1)).year = 2000;�����ú��Ϊʵ�������.
	//anti *arp = p1;
	anti* arp[3] = { &s01,&s02,&s03 };//����һ���ṹָ������
	//�ṹָ���������
	arp[0]->year = 1990;
	arp[1]->year = 2000;
	arp[2]->year = 2010;
	//ע��arp��һ��ָ��arp[2]�Ŷ�Ӧ��ַ����Ҫ��(*(arp[2])).year = 2010;    ����(**(arp + 2)).year = 2010;
	anti** ppa = arp;//��Ϊarp��һ��ָ��������anti**���͵���Ҫ���ν����ú���ܱ��ʵ�壬ppa��ʵ�ʺ�arp��һ����
	cout << (*ppa)->year << endl << (*(ppa + 1))->year <<endl<< (*(ppa + 2))->year << endl;

}

