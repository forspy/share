//static ���εĺ����ͱ���ֻ���ڸ��ļ��ڲ�ʹ�ã�������
//c++ static�������ԣ� 
//1.��̬��Ա����

//2.��̬���ݳ�Ա
#include<iostream>
#include"tree.h"

//
using namespace std;
class human
{
private:
	static int body;
	int foot;
public:
	static int head;//(1).����һ����̬���Ա��static���εľ�̬���Ա��Ϊȫ�ֱ�����
	static void show();//��̬��Ա����
	void walk()//���������ڲ�ֱ�Ӷ��庯�������Ƽ���
	{
		human::body = 1;//ʹ�����ڲ���Աʱ�Ƽ�д������
	}
	void talk() const;//��ʾ������Ա���������޸�ʹ�����Ķ����ֵ
};

int human::head;//(2).����һ�����Ա
extern "C"//������õ�ʱC���ĺ�������ʹ�ø÷�������
{
	void human::show()//����һ����Ա����
	{
		//���Ծ�̬��Ա������Ҳû��thisָ��
	}

}

void human::talk() const
{
	//this->foot = 1;const�Ҷ����εĺ��������޸������Ա������ֵ
	cout << this->foot << endl;//	ֻ������
}

/*
�������֣����ƿռ�
Ϊ�˽����ͬ�����ṩ����ͬ������������������һ�����Լ��ĺ����������ƿռ�
*/
namespace A
{
	class human
	{
	public:
		int head;
	};
}
namespace B
{
	class human
	{
	public:
		int head;
	};
}

int main()
{
	human::head;//static���εľ�̬���Ա���Բ���Ҫ���������ȥ���ʣ�public��ֱ�ӷ���
	human::show();//��̬��Ա�������Ե���ͨ����ʹ��
	using namespace A;//�����A���ƿռ���Բ�д����BҪд ע��������
	A::human A_company;
	A_company.head = 1;
	B::human B_company;
	B_company.head = 2;
}

