/*
�ڹ��캯����ʹ��newʱӦע�������
1.����ڹ��캯����ʹ��new����ʼ����Աָ�룬��Ӧ������������ʹ��delete
2.new��delete�����໥���ݡ�new��Ӧdelete,new[]��Ӧdelete[]��
3.����ж�����캯�������������ͬ�ķ�ʽʹ��new��Ҫô����[]��Ҫô������������һ���Ļ�new[1],��Ϊ��������ֻ��һ����
��ȸ��ƹ���Ӧ�ø���������Ӱ��ľ�̬���Ա
*/
#include"String.h"

int main()
{
	String A("hello world");
	cout << A << endl;
	String B = "SS";//ʹ���˴��ι��취
	cout << "B="<<B << endl;
	A = B;//ʹ��=����
	call(A);
	String C = "!!";
	cout << A + C << endl;
	String* p = new String(A);//new�ĳ�ʼ����ʽ1
	cout << *p << endl;
	delete p;
	String* ptr = new String("hello world!!");//new�ĳ�ʼ����ʽ��
	cout << *ptr << endl;
	delete ptr;
}

