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
	//Single B(100);//�����ǲ��еģ���Ϊ���캯����˽�еģ�����ֻ���þ�̬��Ա�ķ���ȥ����
	Single& s1 = Single::get_instance();
	Single& s2 = Single::get_instance();
	cout << "��ַΪ" << endl;
	cout<< &s1 << endl ;
	cout << &s2 << endl;
	//��������������ָ��ͬһ������˵��ֻ������һ����������γ��˵���ģʽ������ģʽ��
	Singleton& s3 = Singleton::get_instance_p();
	Singleton& s4 = Singleton::get_instance_p();
	cout << "��ַΪ" << endl;
	cout << &s3 << endl;
	cout << &s4 << endl;
	Singleton::clear();
	//��λnew��ʱ��ʹ�ù���ʽ����
}