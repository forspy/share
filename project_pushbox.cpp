#include<stdio.h>
#include<conio.h>
#include<graphics.h>//ͼ�ο�ͷ�ļ�
#include<mmsystem.h>//ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��ý���
/*
1.���ֲ���  mciSendString   MP3  wav��ʽ����   ���ֲ�Ҫ��������
#include<mmsystem.h>//ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��ý���

PlaySound  ֻ�ܲ���wav

2.������  �ز� ������Ƭ-->jpg����bmp��ʽ
ͼ�ο�


�����ӵ�����  ---->��ͼ--->�ƶ�����   ����ȫ���ƶ���Ŀ�ĵ��ϵ�ʱ�� ��Ϸ����

����  ÿһ��������Ӧһ������
1.׼������   ��ͼ��Ҫ׼��  �ز�Ҳ��Ҫ׼��
2.������
3.�ж���Ϸ�Ƿ����
���ݴ�Ų���
������   ��2  ����3  Ŀ�ĵ�4  �յ�0  ǽ1--->����洢
��+Ŀ�ĵ�--->2+4  6
����+Ŀ�ĵ�---->7
*/
int map[8][8] = {//����Ŀյ�   ������ز�   �������ֿ��Բ�һ��)
	0,0,1,1,1,0,0,0,
	0,0,1,4,1,0,0,0,
	0,0,1,0,1,1,1,1,
	1,1,1,3,0,3,4,1,
	1,4,0,3,2,1,1,1,
	1,1,1,1,3,1,0,0,
	0,0,0,1,4,1,0,0,
	0,0,0,1,1,1,0,0
};//8*8�ĵ�ͼ  --->ÿ��ͼƬ��С80*80  �ܴ�С640*640
//int map[8][8] = {//����Ŀյ�   ������ز�   �������ֿ��Բ�һ��)
//	0,0,0,0,0,0,0,0,
//	0,0,0,4,0,0,0,0,
//	0,0,0,0,0,0,0,0,
//	1,1,1,3,0,3,4,1,
//	1,4,0,3,2,1,1,1,
//	1,1,1,1,3,1,0,0,
//	0,0,0,1,4,1,0,0,
//	0,0,0,1,1,1,0,0
//};//8*8�ĵ�ͼ  --->ÿ��ͼƬ��С80*80  �ܴ�С640*640
IMAGE img[6];//�ܹ�6���ز�//ȫ��  �����˶������� 

void init()//�����ز�
{
	//����ͼƬ;
	loadimage(&img[0], "�ز�/����.jpg", 640, 640);
	loadimage(&img[1], "�ز�/Ŀ�ĵ�.jpg", 80, 80);//�����Ƶ�Ŀ�ĵ���
	loadimage(&img[2], "�ز�/ǽ.jpg", 80, 80);
	loadimage(&img[3], "�ز�/����.jpg", 80, 80);
	loadimage(&img[4], "�ز�/����.jpg", 80, 80);
	loadimage(&img[5], "�ز�/Դ��.jpg", 80, 80);//�յ�Ŀ�ĵ�

}
void drawMap()//����ͼ
{
	putimage(0, 0, &img[0]);
	for (int i = 0; i < 8; ++i)//�����С��8
	{
		for (int j = 0; j < 8; ++j)
		{
			switch (map[i][j])//��������
			{
			case 0:
				break;
			case 1:
				putimage(j * 80, i * 80, &img[2]);//ǰ������λ��������
				break;
			case 2:
				putimage(j * 80, i * 80, &img[3]);
				break;
			case 3://����
				putimage(j * 80, i * 80, &img[4]);
				break;
			case 4://Ŀ�ĵ�
				putimage(j * 80, i * 80, &img[5]);
				break;
			case 6:
				putimage(j * 80, i * 80, &img[3]);
				break;
			case 7:
				putimage(j * 80, i * 80, &img[1]);
				break;
			}
		}
	}
}
void play()//��������
{
	int row, column;//�ҵ������λ��
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (map[i][j] == 2 || map[i][j] == 6)//�˵�λ��
			{
				row = i;
				column = j;//�������˵�λ��
			}
		}
	}
	//Ȼ���ж��û����� 
	//getch  --->��ȡ�û�����  conio.h

	switch (getch())//getch()���벻�ð��س�
	{
	case 'W'://����
	case 'w':
		if (map[row - 1][column] == 0 || map[row - 1][column] == 4)
			//�Ϸ��ǿյ� �����ǿյ�Ŀ�ĵ�
		{
			map[row][column] -= 2;//map[x][y]=map[x][y]-2;
			map[row - 1][column] += 2;//��������
		}
		else if (map[row - 1][column] == 3 || map[row - 1][column] == 7)
			//�˵��Ϸ������ӻ�������+Ŀ�ĵ�
		{
			if (map[row - 2][column] == 0 || map[row - 2][column] == 4)//�����Ϸ��ǿյ�  �ƶ�
			{
				map[row][column] -= 2;//��������
				map[row - 1][column] -= 1;//������+2  ������ȥ��-3
				map[row - 2][column] += 3;//����������
			}
		}
		//else if ((map[x - 1][y] == 3 || map[x - 1][y] == 7) && (map[x - 2][y] == 0 || map[x - 2][y] == 4))
		break;
	case 'A'://����
	case 'a':
		if (map[row][column - 1] == 0 || map[row][column - 1] == 4)
		{
			map[row][column] -= 2;
			map[row][column - 1] += 2;
		}
		else if (map[row][column - 1] == 3 || map[row][column - 1] == 7)
		{
			if (map[row][column - 2] == 0 || map[row][column - 2] == 4)
			{
				map[row][column] -= 2;
				map[row][column - 1] -= 1;
				map[row][column - 2] += 3;
			}
		}
		break;
	case 'D'://����
	case 'd':
		if (map[row][column + 1] == 0 || map[row][column + 1] == 4)
		{
			map[row][column] -= 2;
			map[row][column + 1] += 2;
		}
		else if (map[row][column + 1] == 3 || map[row][column + 1] == 7)
		{
			if (map[row][column + 2] == 0 || map[row][column + 2] == 4)
			{
				map[row][column] -= 2;
				map[row][column + 1] -= 1;
				map[row][column + 2] += 3;
			}
		}
		break;

	case 'S':
	case 's':
		if (map[row + 1][column] == 0 || map[row + 1][column] == 4)//�Ϸ��ǿյ� �����ǿյ�Ŀ�ĵ�
		{
			map[row][column] -= 2;//map[x][y]=map[x][y]-2;
			map[row + 1][column] += 2;//��������
		}
		else if (map[row + 1][column] == 3 || map[row + 1][column] == 7)//�˵��Ϸ������ӻ�������+Ŀ�ĵ�
		{
			if (map[row + 2][column] == 0 || map[row + 2][column] == 4)//�����Ϸ��ǿյ�  �ƶ�
			{
				map[row][column] -= 2;//��������
				map[row + 1][column] -= 1;//������+2  ������ȥ��-3
				map[row + 2][column] += 3;//����������
			}
		}
		break;
	}




}
void gameOver()
{
	//ʲôʱ����Ϸ���Խ��� 
	//1. Ӯ    ��������ȫ�����Ƶ�Ŀ�ĵ���-->����û������ 
	//2.��  ��Ϸ��ʱ  �����Ƶ�����
	int flag = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (map[i][j] == 3)//�ҵ�������  ��Ϸ��û��Ӯ
			{
				++flag;//���ӵĸ���
				if (map[i - 1][j] == 1 || map[i + 1][j] == 1)//�Ϸ������·���һ��
				{
					if (map[i][j - 1] == 1 || map[i][j - 1] == 1)//������һ��
					{
						//��Ϸ����  ��
						MessageBox(GetHWnd(), "��", "sad", MB_OK);
						closegraph();
						exit(0);
					}
				}
			}
		}
	}
	if (flag == 0)
	{
		//û������
		//��Ϸ���� Ӯ
		//return 
		MessageBox(GetHWnd(), "Ӯ", "GOOD", MB_OK);
		//��һ������ ���   ����  �ô�����ǰ  Ҳ����дNULL  0
		//�ڶ������ı�  �������Ǳ���  ���ĸ��ǰ�ť
		closegraph();
		exit(0);//�˳�����
	}

}
int main()
{
	mciSendString("open �ز�/bgm.mp3", 0, 0, 0);//������
	mciSendString("play �ز�/bgm.mp3 repeat", 0, 0, 0); //�ȴ� Ȼ�󲥷�
	//�����repeat��ʾѭ������
	//mciSendString("open �ز�/bgm.mp3 alias bgm", 0, 0, 0);//������ alias bgmȡһ������
	//mciSendString("play bgm repeat", 0, 0, 0); //�ȴ� Ȼ�󲥷�
	//�ر�����  stop  ��ͣ pause
	initgraph(640, 640);
	init();//����ͼƬ

		   //��ʼ����=========================================
	putimage(0, 0, &img[0]);//����ͼ
	settextstyle(40, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//���屳��͸��
	//setbkmode(1);//���ñ���ģʽ
				 //set background mode 
	//rectangle(200, 200, 400, 400);//������
	outtextxy(250, 250, "��ʼ��Ϸ");
	MOUSEMSG msg;
	int flag = 1;
	while (flag)
	{
		msg = GetMouseMsg();//��ȡ�����Ϣ
		switch (msg.uMsg)//�ж������Ϣ
		{
		case WM_LBUTTONDOWN://�������
			if (msg.x > 200 && msg.x<400 && msg.y>200 && msg.y < 400)
			{
				//����������ڷ���֮��   �����˳�ѭ��
				flag = 0;
			}
			break;
		default:
			break;
		}
	}

	/*
	������
	MouseHit() �ж��Ƿ���������Ϣ
	MOUSEMSG  ���� ����������Ϣ
	GetMouseMsg()   ��ȡ�����Ϣ�ĺ���
	*/

	//====================================================
	drawMap();
	while (1)
	{
		play();
		drawMap();
		gameOver();
	}
	getchar();
	closegraph();
	return 0;
}