#pragma once
#define SIZE 100
//��ʼ��
void init();
//����ͼƬ
void loadpicture();
//��ͼ
void drawpicture();
//����Ϸ
void playgame();
//����
void my_swap(int row, int col, int a, int b);
//�ж��Ƿ�Խ��
bool is_cross(int row, int col);
//�ж�ʤ������
bool is_win();