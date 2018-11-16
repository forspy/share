#pragma once
template<class T>
class QueueTP
{
private:
	enum{Q_SIZE=10};
	//嵌套类，原来是struct结构体，其实结构体也算是一种类
	//与包含不一样的是，包含会在类内定义一个类成员，而嵌套只是声明
	class Node
	{
	public:
		T item;
		Node* next;
		Node(const T& i):item(i),next(0){ }//Node类的构造函数
	};
	Node* front;
	Node* rear;
	int items;//当前队列里面的人数
	int qsize;//最大队列人数
	QueueTP(const QueueTP& q):qsize(0){ }
	QueueTP& operator=(const QueueTP& q) { return *this; }
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty() { return items == 0; }
	bool isfull() { return items == qsize; }
	int queueCount() { return items; }
	bool enqueue(const T& item);
	bool dequeue(T& item);
};
//注意template模板类的实现必须嵌套在.h文件中
template <class T>
QueueTP<T>::QueueTP(int qs) :qsize(qs)
{
	front = rear = 0;
	items = 0;
}
template<class T>
QueueTP<T>::~QueueTP()
{
	Node* temp;
	while (front != 0)
	{
		temp = front;//保存要删除的头节点
		front = front->next;
		delete temp;
	}
}
template<class T>
bool QueueTP<T>::enqueue(const T& item)//实现插入队列的算法
{
	if (isfull())
		return false;
	Node* add = new Node(item);//使用了Node类的构造函数
							   //如果失败会抛出exception
	items++;
	if (front == 0)
		front = add;
	else
		rear->next = add;
	rear = add;//
	return true;
}
template <class	T>
bool QueueTP<T>::dequeue(T& item)
{
	if (front == 0)
		return false;
	item = front->item;//从头部出去,通过引用返回这个弹出的item，可能以后要用到
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = 0;
	return true;
}