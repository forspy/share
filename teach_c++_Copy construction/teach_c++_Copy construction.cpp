#include"complex.h"

int main()
{
	Complex cp1(1.2);//��ʾ����
	cp1.print();
	Complex cp2 = 1.2;
	//Complex cp2 = Complex(1.2);//��ʽ����  complex cp2=complex(1.2)  ������̲���������
	cp2.print();

	Complex cp3 = cp1;//��ʽ����
	cp3.print();
	Complex cp4(cp1);//��ʽ����
	cp4.print();

	//new��������
	Complex* cp5 = new Complex(cp1);

	ninjia* kakaxi = new ninjia(20);
	kakaxi->show();
	ninjia* n1 = new ninjia(*kakaxi);
	n1->show();
	
	delete kakaxi;
	delete n1;//����Ǳ������ṩ��Ĭ�Ͽ������캯���򲻻������ȿ�����������Ҫ���
	//Ϊ��Ա�����������¿����ڴ棬��̬��ԱҲ������Ҫʹ�ÿ���������=��ʵ�θ����βΣ�returnʱ������ÿ�������
}