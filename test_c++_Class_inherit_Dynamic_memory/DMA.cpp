#define _CRT_SECURE_NO_WARNINGS
#include"DMA.h"
#include<cstring>

//����ʵ��
baseDMA::baseDMA(const char* l, int r)//Ĭ�Ϲ���
{
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA& rs)//��������
{
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	//baseDMA(rs);//���ÿ������죬Ϊʲô������ù��캯�����У���������һ���������
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

ostream& operator<<(ostream& os, const baseDMA& rs)
{
	//ע�����ַ��������ֱ��coutָ��
	cout << "label:"<<rs.label;
	cout << "rating:" << rs.rating;
	return os;
}

//������lacksDMA��ʵ��

lacksDMA::lacksDMA(const char * c, const char * l, int r):baseDMA::baseDMA(l,r)//������ó�ʼ���б�ķ�ʽʹ�ù����������Ա�͹�������Ա��ͬһ��������
{
	strncpy(color, c, 39);//��cָ��ָ����ַ���ǰ39��������color�У�������color����40��Ϊ'\0',���Բ��ܿ���
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs):baseDMA::baseDMA(rs)
{
	strncpy(color, c, COL_LEN-1);//��cָ��ָ����ַ���ǰ39��������color�У�������color����40��Ϊ'\0',���Բ��ܿ���
	color[COL_LEN-1] = '\0';
}

ostream& operator<<(ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;//��Ҫ��ǿת�������ã����û�������<<��const baseMDA& temp=ls;��סҲ���Ե��ǻ��=���ع���
	os << "color:" << ls.color;
	return os;
}

//������hasDMA��ʵ��

hasDMA::hasDMA(const char * s, const char * l, int r):baseDMA(l,r)//������Ĭ�Ϲ��캯��
{
	style = new char[strlen(s) + 1];//�ַ����ȿ����ڴ�
	strcpy(style, s);//�ٿ����ڴ�
}

hasDMA::hasDMA(const char * s, const baseDMA & rs):baseDMA(rs)//��������࿽�����캯��
{
	style = new char[strlen(s) + 1];//�ַ����ȿ����ڴ�
	strcpy(style, s);//�ٿ����ڴ�
}

hasDMA::hasDMA(const hasDMA & hs):baseDMA(hs)//�����࿽�����캯�����ȹ�����ಿ�֣���Ϊconst baseDMA& temp�ܽ�סhs����hs���ಿ�ֵĹ���
{
	//���µ�������Ա���ֽ��п�������
	style = new char[strlen(hs.style) + 1];//�ַ����ȿ����ڴ�
	strcpy(style, hs.style);//�ٿ����ڴ�
}

hasDMA::~hasDMA()
{
	delete[] style;//�����������ಿ�ֺ���Զ����û��ಿ��
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;//1.�ȿ����Ե�
	//2.�����ڴ�(�ͷŻ������������ڴ�)
	baseDMA::operator=(hs);//1.��Ϊconst baseDMA& temp�ܽ�סhs ��Ҳֻ�ܽ��л��ಿ�ֵ�=2.operator=�Ĺ����а����˶Ի�����ڴ��ͷ�
	delete[] style;
	style = new char[strlen(hs.style) + 1];//�ַ����ȿ����ڴ�
	strcpy(style, hs.style);//�ٿ����ڴ�
	return *this;
}

ostream & operator<<(ostream & os, const hasDMA & hs)
{
	os << (const baseDMA&)hs;//ǿת+���û������ã����ϵ�ǿת�ǺϷ��ģ��������ԭ����ʲô
	os << "style:" << hs.style;
	return os;

	// TODO: �ڴ˴����� return ���
}