#include<stdio.h>
#include"stack.h"
//这里的栈指的是数据结构意义上的栈，是广义的栈
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
	printf("栈顶元素为%d\n", value);
	show(&stack);
}