#define _CRT_SECURE_NO_WARNINGS
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


//����snake.cpp�ڵ�ȫ�ֱ���
snake s;//��
food f;//ʳ��
int high_score;//����һ��ȫ����߷�
TCHAR temp_player[11];//����һ��ȫ����߷��û�
int num ;//���������ߵĳ��Ⱦ������ּ���ai��
int ai_temp_len;//����һ��ȫ�ֵ�ai�ߵ���ʱ���ȣ�ʹֻ֮����һ��
int level;//����һ���Ѷ�
int speed;//ȫ���ٶ�

//ʹ��externȫ�ֱ���
IMAGE img;//ʹ��main�ﶨ���ȫ��img
TCHAR playername[11];//ʹ��main�ﶨ���ȫ��playname


//����һ��ai��
snake ss[30];
//1.��ʼ��
void init()
{
	//���ӹ��ܣ�
	//---��������
	mciSendString(L"open ./source/bird.mp3", 0, 0, 0);//������
	mciSendString(L"play ./source/bird.mp3 repeat", 0, 0, 0); //�ȴ� Ȼ�󲥷�
	//��ȡ�浵
	load_record();
	load_player();
	deside();
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
	//ʳ�ﲻ�ܳ������ߵ�����
	
again:	f.f_pt.col = rand() % 18 + 1;//food����λ�ÿ�����1-18���ڣ���Ϊ������Ӧ������
		f.f_pt.row = rand() % 18 + 1;
		for (int i = 0; i < s.len; i++)
		{
			if (f.f_pt.col == s.pt[i].col&&f.f_pt.row == s.pt[i].row)
				goto again;
		}
}
//2.������Ϸ

void gameprint()
{
	cleardevice();//��������������ͻử��
	BeginBatchDraw();
	
	putimage(0, 0, &img);
	//setbkcolor(CYAN);
	
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

	//��ai��
	
	for (int j = 0; j < num; j++)
	{
		for (int i = 0; i < ss[j].len; i++)
		{
			if (i == 0)
			{
				setfillcolor(BLUE);//����ͷ��Ϊ��ɫ
								  //fillrectangle(s.pt[i].col*WIDTH, s.pt[i].row*HEIGHT, (s.pt[i].col + 1)*WIDTH, (s.pt[i].row + 1)*HEIGHT);
				fillroundrect(ss[j].pt[i].col*WIDTH, ss[j].pt[i].row*HEIGHT, (ss[j].pt[i].col + 1)*WIDTH, (ss[j].pt[i].row + 1)*HEIGHT, 10, 10);
			}
			else
			{
				setfillcolor(GREEN);//��������Ϊ��ɫ
				fillrectangle(ss[j].pt[i].col*WIDTH, ss[j].pt[i].row*HEIGHT, (ss[j].pt[i].col + 1)*WIDTH, (ss[j].pt[i].row + 1)*HEIGHT);
			}
		}

	}
	//����ai��
	for (int j = 0; j < num; j++)
	{
		for (int i = ss[j].len - 1; i >= 1; i--)
			ss[j].pt[i] = ss[j].pt[i - 1];
	}


	//�������
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
	
	

	//FlushBatchDraw();ˢ��ʣ�µ�ͼ��
	settextstyle(20, 0, L"����");
	settextcolor(RED);
	setbkmode(TRANSPARENT);//���屳��͸��
	TCHAR str[5] ;
	_stprintf_s(str, _T("%d"), s.len - 3);//sprintf ��T��,����ת�ַ���
	outtextxy(16*WIDTH, 0, L"��ǰ�÷֣�");
	outtextxy(19 * WIDTH, 0, str);//(��ʾ�÷֣�������)���Ż�
	TCHAR str1[5];
	_stprintf_s(str1, _T("%d"), high_score);
	outtextxy(16 * WIDTH, 1*HEIGHT, L"��ߵ÷֣�");
	outtextxy(19 * WIDTH, 1 * HEIGHT, str1);
	outtextxy(14 * WIDTH, 2 * HEIGHT, L"��¼�����ߣ�");
	outtextxy(18 * WIDTH, 2 * HEIGHT, temp_player);

	

	EndBatchDraw();
}

//3.����Ϸ
void playgame()
{
	char direction;
	while (1)//���������̵�ʱ������һ�������ƶ�
	{
		if (level == 1 )
			num = (s.len - 3) / 10;
		else if (level == 2 || level == 3)
			num = (s.len - 3) / 10 + 1;
		while (!_kbhit())//kbhit()���������ɰ��£����򷵻ط�0ֵ�����򷵻�0���������ƣ������ǲ���������Զ��ƶ�?
		{
			//clock_t delay = 1*CLOCKS_PER_SEC;//ai_�� ��ʱһ��
			//clock_t start = clock();
			//����ÿһ���Զ���һ�¶��������ߵ��ƶ�Ƶ���޹�
			/*
			�����Ǹ�������������ο���
			0.��һ���߳�  windows���̣߳�һ�� �����߳� CreateThread
			1.�첽����
			2.�ص�����
			3.�����ϲ���
			*/
			
			ai_game_judgement();
			game_judgement();

			gameprint();
			ai_snakemove();//��Ҫ��ai_snakemove����ai_init
			snakemove();//�Ȼ���
			my_sleep(speed-s.len);
			
			//Sleep(200-s.len);//�����ߵ��ٶ�,ͣһ��ʱ�����ִ��1000ÿ��һ���ƶ�һ�Σ����Ż��������ߵ�len���������ٶȼӿ죩���Ż�1.1
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
		//д��浵������߼�¼
		//save_record();
		snakefood();//��������һ��ʳ��
	}
	//��׼��
	if (s.pt[0].col < 0 || s.pt[0].col>19 || s.pt[0].row < 0 || s.pt[0].row>19)//ײǽ
	{
		if (s.len - 3 > high_score)
		{
			save_player();//��������
			save_record();//�������
		}
			
		mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//�ر�����
		if (MessageBox(GetHWnd(), L"Game over�Ƿ����¿�ʼ", L"��Ϸ��ʾ", MB_YESNO) == IDYES)
		{
			init();
			ai_init();
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

	for (int i = 1; i < s.len; i++)//ײ������
	{
		if (s.pt[0].col == s.pt[i].col&&s.pt[0].row == s.pt[i].row)
		{
			if (s.len - 3 > high_score)
				save_record();//����
			mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//�ر�����
			if (MessageBox(GetHWnd(), L"Game over�Ƿ����¿�ʼ", L"��Ϸ��ʾ", MB_YESNO) == IDYES)
			{
				init();
				ai_init();
				break;
			}
			
			else
				exit(0);
		}
	}

	//ײ��ai��
	for (int j = 0; j < num; j++)//j��ʾ�ǵڼ�ֻai��
	{
		for (int i = 0; i < ss[j].len; i++)
		{
			if (s.pt[0].col == ss[j].pt[i].col&&s.pt[0].row == ss[j].pt[i].row)
			{
				if (s.len - 3 > high_score)
					save_record();//����
				mciSendString(L"close ./source/bird.mp3", 0, 0, 0);//�ر�����
				if (MessageBox(GetHWnd(), L"Game over�Ƿ����¿�ʼ", L"��Ϸ��ʾ", MB_YESNO) == IDYES)
				{
					init();
					ai_init();
					break;
				}

				else
					exit(0);
			}
		}
		
	}
}
//д��浵
void save_record()
{
	FILE* fid1 = fopen("./source/record.txt", "w");
	char temp[10] = { 0 };
	sprintf_s(temp, "%d", s.len - 3);
	fwrite(temp, 1, strlen(temp), fid1);
	fclose(fid1);

}
//д����߳ɼ�������
void save_player()
{
	
	FILE* fid0 = fopen("./source/player.txt", "w");
	fwrite(playername, 11, 1, fid0);
	fclose(fid0);
}
//��ȡ�浵
void load_record()
{
	FILE* fid2 = fopen("./source/record.txt", "r");
	char buff[10] = { 0 };
	fread(buff, 1, 5, fid2);
	sscanf(buff, "%d", &high_score);//�ַ���תint
	fclose(fid2);
}
//��ȡ��߳ɼ�������
void load_player()
{
	FILE* fid3 = fopen("./source/player.txt", "r");
	fread(temp_player, 11, 1, fid3);
	fclose(fid3);
}

//my_sleep���� ���ڼ�����Ӧʱ����sleep����
void my_sleep(double  n)//������Ҫ��ͣ������
{
	long    tm1;
	tm1 = clock(); //����ʱ��tick��
	while (!_kbhit())
	{
		if ((double)(clock() - tm1) / CLOCKS_PER_SEC >= n/1000) break;
		//(double)(clock()-tm1)/CLOCKS_PER_SEC:���δ���ת��Ϊ���������ڲ���ֵ���˳�ѭ��
		//�ж��Ƿ���ִ�е��������ڲ����趨�������������򷵻�
		//�����������ʵ�ֳ�����ӳ�
	}
}

void ai_init()//ai_snake
{
	for (int j = 0; j < 30; j++)
	{
		ss[j].pt[0].col = 10;//set������
		ss[j].pt[0].row = 10;//set������

		ss[j].ch = RIGHT;//�����������ƶ�(��������������򣬴�����)

		ss[j].len = 3;//�����ߵĳ�ʼ����Ϊ3����ʼ���ȿ������ã���ѧ�˽��������޸ģ�

				  //���ߵ������ʼ��(���Ż�������ͷ���ֵ�����λ�ðڷ�����)
		for (int i = 1; i < MAXSIZE; i++)
		{
			ss[j].pt[i].col = -1;
			ss[j].pt[i].row = -1;
		}
	}
}


void ai_snakemove()
{
	for (int i = 0; i < num; i++)
	{
		int d = rand() % 4;
		switch (d)//�жϽ�����Ҫ�ߵķ���,��ͷ�ƶ�
		{
		case 0://�����������
			if (ss[i].ch != DOWN)//���ԭ�������µĲ�������
			{
				ss[i].pt[0].row -= 1;//����
				ss[i].ch = UP;
			}
			else
				ss[i].pt[0].row += 1;//���ּ�������
			break;
		case 1:
			if (ss[i].ch != UP)
			{
				ss[i].pt[0].row += 1;
				ss[i].ch = DOWN;
			}
			else
				ss[i].pt[0].row -= 1;
			break;
		case 2:
			if (ss[i].ch != RIGHT)
			{
				ss[i].pt[0].col -= 1;
				ss[i].ch = LEFT;
			}
			else
				ss[i].pt[0].col += 1;
			break;
		case 3:
			if (ss[i].ch != LEFT)
			{
				ss[i].pt[0].col += 1;
				ss[i].ch = RIGHT;
			}
			else
				ss[i].pt[0].col -= 1;
			break;
		}
	}
}

//void ai_sleep(clock_t wait)
//{
//	clock_t goal;
//	goal = wait + clock();
//	while (goal > clock());
//}

void ai_game_judgement()
{
	for (int i = 0; i < num; i++)
	{
		//���ai�߳���ʳ��
		if (ss[i].pt[0].col == f.f_pt.col&&ss[i].pt[0].row == f.f_pt.row)
		{
			ss[i].len++;//������+1
					//д��浵������߼�¼
					//save_record();
			snakefood();//��������һ��ʳ��
		}
		//ai��Ҳ������ʱ����Ȼ����
		if ((s.len % 10) == 0 && ai_temp_len != s.len)
		{
			//ÿ�������ߵĳ��ȵ�10��ai�ߵĳ��Ⱦ�+1
			ss[i].len++;
			ai_temp_len = s.len;//ԭ���㷨����֤���µ�10 ��ʱ��ֻ����һ��++
		}
		//aiײ��ǽ������һ�˳���
		if (ss[i].pt[0].col < 0)
			ss[i].pt[0].col = 19;
		else if (ss[i].pt[0].col > 19)
			ss[i].pt[0].col = 0;
		else if (ss[i].pt[0].row < 0)
			ss[i].pt[0].row = 19;
		else if (ss[i].pt[0].row > 19)
			ss[i].pt[0].row = 0;
	}
	//ai��ײ��������
	for (int j = 0; j < num; j++)
	{
		for (int i = 1; i < s.len; i++)//ײ�������ߵ�����
		{
			if (ss[j].pt[0].col == s.pt[i].col&&ss[j].pt[0].row == s.pt[i].row)
			{
				ss[j].pt[0].col = 10;//set������
				ss[j].pt[0].row = 10;//set������

				ss[j].ch = RIGHT;//�����������ƶ�(��������������򣬴�����)

				ss[j].len = 3;//�����ߵĳ�ʼ����Ϊ3����ʼ���ȿ������ã���ѧ�˽��������޸ģ�

				for (int i = 1; i < MAXSIZE; i++)//ai�������
				{
					ss[j].pt[i].col = -1;
					ss[j].pt[i].row = -1;
				}
			}

		}
	}
}

//���뿪ʼ����
void set_background()
{
	initgraph(20 * WIDTH, 20 * HEIGHT);
	//loading
	IMAGE img0;
	loadimage(&img0, L"./source/snake.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img0);
	Sleep(1000);
	//��ʼ��Ϸ����
	IMAGE img1_0;
	loadimage(&img1_0, L"./source/snake1_0.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img1_0);
	MOUSEMSG msg;
	int flag = 1;
	while (flag)
	{
		msg = GetMouseMsg();//��ȡ�����Ϣ
		switch (msg.uMsg)//�ж������Ϣ
		{
		case WM_LBUTTONDOWN://�������
			if (msg.x > 8 * WIDTH && msg.x<12 * WIDTH && msg.y>14 * HEIGHT && msg.y < 16 * HEIGHT)
				flag = 0;//����������ڷ���֮��   �����˳�ѭ��
			break;
		}
	}
	//��������ʼ��ļӴ����廭��
	IMAGE img1_1;
	loadimage(&img1_1, L"./source/snake1_1.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img1_1);
	Sleep(300);

	//�����ߵĳ�ʼ�˶��ٶ�//1.û����/���� 2.����/���� 3.����/����
	IMAGE img2_0;
	loadimage(&img2_0, L"./source/snake2_0.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img2_0);

	flag = 1;
	while (flag)
	{
		msg = GetMouseMsg();//��ȡ�����Ϣ
		switch (msg.uMsg)//�ж������Ϣ
		{
		case WM_LBUTTONDOWN://�������
			if (msg.x > 8 * WIDTH && msg.x < 12 * WIDTH && msg.y>13 * HEIGHT && msg.y < 14.5 * HEIGHT)
			{
				flag = 0;
				level = 1;
			}
			else if (msg.x > 8 * WIDTH && msg.x < 12 * WIDTH && msg.y>15 * HEIGHT && msg.y < 16.5 * HEIGHT)
			{
				flag = 0;
				level = 2;
			}
			else if (msg.x > 8 * WIDTH && msg.x < 12 * WIDTH && msg.y>17 * HEIGHT && msg.y < 18.5 * HEIGHT)
			{
				flag = 0;
				level = 3;
			}
			break;
		}
	}
	if (level == 1)
		set_background_2_1();
	else if (level == 2)
		set_background_2_2();
	else if (level == 3)
		set_background_2_3();
}

//�����ģʽ
void set_background_2_1()
{
	IMAGE img2_1;
	loadimage(&img2_1, L"./source/snake2_1.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img2_1);
	Sleep(300);
}
//�����е�ģʽ
void set_background_2_2()
{
	IMAGE img2_2;
	loadimage(&img2_2, L"./source/snake2_2.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img2_2);
	Sleep(300);
}
//��������ģʽ
void set_background_2_3()
{
	IMAGE img2_3;
	loadimage(&img2_3, L"./source/snake2_3.jpg", 20 * WIDTH, 20 * HEIGHT);
	putimage(0, 0, &img2_3);
	Sleep(300);
}
//����ai�ߵ������������ٶ�
void deside()
{
	if (level == 1)
	{
		num = 0;
		speed = 200;
		return;
	}
	if (level == 2)
	{
		num = 1;
		speed = 200;
		return;
	}
	if (level == 3)
	{
		num = 1;
		speed = 100;
		return;
	}
}