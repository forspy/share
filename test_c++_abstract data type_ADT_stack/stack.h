#pragma once
/*
������������ADT_abstract data type
��ջִ�еز�����
������ջ
ѹ��ջ����������ӵ�ջ��
����ջ����ջ��ɾ��������
�鿴ջ�Ƿ�����
�鿴ջ�Ƿ�Ϊ��

ͨ��������ʵ��ADT��
���г�Ա��ʾջ�����ؽӿ�
˽�г�Ա����ջ���ݣ����淽ʽ����ʹ�ó������顢��̬���顢����߼����ݽṹ����������
*/
#ifndef STACK_H_
#define STACK_H_
class Stack
{
private:
	enum{MAX=10};
	long items[MAX];
	int top;
public:
	Stack();
	~Stack();
	bool isempty() const;//bool���ͣ�����true/false
	bool isfull() const;
	bool push(const long& item);//���ջ���˷���false�����򷵻�true
	bool pop(long& item);//���ջ���˷���false�����򷵻�true
};

#endif
