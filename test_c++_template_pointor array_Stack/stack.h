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
#include<iostream>
//与模板函数相同，模板类需要在前面声明
//模板类是泛型编程的重要方法之一，Type是泛型名
template<class Type>//template<typename Type>这样也行  本版本的目标是实现储存一系列指向字符串的指针数组，即形成一个指针栈
class Stack
{
private:
	enum{SIZE=10};
	int stacksize;//指针栈大小,等运行时输入
	Type* items;//1.long items[SIZE];原来是long类型的，为了使得该栈不仅仅适用于double类型使用类模板
	//2.因为items数组的类型改了，所以所有的以items为参数的函数原型都要改
	int top;//栈内类指针计数器：看看栈是否满
public:
	Stack(int ss=SIZE);
	Stack(const Stack<Type>& st);
	~Stack() ;
	bool isempty();//bool类型，返回true/false
	bool isfull();
	bool push(const Type& item);//如果栈满了返回false，否则返回true
	bool pop(Type& item);//如果栈空了返回false，否则返回true
	Stack& operator=(const Stack<Type>& st);
	void show();
};
//原因：c++在写模版函数时（template<class T>之类的），头文件不能与cpp文件分离。这就意味者，
//你头文件定义的含模版的地方必须在头文件中实现，没用模版定义的地方可以放在cpp中实现
// 先定义一个构造函数赋初值
//3.所有的函数实现前面都要加

//4.因为该类变成了模板类 所以作用域为模板类型的类  格式：类<Type>:: 如果是在类里面实现的则可以省略模板前缀和类限定符
template<class Type>
Stack<Type>::Stack(int ss):stacksize(ss),top(0)
{
	items = new Type[stacksize];
}
template<class Type>
Stack<Type>::Stack(const Stack<Type> & st)//拷贝构造
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
bool Stack<Type>::pop(Type& item)//需要改变对象地值，因此不需要const
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
	//1.判断自赋值
	if (this == &stat)
		return *this;
	//2.释放堆内存
	delete[] items;
	//3.然后就类似于拷贝构造了
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
	std::cout << "析构done!\n";
}
#endif
