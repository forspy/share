#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"class and dynamic memory.h"

int String_medium::num_strings = 0;//��ʼ��
//�������죨��������Ķ���
String_medium::String_medium(const String_medium& other)//��Ҫ�����������ʹ��new�Ķ����ڶ���Щ������и���ʱ����Ҫ�Ը�����ӿ������캯�����´����ڴ棬������ȸ���
{
	/*
		�����ʣ�����Ͷ��󿽱���this = 	other����ôthis�϶���һ����ʱ�Ķ��󣬺�������֮ǰ���ͷ��ڴ档
		Ȼ��������other������ڴ汻�ͷŵ�Ŷ
	*/
	
	this->len = other.len;//�ǲ�������һ��һ���������������ˣ��ǵģ�this.str��Ҫ�����ڴ�,�������ֻ����strָ���أ�����һ���ڴ�ɲ����ԣ�
	this->str = new char[this->len + 1];//Ϊ�˷�ֹ�ڴ汻�ͷŵ�����ʱ�����½���һ���ڴ�
	strcpy(str, other.str);
	num_strings++;   //����ʲô����,���ǲ����õģ�˵���Ǵ����˶��ٸ�����
	cout << num_strings << ":" << str << endl;
	//�����������´���һ�������ˣ���������
	//this->str = new char;//�����в��У�
}

//���ö�̬���鹹�캯��
String_medium::String_medium(const char* s)
{
	len = strlen(s);//����������ַ���С��������
	this->str = new char[len + 1];//����һ����̬����,�ַ������������ڶ��ڴ��У������������ָ����ڴ�ѵ�ָ��
	strcpy(str, s);//��s���Ƶ�strָ����ڴ���
	num_strings++;
	cout << num_strings << ":" << str << endl;
}

String_medium::String_medium()//Ĭ�Ϲ��캯��
{
	len = 0;
	str = new char[len + 1];//������ʹ��ʼ��Ϊ0Ҳ����ʹ��delete[] �ͷ�
	num_strings++;
	//str = nullptr;//��ʾstr��һ����ָ�룬c++11����
	str[0] = '\0';//Ҳ����д��str=0;str=NULL
	
}

//��������
String_medium::~String_medium()//ʹ��������������ȷ���������ʱ���Ըö���ʹ�õĶ��ڴ�����ͷ�
{
	cout << str << "  deleted  ";
	num_strings--;
	cout << num_strings << "  left" << endl;
	delete[] str;//�ͷŵ��ö��󴴽��Ķ�̬�ڴ�
}

ostream& operator<<(ostream& os, const String_medium& st)//����д�������򣬱�����Ԫ����Ҳ�������������
{
	os << st.str;

	return os;
}
/*
����������������ԣ�
func(){a=0};
func(int n=0){a=n};
*/
//s1=s2����
//s1=s1.operator=(s2) ���صĶ����s1
//Ҳ��������s0=s1=s2
//s0.operator=(s1.operator=(s2))
//���Ƕ���=����
String_medium& String_medium::operator=(const String_medium& st)
{
	if (this == &st)//��st����ȡ��ַ�������this��˵��
		return *this;//�������������
	delete[] this->str;//�ͷŵ���ֵ���󿪱ٵ��ϵĶ��ڴ�
	this->len = st.len;
	this->str = new char[len + 1];//�����µĶ��ڴ�
	strcpy(this->str, st.str);//����ָ��ö��ڴ��ָ��
	return *this;//�����������
}
//���Ƕ���=char
String_medium& String_medium::operator=(const char* s)
{
	delete[] this->str;//�������ǰ����Ķ��ڴ�ֵ
	this->len = strlen(s);
	this->str = new char[len + 1];
	strcpy(this->str, s);
	return *this;

}
/*
bool operator<(const String_medium& st1, const String_medium& st2)
{
if (strcmp(st1.str, st2.str) < 0)
return true;
else
return false;
}
*/
//��һ����дΪ
bool operator<(const String_medium& st1, const String_medium& st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String_medium& st1, const String_medium& st2)
{
	return (strcmp(st1.str, st2.str) > 0);
}
bool operator==(const String_medium& st1, const String_medium& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}
//����"love"==answer����ת��Ϊoperator==("love",answer);��һ��-->operator==(String_medium("love"),answer);?����Ϊʲô"love"���Զ�ת��ΪString_medium����
//Ҳ����˵String_medium& st1�ܽ�ס"love"���ѽ������String_medium���캯����ס"love"
//��Զ���
char& String_medium::operator[](int i)
{
	return this->str[i];
}
//����ַ���"hello world"
const char& String_medium::operator[](int i)const
{
	return this->str[i];
}
//ʵ����������
istream& operator >> (istream& is, String_medium& st)
{
	char temp[String_medium::CLIMIT];
	is.get(temp, String_medium::CLIMIT);//������ʵ�Ѿ�����˶�temp�����룬�ᱣ���ڻ��������������С�ڻ�������ȷ�����
	//���temp��ֵ��st�������͸�st����ֵ��
	if (is)
		st = temp;
	while (is&&is.get() != '\n')//���������������Ļ����Լ�'\n'
		continue;
	return is;//����is����������ʱ���ж��������
}