#pragma once
struct node
{
	int data;
	struct node* next;
};
//这里为了防止修改全局指针用结构体封装
struct stack
{
	struct node* top;//顶指针
};

//初始化
void init(struct stack* st);

//判断是否为空
int isempty(struct stack* st);

//打印数据
void show(struct stack* st);

//压栈（往栈中存入数据）
void push(struct stack* st, int data);

//创建节点，并链接新建节点的下一个节点
struct node* creat_node(int data, struct node* p_next);
//出栈（把数据从栈中提取出来）
int pop(struct stack* st);

//得到栈顶元素
int get_top(struct stack* st);

//栈清空
void pop_all(struct stack* st);