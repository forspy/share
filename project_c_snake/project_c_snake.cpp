#include"snake.h"
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
extern TCHAR playername[11];//playername��Ϊһ��ȫ�ֹ��������ȫ�ֱ������Զ���ֵΪ0����Ҫ���⸳ֵ
extern IMAGE img;

int main()
{
	
	set_background();
	
	loadimage(&img, L"./source/Grassland.jpg", 20 * WIDTH, 20 * WIDTH);
	
	InputBox(playername, 11, L"�����������");
	srand((unsigned)time(NULL));
	init();
	ai_init();
	//������Ϸ
	//gameprint();
	playgame();
	//�ڷ���release�汾��ʱ��ѡ����߳�MT(project ���ԣ�c/c++->��������)����̬����أ���MDΪ���߳�DLL��̬����أ�,��̬�⶯̬����أ����о�
}