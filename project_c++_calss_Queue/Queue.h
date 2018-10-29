#pragma once
#include<iostream>
#include"Customer.h"
using namespace std;
class Queue
{
private:
	struct node//定义一个链表节点，节点内表示一个顾客以及一个链式指针
	{
		Customer customer;
		struct node* next;
	};
	enum{Q_SIZE=10};//默认队列长度为10人

	//定义一组队列指针
	node* front;//头指针
	node* rear;//尾指针
	int num;//当前队列的人数
	int qsize;//队列最大人数
	//因为拷贝构造新的队列会将首尾指针指向原队列，造成对原队列的误操作
	//所以这里暂时不考虑队列对象的拷贝构造,通过把拷贝构造放入private可以防止拷贝构造
	Queue(const Queue&q){ }
	Queue& operator=(const Queue& q) { return *this; }//防止=重载构造拷贝对象
public:
	Queue();
	Queue(int qs );//有构造函数要写默认构造函数
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queue_count()const;//队列当前人数统计
	bool en_queue(const Customer& customer);//加入队列尾
	bool de_queue(Customer& customer);//从队列头删除一个
};

