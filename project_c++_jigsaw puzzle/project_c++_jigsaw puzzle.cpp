#include<stdio.h>
#include<graphics.h>
#include"jigsaw puzzle.h"


int main()
{
	initgraph(3*SIZE, 3*SIZE);
	init();
	playgame();
	getchar();
	closegraph();
}