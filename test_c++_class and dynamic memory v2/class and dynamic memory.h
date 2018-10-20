#pragma once
using namespace std;
class String_medium
{
private:
	char* str;//ָ��һ����Ӧ�������һ�������ݰ���
	int len;
	static int num_strings;//����ĸ��� ����ͨ��static��num_strings����Ϊ��̬�����࣬
	//��̬�������ص㣺���۴����˶��ٸ����󣬳���ֻ����һ����̬�������� ������ж�����һ����̬��Ա
	static const int CLIMIT = 80;
public:
	/*
	   �����Ϊ���֣�
	        1��Ĭ�Ϲ��죨�޲�����
			2�����ι��죨�в�����
			3���������죨��������Ķ���
	*/
	//��ʱ���ÿ������캯�����½�һ�����󲢽����ʼ��Ϊͬ�����ж���ʱ�����ƹ��캯����������
	String_medium(const String_medium& other); //�������죬���ǰ�һ��other�Ķ������ݿ�������������Ĳ������������ã�����������ã���ֵ������������ѭ�����ÿ������죬const��ʾ����ı����ö����ֵ
	/*
	���¶������ÿ������캯��
	String_easy test(A);//��ʽ�ĸ�ֵ
	String_easy test=A;//��ʽ�ظ�ֵ
	String_easy test=String_easy(A);//���ø��ƹ��캯��ʽ�ظ�ֵ
	String_easy* p=new String_easy(A);//�ڶ��Ͽ���һ���ڴ潨��A�Ŀ������󣬲���ָ��Pָ����ڴ�
	*/
	/*
	1.Ĭ�ϵĸ��ƹ��캯����һ���ƷǾ�̬��Ա������num_strings���ᱻ���ƣ�ǳ���ƣ�����Ϊ��̬�������������࣬�������ǲ���Ӱ��
	2.�����Ա��������������ʹ�������ĸ��ƹ��캯�������Ƴ�Ա
	*/

	String_medium(const char* s);//���캯��
	String_medium();//Ĭ�Ϲ��캯��
	~String_medium();//��������
	//��Ϊ��String_medium�������һЩ�µĹ���
	//����--------
	//���Ƕ���=����
	String_medium& operator=(const String_medium& st);//������=��ֵ��ʱ��Ҳ��������ȸ��Ƶ����⣬���ΪString_easy���д��ֵ�����
	//���Ƕ���=char
	String_medium& operator=(const char* s);
	//����[]�����ܣ���ʾ�����ַ���ĳ���ַ�
	char& operator[](int i);
	const char& operator[](int i)const;
	//��Ԫ����
	friend ostream& operator<<(ostream& os, const String_medium& st);
	//����
	friend istream& operator >> (istream& is, String_medium& st);

	friend bool operator<(const String_medium& st1, const String_medium& st2);
	friend bool operator>(const String_medium& st1, const String_medium& st2);
	friend bool operator==(const String_medium& st1, const String_medium& st2);

};