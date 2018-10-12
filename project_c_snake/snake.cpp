#include "snake.h"
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>//easyx图形库文件
#include<time.h>
#include <conio.h>//检测键盘是否按下
#include<string.h>
//-----音乐头文件
#include<mmsystem.h>//头文件
#pragma comment(lib,"winmm.lib")//多媒体库
//-----
//定义全局变量
snake s;//蛇
food f;//食物
//产生随机数种子
//1.初始化
void init()
{
	//---播放音乐
	mciSendString(L"open ./source/bird.mp3", 0, 0, 0);//打开音乐
	mciSendString(L"play ./source/bird.mp3 repeat", 0, 0, 0); //先打开 然后播放
	//------
	//假设一开始蛇头位于左上角，那么蛇只能往右或者往下，待完善
	//蛇头初始化
	s.pt[0].col = 0;//set横坐标
	s.pt[0].row = 0;//set纵坐标
	
	s.ch = RIGHT;//假设蛇往右移动(可以设置随机方向，待完善)

	s.len = 3;//设置蛇的初始长度为3（初始长度可以设置，等学了界面在来修改）

	//给蛇的身体初始化(待优化，根据头出现的任意位置摆放身体)
	for (int i = 1; i < MAXSIZE; i++)
	{
		s.pt[i].col = -1;
		s.pt[i].row = -1;
	}
	//food位置随机初始化生成（待完善）
	snakefood();

}
//随机产生一个食物
void snakefood()
{
	f.f_pt.col = rand() % 18+1;//food产生位置控制在1-18以内，因为按键反应不灵敏
	f.f_pt.row = rand() % 18+1;
	//食物不能出现在蛇的身上
}
//2.绘制游戏
void gameprint()
{

	//niub帅凯文
	BeginBatchDraw();
	setbkcolor(CYAN);
	cleardevice();//清屏如果不清屏就会画重
	/*
	setlinecolor(BLUE);
	for (int i = 0; i < 20; i++)//（不用每次画，看着烦，待完善，已解决闪屏BeginBatchDraw();）
	{
		for (int j = 0; j < 20; j++)
		{
			rectangle(i*WIDTH, j*HEIGHT, (i + 1)*WIDTH, (j + 1)*HEIGHT);
		}
	}
	*/
	//1.画食物
	setfillcolor(YELLOW);
	fillrectangle(f.f_pt.col*WIDTH, f.f_pt.row*HEIGHT, (f.f_pt.col + 1)*WIDTH, (f.f_pt.row + 1)*HEIGHT);
	//2.画蛇
	for (int i = 0; i < s.len; i++)
	{
		if (i == 0)
		{
			
			setfillcolor(RED);//设置头部为红色
			//fillrectangle(s.pt[i].col*WIDTH, s.pt[i].row*HEIGHT, (s.pt[i].col + 1)*WIDTH, (s.pt[i].row + 1)*HEIGHT);
			fillroundrect(s.pt[i].col*WIDTH, s.pt[i].row*HEIGHT, (s.pt[i].col + 1)*WIDTH, (s.pt[i].row + 1)*HEIGHT,10,10);
		}
		else
		{
			setfillcolor(GREEN);//设置身体为绿色
			fillrectangle(s.pt[i].col*WIDTH, s.pt[i].row*HEIGHT, (s.pt[i].col + 1)*WIDTH, (s.pt[i].row + 1)*HEIGHT);
		}
		
	}
	//批量绘图：先放到缓存再一次性投到屏幕上绘制出来，可以防止闪屏（贴图跟计算机屏幕刷新的频率不一致）（win32双缓冲机制）
	//3.更新蛇的身体
	//逆着更新pt5=pt4 pt4=pt3 pt3=pt2
	//注意：下一节的位置在下一次更新身体后会到上一节的位置
	for (int i = s.len-1; i >= 1; i--)
		s.pt[i] = s.pt[i - 1];
	
	/*
	注意不能顺着更新，因为会导致比如pt3=pt2=pt1始终=pt0
	for (int i = 1; i < s.len-1; i++)
	s.pt[i] = s.pt[i - 1];
	*/
	EndBatchDraw();

	FlushBatchDraw();
	settextstyle(20, 0, L"楷体");
	settextcolor(RED);
	setbkmode(TRANSPARENT);//字体背景透明
	TCHAR str[5] ;
	_stprintf_s(str, _T("%d"), s.len - 3);//sprintf 的T版
	outtextxy(17*WIDTH, 0, L"得分：");
	outtextxy(19 * WIDTH, 0, str);//(显示得分，待完善)

	
}

//3.玩游戏
void playgame()
{
	char direction;
	while (1)//当不按键盘的时候，蛇向一个方向移动
	{
		
		while (!_kbhit())//kbhit()检测键盘是由按下，有则返回非0值，否则返回0，（待完善）现在是不输入键盘自动移动?
		{
			game_judgement();
			gameprint();
			snakemove();//先画后动
			
			Sleep(200-s.len);//控制蛇的速度,停一段时间继续执行1000每隔一秒移动一次（待优化，随着蛇的len长度增加速度加快）
		}
		direction = _getch();
		switch (direction)
		{
		case UP:
			if (s.ch != DOWN)
				s.ch = UP;
			break;
		case DOWN:
			if (s.ch != UP)
				s.ch = DOWN;
			break;
		case LEFT:
			if (s.ch != RIGHT)
				s.ch = LEFT;
			break;
		case RIGHT:
			if (s.ch != LEFT)
				s.ch = RIGHT;
		}
	}
}

void snakemove()
{
	//开关语句
	switch (s.ch)//判断接下来要走的方向,蛇头移动
	{
	case UP:
		s.pt[0].row -= 1;
		break;
	case DOWN:
		s.pt[0].row += 1;
		break;
	case LEFT:
		s.pt[0].col -= 1;
		break;
	case RIGHT:
		s.pt[0].col += 1;
		break;
	}
}

/*
判断：
1.蛇头是否吃到食物
2.蛇头是否撞到墙壁
3.蛇头是否撞到身体
*/
//4.游戏判断
void game_judgement()
{
	if (s.pt[0].col == f.f_pt.col&&s.pt[0].row == f.f_pt.row)
	{
		s.len++;//蛇身长度+1
		snakefood();//重新生成一个食物
	}
	//标准版
	if (s.pt[0].col < 0 || s.pt[0].col>19 || s.pt[0].row < 0 || s.pt[0].row>19)
	{
		mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//关闭音乐
		if (MessageBox(GetHWnd(), L"Game over是否重新开始", L"游戏提示", MB_YESNO) == IDYES)
		{
			init();
		}
		else
			exit(0);
	}
	/*
	//加强版(待完善)
	if (s.pt[0].col < 0)
		s.pt[0].col = 19;
	else if (s.pt[0].col > 19)
		s.pt[0].col = 0;
	else if (s.pt[0].row < 0)
		s.pt[0].row = 19;
	else if (s.pt[0].row > 19)
		s.pt[0].row = 0;
	*/

	for (int i = 1; i < s.len; i++)
	{
		if (s.pt[0].col == s.pt[i].col&&s.pt[0].row == s.pt[i].row)
		{
			mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//关闭音乐
			if (MessageBox(GetHWnd(), L"Game over是否重新开始", L"游戏提示", MB_YESNO) == IDYES)
				init();
			else
				exit(0);
		}
	}
}