#include"Accout.h"

int main()
{
	Accout A("xiaoming", 11111, 12345, 3000);
	
	Accout::adjust();//��̬��Ա�����������κ�һ�����󣬾������е������ʸ������޹أ�û��thisָ��
	
	//A.adjust();//3.��Ȼͨ������ȥ����Ҳ��
	//Accout::m_rate;//4.public��̬��������������	
	A.profit();
	A.show();
	//����ģʽ������ֻ��һ������ �������������
}