#include"stack.h"
#include<iostream>
//�ȶ���һ�����캯������ֵ
Stack::Stack()
{
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const long& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(long& item)//��Ҫ�ı�����ֵ����˲���Ҫconst
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}
void Stack::show()
{
	std::cout << "��Ʒ�嵥Ϊ��\n";
	for (int i = 0; i < top; i++)
		std::cout << items[i] << std::endl;
}
Stack::~Stack()
{
	std::cout << "����done!\n";
}