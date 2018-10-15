#include"snake.h"
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
extern TCHAR playername[11];//playername成为一个全局共享变量，全局变量会自动赋值为0不需要另外赋值
extern IMAGE img;

int main()
{
	
	set_background();
	
	loadimage(&img, L"./source/Grassland.jpg", 20 * WIDTH, 20 * WIDTH);
	
	InputBox(playername, 11, L"请输入参赛名");
	srand((unsigned)time(NULL));
	init();
	ai_init();
	//绘制游戏
	//gameprint();
	playgame();
	//在发布release版本的时候选择多线程MT(project 属性，c/c++->代码生成)（静态库加载）（MD为多线程DLL动态库加载）,静态库动态库加载，待研究
}