#pragma once
#include<graphics.h>
#ifndef _SOKOBAN_H_
#define _SOKOBAN_H_

#define Row 9//9��
#define Col 8//8��
#define Size 45//ͼƬ�Ĵ�С
//�����ͼ
int LoadMap(int MapId);
//����ͼƬ
void LoadPicture();
//���ÿ�ʼ����
int set_background();
//��ͼ
void DrawGame(int MapId);
//�ƶ�
void PlayGame();
//�����ж�
int iswin();
#endif