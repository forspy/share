#define _CRT_SECURE_NO_WARNINGS
#include"Sokoban.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//easyXͼ�ο�ֻ֧��c++������Ҫд��cpp�ļ���

int Map[Row][Col];//9*8,��һ��������ʾ��ǰ�ؿ�����
IMAGE img[7];
//IMAGE img[6];


//���ص�ͼ
int LoadMap(int MapId)
{
	FILE* fid = fopen("Map.txt","r");

	if (!fid)
		return 0;
	//�����ļ�ָ��λ�� ע��ÿ�л���\n ����Map.txt�ĵ�һ���ǿյ� \n���ƶ�����λ��
	fseek(fid, (MapId - 1) * 66, SEEK_SET);//8*8+2
	char str[65] = { 0 };
	int n=fread(str, 64,1, fid);
	fclose(fid);
	if (n == 0)
		return 0;
	//����λ���鸳ֵ
	int k = 0;
	for (int i = 1; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
			Map[i][j] = str[k++] - '0';//��Ϊstr���ַ���'1'=49   '0'=48��Ҳ����ʹ��atoi(),ѡҪ����ͷ�ļ�#include<stdlib.h>
	}
	return 1;//��ʾ��ȷ����
}
//����ͼƬ
void LoadPicture()
{
	loadimage(&img[0], L"./source/blank.jpg", Size, Size);//�յ� ���ֽ�Ҫ��L ����Ϊ���ֽڲ��� ����յص����˼·�Ƿ�ΪһС��һС��ȡ��
	loadimage(&img[1], L"./source/box.jpg", Size, Size);//����
	loadimage(&img[2], L"./source/dbox.jpg", Size, Size);//�����Ƶ�Ŀ�ĵ�
	loadimage(&img[3], L"./source/people.jpg", Size, Size);//��
	loadimage(&img[4], L"./source/point.jpg", Size, Size);//Ŀ�ĵ�
	loadimage(&img[5], L"./source/wall.jpg", Size, Size);//ǽ��
	loadimage(&img[6], L"./source/push_box.jpg", Col*Size, (Row-1)*Size);//��ʼ����ͼ��
}
int set_background()
{
	initgraph(Col*Size, Row*Size);//x,y����
	putimage(0, Size, &img[6]);//����ͼ
	settextstyle(40, 0, L"����");
	//settextcolor(BLACK);
	setbkmode(TRANSPARENT);//���屳��͸��
						   //setbkmode(1);//���ñ���ģʽ
						   //set background mode 
						   //rectangle(200, 200, 400, 400);//������
	outtextxy(0, 0, L"��ȡ�浵");
	outtextxy(4 * Size, 0, L"���¿�ʼ");
	MOUSEMSG msg;
	int flag = 1;
	while (flag)
	{
		msg = GetMouseMsg();//��ȡ�����Ϣ
		switch (msg.uMsg)//�ж������Ϣ
		{
		case WM_LBUTTONDOWN://�������
			if (msg.x > 0 && msg.x<4*Size && msg.y>0 && msg.y < Size)
			{
				//����������ڷ���֮��   �����˳�ѭ��
				flag = 0;
				return 1;
			}
			else if (msg.x > 4 * Size&&msg.x < 8 * Size &&msg.y>0 && msg.y < Size)
			{
				flag = 0;
				return 0;
			}
			break;
		}
	}
	return 1;
}
          
//���ݵ�ͼ��ͼ
void DrawGame(int MapId)
{
	for (int i = 1; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			switch (Map[i][j])//case ��ʾMap��ֵ
			{
			case 0://��ʾ�յ�
				putimage(j * Size, i * Size, &img[0]);
				break;
			case 1://��ʾǽ
				putimage(j * Size, i * Size, &img[5]);
				break;
			case 3://��ʾĿ�ĵ�
				putimage(j * Size, i * Size, &img[4]);
				break;
			case 4://��ʾ����
				putimage(j * Size, i * Size, &img[1]);
				break;
			case 5://��ʾ��
				putimage(j * Size, i * Size, &img[3]);
				break;
			case 7://��ʾ������Ŀ�ĵ�
				putimage(j * Size, i * Size, &img[2]);
				break;
			case 8://��ʾ����Ŀ�ĵ�
				putimage(j * Size,i * Size, &img[3]);
				break;
			}
		}
	}
	TCHAR sztemp[100] = { 0 };//��ʱ�ַ�������  charΪ���ֽ�  TCHARΪ���ֽ�����
	//��ʽ���ַ���
	wsprintf(sztemp, L"��ǰ��������%d��", MapId);//wsprintf�����ڿ��ֽ�buff���� һ����spirntf����
	settextstyle(30, 0, L"����");//�������L�������ö��ֽ��ַ��� 
	//settextcolor(GREEN);
	outtextxy(70, 5, sztemp);//��(80,0)����ʾ

}

//�ƶ�
void PlayGame()
{
	int p_row, p_col;
	int flag = 0;
	for (int i = 1; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Map[i][j] == 5 || Map[i][j] == 8)
			{
				p_row = i;
				p_col = j;
				//----����������ʽ��������ѭ��
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	char ch = _getch();
	//�˵�ֵΪ5
	switch (ch)
	{
	case 'W'://����
	case 'w':
		if (Map[p_row - 1][p_col] == 0 || Map[p_row - 1][p_col] == 3)
			//�Ϸ��ǿյ� �����ǿյ�Ŀ�ĵ�
		{
			Map[p_row][p_col]-=5;//��յ�
			Map[p_row - 1][p_col] += 5;//�յر���
		}
		else if (Map[p_row - 1][p_col] == 4 || Map[p_row - 1][p_col] == 7)
			//�˵��Ϸ������ӻ�������+Ŀ�ĵ�
		{
			if (Map[p_row - 2][p_col] == 0 || Map[p_row - 2][p_col] == 3)//�����Ϸ��ǿյػ�Ŀ�ĵ�  �ƶ�
			{
				Map[p_row][p_col] -= 5;//��������
				Map[p_row - 1][p_col] +=1;//������+5  ������ȥ��-4������+1
				Map[p_row - 2][p_col] += 4;//����������
			}
		}
		break;

	case 'S'://����
	case 's':
		if (Map[p_row + 1][p_col] == 0 || Map[p_row + 1][p_col] == 3)
			//�·��ǿյ� �����ǿյ�Ŀ�ĵ�
		{
			Map[p_row][p_col] -= 5;//��յ�
			Map[p_row + 1][p_col] += 5;//�յر���
		}
		else if (Map[p_row + 1][p_col] == 4 || Map[p_row + 1][p_col] == 7)
			//�˵��·������ӻ�������+Ŀ�ĵ�
		{
			if (Map[p_row + 2][p_col] == 0 || Map[p_row + 2][p_col] == 3)//�����·��ǿյػ�Ŀ�ĵ�  �ƶ�
			{
				Map[p_row][p_col] -= 5;//��������
				Map[p_row + 1][p_col] += 1;//������+5  ������ȥ��-4������+1
				Map[p_row + 2][p_col] += 4;//����������
			}
		}
		break;

	case 'A'://����
	case 'a':
		if (Map[p_row ][p_col-1] == 0 || Map[p_row ][p_col-1] == 3)
			//���ǿյ� �����ǿյ�Ŀ�ĵ�
		{
			Map[p_row][p_col] -= 5;//��յ�
			Map[p_row ][p_col-1] += 5;//�յر���
		}
		else if (Map[p_row][p_col-1] == 4 || Map[p_row][p_col-1] == 7)
			//�˵��������ӻ�������+Ŀ�ĵ�
		{
			if (Map[p_row ][p_col-2] == 0 || Map[p_row ][p_col-2] == 3)//�������ǿյػ�Ŀ�ĵ�  �ƶ�
			{
				Map[p_row][p_col] -= 5;//��������
				Map[p_row ][p_col-1] += 1;//������+5  ����ȥ��-4������+1
				Map[p_row ][p_col-2] += 4;//����������
			}
		}
		break;

	case 'D'://����
	case 'd':
		if (Map[p_row][p_col + 1] == 0 || Map[p_row][p_col+1] == 3)
			//�ҷ��ǿյ� �����ǿյ�Ŀ�ĵ�
		{
			Map[p_row][p_col] -= 5;//��յ�
			Map[p_row][p_col + 1] += 5;//�յر���
		}
		else if (Map[p_row][p_col + 1] == 4 || Map[p_row][p_col + 1] == 7)
			//�˵��ҷ������ӻ�������+Ŀ�ĵ�
		{
			if (Map[p_row][p_col + 2] == 0 || Map[p_row][p_col + 2] == 3)//�����ҷ��ǿյػ�Ŀ�ĵ�  �ƶ�
			{
				Map[p_row][p_col] -= 5;//��������
				Map[p_row][p_col + 1] += 1;//������+5  ����ȥ��-4������+1
				Map[p_row][p_col + 2] += 4;//����������
			}
		}
		break;
	}
	
}

//�����ж�
int iswin()
{
	//ʲôʱ����Ϸ���Խ��� 
	//1. Ӯ    ��������ȫ�����Ƶ�Ŀ�ĵ���-->����û������ 
	//2.��  ��Ϸ��ʱ  �����Ƶ�����
	int count = 0;
	for (int i = 1; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (Map[i][j] == 4)//�ҵ�������  ��Ϸ��û��Ӯ
			{
				count++;
				//�����������ǽ����
				//if (Map[i - 1][j] == 1 || Map[i + 1][j] == 1)//�Ϸ������·���һ��ǽ
				//{
				//	if (Map[i][j - 1] == 1 || Map[i][j + 1] == 1)//������һ��
				//	{
				//		//��Ϸ����  ��
				//		MessageBox(GetHWnd(), L"��", L"lose", MB_OK);
				//		closegraph();
				//		exit(0);//�˳�����
				//	}
				//		
				//}
				
			}
		}
	}
	if (count >0)
		return 0;
	else
		return 1;
		//û������
		//��Ϸ���� Ӯ
		//return 
		//MessageBox(GetHWnd(), L"��һ��", L"GOOD", MB_OK);
		//��һ������ ���   ����  �ô�����ǰ  Ҳ����дNULL  0
		//�ڶ������ı�  �������Ǳ���  ���ĸ��ǰ�ť
		//closegraph();
		//exit(0);//�˳�����

}

