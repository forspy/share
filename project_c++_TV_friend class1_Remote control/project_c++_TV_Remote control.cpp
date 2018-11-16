#include"Tv.h"
#include<iostream>
using namespace std;
int main()
{
	Tv television;//创建Tv上的手动设置
	television.setting();
	television.onoff();
	television.chanup();//上调频道
	television.chanup();
	television.setting();
	
	Remote Rcontrol;
	Rcontrol.set_chan(television, 42);
	Rcontrol.volup(television);//参数为television对象
	Rcontrol.volup(television);//继续上调
	television.setting();

	Tv television2(Tv::On);
	television2.set_mode();
	Rcontrol.set_chan(television2, 28);
	television2.setting();
	//所以，友元类可以用来表示一些关系
}