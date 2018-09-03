#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"link_list.h"
//动态数组在增加或删除一个数的时候需要移动整个数列，扩容时还需要复制原数列，因此列表出现了，解决这个问题
struct link_node
{
	struct link_node* next;
};
typedef struct link_node* list_head;
struct rect
{
	int x;
	int y;
	int w;
	int h;
};
struct circle
{
	int x;
	int y;
	int r;
};
struct shape
{
	int type;
	int order;//编号
	union
	{
		struct rect r;
		struct circle c;
	}u;
	struct link_node link;
};

struct shape* alloc_shape();
void free_shape(struct shape* s);
void list_insert_head(struct link_node** walk, struct link_node* node);//头插入节点
void list_insert_tail(struct link_node** walk, struct link_node* node);//尾部插入节点
void list_remove(struct link_node** walk, struct link_node* node);//删除节点
int main()
{
	struct link_node* head=NULL;//链表头

	//头部（下面）插入节点
	struct shape* s = alloc_shape();
	s->order = 1;
	list_insert_head(&head, &s->link);//->的优先级比&高，要改变实参内存的值需要传入对应的地址
	//头部（下面）继续插入节点
	s = alloc_shape();
	s->order = 2;
	list_insert_head(&head, &s->link);
	//尾部（下面）插入节点
	s = alloc_shape();
	s->order = 3;
	list_insert_tail(&head, &s->link);
	


	//遍历链表里所有的元素
	struct link_node* pointer = head;
	while (pointer)//有节点
	{
		//访问这个节点
		//基地址+offset=&（基地址->成员），当基地址=0时，offset=&（NULL->成员）
		struct shape* elem = (struct shape*)((char*)pointer - (int)(&(((struct shape*)NULL)->link)));
		printf("elem->order=%d\n", elem->order);

		pointer = pointer->next;
	}
	printf("-----------------------\n");
	//删掉一个节点
	list_remove(&head, &s->link);

	//遍历链表里所有的元素
	struct link_node* pointer1 = head;
	while (pointer1)//有节点
	{
		//访问这个节点
		//基地址+offset=&（基地址->成员），当基地址=0时，offset=&（NULL->成员）
		struct shape* elem = (struct shape*)((char*)pointer1 - (int)(&(((struct shape*)NULL)->link)));
		printf("elem->order=%d\n", elem->order);

		pointer1 = pointer1->next;
	}
}

struct shape* alloc_shape()
{
	struct shape* s = malloc(sizeof(struct shape));
	memset(s, 0, sizeof(struct shape));
	return s;
}
void free_shape(struct shape* s)
{
	free(s);
}
void list_insert_head(struct link_node** walk, struct link_node* node)//头插入节点
{
	//struct link_node** walk = header;//walk相当于temp中间变量，用于改变链向
	node->next = *walk;
	*walk = node;
}
void list_insert_tail(struct link_node** walk, struct link_node* node)//尾部插入节点
{
	while (*walk)
	{
		walk = &((*walk)->next);
	}
	*walk = node;
	node->next = NULL;
}
//移除一个节点
void list_remove(struct link_node** walk, struct link_node* node)
{
	while (*walk)
	{
		if (*walk == node)
		{
			*walk = node->next;
			node->next = NULL;
			return;//跳出
		}
		walk = &((*walk)->next);
	}
}