#include<stdio.h>
#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <windows.h>
void main()
{
	initgraph(400, 480);   // ������ͼ���ڣ���СΪ 640x480 ����
	circle(200, 200, 100); // ��Բ��Բ��(200, 200)���뾶 100
	system("pause");             // �����������
	closegraph();          // �رջ�ͼ����
}