/*
���������
1.���ж��������������Ϊ������
2.Ҫ���ù��г�Ա��������ͨ������
3.�ڶ����Ա����ʱ������ʹ����������������
*/
#include<iostream>
#define MM 12
class Test
{
private:
	const int Months = 12;
	//int m0[Months];//�����ǲ��еģ���Ϊ��
	//1.������ֻ�������˶������ʽ����û�д�����������ڴ�������ǰ����û�����ڴ洢�Ŀռ�
	//2.����ʹ��#define �����ı����
	int m1[MM];
	//3.����ʹ��ö���ṩ��������
	enum{my_Months=12};//�����ö��ֻ��Ϊ�˴������ų������������㴴��ö�����͵ı��������û�б�Ҫ�ṩö����
	//����ios_base::fixed  ����fixed��ios_base�ж����ö����
	int m2[my_Months];
	//4.ʹ��static
	static const int Mon = 12;//�ó��������ھ�̬�������������Ǵ����ڶ����У�������Mon����������Test������
	int m3[Mon];
	//Ϊ�˱���ö����������ͻ��c++���������е�ö��
	//���磺
	enum old { small, large };//ȫ��
	enum class young { little, big };//������
	old one = small;//ȫ��
	young two = young::little;//������
	int king = one;//ȫ��Ŀ��Խ�����ʽ���͵�ת��
	//int ring = two;//�ֲ��������ڲ��ܽ�����ʽ���͵�ת��
	int ring = (int)two;//���������ڵ�ö����Ҫ��ʽ��ǿ��ת��
};

int main()
{
	return 0;
}