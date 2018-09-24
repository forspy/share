#pragma once
#include<graphics.h>
#ifndef _SOKOBAN_H_
#define _SOKOBAN_H_

#define Row 9//9行
#define Col 8//8列
#define Size 45//图片的大小
//导入地图
int LoadMap(int MapId);
//导入图片
void LoadPicture();
//设置开始背景
int set_background();
//贴图
void DrawGame(int MapId);
//移动
void PlayGame();
//过关判断
int iswin();
#endif