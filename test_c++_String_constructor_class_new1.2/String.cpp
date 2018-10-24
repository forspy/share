#include "String.h"

int String::num = 0;//ע�⣬��������о�̬��Ա����Ҫ����ֵ
					//����ڹ��캯����ʹ��new����ʼ����Աָ��
String::String()//Ĭ�Ϲ��캯��
{
	num++;
	len = 0;
	str = new string[len + 1];
	*str = "";
}
String::String(const string& st)//Ĭ�ϴ��ι��캯��
{
	num++;//���¾�̬
	len = st.size();//��st.length()һ��
	str = new string[len + 1];
	*str = st;
}
//��ȸ��ƶ�������Ҫһ��
//��ʽ�Ĵ�����Ҫ��������
String::String(const String& origin)//�������캯�� ���ⷵ�ض��󽫵��ÿ������캯�������������ò���
{
	this->len = origin.len;
	this->str = new string[len + 1];
	*(this->str) = *(origin.str);
	num++;//Ҫд�ģ���Ϊ���Ӻ�������ν���ʱ�������������num--
}
String String::operator+(const String& b)const
{
	return String(*str + *(b.str)); //���ⷵ�ض��󽫵��ÿ������캯��,return����ʽ�Ĵ���һ����ʱ���󣬴����Ĺ��̵��ÿ������캯�����Ӻ����еĶ��󽫵���������������
									//�������ò�����ù�����������������Ҫ����һ���ֲ�������Ӧ�÷��ض������������
}
String& String::operator=(const String& a)//��ʾ�Ķ���=����  ע���ˣ�һ�����ò���������const���ͣ�����ҲҪ��const���ͣ���Ӧ�������ˣ�operator����
{
	if (this == &a)
		return *this;
	delete[] this->str;
	this->len = a.len;
	this->str = new string[len + 1];
	*str = *(a.str);//string����=string������ܰ�ֵ������
	return *this;
}
//��������
String::~String()
{
	num--;
	delete[] this->str;
}
//Ϊ��ʵ�������Ҫ����<<
ostream& operator<<(ostream& os, const String& st)
{
	cout << *(st.str);
	return os;//return os��Ϊ���������(cout<<A)<<B<<endl;����ostream��istream��û��public�������캯���ģ���˱��뷵������
}


void call(const String temp)//ʹ�ÿ�������
{
	cout << temp << endl;
}