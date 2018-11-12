#pragma once
/*
������ĳ������غͷ�װ
���󣺱�ʾ�û��������෽���ع��нӿڶ������ִ�в���
���أ�������ݳ�Ա������˽�еأ�����ζ��ֻ��ͨ����Ա������������Щ����
��װ����Ա������ʵ��ϸ�ڣ������ݱ�ʾ�ͷ����ش��붼�����ص�
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
#include<iostream>
//��ģ�庯����ͬ��ģ������Ҫ��ǰ������
//ģ�����Ƿ��ͱ�̵���Ҫ����֮һ��Type�Ƿ�����
template<class Type>//template<typename Type>����Ҳ��
class Stack
{
private:
	enum{MAX=10};
	Type items[MAX];//1.long items[MAX];ԭ����long���͵ģ�Ϊ��ʹ�ø�ջ������������double����ʹ����ģ��
	//2.��Ϊitems��������͸��ˣ��������е���itemsΪ�����ĺ���ԭ�Ͷ�Ҫ��
	int top;
public:
	Stack();
	~Stack();
	bool isempty() ;//bool���ͣ�����true/false
	bool isfull() ;
	bool push(const Type& item);//���ջ���˷���false�����򷵻�true
	bool pop(Type& item);//���ջ���˷���false�����򷵻�true
	void show();//����˽�в��ֵ�����
};
//ԭ��c++��дģ�溯��ʱ��template<class T>֮��ģ���ͷ�ļ�������cpp�ļ����롣�����ζ�ߣ�
//��ͷ�ļ�����ĺ�ģ��ĵط�������ͷ�ļ���ʵ�֣�û��ģ�涨��ĵط����Է���cpp��ʵ��
// �ȶ���һ�����캯������ֵ
//3.���еĺ���ʵ��ǰ�涼Ҫ��
template<class Type>
//4.��Ϊ��������ģ���� ����������Ϊģ�����͵���  ��ʽ����<Type>:: �������������ʵ�ֵ������ʡ��ģ��ǰ׺�����޶���
Stack<Type>::Stack()
{
	top = 0;
}
template<class Type>
bool Stack<Type>::isempty()
{
	return top == 0;
}
template<class Type>
bool Stack<Type>::isfull()
{
	return top == MAX;
}
template<class Type>
bool Stack<Type>::push(const Type& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}
template<class Type>
bool Stack<Type>::pop(Type& item)//��Ҫ�ı�����ֵ����˲���Ҫconst
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}
template<class Type>
void Stack<Type>::show()
{
	std::cout << "��Ʒ�嵥Ϊ��\n";
	for (int i = 0; i < top; i++)
		std::cout << items[i] << std::endl;
}
template<class Type>
Stack<Type>::~Stack()
{
	std::cout << "����done!\n";
}
#endif
