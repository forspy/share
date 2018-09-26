#pragma once
#pragma once
struct node
{
	int ID;
	struct node* prv;//指向前一个节点
	struct node* next;//指向后一个节点
};
//为了防止指向头尾的指针被不经意间修改，放入结构体内，防止手贱不经意修改，导致头尾指针乱指
//这样使得p_head和p_end只能通过结构体去访问
struct dlist
{
	struct node* p_head;//指向链表的头部
	struct node* p_end;//指向链表的尾部
};

//初始化
void init(struct dlist*);
//判断链表内是否有节点
int isempty(struct dlist* list);

//返回节点个数
int getsize(struct dlist*);

//显示所有信息
void show(struct dlist* list);

//尾插法
void insert_end(struct dlist* list, int data);

//删除一个节点，返回下一个节点地址,并且隐式地返回上一个节点的地址
struct node* delete_node(struct node* node, struct node** p_prv);

//指定位置删除
void del_pos(struct dlist* list, int pos);
//指定位置删除version 1.1
void del_pos_v1(struct dlist* list, int pos);
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