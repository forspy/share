#include "Queue.h"
Queue::Queue()
{
	qsize = Q_SIZE;
	front = NULL;
	rear = NULL;
	num = 0;
}

Queue::Queue(int qs)
{
	qsize = qs;
	front = NULL;
	rear = NULL;
	num = 0;
}

bool Queue::isempty()const
{
	return num == 0;
}

bool Queue::isfull()const
{
	return num == qsize;
}

int Queue::queue_count()const
{
	return num;
}

bool Queue::en_queue(const Customer& customer)//插入队尾
{
	if (isfull())
		return false;
	//尾插法
	node* add = new node;//创建一个节点
	//给节点赋值
	add->customer = customer;//将customer对象传入节点
	add->next = NULL;//节点先接地好习惯
	num++;
	if (front==NULL)
	{
		front = add;
	}
	else
	{
		rear->next = add;
	}
	rear = add;
	return true;
}

bool Queue::de_queue(Customer& customer)
{
	if (isempty())
		return false;
	//头删法
	customer = front->customer;//返回这个弹出的customer，可能以后要用到
	node* temp = front;
	front = front->next;
	num--;
	delete temp;
	if (isempty())
		rear = NULL;
	return true;
}
//在对象过期时我们选择析构掉它
Queue::~Queue()
{
	//注意一个节点一个节点析构
	node* temp;
	if (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
