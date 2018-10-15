#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include"jigsaw puzzle.h"
/*
1 2 3
4 5 6
7 8 0
*/
int pic[3][3];
/*
= {
	{1,2,3},
	{4,5,6},
	{7,8,0},
};
*/

IMAGE img[9];

void init()
{
	//种下随机数种子
	srand((unsigned int)time(NULL));
	//0 1 2 3 4 5 6 7 8表示9张图片，其中0表示空白图片？
	/*
	要随机给9张图片赋值 并且不能重复
	实现方法：
	0.建立一个一位数组a[9]={0，1，2，3，4，5，6，7，8};
	1.随机一个下标b
	2.拿出该值后使用memmove
	*/ 
	int a[9] = { 0,1,2,3,4,5,6,7,8 };
	int n;//去一个随机的下标
	int len=9;//随机下标的范围
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			n = rand() % len;
			pic[i][j]=a[n];
			memmove(a + n, a + n + 1, (9 - n) * sizeof(int));
			/*这样也能实现memove的功能
			for(int k=n;k<len;k++)
			a[k]=a[k+1];
			*/
			len--;
		}
	}
	/*测试随机输出情况
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", pic[i][j]);
		}
	}
	*/
	//载入图片
	loadpicture();
}
//载入图片
void loadpicture()
{
	TCHAR path[50] ;//路径名，因为easyX只支持多字节
	for (int i = 0; i < 9; i++)
	{
		memset(path, 0, sizeof(path));//每个循环给path初始化
		_stprintf_s(path, L"./source/images/%d.jpg", i);//格式化输入，并将整形i转化为Tchar类型
		loadimage(&img[i], path, SIZE, SIZE);//载入图片，并设置每张图片的大小为100*100
	}
}

//贴图
void drawpicture()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//如果pic[0][0]=3，就把3.jpg放在0，0位置
			/*easyx的putimage是和windows系统上的坐标相反的传统的是x对应row行，y对应col列
			   x
			——————
			| 
	y		|
			|
			*///    x col列    y row行
			putimage(j*SIZE, i*SIZE, &img[pic[i][j]]);
		}
	}
}

//玩游戏
void playgame()
{
	MOUSEMSG m;//用来获取鼠标信息
	int row;//行
	int col;//列
	while (1)
	{

		drawpicture();
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			row = m.y / 100;//m.y表示行row
			col = m.x / 100;//m.x表示列col
			/*(windows的表示)
			 col   x
			|————
	row	y	|
			|
			*/
			if (pic[row - 1][col + 0] == 0 && is_cross(row - 1, col))//如果鼠标点击当前图片的上面是空白，则可以移动,并且不能越界
				my_swap(row, col, -1, 0);
			else if (pic[row + 1][col + 0] == 0 && is_cross(row + 1, col))//下面空白
				my_swap(row, col, 1, 0);
			else if (pic[row + 0][col - 1] == 0 && is_cross(row, col - 1))//左边是空白
				my_swap(row, col, 0, -1);
			else if (pic[row + 0][col + 1] == 0 && is_cross(row, col + 1))//右边是空白
				my_swap(row, col, 0, 1);

			break;
		}
		if (is_win())
			break;
	}
	MessageBox(GetHWnd(), L"恭喜获取女朋友一枚", L"通关提示", MB_OK);
}
//交换
void my_swap(int row,int col,int a, int b)
{
	int temp;
	temp = pic[row][col];
	pic[row][col] = pic[row + a][col + b];
	pic[row + a][col + b] = temp;
}

//判断是否越界
bool is_cross(int row,int col)
{
	return row >= 0 && row < 3 && col >= 0 && col < 3;
}
//判断胜利条件
bool is_win()
{
	int goal[9] = { 1,2,3,4,5,6,7,8,0 };
	
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pic[i][j] != goal[k++])//如果排序按照goal的顺序拍好的话通关
			{
				return false;
			}
		}
	}
	return true;
}