#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"hash_table.h"
//����hash����
struct hash_table* create_hash_table(int n)
{
	struct hash_table* t = (struct hash_table*)malloc(sizeof(struct hash_table));//��������ѽ��ʵ����ֻ������4�ֽڣ�����ָ��Ҳ��ָ�룩+4�ֽ�(int)�����Զ���ָ��������Ҫ���������ڴ�
	memset(t, 0, sizeof(struct hash_table));
	t->hash_set = malloc(n * sizeof(struct hash_node*));//��������һ��n�����ϵ�����ͷָ��Ŀռ䣬ΪʲôҪ�������ٿռ䣬��������ѽ�� sizeof(struct hash_node*)ָ����һ��ָ�룬һ��n��ָ��
	memset(t->hash_set, 0, n * sizeof(struct hash_node*));
	t->n = n;
	return t;
}
//�ͷ�hash����,ɾ�����е�Ԫ��
void destroy_hash_table(struct hash_table* t)
{
	//1.��ɾ��������ʹ��malloc�����Ľڵ��key
	hash_clear(t);
	//2.��ɾ��hash_set���ٵ�n������
	if (t->hash_set)
	{
		free(t->hash_set);
		t->hash_set = NULL;
	}
	//3.���ɾ��t���ٵ�8���ֽ� 
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


//hash���룬����һ��key��value�����ж����ظ���������ͷ������
void hash_insert(struct hash_table* t, char* key, void* value)
{
	//������һ��hash�ڵ�
	struct hash_node* node = (struct hash_node*)malloc(sizeof(struct hash_node));
	memset(node, 0, sizeof(struct hash_node));
	//�ַ������ƣ�ע������key��һ��ָ�룬����strup�ڶ��Ͽ��ٿռ䣬��Ϊ���ٿռ��ʱ�������char������п���
	//ֻ����������ָ��Ŀռ�һ��12�ֽ�ɾ��ʱע����Ҫ������node->key�����ͷ�
	node->key = strdup(key);
	node->value = value;//������Ϣ����

	unsigned int index = hash_index(key)%t->n;//ʹ��hash�㷨������key�����ĸ�����

	struct hash_node* header = t->hash_set[index];//1.t->hash_set[index]��ʾһ��ָ�����������һ��ָ�룬walk��ʾͷָ��ָ�����λ��
	//2.ͨ��t���ʵ���main �е�hash_set���ı���main�е�hash_set��ָ��
	//����ͷ�巨
	node->next = header;//����t->hash_set[index]��һ����ַ
	t->hash_set[index] = node;//����t->hash_set[index]��һ��������ָ�룩
}
//hash���룬������һ����ͬ��key��ʱ�򣬲���ͷ�����룬���Ǹ������key��Ӧ������
void hash_set(struct hash_table* t, char* key, void* value)
{
	//1.���key���index�����ĸ�����
	unsigned int index = hash_index(key) % t->n;//ʹ��hash�㷨������key�����ĸ�����

	//2.��Ϊ��Ҫ�ж�keyֵ�Ƿ���ͬ��������Ҫʹ�ö���ָ�����һ�鵥�����ı������е�ֵ
	struct hash_node** walk = &(t->hash_set[index]);
	//����
	while (*walk)
	{
		if (strcmp((*walk)->key, key) == 0)
		{
			(*walk)->value = value;
			return;
		}
		walk = &((*walk)->next);
	}
	//3.������ɺ���û�У�����Ҫ��������ڵ㣬����ʹ��ͷ�巨
	//������һ��hash�ڵ�
	struct hash_node* node = (struct hash_node*)malloc(sizeof(struct hash_node));
	memset(node, 0, sizeof(struct hash_node));
	//ע������key��һ��ָ�룬����strup�ڶ��Ͽ��ٿռ䣬��Ϊ���ٿռ��ʱ�������char������п���
	//ֻ����������ָ��Ŀռ�һ��12�ֽ�ɾ��ʱע����Ҫ������node->key�����ͷ�
	node->key = strdup(key);//�ַ������ƣ�strdup�൱����malloc,��strcpy
	node->value = value;//������Ϣ����

	struct hash_node* header = t->hash_set[index];//1.t->hash_set[index]��ʾһ��ָ�����������һ��ָ�룬walk��ʾͷָ��ָ�����λ��
												  //2.ͨ��t���ʵ���main �е�hash_set���ı���main�е�hash_set��ָ��
												  //����ͷ�巨
	node->next = header;//����t->hash_set[index]��һ����ַ
	t->hash_set[index] = node;//����t->hash_set[index]��һ��������ָ�룩

	//�����ʹ��ͷ���ʹ��β��Ļ�����: *walk=node; ��Ϊ�ղű�����ʱ��*walk�Ѿ��ߵ���NULL
}
//hash����
void* hash_find(struct hash_table* t, char* key)
{
	//1.���key���index�����ĸ�����
	unsigned int index = hash_index(key) % t->n;//ʹ��hash�㷨������key�����ĸ�����
	//2.��������
	struct hash_node* walk = t->hash_set[index];//��Ϊ����ֻ��Ҫ���Ҷ�����Ҫ�ı���������ֻʹ��һ��ָ���������
	//����
	while (walk)
	{
		if (strcmp(walk->key, key) == 0)
			return walk->value;
		walk = walk->next;
	}
	//û���ҵ��򷵻�NULL
	return NULL;
}

//ɾ��hash���е���
void hash_delete(struct hash_table* t, char* key)
{
	//1.���key���index�����ĸ�����
	unsigned int index = hash_index(key) % t->n;//ʹ��hash�㷨������key�����ĸ�����

	//2.��Ϊ��Ҫ�ı�����������Ҫʹ�ö���ָ�����һ�鵥�����ж�keyֵ�Ƿ���ͬ��ɾ�������еĽڵ�
	struct hash_node** walk = &(t->hash_set[index]);

	//3.����ɾ���ڵ㲢�ͷ�
	while (*walk)
	{
		if (strcmp((*walk)->key, key) == 0)//���ʹ��hash_insert�п���һ��key��Ӧ���value
		{
			struct hash_node* temp = *walk;
			*walk = (*walk)->next;
			temp->next = NULL;
			free(temp->key);//��free strdup���ٳ�����key
			free(temp);//��free�����Ľڵ�
		}
		else
			walk = &((*walk)->next);//if�е�*walk = (*walk)->next;�б����ĸ���Ч�����������������Ҫelse
	}
}

//ɾ��hash��׼��������ɾ�������е�ÿ���ڵ�Ͷ�Ӧ��key
void hash_clear(struct hash_table* t)//ע�⣬����������Ҫÿ���ڵ�һ��һ��ɾ����˭�����˿ռ��ɾ����Ӧ��ָ��
{
	//1.������ͬ�ļ���
	for (int i = 0; i < t->n; i++)
	{
		//2.����ĳ�������е�����,��ɾ��key�ͽڵ�
		struct hash_node* walk = t->hash_set[i];
		while (walk)
		{
			struct hash_node* temp = walk;
			walk = walk->next;
			temp->next = NULL;
			//ɾ��key�ͽڵ�
			free(temp->key);
			free(temp);
		}
	}
}

//��ʾhash�������Ԫ��
//����һ��key���϶�Ӧ������֣����Ը���key���Ƴ����Ʋ�����
void show_all(struct hash_table* t)
{
	//1.������ͬ�ļ���
	for (int i = 0; i < t->n; i++)
	{
		printf("��%d�����ϣ�", i);
		//2.����һ�����ϵ�����
		struct hash_node* walk = t->hash_set[i];
		while (walk)
		{
			printf("%d->", (int)(walk->value));
			walk = walk->next;
		}
		printf("\n");
	}
}
