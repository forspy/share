#pragma once
#include<iostream>
#include"Customer.h"
using namespace std;
class Queue
{
private:
	struct node//����һ������ڵ㣬�ڵ��ڱ�ʾһ���˿��Լ�һ����ʽָ��
	{
		Customer customer;
		struct node* next;
	};
	enum{Q_SIZE=10};//Ĭ�϶��г���Ϊ10��

	//����һ�����ָ��
	node* front;//ͷָ��
	node* rear;//βָ��
	int num;//��ǰ���е�����
	int qsize;//�����������
	//��Ϊ���������µĶ��лὫ��βָ��ָ��ԭ���У���ɶ�ԭ���е������
	//����������ʱ�����Ƕ��ж���Ŀ�������,ͨ���ѿ����������private���Է�ֹ��������
	Queue(const Queue&q){ }
	Queue& operator=(const Queue& q) { return *this; }//��ֹ=���ع��쿽������
public:
	Queue();
	Queue(int qs );//�й��캯��ҪдĬ�Ϲ��캯��
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queue_count()const;//���е�ǰ����ͳ��
	bool en_queue(const Customer& customer);//�������β
	bool de_queue(Customer& customer);//�Ӷ���ͷɾ��һ��
};

