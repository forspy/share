#include<stdio.h>
#include<conio.h>
#include<graphics.h>//图形库头文件
#include<mmsystem.h>//头文件
#pragma comment(lib,"winmm.lib")//多媒体库
/*
1.音乐播放  mciSendString   MP3  wav格式音乐   音乐不要用网易云
#include<mmsystem.h>//头文件
#pragma comment(lib,"winmm.lib")//多媒体库

PlaySound  只能播放wav

2.推箱子  素材 几张照片-->jpg或者bmp格式
图形库


推箱子的流程  ---->地图--->推动箱子   箱子全部推动到目的地上的时候 游戏结束

操作  每一个操作对应一个函数
1.准备工作   地图需要准备  素材也需要准备
2.推箱子
3.判断游戏是否结束
数据存放部分
推箱子   人2  箱子3  目的地4  空地0  墙1--->数组存储
人+目的地--->2+4  6
箱子+目的地---->7
*/
int map[8][8] = {//内外的空地   如果有素材   两个数字可以不一样)
	0,0,1,1,1,0,0,0,
	0,0,1,4,1,0,0,0,
	0,0,1,0,1,1,1,1,
	1,1,1,3,0,3,4,1,
	1,4,0,3,2,1,1,1,
	1,1,1,1,3,1,0,0,
	0,0,0,1,4,1,0,0,
	0,0,0,1,1,1,0,0
};//8*8的地图  --->每张图片大小80*80  总大小640*640
//int map[8][8] = {//内外的空地   如果有素材   两个数字可以不一样)
//	0,0,0,0,0,0,0,0,
//	0,0,0,4,0,0,0,0,
//	0,0,0,0,0,0,0,0,
//	1,1,1,3,0,3,4,1,
//	1,4,0,3,2,1,1,1,
//	1,1,1,1,3,1,0,0,
//	0,0,0,1,4,1,0,0,
//	0,0,0,1,1,1,0,0
//};//8*8的地图  --->每张图片大小80*80  总大小640*640
IMAGE img[6];//总共6张素材//全局  所有人都可以用 

void init()//加载素材
{
	//加载图片;
	loadimage(&img[0], "素材/背景.jpg", 640, 640);
	loadimage(&img[1], "素材/目的地.jpg", 80, 80);//箱子推到目的地上
	loadimage(&img[2], "素材/墙.jpg", 80, 80);
	loadimage(&img[3], "素材/人物.jpg", 80, 80);
	loadimage(&img[4], "素材/箱子.jpg", 80, 80);
	loadimage(&img[5], "素材/源氏.jpg", 80, 80);//空的目的地

}
void drawMap()//画地图
{
	putimage(0, 0, &img[0]);
	for (int i = 0; i < 8; ++i)//数组大小是8
	{
		for (int j = 0; j < 8; ++j)
		{
			switch (map[i][j])//遍历数组
			{
			case 0:
				break;
			case 1:
				putimage(j * 80, i * 80, &img[2]);//前面两个位置是坐标
				break;
			case 2:
				putimage(j * 80, i * 80, &img[3]);
				break;
			case 3://箱子
				putimage(j * 80, i * 80, &img[4]);
				break;
			case 4://目的地
				putimage(j * 80, i * 80, &img[5]);
				break;
			case 6:
				putimage(j * 80, i * 80, &img[3]);
				break;
			case 7:
				putimage(j * 80, i * 80, &img[1]);
				break;
			}
		}
	}
}
void play()//操作部分
{
	int row, column;//找到人物的位置
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (map[i][j] == 2 || map[i][j] == 6)//人的位置
			{
				row = i;
				column = j;//保存了人的位置
			}
		}
	}
	//然后判断用户输入 
	//getch  --->获取用户按键  conio.h

	switch (getch())//getch()输入不用按回车
	{
	case 'W'://往上
	case 'w':
		if (map[row - 1][column] == 0 || map[row - 1][column] == 4)
			//上方是空地 或者是空的目的地
		{
			map[row][column] -= 2;//map[x][y]=map[x][y]-2;
			map[row - 1][column] += 2;//人往上走
		}
		else if (map[row - 1][column] == 3 || map[row - 1][column] == 7)
			//人的上方是箱子或者箱子+目的地
		{
			if (map[row - 2][column] == 0 || map[row - 2][column] == 4)//箱子上方是空地  推动
			{
				map[row][column] -= 2;//人往上走
				map[row - 1][column] -= 1;//人来了+2  箱子上去了-3
				map[row - 2][column] += 3;//箱子往上推
			}
		}
		//else if ((map[x - 1][y] == 3 || map[x - 1][y] == 7) && (map[x - 2][y] == 0 || map[x - 2][y] == 4))
		break;
	case 'A'://往左
	case 'a':
		if (map[row][column - 1] == 0 || map[row][column - 1] == 4)
		{
			map[row][column] -= 2;
			map[row][column - 1] += 2;
		}
		else if (map[row][column - 1] == 3 || map[row][column - 1] == 7)
		{
			if (map[row][column - 2] == 0 || map[row][column - 2] == 4)
			{
				map[row][column] -= 2;
				map[row][column - 1] -= 1;
				map[row][column - 2] += 3;
			}
		}
		break;
	case 'D'://往右
	case 'd':
		if (map[row][column + 1] == 0 || map[row][column + 1] == 4)
		{
			map[row][column] -= 2;
			map[row][column + 1] += 2;
		}
		else if (map[row][column + 1] == 3 || map[row][column + 1] == 7)
		{
			if (map[row][column + 2] == 0 || map[row][column + 2] == 4)
			{
				map[row][column] -= 2;
				map[row][column + 1] -= 1;
				map[row][column + 2] += 3;
			}
		}
		break;

	case 'S':
	case 's':
		if (map[row + 1][column] == 0 || map[row + 1][column] == 4)//上方是空地 或者是空的目的地
		{
			map[row][column] -= 2;//map[x][y]=map[x][y]-2;
			map[row + 1][column] += 2;//人往上走
		}
		else if (map[row + 1][column] == 3 || map[row + 1][column] == 7)//人的上方是箱子或者箱子+目的地
		{
			if (map[row + 2][column] == 0 || map[row + 2][column] == 4)//箱子上方是空地  推动
			{
				map[row][column] -= 2;//人往上走
				map[row + 1][column] -= 1;//人来了+2  箱子上去了-3
				map[row + 2][column] += 3;//箱子往上推
			}
		}
		break;
	}




}
void gameOver()
{
	//什么时候游戏可以结束 
	//1. 赢    所有箱子全部都推到目的地上-->外面没有箱子 
	//2.输  游戏超时  箱子推到死角
	int flag = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (map[i][j] == 3)//找到了箱子  游戏还没有赢
			{
				++flag;//箱子的个数
				if (map[i - 1][j] == 1 || map[i + 1][j] == 1)//上方或者下方有一个
				{
					if (map[i][j - 1] == 1 || map[i][j - 1] == 1)//左右有一个
					{
						//游戏结束  输
						MessageBox(GetHWnd(), "输", "sad", MB_OK);
						closegraph();
						exit(0);
					}
				}
			}
		}
	}
	if (flag == 0)
	{
		//没有箱子
		//游戏结束 赢
		//return 
		MessageBox(GetHWnd(), "赢", "GOOD", MB_OK);
		//第一个参数 句柄   作用  让窗口置前  也可以写NULL  0
		//第二个是文本  第三个是标题  第四个是按钮
		closegraph();
		exit(0);//退出程序
	}

}
int main()
{
	mciSendString("open 素材/bgm.mp3", 0, 0, 0);//打开音乐
	mciSendString("play 素材/bgm.mp3 repeat", 0, 0, 0); //先打开 然后播放
	//后面的repeat表示循环播放
	//mciSendString("open 素材/bgm.mp3 alias bgm", 0, 0, 0);//打开音乐 alias bgm取一个别名
	//mciSendString("play bgm repeat", 0, 0, 0); //先打开 然后播放
	//关闭音乐  stop  暂停 pause
	initgraph(640, 640);
	init();//加载图片

		   //开始界面=========================================
	putimage(0, 0, &img[0]);//背景图
	settextstyle(40, 0, "楷体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//字体背景透明
	//setbkmode(1);//设置背景模式
				 //set background mode 
	//rectangle(200, 200, 400, 400);//画矩形
	outtextxy(250, 250, "开始游戏");
	MOUSEMSG msg;
	int flag = 1;
	while (flag)
	{
		msg = GetMouseMsg();//获取鼠标消息
		switch (msg.uMsg)//判断鼠标消息
		{
		case WM_LBUTTONDOWN://左键按下
			if (msg.x > 200 && msg.x<400 && msg.y>200 && msg.y < 400)
			{
				//点击的区域在方框之内   可以退出循环
				flag = 0;
			}
			break;
		default:
			break;
		}
	}

	/*
	鼠标操作
	MouseHit() 判断是否存在鼠标消息
	MOUSEMSG  类型 存放是鼠标消息
	GetMouseMsg()   获取鼠标信息的函数
	*/

	//====================================================
	drawMap();
	while (1)
	{
		play();
		drawMap();
		gameOver();
	}
	getchar();
	closegraph();
	return 0;
}