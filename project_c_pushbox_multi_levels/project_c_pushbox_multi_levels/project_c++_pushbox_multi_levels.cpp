#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Sokoban.h"
//-----����ͷ�ļ�
#include<mmsystem.h>//ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��ý���
//-----

int main()
{
	//---��������
	mciSendString(L"open ./source/PoPoyans.mp3", 0, 0, 0);//������
	mciSendString(L"play ./source/PoPoyans.mp3 repeat", 0, 0, 0); //�ȴ� Ȼ�󲥷�
	//------
	int game_level = 1;
	//��ȡ�浵
	FILE* fd1 = fopen("save.txt", "r");
	char buff[10] = { 0 };
	fread(buff, 1, 5, fd1);
	sscanf(buff,"%d",&game_level);//�ַ���תint
	//game_level = atoi(buff);//���Ƽ�ʹ��
	fclose(fd1);

	LoadPicture();

	if (set_background() == 0)
		game_level = 1;
	closegraph();

	initgraph(Col*Size, Row*Size);//x,y����,����ʵ�ǵڶ������ڣ���Ϊ��ͼƬ��д���ֻ�����ӡ�ǣ�ԭ�������
	//�����ڿ�ʼ�����Ժ����´���һ������
	
	//1.��ʼ��
	if (LoadMap(game_level) == 0)
		MessageBox(GetHWnd(), L"��Ϸ��ʼ��ʧ��", L"sorry", MB_OK);

	while (1)
	{
		//2.���ݼ��ص�ͼ��Ϣ���Ƶ�ͼ
		DrawGame(game_level);
		//3.�ı��ͼ��Ϣ
		PlayGame();
		//4.�����Ժ���¼��ص�ͼ��Ϣ
		if (iswin() == 1)
		{
			game_level++;
			//��ȡ�浵-----
			FILE* fd2 = fopen("save.txt", "w");
			char temp[10] = { 0 };
			sprintf(temp, "%d", game_level);//int ת�ַ���
			fwrite(temp, 1, strlen(temp), fd2);
			fclose(fd2);
			//------------
			if (LoadMap(game_level) == 0)//��һ������LoadMap(game_level)�ĵ�ͼ����
			{
				//system("cls");
				if (MessageBox(GetHWnd(), L"��ϲ����Ϸ�Ѿ�ͨ�أ��Ƿ����¿�ʼ", L"��ϲ", MB_YESNO) == IDYES)
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