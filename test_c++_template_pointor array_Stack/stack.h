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
template<class Type>//template<typename Type>����Ҳ��  ���汾��Ŀ����ʵ�ִ���һϵ��ָ���ַ�����ָ�����飬���γ�һ��ָ��ջ
class Stack
{
private:
	enum{SIZE=10};
	int stacksize;//ָ��ջ��С,������ʱ����
	Type* items;//1.long items[SIZE];ԭ����long���͵ģ�Ϊ��ʹ�ø�ջ������������double����ʹ����ģ��
	//2.��Ϊitems��������͸��ˣ��������е���itemsΪ�����ĺ���ԭ�Ͷ�Ҫ��
	int top;//ջ����ָ�������������ջ�Ƿ���
public:
	Stack(int ss=SIZE);
	Stack(const Stack<Type>& st);
	~Stack() ;
	bool isempty();//bool���ͣ�����true/false
	bool isfull();
	bool push(const Type& item);//���ջ���˷���false�����򷵻�true
	bool pop(Type& item);//���ջ���˷���false�����򷵻�true
	Stack& operator=(const Stack<Type>& st);
	void show();
};
//ԭ��c++��дģ�溯��ʱ��template<class T>֮��ģ���ͷ�ļ�������cpp�ļ����롣�����ζ�ߣ�
//��ͷ�ļ�����ĺ�ģ��ĵط�������ͷ�ļ���ʵ�֣�û��ģ�涨��ĵط����Է���cpp��ʵ��
// �ȶ���һ�����캯������ֵ
//3.���еĺ���ʵ��ǰ�涼Ҫ��

//4.��Ϊ��������ģ���� ����������Ϊģ�����͵���  ��ʽ����<Type>:: �������������ʵ�ֵ������ʡ��ģ��ǰ׺�����޶���
template<class Type>
Stack<Type>::Stack(int ss):stacksize(ss),top(0)
{
	items = new Type[stacksize];
}
template<class Type>
Stack<Type>::Stack(const Stack<Type> & st)//��������
{
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}
template<class Type>
bool Stack<Type>::isempty()
{
	return top == 0;
}
template<class Type>
bool Stack<Type>::isfull()
{
	return top == stacksize;
}
template<class Type>
bool Stack<Type>::push(const Type& item)
{
	if (top < stacksize)
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
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
	//1.�ж��Ը�ֵ
	if (this == &stat)
		return *this;
	//2.�ͷŶ��ڴ�
	delete[] items;
	//3.Ȼ��������ڿ���������
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}

template<class Type>
void Stack<Type>::show()
{
	for (int i = 0; i < top; i++)
	{
		cout << items[i] << endl;
	}
}

template<class Type>
Stack<Type>::~Stack()
{
	delete[] items;
	std::cout << "����done!\n";
}
#endif
