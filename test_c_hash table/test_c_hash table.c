#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hash_table.h"
//hash算法的目的是为了快速查找
//key-->value(数据信息)
//1.如何根据key分集合？ 
//2.怎么分能够相对比较均匀？
//3.如何根据在集合内找key？
//4.如何用链表把集合内的节点串联起来？
//HASH哈希算法
//(1).将一个字符串-->整数  然后将这个整数%N 得到的值位于[0，N-1]之间 只要字符串很多就能形成[0,N-1]的集合序列号，形成一个数组
//(2).对于不同的字符串，我们要尽可能生成不同的key； 通过hash散列，要散的足够均匀 例如"hello"-->3 "hellm"-->5
int main()
{
	struct hash_table* t = create_hash_table(3);//创建3个集合,创建集合越多散列越平均,开销只增加4*n个
	//插入
	//注意void*可以转成多种类型而不失真，因此可以使用void*类型保存数据
	hash_insert(t, "xiaoming", (void*)12);
	hash_insert(t, "xiaohong", (void*)36);
	//插入或覆盖
	hash_set(t, "xiaohong", (void*)999);
	hash_set(t, "xiaowang", (void*)39);
	hash_set(t, "xiaoqiu", (void*)30);
	hash_set(t, "xiaohu", (void*)20);
	//查找
	int ret = (int)hash_find(t, "xiaoming");
	printf("xiaoming=%d\n", ret);
	ret = (int)hash_find(t, "xiaohong");
	printf("xiaohong=%d\n", ret);
	//找不到
	ret = (int)hash_find(t, "xiaozhang");
	printf("xiaozhang=%d\n", ret);
	/*
	//如果想输入其他要素比如可以在hash_node结构中增加成员，也可以使用新key结合void*类型输入
	hash_insert(t, "xiaoming_address", (void*)"shanghai");
	char* address = (void*)hash_find(t, "xiaoming_address");
	printf("xiaoming_address=%s\n", address);
	*/
	//根据key删除所有该key对应的值（通过hash_insert插入而没有覆盖）
	hash_delete(t, "xiaoming");
	ret = (int)hash_find(t, "xiaoming");
	printf("xiaoming=%d\n", ret);

	show_all(t);
	//删除整个hash表
	destroy_hash_table(t);
}