#include"snake.h"
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main()
{
	
	initgraph(20 * WIDTH, 20 * HEIGHT);//(窗口标题名称要改，待完善)
	srand((unsigned)time(NULL));
	init();
	//绘制游戏
	//gameprint();
	playgame();
	//在发布release版本的时候选择多线程MT(project 属性，c/c++->代码生成)（静态库加载）（MD为多线程DLL动态库加载）,静态库动态库加载，待研究
}