#include<iostream>
#include<cstdlib>
#include<ctime>
#include"vector.h"
using namespace std;
using VECTOR::Vector;//ʹ����
int main()
{
	/*
	enum TT
	{
		RED,GREEN
	};
	std::cout<<TT(1);//Сtipsͨ��ö���±�Ҳ�����ҵ�ö��ֵֻ������ö����(num)
	*/
	//ģ��������
	srand((unsigned int)time(NULL));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);//��ʼ������
	unsigned long steps = 0;//ͳ�Ʋ���
	double target;//��ʾ�������Ŀ�����
	double dstep;
	cout << "�������������Ŀ������ж�Զ(��q�Ƴ�)" << endl;
	while (cin >> target)//ֻҪ���������ϸ�ʽ�ͻ�ѭ��
	{
		cout << "������ÿ������" << endl;
		if (!(cin >> dstep))//��������ʽ�������˳�
		{
			cout << "�����ʽ���� �˳�" << endl;
			break;
		}
		while (result.magval() < target)
		{
			direction = rand() % 360;//���һ������
			//step = Vector(dstep, direction, Vector::POL);����ÿ�����ù��캯���������һ�����󣬲������ڴ�Ĺ���
			step.reset(dstep, direction, Vector::POL);//������һС���Ĵ�С�ͷ���
			result = result + step;//ʵ��ʸ������
			steps++;//ͳ�Ʋ���
		}
		//�������
		cout << "����" << steps << "��,���߳���" << target << "�ף���ԭ�㣩" << endl;
		result.polar_mode();//����Ϊ������ģʽ
		//��������<<��ʾ
		cout << "������ģʽ" << endl;
		cout << result << endl;
		cout << "ƽ��ÿ������" << result.magval() / steps << endl;
		//����
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "�������������Ŀ������ж�Զ(��q�Ƴ�)" << endl;
	}
	cout << "bye" << endl;
	cin.clear();//������ص�boolֵ
	while (cin.get() != '\n')//�ͷŻ���С����
		continue;
	return 0;
}