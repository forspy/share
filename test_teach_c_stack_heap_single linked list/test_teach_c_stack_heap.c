#include<stdio.h>
#include"stack.h"
//�����ջָ�������ݽṹ�����ϵ�ջ���ǹ����ջ
int main()
{
	struct stack stack;
	init(&stack);
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	pop(&stack);
	//pop_all(&stack);
	int value=get_top(&stack);
	printf("ջ��Ԫ��Ϊ%d\n", value);
	show(&stack);
}