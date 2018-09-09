//树是一种组织数据的方式
//比如：文件夹->子文件夹->文件
//比如：二叉树
//   根节点T_node
//    /  \
//   /    \
//子节点A  子节点B
//通用树形结构设计（链表法）
/* __________
   |        |
   |  宿主  |
   |        |
   |________|
   | 树节点 |
   |________|
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LINK_TO_ELEM(link_ptr,elem_type,mem_name) ((elem_type*)(((unsigned char*)link_ptr)-(int)(&(((elem_type*)NULL)->mem_name))))
struct tree_link
{
	struct tree_link* parent;//指向自己的父亲
	struct tree_link* children;//指向自己的孩子，链表头
	struct tree_link* brother;//指向自己的兄弟
};

//ps:也可以用动态数组的方式

struct item_node
{
	int num;
	char name[50];
	struct tree_link link;
};

struct item_node* alloc_item_node(const char* name);
void link_parent(struct tree_link* link, struct tree_link* parent);//在子节点的兄弟节点的下一个插入节点
void trans_tree(struct tree_link* root);//先遍历根节点，后遍历字节点，先序递归
int main()
{
	struct tree_link* tree_root = NULL;
	struct item_node* root = alloc_item_node("A");//定义根树宿主A
	//tree_root = &root->link;

	struct item_node* node;
	node = alloc_item_node("B");//定义子树宿主B
	struct item_node* node_b = node;
	link_parent(&node->link, &root->link);

	node = alloc_item_node("C");
	link_parent(&node->link, &root->link);

	node = alloc_item_node("D");
	link_parent(&node->link, &root->link);
	//-------------------------------------B节点的子树
	
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

void link_parent(struct tree_link* link, struct tree_link* parent)//link表示要插入的节点，parent表示父节点
{
	link->parent = parent;//1式
	if (parent == NULL)
		return;
	struct tree_link** walk = &parent->children;//这里=link是否可以？不可以link是随机插入的节点，walk是要从子节点的头部开始遍历
	while (*walk)
	{
		walk = &(*walk)->brother;//与1式的原理一样（*walk）是一个节点，与link一样
	}
	*walk = link;
}

void trans_tree(struct tree_link* root)//先遍历根节点，后遍历字节点，先序递归
{
	struct item_node* node = LINK_TO_ELEM(root, struct item_node, link);
	printf("%s\n", node->name);
	//递归遍历所有子树
	struct tree_link* walk = root->children;
	while (walk)
	{
		trans_tree(walk);
		walk = walk->brother;
	}
}