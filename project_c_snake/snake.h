#pragma once
#define MAXSIZE 100

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
//д��浵
void save_record();
//��ȡ�浵
void load_record();
//my_sleep���� ���ڼ�����Ӧʱ����sleep����
void my_sleep(double  n);
//д����߳ɼ�������
void save_player();
//��ȡ��߳ɼ�������
void load_player();
//����ai��-----
void ai_init();//ai_snake
void ai_snakemove();
void ai_game_judgement();
//-------

//�����ģʽ
void set_background_2_1();
//�����е�ģʽ
void set_background_2_2();
//��������ģʽ
void set_background_2_3();
//��ʼ���漰�趨
void set_background();
//����ai�ߵ������������ٶ�
void deside();