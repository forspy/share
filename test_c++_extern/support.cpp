//support.cpp ---- use external varibales . compile with external.cpp
#include <iostream>
using std::cout;
extern double warming; //use warming another file
void update(double dt);
void local();

void update(double dt) {
	extern double warming; //extern ʹ��ȫ���ļ�����ı���warming
	warming += dt;
	cout << "Updataing global warming to " << warming << "degress.\n";
}

void local() {
	//����һ���ֲ����Զ�����warming���ں���������ȫ���ļ������warming
	double warming = 0.8;
	cout << "Local warming = " << warming << "degress.\n";
	cout << "But global warming = " << ::warming << "degress.\n";
	//ʹ��C++���������������ȫ�ֹ����warming�������Ǻ����ڶ�����Զ�����warming��
}