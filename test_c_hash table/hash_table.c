#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hash_table.h"
//创建hash集合
struct hash_table* create_hash_table(int n)
{
	struct hash_table* t = (struct hash_table*)malloc(sizeof(struct hash_table));//待解决？已解决实际上只开辟了4字节（二级指针也是指针）+4字节(int)，所以对于指针数组需要继续开辟内存
	memset(t, 0, sizeof(struct hash_table));
	t->hash_set = malloc(n * sizeof(struct hash_node*));//用来开辟一共n个集合的链表头指针的空间，为什么要继续开辟空间，待解决？已解决
	memset(t->hash_set, 0, n * sizeof(struct hash_node*));
	t->n = n;
	return t;
}
//释放hash集合,删掉所有的元素
void destroy_hash_table(struct hash_table* t)
{
	if (t->hash_set)
	{
		free(t->hash_set);
		t->hash_set = NULL;
	}
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


//hash插入，插入一个key和value，不判断有重复
void hash_insert(struct hash_table* t, char* key, void* value)
{
	//先申请一个hash节点
	struct hash_node* node = (struct hash_node*)malloc(sizeof(struct hash_node));
	memset(node, 0, sizeof(struct hash_node));

	node->key = strup(key);//字符串复制
	node->value = value;//具体信息复制

	unsigned int index = hash_index(key)%t->n;//使用hash算法来返回key属于哪个集合

}