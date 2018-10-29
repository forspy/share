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

bool Queue::en_queue(const Customer& customer)//�����β
{
	if (isfull())
		return false;
	//β�巨
	node* add = new node;//����һ���ڵ�
	//���ڵ㸳ֵ
	add->customer = customer;//��customer������ڵ�
	add->next = NULL;//�ڵ��Ƚӵغ�ϰ��
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
	//ͷɾ��
	customer = front->customer;//�������������customer�������Ժ�Ҫ�õ�
	node* temp = front;
	front = front->next;
	num--;
	delete temp;
	if (isempty())
		rear = NULL;
	return true;
}
//�ڶ������ʱ����ѡ����������
Queue::~Queue()
{
	//ע��һ���ڵ�һ���ڵ�����
	node* temp;
	if (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
