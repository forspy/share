/*
�ڹ��캯����ʹ��newʱӦע�������
1.����ڹ��캯����ʹ��new����ʼ����Աָ�룬��Ӧ������������ʹ��delete
2.new��delete�����໥���ݡ�new��Ӧdelete,new[]��Ӧdelete[]��
3.����ж�����캯�������������ͬ�ķ�ʽʹ��new��Ҫô����[]��Ҫô������������һ���Ļ�new[1],��Ϊ��������ֻ��һ����
��ȸ��ƹ���Ӧ�ø���������Ӱ��ľ�̬���Ա
*/
#include<iostream>
#include<string>
using namespace std;
//��
class String
{
private:
	static int num;//��̬��Ա
	int len;
	string* str;//��Ϊ��Ҫ�ڶ��Ͽ��ڴ棬������Ҫһ��string*��ָ��
public:
	String();//Ĭ�Ϲ��캯��
	String(const string& st);//Ĭ�ϴ��ι��캯��
	String(const String& origin);//�������캯��
	String& operator=(const String& st);//����=��ȸ���
	~String();
	friend ostream& operator<<(ostream& os,const String& st);//��Ϊostream���ⲿ�࣬Ϊ����os�ܹ����ʵ�String���ڲ��ĳ�Ա����Ҫ������Ԫ����
};
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
String::String(const String& origin)//�������캯��
{
	this->len = origin.len;
	this->str = new string[len + 1];
	*(this->str) = *(origin.str);
	num++;//Ҫд�ģ���Ϊ���Ӻ�������ν���ʱ�������������num--
}

String& String::operator=(const String& a)//��ʾ�Ķ���=����
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
	return os;//return os��Ϊ���������(cout<<A)<<B<<endl;
}
void call(const String temp);
int main()
{
	String A("hello world");
	cout << A << endl;
	String B = "SS";//ʹ���˴��ι��취
	cout << "B="<<B << endl;
	A = B;//ʹ��=����
	call(A);

}

void call(const String temp)//ʹ�ÿ�������
{
	cout << temp << endl;
}