#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include"class and dynamic memory.h"
using std::cout;
using std::endl;
int String_easy::num_strings = 0;//��ʼ��
//�������죨��������Ķ���
String_easy::String_easy(const String_easy& other)//��Ҫ�����������ʹ��new�Ķ����ڶ���Щ������и���ʱ����Ҫ�Ը�����ӿ������캯�����´����ڴ棬������ȸ���
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
String_easy::String_easy(const char* s)
{
	len = strlen(s);//����������ַ���С��������
	this->str = new char[len + 1];//����һ����̬����,�ַ������������ڶ��ڴ��У������������ָ����ڴ�ѵ�ָ��
	strcpy(str, s);//��s���Ƶ�strָ����ڴ���
	num_strings++;
	cout << num_strings << ":" << str << endl;
}

String_easy::String_easy()//Ĭ�Ϲ��캯��
{
	len = 3;
	str = new char[len + 1];//
	strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ":" << str << endl;
}

//��������
String_easy::~String_easy()//ʹ��������������ȷ���������ʱ���Ըö���ʹ�õĶ��ڴ�����ͷ�
{
	cout << str << "  deleted  ";
	num_strings--;
	cout << num_strings << "  left" << endl;
	delete[] str;//�ͷŵ��ö��󴴽��Ķ�̬�ڴ�
}

std::ostream& operator<<(std::ostream& os, const String_easy& st)
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
String_easy& String_easy::operator=(const String_easy& st)
{
	if (this == &st)//��st����ȡ��ַ�������this��˵��
		return *this;//�������������
	delete[] this->str;//�ͷŵ���ֵ���󿪱ٵ��ϵĶ��ڴ�
	this->len = st.len;
	this->str = new char[len + 1];//�����µĶ��ڴ�
	strcpy(this->str, st.str);//����ָ��ö��ڴ��ָ��
	return *this;//�����������
}