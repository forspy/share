#include<stdio.h>
#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<mmsystem.h>//���ֲ���
#pragma comment(lib,"winmm.lib")//���ؿ��ļ������ֲ��ţ������Ƶ�mp3�ò��ˣ��ӹ���
int main()
{
	initgraph(640, 480);   // ������ͼ���ڣ���СΪ 640x480 ����
	circle(200, 200, 100); // ��Բ��Բ��(200, 200)���뾶 100
	setlinecolor(RGB(255, 60, 70));//������
	//setlinecolor(TRANSPARENT);͸��ɫ
	setfillcolor(BLUE);//�������䶼����
	ellipse(10, 20, 200, 100);//˫����
	line(100, 100, 200, 200);
	rectangle(100, 100, 200, 200);//����
	roundrect(20, 30, 90, 90,50,50);//Բ�Ǿ���
	fillellipse(10, 20, 70, 70);//�����Բ
	fillellipse(10, 20, 120, 120);
	
	IMAGE p;
	IMAGE *ptr;
	ptr = &p;//����ptr����һ��ֵ�ˣ�ע���ʼ����ָ�봴������Ҫָ��Ҳ����ֱ��loadimage(&p,
	//loadimage(NULL, "C:/Users/qq315/Desktop/΢�Ź��ں��ļ���ͼƬ/�㷨/1.jpg");//·������б��/    ����һ
	loadimage(ptr, "C:/Users/qq315/Desktop/΢�Ź��ں��ļ���ͼƬ/�㷨/1.jpg");
	putimage(100,100,ptr);//��������λ��+ָ��
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	outtextxy(100, 100, "aaa");
	//��������
	mciSendString("open haha.mp3 alias xxx", NULL, NULL, NULL);
	mciSendString("play xxx repeat", NULL, NULL, NULL);

	MOUSEMSG msg;
	while (1)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)//�ж���Ϣ����
		{
		case WM_LBUTTONDOWN:

			//MessageBox(NULL, "hello", "hello", MB_OK);
			circle(msg.x, msg.y, 100);
			break;
		default:
			break;
		}
	}
	//mciSendString("stop xxx ", NULL, NULL, NULL);
	//textwidget'h
	//easyX���е�����Ҫ�������루����getch��ǰ
	_getch();              // �����������,����Ҫ�س�������Ҫstdio.h
	//getchar();              // �����������
	closegraph();          // �رջ�ͼ����
	//��ͼ��ps��png ��gif��ͼƬ��������bmp/jpg/gif/emf/wmf/ico��ͼƬ������
	
}