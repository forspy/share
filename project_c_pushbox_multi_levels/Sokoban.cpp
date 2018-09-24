#define _CRT_SECURE_NO_WARNINGS
#include"Sokoban.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//easyX图形库只支持c++，所以要写在cpp文件里

int Map[Row][Col];//9*8,第一行用来显示当前关卡文字
IMAGE img[7];
//IMAGE img[6];


//加载地图
int LoadMap(int MapId)
{
	FILE* fid = fopen("Map.txt","r");

	if (!fid)
		return 0;
	//设置文件指针位置 注意每行还有\n 我们Map.txt的第一行是空的 \n算移动两个位置
	fseek(fid, (MapId - 1) * 66, SEEK_SET);//8*8+2
	char str[65] = { 0 };
	int n=fread(str, 64,1, fid);
	fclose(fid);
	if (n == 0)
		return 0;
	//给二位数组赋值
	int k = 0;
	for (int i = 1; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
			Map[i][j] = str[k++] - '0';//因为str是字符串'1'=49   '0'=48，也可以使用atoi(),选要加载头文件#include<stdlib.h>
	}
	return 1;//表示正确导入
}
//导入图片
void LoadPicture()
{
	loadimage(&img[0], L"./source/blank.jpg", Size, Size);//空地 宽字节要加L 设置为多字节不用 这里空地的设计思路是分为一小块一小块取铺
	loadimage(&img[1], L"./source/box.jpg", Size, Size);//箱子
	loadimage(&img[2], L"./source/dbox.jpg", Size, Size);//箱子推到目的地
	loadimage(&img[3], L"./source/people.jpg", Size, Size);//人
	loadimage(&img[4], L"./source/point.jpg", Size, Size);//目的地
	loadimage(&img[5], L"./source/wall.jpg", Size, Size);//墙壁
	loadimage(&img[6], L"./source/push_box.jpg", Col*Size, (Row-1)*Size);//开始界面图像
}
int set_background()
{
	initgraph(Col*Size, Row*Size);//x,y窗口
	putimage(0, Size, &img[6]);//背景图
	settextstyle(40, 0, L"楷体");
	//settextcolor(BLACK);
	setbkmode(TRANSPARENT);//字体背景透明
						   //setbkmode(1);//设置背景模式
						   //set background mode 
						   //rectangle(200, 200, 400, 400);//画矩形
	outtextxy(0, 0, L"读取存档");
	outtextxy(4 * Size, 0, L"重新开始");
	MOUSEMSG msg;
	int flag = 1;
	while (flag)
	{
		msg = GetMouseMsg();//获取鼠标消息
		switch (msg.uMsg)//判断鼠标消息
		{
		case WM_LBUTTONDOWN://左键按下
			if (msg.x > 0 && msg.x<4*Size && msg.y>0 && msg.y < Size)
			{
				//点击的区域在方框之内   可以退出循环
				flag = 0;
				return 1;
			}
			else if (msg.x > 4 * Size&&msg.x < 8 * Size &&msg.y>0 && msg.y < Size)
			{
				flag = 0;
				return 0;
			}
			break;
		}
	}
	return 1;
}
          
//根据地图贴图
void DrawGame(int MapId)
{
	for (int i = 1; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			switch (Map[i][j])//case 表示Map的值
			{
			case 0://表示空地
				putimage(j * Size, i * Size, &img[0]);
				break;
			case 1://表示墙
				putimage(j * Size, i * Size, &img[5]);
				break;
			case 3://表示目的地
				putimage(j * Size, i * Size, &img[4]);
				break;
			case 4://表示箱子
				putimage(j * Size, i * Size, &img[1]);
				break;
			case 5://表示人
				putimage(j * Size, i * Size, &img[3]);
				break;
			case 7://表示箱子在目的地
				putimage(j * Size, i * Size, &img[2]);
				break;
			case 8://表示人在目的地
				putimage(j * Size,i * Size, &img[3]);
				break;
			}
		}
	}
	TCHAR sztemp[100] = { 0 };//临时字符串数组  char为多字节  TCHAR为宽字节类型
	//格式化字符串
	wsprintf(sztemp, L"当前关数：第%d关", MapId);//wsprintf适用于宽字节buff对象 一般用spirntf就行
	settextstyle(30, 0, L"楷体");//如果不输L可以设置多字节字符集 
	//settextcolor(GREEN);
	outtextxy(70, 5, sztemp);//在(80,0)处显示

}

//移动
void PlayGame()
{
	int p_row, p_col;
	int flag = 0;
	for (int i = 1; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Map[i][j] == 5 || Map[i][j] == 8)
			{
				p_row = i;
				p_col = j;
				//----利用下述方式跳出两层循环
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	char ch = _getch();
	//人的值为5
	switch (ch)
	{
	case 'W'://往上
	case 'w':
		if (Map[p_row - 1][p_col] == 0 || Map[p_row - 1][p_col] == 3)
			//上方是空地 或者是空的目的地
		{
			Map[p_row][p_col]-=5;//变空地
			Map[p_row - 1][p_col] += 5;//空地变人
		}
		else if (Map[p_row - 1][p_col] == 4 || Map[p_row - 1][p_col] == 7)
			//人的上方是箱子或者箱子+目的地
		{
			if (Map[p_row - 2][p_col] == 0 || Map[p_row - 2][p_col] == 3)//箱子上方是空地或目的地  推动
			{
				Map[p_row][p_col] -= 5;//人往上走
				Map[p_row - 1][p_col] +=1;//人来了+5  箱子上去了-4，所以+1
				Map[p_row - 2][p_col] += 4;//箱子往上推
			}
		}
		break;

	case 'S'://往下
	case 's':
		if (Map[p_row + 1][p_col] == 0 || Map[p_row + 1][p_col] == 3)
			//下方是空地 或者是空的目的地
		{
			Map[p_row][p_col] -= 5;//变空地
			Map[p_row + 1][p_col] += 5;//空地变人
		}
		else if (Map[p_row + 1][p_col] == 4 || Map[p_row + 1][p_col] == 7)
			//人的下方是箱子或者箱子+目的地
		{
			if (Map[p_row + 2][p_col] == 0 || Map[p_row + 2][p_col] == 3)//箱子下方是空地或目的地  推动
			{
				Map[p_row][p_col] -= 5;//人往下走
				Map[p_row + 1][p_col] += 1;//人来了+5  箱子上去了-4，所以+1
				Map[p_row + 2][p_col] += 4;//箱子往下推
			}
		}
		break;

	case 'A'://往左
	case 'a':
		if (Map[p_row ][p_col-1] == 0 || Map[p_row ][p_col-1] == 3)
			//左方是空地 或者是空的目的地
		{
			Map[p_row][p_col] -= 5;//变空地
			Map[p_row ][p_col-1] += 5;//空地变人
		}
		else if (Map[p_row][p_col-1] == 4 || Map[p_row][p_col-1] == 7)
			//人的左方是箱子或者箱子+目的地
		{
			if (Map[p_row ][p_col-2] == 0 || Map[p_row ][p_col-2] == 3)//箱子左方是空地或目的地  推动
			{
				Map[p_row][p_col] -= 5;//人往上走
				Map[p_row ][p_col-1] += 1;//人来了+5  箱子去了-4，所以+1
				Map[p_row ][p_col-2] += 4;//箱子往左推
			}
		}
		break;

	case 'D'://往右
	case 'd':
		if (Map[p_row][p_col + 1] == 0 || Map[p_row][p_col+1] == 3)
			//右方是空地 或者是空的目的地
		{
			Map[p_row][p_col] -= 5;//变空地
			Map[p_row][p_col + 1] += 5;//空地变人
		}
		else if (Map[p_row][p_col + 1] == 4 || Map[p_row][p_col + 1] == 7)
			//人的右方是箱子或者箱子+目的地
		{
			if (Map[p_row][p_col + 2] == 0 || Map[p_row][p_col + 2] == 3)//箱子右方是空地或目的地  推动
			{
				Map[p_row][p_col] -= 5;//人往上走
				Map[p_row][p_col + 1] += 1;//人来了+5  箱子去了-4，所以+1
				Map[p_row][p_col + 2] += 4;//箱子往右推
			}
		}
		break;
	}
	
}

//过关判断
int iswin()
{
	//什么时候游戏可以结束 
	//1. 赢    所有箱子全部都推到目的地上-->外面没有箱子 
	//2.输  游戏超时  箱子推到死角
	int count = 0;
	for (int i = 1; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (Map[i][j] == 4)//找到了箱子  游戏还没有赢
			{
				count++;
				//如果箱子陷在墙角内
				//if (Map[i - 1][j] == 1 || Map[i + 1][j] == 1)//上方或者下方有一个墙
				//{
				//	if (Map[i][j - 1] == 1 || Map[i][j + 1] == 1)//左右有一个
				//	{
				//		//游戏结束  输
				//		MessageBox(GetHWnd(), L"输", L"lose", MB_OK);
				//		closegraph();
				//		exit(0);//退出程序
				//	}
				//		
				//}
				
			}
		}
	}
	if (count >0)
		return 0;
	else
		return 1;
		//没有箱子
		//游戏结束 赢
		//return 
		//MessageBox(GetHWnd(), L"下一关", L"GOOD", MB_OK);
		//第一个参数 句柄   作用  让窗口置前  也可以写NULL  0
		//第二个是文本  第三个是标题  第四个是按钮
		//closegraph();
		//exit(0);//退出程序

}

