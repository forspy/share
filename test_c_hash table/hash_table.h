#pragma once
//hash节点
struct hash_node
{
	char* key;
	void* value;

	struct hash_node* next;
};
/*
struct hash_table
{
	struct hash_node* hash_set[100];//如果写成这样，直接能开出400字节的内存
};
*/
struct hash_table
{
	struct hash_node* *hash_set;//每个集合的链表头指针，相当于struct hash_node* hash_set[n],指针数组
	int n;//表示有多少个集合
};
//hash算法
unsigned int hash_index(char *str);

//分集合
struct hash_table* create_hash_table(int n);//n表示分成几个集合

//删除hash表准备工作：删除集合中的每个节点和对应的key
void hash_clear(struct hash_table* t);
//删除整个hash表
void destroy_hash_table(struct hash_table* t);

//hash查找
void* hash_find(struct hash_table* t,char* key);

//删除hash表中的项
void hash_delete(struct hash_table* t, char* key);

//hash插入，插入一个key和value，不判断有重复
void hash_insert(struct hash_table* t, char* key, void* value);

//hash插入或更改，插入/更改一个key和value，重复就更改	
void hash_set(struct hash_table* t, char* key, void* value);
//显示所有节点
void show_all(struct hash_table* t);
