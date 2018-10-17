#pragma once
class Time
{
private:
	int hours;
	int minutes;
public:
	Time();//���캯��
	Time(int h, int m = 0);
	void addmin(int m);
	void addhour(int h);
	void reset(int h = 0, int m = 0);
	Time sum(const Time& t)const;
	Time operator+(const Time& t)const;//ΪTime����Ӽӷ����㣨��Ҫ��
	Time operator-(const Time& t)const;
	Time operator*(double mult)const;
	

	//������Ϊֹ����Ĺ��к����Ƿ��������˽�в��ֵ�Ψһ;����Ϊ���ʺ��ض��ı�����⣬c++�ṩ��һ��������ʽ�ķ���Ȩ�ޣ���Ԫ
	/*
	��Ԫ�����֣�
	��Ԫ����
	��Ԫ��
	��Ԫ��Ա����

	*/
	//ͨ���ú�����Ϊ�����Ԫ�����Ը���ú���������ĺ�����ͬ�ķ���Ȩ�ޣ������Ƚ�����Ԫ����
	//��Ԫ�����Ĵ�����Ҫ��Ϊ��������Ķ����ܹ����ʵ����е�˽�г�Ա

	//���⣺�����total=2*total��ʵ�ֲ����ˣ���Ϊ2���Ƕ����������һ����Ԫ����
	friend Time operator*(double mult, const Time& t);//ע�⣺��Ԫ������Ҫ������ԭ�ͷ����������У�������friend
	/*
	��Ȼoperator*()�����������������ĵģ����������ǳ�Ա����������ʹ��.������ ���Բ���Ҫʹ��Time::�޶���������
	��Ԫ�������Ա�����ķ���Ȩ��ͬ
	ʵ���в���Ҫдfriend
	*/
	void show()const;
};

Time test(double a, const Time& t);