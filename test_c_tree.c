//����һ����֯���ݵķ�ʽ
//���磺�ļ���->���ļ���->�ļ�
//���磺������
//   ���ڵ�T_node
//    /  \
//   /    \
//�ӽڵ�A  �ӽڵ�B
//ͨ�����νṹ��ƣ�������
/* __________
   |        |
   |  ����  |
   |        |
   |________|
   | ���ڵ� |
   |________|
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LINK_TO_ELEM(link_ptr,elem_type,mem_name) ((elem_type*)(((unsigned char*)link_ptr)-(int)(&(((elem_type*)NULL)->mem_name))))
struct tree_link
{
	struct tree_link* parent;//ָ���Լ��ĸ���
	struct tree_link* children;//ָ���Լ��ĺ��ӣ�����ͷ
	struct tree_link* brother;//ָ���Լ����ֵ�
};

//ps:Ҳ�����ö�̬����ķ�ʽ

struct item_node
{
	int num;
	char name[50];
	struct tree_link link;
};

struct item_node* alloc_item_node(const char* name);
void link_parent(struct tree_link* link, struct tree_link* parent);//���ӽڵ���ֵܽڵ����һ������ڵ�
void trans_tree(struct tree_link* root);//�ȱ������ڵ㣬������ֽڵ㣬����ݹ�
int main()
{
	struct tree_link* tree_root = NULL;
	struct item_node* root = alloc_item_node("A");//�����������A
	//tree_root = &root->link;

	struct item_node* node;
	node = alloc_item_node("B");//������������B
	struct item_node* node_b = node;
	link_parent(&node->link, &root->link);

	node = alloc_item_node("C");
	link_parent(&node->link, &root->link);

	node = alloc_item_node("D");
	link_parent(&node->link, &root->link);
	//-------------------------------------B�ڵ������
	
	node = alloc_item_node("E");
	link_parent(&node->link, &node_b->link);

	node = alloc_item_node("F");
	link_parent(&node->link, &node_b->link);

	trans_tree(&root->link);
}

struct item_node* alloc_item_node(const char* name)
{
	struct item_node* node = (struct item_node*)malloc(sizeof(struct item_node));
	memset(node, 0, sizeof(struct item_node));
	strcpy(node->name, name);
	return node;
}

void link_parent(struct tree_link* link, struct tree_link* parent)//link��ʾҪ����Ľڵ㣬parent��ʾ���ڵ�
{
	link->parent = parent;//1ʽ
	if (parent == NULL)
		return;
	struct tree_link** walk = &parent->children;//����=link�Ƿ���ԣ�������link���������Ľڵ㣬walk��Ҫ���ӽڵ��ͷ����ʼ����
	while (*walk)
	{
		walk = &(*walk)->brother;//��1ʽ��ԭ��һ����*walk����һ���ڵ㣬��linkһ��
	}
	*walk = link;
}

void trans_tree(struct tree_link* root)//�ȱ������ڵ㣬������ֽڵ㣬����ݹ�
{
	struct item_node* node = LINK_TO_ELEM(root, struct item_node, link);
	printf("%s\n", node->name);
	//�ݹ������������
	struct tree_link* walk = root->children;
	while (walk)
	{
		trans_tree(walk);
		walk = walk->brother;
	}
}