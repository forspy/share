#pragma once
#define MAXSIZE 100

#define WIDTH 30//每一个格子的高度和宽度
#define HEIGHT 30
typedef enum
{
	//easyx 给出的方向键的值
	UP=72,
	DOWN=80,
	LEFT=75,
	RIGHT=77
}CH;
//蛇的坐标	
typedef struct
{
	int col;//横轴坐标
	int row;//纵轴坐标
}point;
typedef struct
{
	point pt[MAXSIZE];//每一截蛇是一个坐标，因此形成了一个数组
	int len;//蛇的长度
	CH ch;//蛇的方向,ch的值从enum类型里面选择
}snake;
//食物
typedef struct
{
	point f_pt;//食物的坐标
}food;




//1.初始化游戏
void init();
//2.绘制游戏
void gameprint();
//随机产生一个食物
void snakefood();
//3.玩游戏
void playgame();
//移动蛇
void snakemove();
//4.游戏判断
void game_judgement();
//写入存档
void save_record();
//读取存档
void load_record();
//my_sleep函数 用于键盘响应时跳出sleep函数
void my_sleep(double  n);
//写入最高成绩者姓名
void save_player();
//读取最高成绩者姓名
void load_player();
//载入ai蛇-----
void ai_init();//ai_snake
void ai_snakemove();
void ai_game_judgement();
//-------

//载入简单模式
void set_background_2_1();
//载入中等模式
void set_background_2_2();
//载入困难模式
void set_background_2_3();
//开始界面及设定
void set_background();
//设置ai蛇的条数和总体速度
void deside();