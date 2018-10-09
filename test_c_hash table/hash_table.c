#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hash_table.h"
//����hash����
struct hash_table* create_hash_table(int n)
{
	struct hash_table* t = (struct hash_table*)malloc(sizeof(struct hash_table));//��������ѽ��ʵ����ֻ������4�ֽڣ�����ָ��Ҳ��ָ�룩+4�ֽ�(int)�����Զ���ָ��������Ҫ���������ڴ�
	memset(t, 0, sizeof(struct hash_table));
	t->hash_set = malloc(n * sizeof(struct hash_node*));//��������һ��n�����ϵ�����ͷָ��Ŀռ䣬ΪʲôҪ�������ٿռ䣬��������ѽ��
	memset(t->hash_set, 0, n * sizeof(struct hash_node*));
	t->n = n;
	return t;
}
//�ͷ�hash����,ɾ�����е�Ԫ��
void destroy_hash_table(struct hash_table* t)
{
	if (t->hash_set)
	{
		free(t->hash_set);
		t->hash_set = NULL;
	}
	free(t);
}
//hash�㷨
unsigned int hash_index(char *str)
{
	register unsigned int h;
	register unsigned char *p;

	for (h = 0, p = (unsigned char *)str; *p; p++)
		h = 31 * h + *p;

	return h;
}


//hash���룬����һ��key��value�����ж����ظ�
void hash_insert(struct hash_table* t, char* key, void* value)
{
	//������һ��hash�ڵ�
	struct hash_node* node = (struct hash_node*)malloc(sizeof(struct hash_node));
	memset(node, 0, sizeof(struct hash_node));

	node->key = strup(key);//�ַ�������
	node->value = value;//������Ϣ����

	unsigned int index = hash_index(key)%t->n;//ʹ��hash�㷨������key�����ĸ�����

}