#include"snake.h"
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main()
{
	
	initgraph(20 * WIDTH, 20 * HEIGHT);//(���ڱ�������Ҫ�ģ�������)
	srand((unsigned)time(NULL));
	init();
	//������Ϸ
	//gameprint();
	playgame();
	//�ڷ���release�汾��ʱ��ѡ����߳�MT(project ���ԣ�c/c++->��������)����̬����أ���MDΪ���߳�DLL��̬����أ�,��̬�⶯̬����أ����о�
}