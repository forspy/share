#pragma once
#define SIZE 100
//初始化
void init();
//载入图片
void loadpicture();
//贴图
void drawpicture();
//玩游戏
void playgame();
//交换
void my_swap(int row, int col, int a, int b);
//判断是否越界
bool is_cross(int row, int col);
//判断胜利条件
bool is_win();