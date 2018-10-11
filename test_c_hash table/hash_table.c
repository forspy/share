#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hash_table.h"
//创建hash集合
struct hash_table* create_hash_table(int n)
{
	struct hash_table* t = (struct hash_table*)malloc(sizeof(struct hash_table));//待解决？已解决实际上只开辟了4字节（二级指针也是指针）+4字节(int)，所以对于指针数组需要继续开辟内存
	memset(t, 0, sizeof(struct hash_table));
	t->hash_set = malloc(n * sizeof(struct hash_node*));//用来开辟一共n个集合的链表头指针的空间，为什么要继续开辟空间，待解决？已解决 sizeof(struct hash_node*)指的是一个指针，一共n个指针
	memset(t->hash_set, 0, n * sizeof(struct hash_node*));
	t->n = n;
	return t;
}
//释放hash集合,删掉所有的元素
void destroy_hash_table(struct hash_table* t)
{
	//1.先删除集合内使用malloc创建的节点和key
	hash_clear(t);
	//2.再删除hash_set开辟的n个集合
	if (t->hash_set)
	{
		free(t->hash_set);
		t->hash_set = NULL;
	}
	//3.最后删除t开辟的8个字节 
	free(t);
}
//hash算法
unsigned int hash_index(char *str)
{
	register unsigned int h;
	register unsigned char *p;

	for (h = 0, p = (unsigned char *)str; *p; p++)
		h = 31 * h + *p;

	return h;
}


//hash插入，插入一个key和value，不判断有重复，反复再头部插入
void hash_insert(struct hash_table* t, char* key, void* value)
{
	//先申请一个hash节点
	struct hash_node* node = (struct hash_node*)malloc(sizeof(struct hash_node));
	memset(node, 0, sizeof(struct hash_node));
	//字符串复制，注意这里key是一个指针，是用strup在堆上开辟空间，因为开辟空间的时候不是针对char数组进行开辟
	//只开辟了三个指针的空间一共12字节删除时注意需要单独对node->key进行释放
	node->key = strdup(key);
	node->value = value;//具体信息复制

	unsigned int index = hash_index(key)%t->n;//使用hash算法来返回key属于哪个集合

	struct hash_node* header = t->hash_set[index];//1.t->hash_set[index]表示一个指针数组的其中一个指针，walk表示头指针指向这个位置
	//2.通过t访问到了main 中的hash_set，改变了main中的hash_set的指向
	//链表头插法
	
	//node->next = header;//这里t->hash_set[index]是一个地址(辅助代码，表示这样也行，更容易理解)
	//指针在右值和左值表示的意义不同，在右值表示地址，在左值表示变量
	//普通变量在左值和在右值时的意义也不一样，在右值表示值，在左值表示变量
	node->next = t->hash_set[index];//这里t->hash_set[index]是一个地址
	t->hash_set[index] = node;//这里t->hash_set[index]是一个变量（指针）
}
//hash插入，当输入一个相同的key的时候，不在头部插入，而是覆盖这个key对应的内容
void hash_set(struct hash_table* t, char* key, void* value)
{
	//1.针对key求得index属于哪个集合
	unsigned int index = hash_index(key) % t->n;//使用hash算法来返回key属于哪个集合

	//2.因为需要判断key值是否相同，所以需要使用二阶指针遍历一遍单链表，改变链表中的值
	struct hash_node** walk = &(t->hash_set[index]);
	//遍历
	while (*walk)
	{
		if (strcmp((*walk)->key, key) == 0)
		{
			(*walk)->value = value;
			return;
		}
		walk = &((*walk)->next);
	}
	//3.遍历完成后发现没有，则需要重新申请节点，这里使用头插法
	//先申请一个hash节点
	struct hash_node* node = (struct hash_node*)malloc(sizeof(struct hash_node));
	memset(node, 0, sizeof(struct hash_node));
	//注意这里key是一个指针，是用strup在堆上开辟空间，因为开辟空间的时候不是针对char数组进行开辟
	//只开辟了三个指针的空间一共12字节删除时注意需要单独对node->key进行释放
	node->key = strdup(key);//字符串复制，strdup相当于先malloc,再strcpy
	node->value = value;//具体信息复制

	struct hash_node* header = t->hash_set[index];//1.t->hash_set[index]表示一个指针数组的其中一个指针，walk表示头指针指向这个位置
												  //2.通过t访问到了main 中的hash_set，改变了main中的hash_set的指向
												  //链表头插法
	node->next = header;//这里t->hash_set[index]是一个地址
	t->hash_set[index] = node;//这里t->hash_set[index]是一个变量（指针）

	//如果不使用头插而使用尾插的话就是: *walk=node; 因为刚才遍历的时候*walk已经走到了NULL
}
//hash查找
void* hash_find(struct hash_table* t, char* key)
{
	//1.针对key求得index属于哪个集合
	unsigned int index = hash_index(key) % t->n;//使用hash算法来返回key属于哪个集合
	//2.遍历查找
	struct hash_node* walk = t->hash_set[index];//因为这里只需要查找而不需要改变链表，所以只使用一阶指针遍历就行
	//遍历
	while (walk)
	{
		if (strcmp(walk->key, key) == 0)
			return walk->value;
		walk = walk->next;
	}
	//没有找到则返回NULL
	return NULL;
}

//删除hash表中的项
void hash_delete(struct hash_table* t, char* key)
{
	//1.针对key求得index属于哪个集合
	unsigned int index = hash_index(key) % t->n;//使用hash算法来返回key属于哪个集合

	//2.因为需要改变链表，所以需要使用二阶指针遍历一遍单链表，判断key值是否相同，删除链表中的节点
	struct hash_node** walk = &(t->hash_set[index]);

	//3.遍历删除节点并释放
	while (*walk)
	{
		if (strcmp((*walk)->key, key) == 0)//如果使用hash_insert有可能一个key对应多个value
		{
			struct hash_node* temp = *walk;
			*walk = (*walk)->next;
			temp->next = NULL;
			free(temp->key);//先free strdup开辟出来的key
			free(temp);//再free孤立的节点
		}
		else
			walk = &((*walk)->next);//if中的*walk = (*walk)->next;有遍历的附加效果，所以这里遍历需要else
	}
}

//删除hash表准备工作：删除集合中的每个节点和对应的key
void hash_clear(struct hash_table* t)//注意，对于链表需要每个节点一个一个删除，谁开辟了空间就删除对应的指针
{
	//1.遍历不同的集合
	for (int i = 0; i < t->n; i++)
	{
		//2.遍历某个集合中的链表,并删除key和节点
		struct hash_node* walk = t->hash_set[i];
		while (walk)
		{
			struct hash_node* temp = walk;
			walk = walk->next;
			temp->next = NULL;
			//删除key和节点
			free(temp->key);
			free(temp);
		}
	}
}

//显示hash表的所有元素
//但是一个key集合对应多个名字，所以根据key逆推出名称不可行
void show_all(struct hash_table* t)
{
	//1.遍历不同的集合
	for (int i = 0; i < t->n; i++)
	{
		printf("第%d个集合：", i);
		//2.遍历一个集合的链表
		struct hash_node* walk = t->hash_set[i];
		while (walk)
		{
			printf("%d->", (int)(walk->value));
			walk = walk->next;
		}
		printf("\n");
	}
}
