#pragma once
/*
关于类的抽象、隐藏和封装
抽象：表示用户可以用类方法地公有接口对类对象执行操作
隐藏：类的数据成员可以是私有地，这意味着只能通过成员函数来访问这些数据
封装：成员函数的实现细节，如数据表示和方法地代码都是隐藏地
抽象数据类型ADT_abstract data type
对栈执行地操作：
创建空栈
压入栈：将数据添加到栈顶
弹出栈：从栈顶删除数据项
查看栈是否填满
查看栈是否为空

通过类声明实现ADT：
公有成员表示栈操作地接口
私有成员储存栈数据（储存方式可以使用常规数组、动态数组、或更高级数据结构（如链表））
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
	bool isempty() const;//bool类型，返回true/false
	bool isfull() const;
	bool push(const long& item);//如果栈满了返回false，否则返回true
	bool pop(long& item);//如果栈空了返回false，否则返回true
	void show();//访问私有部分地数据
};

#endif
