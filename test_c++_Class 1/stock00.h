#pragma once
#include<string>

class Stock//����һ����
{
private://˽�г�Ա  ������������ ֻ�й��г�Ա�ܷ��ʣ���װ��һ�֣�
	//������ͨ������˽�в���
	std::string company;//��˾����
	long shares;//���ֹ�Ʊ����
	double share_val;//ÿ�ɵļ۸�
	double total_val;//�ܼ۸�
	void set_tot() { total_val = shares*share_val; };//��Ա����  ���Ծ͵ض��壬Ҳ������ԭ�ͱ�ʾ���Ժ�ʵ�֣�
	//set_tot()������������ �����������������������еĺ�����ͨ����С����
public://���г�Ա  ����ӿ�
	//�����Ľӿں������ڹ��в���
	void acquire(const std::string& co, long n, double pr);//��ù�Ʊ
	void buy(long num, double price);//����
	void sell(long num, double price);//������Ʊ
	void update(double price);//���¹ɼ�
	void show();//��ʾ�ֹ���Ϣ
};
/* Ҳ����ʹ��inline������������

inline void Stock::set_tot()
{
	total_val = shares*share_val;
}
*/