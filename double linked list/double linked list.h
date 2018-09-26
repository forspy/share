#pragma once
struct node
{
	int ID;
	struct node* prv;//指向前一个节点
	struct node* next;//指向后一个节点
};
//为了防止指向头尾的指针被修改，放入结构体内，小习惯
struct dlist
{
	struct node* p_head;
	struct node* p_end;
};

//初始化
void init(struct dlist*);
//判断链表内是否有节点
int isempty(struct dlist* list);

//返回节点个数
int getsize(struct dlist*);

//显示所有信息
void show(struct dlist* list);
////获取头节点
//int get_head_data(struct dlist* list);

//尾插法
int insert_end(struct dlist* list,int data);

//头插法
int insert_head();

//尾删法
int del_end();

//头删法
int del_head();

//改变节点
int change_node();

//查找节点
int find_node();