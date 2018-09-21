#pragma once
/*
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
};

#endif
