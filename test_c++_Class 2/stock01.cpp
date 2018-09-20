#include<iostream>
#include"stock01.h"

//���캯����ʵ�ֲ��֣���ʽ�����أ�
Stock::Stock()//���캯��û�з���ֵ
{
	std::cout << "����Ĭ�Ϲ��캯��\n";
	company = "No company";
	shares = 0;
	share_val = 0.0;
	set_tot();
}
Stock::Stock(const std::string& co, long n, double pr)//1.Stock::(��+��������������)��ʾ�ó�Ա�����ܹ�ʹ�����������г�Ա2.ʹ�����ý�סstring����
{
	//std::cout << "ʹ�ù�˾������һ��������������Ĭ�ϲ����ķ�ʽ���ù��캯��\n";
	company = co;
	if (n < 0)
	{
		std::cout << "�ֹ���Ŀ����Ϊ��������Ϊ0\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;//��סÿ�ɼ۸�
	set_tot();//����˽�г�Ա��total_val���ܼ۸�
}
//����������ʵ��
Stock::~Stock()
{
	std::cout << "Done!\n";//������Ȼû��ʹ��new�����ڴ棬���������������ᷢ�Ӻܴ����ã������ٿ��Կ���Stock�Ķ������������
}
//Stock::(��+��������������)��ʾ�ó�Ա�����ܹ�ʹ�����������г�Ա2.ʹ�����ý�סstring����
void Stock::buy(long num, double price)//���뼸��
{
	if (num < 0)
		std::cout << "���벻��Ϊ����\n";
	else
	{
		shares += num;
		share_val = price;//��Ʊ�ּ�
		set_tot();//���¼���
	}
}

void Stock::sell(long num, double price)//��������
{
	using std::cout;//ʹ�����ƿռ䷽��һ��
	if (num < 0)
		cout << "��������Ϊ����\n";
	else if (num > shares)
		cout << "������Ŀ���ܴ����ֳ���Ŀ\n";
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)//�ɼ۱䶯
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::endl;
	std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);//����Ĭ�������ʽ
																								   //std�����ƿռ䣬ios_base�����ƿռ��µ��࣬ftmflags�Ǹ����µ�һ������ orig�Ǳ��������������ʽ  fixed�Ǳ���С�������floatfield���������ʾ�Ϳ�ѧ��ʾ
	std::streamsize prec = std::cout.precision(3);//��¼Ĭ�����С�������λ
	std::cout << "��˾��" << company << endl
		<< "�ֹ�����" << shares << endl
		<< "�ɼۣ�" << share_val << endl;
	std::cout.precision(2);//��С�������λ����ܼ�
	std::cout << "�ù��ܼ�ֵ" << total_val << endl;
	//��ԭĬ������
	std::cout.setf(orig);
	std::cout.precision(prec);
}