#include"stack.h"
#include<iostream>
//先定义一个构造函数赋初值
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

bool Stack::pop(long& item)//需要改变对象地值，因此不需要const
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
	std::cout << "物品清单为：\n";
	for (int i = 0; i < top; i++)
		std::cout << items[i] << std::endl;
}
Stack::~Stack()
{
	std::cout << "析构done!\n";
}