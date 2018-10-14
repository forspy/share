#define _CRT_SECURE_NO_WARNINGS
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


//定义snake.cpp内的全局变量
snake s;//蛇
food f;//食物
int high_score;//定义一个全局最高分
TCHAR temp_player[11];//定义一个全局最高分用户
int num ;//随着主角蛇的长度决定出现几条ai蛇
int ai_temp_len;//定义一个全局的ai蛇的零时长度，使之只更新一次
int level;//定义一个难度
int speed;//全局速度

//使用extern全局变量
IMAGE img;//使用main里定义的全局img
TCHAR playername[11];//使用main里定义的全局playname


//定义一批ai蛇
snake ss[30];
//1.初始化
void init()
{
	//附加功能：
	//---播放音乐
	mciSendString(L"open ./source/bird.mp3", 0, 0, 0);//打开音乐
	mciSendString(L"play ./source/bird.mp3 repeat", 0, 0, 0); //先打开 然后播放
	//读取存档
	load_record();
	load_player();
	deside();
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
	//食物不能出现在蛇的身上
	
again:	f.f_pt.col = rand() % 18 + 1;//food产生位置控制在1-18以内，因为按键反应不灵敏
		f.f_pt.row = rand() % 18 + 1;
		for (int i = 0; i < s.len; i++)
		{
			if (f.f_pt.col == s.pt[i].col&&f.f_pt.row == s.pt[i].row)
				goto again;
		}
}
//2.绘制游戏

void gameprint()
{
	cleardevice();//清屏如果不清屏就会画重
	BeginBatchDraw();
	
	putimage(0, 0, &img);
	//setbkcolor(CYAN);
	
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

	//画ai蛇
	
	for (int j = 0; j < num; j++)
	{
		for (int i = 0; i < ss[j].len; i++)
		{
			if (i == 0)
			{
				setfillcolor(BLUE);//设置头部为红色
								  //fillrectangle(s.pt[i].col*WIDTH, s.pt[i].row*HEIGHT, (s.pt[i].col + 1)*WIDTH, (s.pt[i].row + 1)*HEIGHT);
				fillroundrect(ss[j].pt[i].col*WIDTH, ss[j].pt[i].row*HEIGHT, (ss[j].pt[i].col + 1)*WIDTH, (ss[j].pt[i].row + 1)*HEIGHT, 10, 10);
			}
			else
			{
				setfillcolor(GREEN);//设置身体为绿色
				fillrectangle(ss[j].pt[i].col*WIDTH, ss[j].pt[i].row*HEIGHT, (ss[j].pt[i].col + 1)*WIDTH, (ss[j].pt[i].row + 1)*HEIGHT);
			}
		}

	}
	//更新ai蛇
	for (int j = 0; j < num; j++)
	{
		for (int i = ss[j].len - 1; i >= 1; i--)
			ss[j].pt[i] = ss[j].pt[i - 1];
	}


	//画玩家蛇
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
	
	

	//FlushBatchDraw();刷新剩下的图形
	settextstyle(20, 0, L"楷体");
	settextcolor(RED);
	setbkmode(TRANSPARENT);//字体背景透明
	TCHAR str[5] ;
	_stprintf_s(str, _T("%d"), s.len - 3);//sprintf 的T版,数字转字符串
	outtextxy(16*WIDTH, 0, L"当前得分：");
	outtextxy(19 * WIDTH, 0, str);//(显示得分，待完善)已优化
	TCHAR str1[5];
	_stprintf_s(str1, _T("%d"), high_score);
	outtextxy(16 * WIDTH, 1*HEIGHT, L"最高得分：");
	outtextxy(19 * WIDTH, 1 * HEIGHT, str1);
	outtextxy(14 * WIDTH, 2 * HEIGHT, L"记录保持者：");
	outtextxy(18 * WIDTH, 2 * HEIGHT, temp_player);

	

	EndBatchDraw();
}

//3.玩游戏
void playgame()
{
	char direction;
	while (1)//当不按键盘的时候，蛇向一个方向移动
	{
		if (level == 1 )
			num = (s.len - 3) / 10;
		else if (level == 2 || level == 3)
			num = (s.len - 3) / 10 + 1;
		while (!_kbhit())//kbhit()检测键盘是由按下，有则返回非0值，否则返回0，（待完善）现在是不输入键盘自动移动?
		{
			//clock_t delay = 1*CLOCKS_PER_SEC;//ai_蛇 延时一秒
			//clock_t start = clock();
			//让蛇每一秒自动动一下而跟主角蛇的移动频率无关
			/*
			顾问们给出的意见（供参考）
			0.另开一个线程  windows多线程（一） 创建线程 CreateThread
			1.异步处理
			2.回调函数
			3.看看上层框架
			*/
			
			ai_game_judgement();
			game_judgement();

			gameprint();
			ai_snakemove();//需要把ai_snakemove调到ai_init
			snakemove();//先画后动
			my_sleep(speed-s.len);
			
			//Sleep(200-s.len);//控制蛇的速度,停一段时间继续执行1000每隔一秒移动一次（待优化，随着蛇的len长度增加速度加快）已优化1.1
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
		//写入存档保存最高纪录
		//save_record();
		snakefood();//重新生成一个食物
	}
	//标准版
	if (s.pt[0].col < 0 || s.pt[0].col>19 || s.pt[0].row < 0 || s.pt[0].row>19)//撞墙
	{
		if (s.len - 3 > high_score)
		{
			save_player();//保存名字
			save_record();//保存分数
		}
			
		mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//关闭音乐
		if (MessageBox(GetHWnd(), L"Game over是否重新开始", L"游戏提示", MB_YESNO) == IDYES)
		{
			init();
			ai_init();
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

	for (int i = 1; i < s.len; i++)//撞到自身
	{
		if (s.pt[0].col == s.pt[i].col&&s.pt[0].row == s.pt[i].row)
		{
			if (s.len - 3 > high_score)
				save_record();//保存
			mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//关闭音乐
			if (MessageBox(GetHWnd(), L"Game over是否重新开始", L"游戏提示", MB_YESNO) == IDYES)
			{
				init();
				ai_init();
				break;
			}
			
			else
				exit(0);
		}
	}

	//撞到ai蛇
	for (int j = 0; j < num; j++)//j表示是第几只ai蛇
	{
		for (int i = 0; i < ss[j].len; i++)
		{
			if (s.pt[0].col == ss[j].pt[i].col&&s.pt[0].row == ss[j].pt[i].row)
			{
				if (s.len - 3 > high_score)
					save_record();//保存
				mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//关闭音乐
				if (MessageBox(GetHWnd(), L"Game over是否重新开始", L"游戏提示", MB_YESNO) == IDYES)
				{
					init();
					ai_init();
					break;
				}

				else
					exit(0);
			}
		}
		
	}
}
//写入存档
void save_record()
{
	FILE* fid1 = fopen("./source/record.txt", "w");
	char temp[10] = { 0 };
	sprintf_s(temp, "%d", s.len - 3);
	fwrite(temp, 1, strlen(temp), fid1);
	fclose(fid1);

}
//写入最高成绩者姓名
void save_player()
{
	
	FILE* fid0 = fopen("./source/player.txt", "w");
	fwrite(playername, 11, 1, fid0);
	fclose(fid0);
}
//读取存档
void load_record()
{
	FILE* fid2 = fopen("./source/record.txt", "r");
	char buff[10] = { 0 };
	fread(buff, 1, 5, fid2);
	sscanf(buff, "%d", &high_score);//字符串转int
	fclose(fid2);
}
//读取最高成绩者姓名
void load_player()
{
	FILE* fid3 = fopen("./source/player.txt", "r");
	fread(temp_player, 11, 1, fid3);
	fclose(fid3);
}

//my_sleep函数 用于键盘响应时跳出sleep函数
void my_sleep(double  n)//参数是要暂停的秒数
{
	long    tm1;
	tm1 = clock(); //返回时钟tick数
	while (!_kbhit())
	{
		if ((double)(clock() - tm1) / CLOCKS_PER_SEC >= n/1000) break;
		//(double)(clock()-tm1)/CLOCKS_PER_SEC:将滴答数转化为秒数，大于参数值则退出循环
		//判断是否函数执行的秒数大于参数设定的秒数，大于则返回
		//这个函数可以实现程序的延迟
	}
}

void ai_init()//ai_snake
{
	for (int j = 0; j < 30; j++)
	{
		ss[j].pt[0].col = 10;//set横坐标
		ss[j].pt[0].row = 10;//set纵坐标

		ss[j].ch = RIGHT;//假设蛇往右移动(可以设置随机方向，待完善)

		ss[j].len = 3;//设置蛇的初始长度为3（初始长度可以设置，等学了界面在来修改）

				  //给蛇的身体初始化(待优化，根据头出现的任意位置摆放身体)
		for (int i = 1; i < MAXSIZE; i++)
		{
			ss[j].pt[i].col = -1;
			ss[j].pt[i].row = -1;
		}
	}
}


void ai_snakemove()
{
	for (int i = 0; i < num; i++)
	{
		int d = rand() % 4;
		switch (d)//判断接下来要走的方向,蛇头移动
		{
		case 0://随机到向上走
			if (ss[i].ch != DOWN)//如果原本是向下的不能向上
			{
				ss[i].pt[0].row -= 1;//向上
				ss[i].ch = UP;
			}
			else
				ss[i].pt[0].row += 1;//保持继续向下
			break;
		case 1:
			if (ss[i].ch != UP)
			{
				ss[i].pt[0].row += 1;
				ss[i].ch = DOWN;
			}
			else
				ss[i].pt[0].row -= 1;
			break;
		case 2:
			if (ss[i].ch != RIGHT)
			{
				ss[i].pt[0].col -= 1;
				ss[i].ch = LEFT;
			}
			else
				ss[i].pt[0].col += 1;
			break;
		case 3:
			if (ss[i].ch != LEFT)
			{
				ss[i].pt[0].col += 1;
				ss[i].ch = RIGHT;
			}
			else
				ss[i].pt[0].col -= 1;
			break;
		}
	}
}

//void ai_sleep(clock_t wait)
//{
//	clock_t goal;
//	goal = wait + clock();
//	while (goal > clock());
//}

void ai_game_judgement()
{
	for (int i = 0; i < num; i++)
	{
		//如果ai蛇吃了食物
		if (ss[i].pt[0].col == f.f_pt.col&&ss[i].pt[0].row == f.f_pt.row)
		{
			ss[i].len++;//蛇身长度+1
					//写入存档保存最高纪录
					//save_record();
			snakefood();//重新生成一个食物
		}
		//ai蛇也会随着时间自然生长
		if ((s.len % 10) == 0 && ai_temp_len != s.len)
		{
			//每次主角蛇的长度到10，ai蛇的长度就+1
			ss[i].len++;
			ai_temp_len = s.len;//原创算法：保证更新到10 的时候只运行一次++
		}
		//ai撞到墙后在另一端出现
		if (ss[i].pt[0].col < 0)
			ss[i].pt[0].col = 19;
		else if (ss[i].pt[0].col > 19)
			ss[i].pt[0].col = 0;
		else if (ss[i].pt[0].row < 0)
			ss[i].pt[0].row = 19;
		else if (ss[i].pt[0].row > 19)
			ss[i].pt[0].row = 0;
	}
	//ai蛇撞到主角蛇
	for (int j = 0; j < num; j++)
	{
		for (int i = 1; i < s.len; i++)//撞到主角蛇的身躯
		{
			if (ss[j].pt[0].col == s.pt[i].col&&ss[j].pt[0].row == s.pt[i].row)
			{
				ss[j].pt[0].col = 10;//set横坐标
				ss[j].pt[0].row = 10;//set纵坐标

				ss[j].ch = RIGHT;//假设蛇往右移动(可以设置随机方向，待完善)

				ss[j].len = 3;//设置蛇的初始长度为3（初始长度可以设置，等学了界面在来修改）

				for (int i = 1; i < MAXSIZE; i++)//ai蛇身更新
				{
					ss[j].pt[i].col = -1;
					ss[j].pt[i].row = -1;
				}
			}

		}
	}
}

//载入开始画面
void set_background()
{
	initgraph(20 * WIDTH, 20 * HEIGHT);
	//loading
	IMAGE img0;
	loadimage(&img0, L"./source/snake.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img0);
	Sleep(1000);
	//开始游戏画面
	IMAGE img1_0;
	loadimage(&img1_0, L"./source/snake1_0.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img1_0);
	MOUSEMSG msg;
	int flag = 1;
	while (flag)
	{
		msg = GetMouseMsg();//获取鼠标消息
		switch (msg.uMsg)//判断鼠标消息
		{
		case WM_LBUTTONDOWN://左键按下
			if (msg.x > 8 * WIDTH && msg.x<12 * WIDTH && msg.y>14 * HEIGHT && msg.y < 16 * HEIGHT)
				flag = 0;//点击的区域在方框之内   可以退出循环
			break;
		}
	}
	//载入点击开始后的加粗字体画面
	IMAGE img1_1;
	loadimage(&img1_1, L"./source/snake1_1.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img1_1);
	Sleep(300);

	//设置蛇的初始运动速度//1.没有蛇/慢速 2.有蛇/慢速 3.有蛇/快速
	IMAGE img2_0;
	loadimage(&img2_0, L"./source/snake2_0.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img2_0);

	flag = 1;
	while (flag)
	{
		msg = GetMouseMsg();//获取鼠标消息
		switch (msg.uMsg)//判断鼠标消息
		{
		case WM_LBUTTONDOWN://左键按下
			if (msg.x > 8 * WIDTH && msg.x < 12 * WIDTH && msg.y>13 * HEIGHT && msg.y < 14.5 * HEIGHT)
			{
				flag = 0;
				level = 1;
			}
			else if (msg.x > 8 * WIDTH && msg.x < 12 * WIDTH && msg.y>15 * HEIGHT && msg.y < 16.5 * HEIGHT)
			{
				flag = 0;
				level = 2;
			}
			else if (msg.x > 8 * WIDTH && msg.x < 12 * WIDTH && msg.y>17 * HEIGHT && msg.y < 18.5 * HEIGHT)
			{
				flag = 0;
				level = 3;
			}
			break;
		}
	}
	if (level == 1)
		set_background_2_1();
	else if (level == 2)
		set_background_2_2();
	else if (level == 3)
		set_background_2_3();
}

//载入简单模式
void set_background_2_1()
{
	IMAGE img2_1;
	loadimage(&img2_1, L"./source/snake2_1.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img2_1);
	Sleep(300);
}
//载入中等模式
void set_background_2_2()
{
	IMAGE img2_2;
	loadimage(&img2_2, L"./source/snake2_2.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img2_2);
	Sleep(300);
}
//载入困难模式
void set_background_2_3()
{
	IMAGE img2_3;
	loadimage(&img2_3, L"./source/snake2_3.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img2_3);
	Sleep(300);
}
//设置ai蛇的条数和总体速度
void deside()
{
	if (level == 1)
	{
		num = 0;
		speed = 200;
		return;
	}
	if (level == 2)
	{
		num = 1;
		speed = 200;
		return;
	}
	if (level == 3)
	{
		num = 1;
		speed = 100;
		return;
	}
}