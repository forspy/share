#include<stdio.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include<mmsystem.h>//音乐播放
#pragma comment(lib,"winmm.lib")//加载库文件，音乐播放，网易云的mp3用不了，加过密
int main()
{
	initgraph(640, 480);   // 创建绘图窗口，大小为 640x480 像素
	circle(200, 200, 100); // 画圆，圆心(200, 200)，半径 100
	setlinecolor(RGB(255, 60, 70));//红绿蓝
	//setlinecolor(TRANSPARENT);透明色
	setfillcolor(BLUE);//下面的填充都设置
	ellipse(10, 20, 200, 100);//双坐标
	line(100, 100, 200, 200);
	rectangle(100, 100, 200, 200);//矩形
	roundrect(20, 30, 90, 90,50,50);//圆角矩形
	fillellipse(10, 20, 70, 70);//填充椭圆
	fillellipse(10, 20, 120, 120);
	
	IMAGE p;
	IMAGE *ptr;
	ptr = &p;//这样ptr就有一个值了，注意初始化，指针创建出来要指向，也可以直接loadimage(&p,
	//loadimage(NULL, "C:/Users/qq315/Desktop/微信公众号文件和图片/算法/1.jpg");//路径：正斜杠/    方法一
	loadimage(ptr, "C:/Users/qq315/Desktop/微信公众号文件和图片/算法/1.jpg");
	putimage(100,100,ptr);//方法二：位置+指针
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	outtextxy(100, 100, "aaa");
	//播放音乐
	mciSendString("open haha.mp3 alias xxx", NULL, NULL, NULL);
	mciSendString("play xxx repeat", NULL, NULL, NULL);

	MOUSEMSG msg;
	while (1)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)//判断消息类型
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
	//easyX所有的命令要放在输入（比如getch）前
	_getch();              // 按任意键继续,不需要回车，不需要stdio.h
	//getchar();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
	//贴图（ps：png 和gif的图片不能贴，bmp/jpg/gif/emf/wmf/ico的图片能贴）
	
}