#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Sokoban.h"
//-----音乐头文件
#include<mmsystem.h>//头文件
#pragma comment(lib,"winmm.lib")//多媒体库
//-----

int main()
{
	//---播放音乐
	mciSendString(L"open ./source/PoPoyans.mp3", 0, 0, 0);//打开音乐
	mciSendString(L"play ./source/PoPoyans.mp3 repeat", 0, 0, 0); //先打开 然后播放
	//------
	int game_level = 1;
	//读取存档
	FILE* fd1 = fopen("save.txt", "r");
	char buff[10] = { 0 };
	fread(buff, 1, 5, fd1);
	sscanf(buff,"%d",&game_level);//字符串转int
	//game_level = atoi(buff);//不推荐使用
	fclose(fd1);

	LoadPicture();

	if (set_background() == 0)
		game_level = 1;
	closegraph();

	initgraph(Col*Size, Row*Size);//x,y窗口,在其实是第二个窗口，因为在图片上写文字会留有印记（原理不清楚）
	//所以在开始界面以后重新打开了一个程序
	
	//1.初始化
	if (LoadMap(game_level) == 0)
		MessageBox(GetHWnd(), L"游戏初始化失败", L"sorry", MB_OK);

	while (1)
	{
		//2.根据加载地图信息绘制地图
		DrawGame(game_level);
		//3.改变地图信息
		PlayGame();
		//4.过关以后从新加载地图信息
		if (iswin() == 1)
		{
			game_level++;
			//读取存档-----
			FILE* fd2 = fopen("save.txt", "w");
			char temp[10] = { 0 };
			sprintf(temp, "%d", game_level);//int 转字符串
			fwrite(temp, 1, strlen(temp), fd2);
			fclose(fd2);
			//------------
			if (LoadMap(game_level) == 0)//这一步会有LoadMap(game_level)的地图加载
			{
				//system("cls");
				if (MessageBox(GetHWnd(), L"恭喜，游戏已经通关，是否重新开始", L"恭喜", MB_YESNO) == IDYES)
				{
					game_level = 1;
					LoadMap(game_level);
				}
				else
					break;
			}
		}
	}
	
	getchar();
	closegraph();
	return 0;
}