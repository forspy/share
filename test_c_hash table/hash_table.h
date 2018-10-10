#pragma once
//hash�ڵ�
struct hash_node
{
	char* key;
	void* value;

	struct hash_node* next;
};
/*
struct hash_table
{
	struct hash_node* hash_set[100];//���д��������ֱ���ܿ���400�ֽڵ��ڴ�
};
*/
struct hash_table
{
	struct hash_node* *hash_set;//ÿ�����ϵ�����ͷָ�룬�൱��struct hash_node* hash_set[n],ָ������
	int n;//��ʾ�ж��ٸ�����
};
//hash�㷨
unsigned int hash_index(char *str);

//�ּ���
struct hash_table* create_hash_table(int n);//n��ʾ�ֳɼ�������

//ɾ��hash��׼��������ɾ�������е�ÿ���ڵ�Ͷ�Ӧ��key
void hash_clear(struct hash_table* t);
//ɾ������hash��
void destroy_hash_table(struct hash_table* t);

//hash����
void* hash_find(struct hash_table* t,char* key);

//ɾ��hash���е���
void hash_delete(struct hash_table* t, char* key);

//hash���룬����һ��key��value�����ж����ظ�
void hash_insert(struct hash_table* t, char* key, void* value);

//hash�������ģ�����/����һ��key��value���ظ��͸���	
void hash_set(struct hash_table* t, char* key, void* value);
//��ʾ���нڵ�
void show_all(struct hash_table* t);
