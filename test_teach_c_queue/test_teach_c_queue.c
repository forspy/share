#include<stdio.h>
#include"queue.h"
//队列：先进先出
//重要：从队尾入队列，从队首出去
//MFC应用队列：先来了先处理
//点击：存入消息队列
//客户端发送消息给服务器端，服务器端通过队列处理数据，（有时候当客户端发送消息太多时，就会对客户端进行把控）
//顺序表：就是数组
//循环链表简介：----
//时间片处理方式，循环队列，在规定时间内比如0.1秒处理完，处理不完则先保存，一会儿在循环到以后再处理，多线程处理,循环链表不free，
//不需要频繁的使用和释放，以空间换时间
//头指针找到尾指针就得到size，满了就重新申请节点，插入
//循环链表（顺序表）里开辟的内存既定，rear指向插入数据的后一个位置，所以front和rear重叠时表示三种情况：1.没有数据的时候2.只有一个数据的时候3.循环链表满的时候
//----
int main()
{
	struct queue qu;
	init(&qu);
	push(&qu,1);//传入头尾指针
	push(&qu, 2);
	push(&qu, 3);
	pop(&qu);
	printf("队列元素%d\n",get_size(&qu));
	show(&qu);
}