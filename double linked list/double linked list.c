#include"double linked list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init(struct dlist* list)//p_head和p_end为全局变量
{
	list->p_head = NULL;
	list->p_end = NULL;
}

//如果没有节点
int isempty(struct dlist* list)
{
	return !(list->p_head) && !(list->p_end);//链表没有节点返回1，有节点返回0
}
//返回链表的节点个数
int getsize(struct dlist* list)
{
	if (isempty(list))//如果链表为空，那么也不存在prv和next，所以要先判断链表是否为NULL
	{
		printf("链表为空\n");
		return 0;
	}
	int size = 0;
	struct node* p = list->p_end;

	//加入从后往前找，也可以从前往后找，这样p=list->p_head
	while (p)
	{
		p = p->prv;
		size++;
	}
	printf("双向链表节点个数为%d\n", size);
	return size;
}
//遍历显示节点内容
void show(struct dlist* list)
{
	if (isempty(list))
	{
		printf("链表为空\n");
		return;
	}
	struct node* p = list->p_head;//使用一个临时变量p去遍历，不改变p_head的指向，p_head还是指头
	//从头部往下遍历
	while (p)
	{
		printf("%d<->", p->ID);
		p = p->next;
	}
}
//新节点用malloc开辟内存，并对该节点的前后进行链接
struct node* creat_data(int data, struct node* p_next, struct node* p_prv)//p_next和p_next表示传入新开节点的下一个节点的地址和上一个节点的地址
{
	struct node* p = (struct node*)malloc(sizeof(struct node));//开辟一个节点内存
	if (!p)
	{
		printf("申请节点失败\n");
		return NULL;
	}
	p->ID = data;
	p->next = p_next;
	p->prv = p_prv;
	return p;
}
//尾插法
void insert_end(struct dlist* list, int data)
{
	//if (isempty(list))
	//{
	//	printf("链表为空\n");
	//	return 0;
	//}
	
	//先移动p_end再链接
	list->p_end = creat_data(data, NULL, list->p_end);
	//1.新节点用malloc开辟内存，并对该节点的前后进行链接
	//2.将p_end指针移向新节点，注意这里的p_end是一个全局变量，在函数内改变p_end的指向，在外部也会改变p_end的指向
	if (list->p_end->prv)//如果p_end指向新节点以后，新节点的前面还有节点，也就是说不止一个节点>=2
	{
		list->p_end->prv->next = list->p_end;
		//3.将前一个节点链接新节点，这里体现了双向链表的优势，得到了前一个节点的next即，list->p_end->prv->next，链接到当前的list->p_end
	}
	else//只有一个节点
	{
		list->p_head = list->p_end;//只有一个节点的话，头部也指向这个节点
	}
	//待测试
	/*
	//先链再移动p_end
	list->p_end->next = creat_data(data, NULL, list->p_end);
	list->p_end = list->p_end->next;
	*/

}
//删除一个节点，返回下一个节点地址,并且隐式地返回上一个节点的地址
struct node* delete_node(struct node* node, struct node** p_prv)//node为要删除的节点地址，p_prv为前一个节点，因为只能返回一个值，所以通过参数二级指针返回
{
	struct node* temp = node->next;//用临时temp指针保存下一个节点的地址，等下要返回
	//使得要删除节点的 下一个节点的prv指针 指向要删除节点的前一个节点

	//问题？：为啥要传要删除节点的 下一个节点的prv指针的地址？不是有吗？node->next->prv这个不是吗
	
	if (p_prv)//如有有前一个节点
	{
		*p_prv = node->prv;//链上上一个
	}
	free(node);
	return temp;
}

//指定位置删除
void del_pos(struct dlist* list, int pos)
{
	struct node* p = list->p_head;
	//prv前节点 next后节点
	//指定位置删除待优化，先使用基础遍历版本
	for (int i = 0; i < pos-1; i++)
	{
		p = p->next;
		//待优化（已优化）
		if (p== NULL)
		{
			printf("要删除的pos位置超出链表节点数\n");
			return;
		}
	}
	struct node* p_prv = NULL;//先定义一个前节点
	struct node* p_next = delete_node(p, &p_prv);//返回后一个节点
												 //前节点的next链接后节点
	if (p_prv)//如果前节点不为空
	{
		p_prv->next = p_next;
	}
	else//如果没有前节点则p_head指向后节点
	{
		list->p_head = p_next;
	}
	//后节点的prv链接前节点
	if (p_next)
	{
		p_next->prv = p_prv;
	}
	else//如果没有后节点则p_end指向前节点
	{
		list->p_end = p_prv;
	}
}

//指定位置删除version 1.1,不使用函数封装返回前后节点的方法，更简明清晰
void del_pos_v1(struct dlist* list, int pos)
{
	struct node* p = list->p_head;
	//prv前节点 next后节点
	//指定位置删除待优化，先使用基础遍历版本
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
		//待优化（已优化）
		if (p == NULL)
		{
			printf("要删除的pos位置超出链表节点数\n");
			return;
		}
	}
	struct node* p_prv = p->prv;//找到p的前节点
	struct node* p_next = p->next;//找到p的后节点
	if (p_prv)//如果前节点不为空
	{
		p_prv->next = p_next;
	}
	else//如果没有前节点则p_head指向后节点
	{
		list->p_head = p_next;
	}
	//后节点的prv链接前节点
	if (p_next)
	{
		p_next->prv = p_prv;
	}
	else//如果没有后节点则p_end指向前节点
	{
		list->p_end = p_prv;
	}

}
//查找节点
int find_node(struct dlist* list, int data)
{
	int pos = 1;
	struct node* p = list->p_head;
	while (p)
	{
		if (p->ID == data)
		{
			return pos;
		}
		p = p->next;
		pos++;
	}
	return 0;
}
//改变节点
void change_node(struct dlist* list, int data, int new_data)
{
	struct node* p = list->p_head;
	while (p)
	{
		if (p->ID == data)
		{
			p->ID = new_data;
		}
		p = p->next;
	}
}
//头删法
void del_head(struct dlist* list)
{
	if (isempty(list))
	{
		printf("没有节点\n");
		return ;
	}
	struct node* p_prv = NULL;//先定义一个前节点
	struct node* p_next = delete_node(list->p_head, &p_prv);//返回后一个节点
	list->p_head = p_next;//头部指针移向下一个节点
	if (list->p_head)//至少有2个节点以上，删了一个还有一个以上
	{
		list->p_head->prv = NULL;
	}
	else//仅有的一个节点也被删除了
	{
		//list->p_end = NULL;
		list->p_end = list->p_head;//上下都行
	}
}
//尾删法
void del_end(struct dlist* list)
{
	if (isempty(list))
	{
		printf("没有节点\n");
		return;
	}
	struct node* p_prv = NULL;//先定义一个前节点
	struct node* p_next = delete_node(list->p_end, &p_prv);//返回后一个节点
	list->p_end = p_prv;//尾部指针指向前一个节点
	if (list->p_end)//至少有2个节点以上，删了一个还有一个以上
	{
		list->p_end->next = NULL;
	}
	else // 仅有的一个节点也被删除了
	{
		list->p_head = NULL;
	}
}

//头插法
void insert_head(struct dlist* list, int data)
{
	list->p_head=creat_data(data, list->p_head, NULL);

	if (list->p_head->next)
	{
		list->p_head->next->prv = list->p_head;//后一个节点的prv链上p_head
	}
	else//如果插入后只有一个节点，就将p_end指向p_head的同一个节点
	{
		list->p_end = list->p_head;
	}
}