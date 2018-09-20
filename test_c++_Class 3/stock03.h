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


	   //--------���幹�캯������ʼ��Stock��ĳ�Ա����
	Stock();//ͨ���������صķ�ʽ����������ʵ��.cpp���ָ���ֵ������Ĭ�Ϸ�ʽ����ֻʹ��һ�֣��Ƽ�ʹ��Ĭ�ϲ�����ʽ��

			//�Ƽ�����Ĭ�Ϻ����ķ�ʽ
			//��Ĭ�ϲ����ķ�ʽ�������еĹ��캯�������в����ṩĬ��ֵ
	Stock(const std::string& co, long n = 0, double pr = 0.0);//���캯���ĺ�����Ҫ������һ��


															  //-------������������,
															  //�������������ã�
															  //1.���ٶ���ֱ�������Ϊֹ
															  //2.����������������̬�����ڳ������ʱ���ã�����Զ������ڴ�������ʱ���ã��������ͨ��new��������ʹ��deleteɾ���ڴ�ʱ������������
															  //3.������ڹ���ʱ�����������Զ������ã����û���������������������Զ���ʽ����һ����������
	~Stock();
	//void acquire(const std::string& co, long n, double pr);//��ù�Ʊ---version1 ��Ϊ���˹��캯�����൱�ڶ�Stock������ĳ�Ա����ֵ�����Դ�����acquire�Ĺ���
	void buy(long num, double price);//����
	void sell(long num, double price);//������Ʊ
	void update(double price);//���¹ɼ�
	void show() const;//��ʾ�ֹ���Ϣ
	//����thisָ��ָ����ʽ����
	const Stock& topval(const Stock& s) const;//����һ��Stock&���͵����ã���һ��const����Ϊ������const Stock������ֵҪ�������������һ�£�
	//�ڶ��������ڵ�const��ʾ�����޸���ʽ�����ֵ��������const��ʾ�����޸ĵ��ø��෽���Ķ����ֵ
};
/* Ҳ����ʹ��inline������������
inline void Stock::set_tot()
{
total_val = shares*share_val;
}
*/