#pragma once
#include<iostream>

class String_easy
{
private:
	char* str;//ָ��һ����Ӧ�������һ�������ݰ���
	int len;
	static int num_strings;//����ĸ��� ����ͨ��static��num_strings����Ϊ��̬�����࣬
	//��̬�������ص㣺���۴����˶��ٸ����󣬳���ֻ����һ����̬�������� ������ж�����һ����̬��Ա
	
public:
	/*
	   �����Ϊ���֣�
	        1��Ĭ�Ϲ��죨�޲�����
			2�����ι��죨�в�����
			3���������죨��������Ķ���
	*/
	//��ʱ���ÿ������캯�����½�һ�����󲢽����ʼ��Ϊͬ�����ж���ʱ�����ƹ��캯����������
	String_easy(const String_easy& other); //�������죬���ǰ�һ��other�Ķ������ݿ�������������Ĳ������������ã�����������ã���ֵ������������ѭ�����ÿ������죬const��ʾ����ı����ö����ֵ
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

	String_easy(const char* s);//���캯��
	String_easy();//Ĭ�Ϲ��캯��
	~String_easy();//��������
	String_easy& operator=(const String_easy& st);//������=��ֵ��ʱ��Ҳ��������ȸ��Ƶ����⣬���ΪString_easy���д��ֵ�����
	//��Ԫ����
	friend std::ostream& operator<<(std::ostream& os, const String_easy& st);

};