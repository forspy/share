#pragma once
#define MAXSIZE 1000

#define WIDTH 30//ÿһ�����ӵĸ߶ȺͿ��
#define HEIGHT 30
typedef enum
{
	//easyx �����ķ������ֵ
	UP=72,
	DOWN=80,
	LEFT=75,
	RIGHT=77
}CH;
//�ߵ�����	
typedef struct
{
	int col;//��������
	int row;//��������
}point;
typedef struct
{
	point pt[MAXSIZE];//ÿһ������һ�����꣬����γ���һ������
	int len;//�ߵĳ���
	CH ch;//�ߵķ���,ch��ֵ��enum��������ѡ��
}snake;
//ʳ��
typedef struct
{
	point f_pt;//ʳ�������
}food;

//1.��ʼ����Ϸ
void init();
//2.������Ϸ
void gameprint();
//�������һ��ʳ��
void snakefood();
//3.����Ϸ
void playgame();
//�ƶ���
void snakemove();
//4.��Ϸ�ж�
void game_judgement();