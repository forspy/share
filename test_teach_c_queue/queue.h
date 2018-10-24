#pragma once
struct node
{
	int data;
	struct node* next;
};

//为了传参方便，封装更安全
//这样访问和修改front和rear更方便，通过（形参）queue* qu=&qu;可以qu->front，qu->rear方便的修改front和rear的指向，如果
//单独传入头尾指针需要(&front,&rear),以及用struct node**front,和struct node** rear来接
struct queue
{
	struct node* front;//队列的头
	struct node* rear;//队列的尾
};
//初始化
void init(struct queue* qu);

//入队列
void push(struct queue* qu, int data);
//出队列
int pop(struct queue* qu);
//显示所有数据
void show(struct queue* qu);
//获取队首元素
int get_front(struct queue* qu);
//得到队列大小
int get_size(struct queue* qu);
//判断是否为空
int isempty(struct queue* qu);
