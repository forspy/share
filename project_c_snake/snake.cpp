#include "snake.h"
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>//easyxͼ�ο��ļ�
#include<time.h>
#include <conio.h>//�������Ƿ���
#include<string.h>
//-----����ͷ�ļ�
#include<mmsystem.h>//ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��ý���
//-----
//����ȫ�ֱ���
snake s;//��
food f;//ʳ��
//�������������
//1.��ʼ��
void init()
{
	//---��������
	mciSendString(L"open ./source/bird.mp3", 0, 0, 0);//������
	mciSendString(L"play ./source/bird.mp3 repeat", 0, 0, 0); //�ȴ� Ȼ�󲥷�
	//------
	//����һ��ʼ��ͷλ�����Ͻǣ���ô��ֻ�����һ������£�������
	//��ͷ��ʼ��
	s.pt[0].col = 0;//set������
	s.pt[0].row = 0;//set������
	
	s.ch = RIGHT;//�����������ƶ�(��������������򣬴�����)

	s.len = 3;//�����ߵĳ�ʼ����Ϊ3����ʼ���ȿ������ã���ѧ�˽��������޸ģ�

	//���ߵ������ʼ��(���Ż�������ͷ���ֵ�����λ�ðڷ�����)
	for (int i = 1; i < MAXSIZE; i++)
	{
		s.pt[i].col = -1;
		s.pt[i].row = -1;
	}
	//foodλ�������ʼ�����ɣ������ƣ�
	snakefood();

}
//�������һ��ʳ��
void snakefood()
{
	f.f_pt.col = rand() % 18+1;//food����λ�ÿ�����1-18���ڣ���Ϊ������Ӧ������
	f.f_pt.row = rand() % 18+1;
	//ʳ�ﲻ�ܳ������ߵ�����
}
//2.������Ϸ
void gameprint()
{

	//niub˧����
	BeginBatchDraw();
	setbkcolor(CYAN);
	cleardevice();//��������������ͻử��
	/*
	setlinecolor(BLUE);
	for (int i = 0; i < 20; i++)//������ÿ�λ������ŷ��������ƣ��ѽ������BeginBatchDraw();��
	{
		for (int j = 0; j < 20; j++)
		{
			rectangle(i*WIDTH, j*HEIGHT, (i + 1)*WIDTH, (j + 1)*HEIGHT);
		}
	}
	*/
	//1.��ʳ��
	setfillcolor(YELLOW);
	fillrectangle(f.f_pt.col*WIDTH, f.f_pt.row*HEIGHT, (f.f_pt.col + 1)*WIDTH, (f.f_pt.row + 1)*HEIGHT);
	//2.����
	for (int i = 0; i < s.len; i++)
	{
		if (i == 0)
		{
			
			setfillcolor(RED);//����ͷ��Ϊ��ɫ
			//fillrectangle(s.pt[i].col*WIDTH, s.pt[i].row*HEIGHT, (s.pt[i].col + 1)*WIDTH, (s.pt[i].row + 1)*HEIGHT);
			fillroundrect(s.pt[i].col*WIDTH, s.pt[i].row*HEIGHT, (s.pt[i].col + 1)*WIDTH, (s.pt[i].row + 1)*HEIGHT,10,10);
		}
		else
		{
			setfillcolor(GREEN);//��������Ϊ��ɫ
			fillrectangle(s.pt[i].col*WIDTH, s.pt[i].row*HEIGHT, (s.pt[i].col + 1)*WIDTH, (s.pt[i].row + 1)*HEIGHT);
		}
		
	}
	//������ͼ���ȷŵ�������һ����Ͷ����Ļ�ϻ��Ƴ��������Է�ֹ��������ͼ���������Ļˢ�µ�Ƶ�ʲ�һ�£���win32˫������ƣ�
	//3.�����ߵ�����
	//���Ÿ���pt5=pt4 pt4=pt3 pt3=pt2
	//ע�⣺��һ�ڵ�λ������һ�θ��������ᵽ��һ�ڵ�λ��
	for (int i = s.len-1; i >= 1; i--)
		s.pt[i] = s.pt[i - 1];
	
	/*
	ע�ⲻ��˳�Ÿ��£���Ϊ�ᵼ�±���pt3=pt2=pt1ʼ��=pt0
	for (int i = 1; i < s.len-1; i++)
	s.pt[i] = s.pt[i - 1];
	*/
	EndBatchDraw();

	FlushBatchDraw();
	settextstyle(20, 0, L"����");
	settextcolor(RED);
	setbkmode(TRANSPARENT);//���屳��͸��
	TCHAR str[5] ;
	_stprintf_s(str, _T("%d"), s.len - 3);//sprintf ��T��
	outtextxy(17*WIDTH, 0, L"�÷֣�");
	outtextxy(19 * WIDTH, 0, str);//(��ʾ�÷֣�������)

	
}

//3.����Ϸ
void playgame()
{
	char direction;
	while (1)//���������̵�ʱ������һ�������ƶ�
	{
		
		while (!_kbhit())//kbhit()���������ɰ��£����򷵻ط�0ֵ�����򷵻�0���������ƣ������ǲ���������Զ��ƶ�?
		{
			game_judgement();
			gameprint();
			snakemove();//�Ȼ���
			
			Sleep(200-s.len);//�����ߵ��ٶ�,ͣһ��ʱ�����ִ��1000ÿ��һ���ƶ�һ�Σ����Ż��������ߵ�len���������ٶȼӿ죩
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
	//�������
	switch (s.ch)//�жϽ�����Ҫ�ߵķ���,��ͷ�ƶ�
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
�жϣ�
1.��ͷ�Ƿ�Ե�ʳ��
2.��ͷ�Ƿ�ײ��ǽ��
3.��ͷ�Ƿ�ײ������
*/
//4.��Ϸ�ж�
void game_judgement()
{
	if (s.pt[0].col == f.f_pt.col&&s.pt[0].row == f.f_pt.row)
	{
		s.len++;//������+1
		snakefood();//��������һ��ʳ��
	}
	//��׼��
	if (s.pt[0].col < 0 || s.pt[0].col>19 || s.pt[0].row < 0 || s.pt[0].row>19)
	{
		mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//�ر�����
		if (MessageBox(GetHWnd(), L"Game over�Ƿ����¿�ʼ", L"��Ϸ��ʾ", MB_YESNO) == IDYES)
		{
			init();
		}
		else
			exit(0);
	}
	/*
	//��ǿ��(������)
	if (s.pt[0].col < 0)
		s.pt[0].col = 19;
	else if (s.pt[0].col > 19)
		s.pt[0].col = 0;
	else if (s.pt[0].row < 0)
		s.pt[0].row = 19;
	else if (s.pt[0].row > 19)
		s.pt[0].row = 0;
	*/

	for (int i = 1; i < s.len; i++)
	{
		if (s.pt[0].col == s.pt[i].col&&s.pt[0].row == s.pt[i].row)
		{
			mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//�ر�����
			if (MessageBox(GetHWnd(), L"Game over�Ƿ����¿�ʼ", L"��Ϸ��ʾ", MB_YESNO) == IDYES)
				init();
			else
				exit(0);
		}
	}
}