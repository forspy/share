#include"Tv.h"
#include<iostream>
using namespace std;
int main()
{
	Tv television;//����Tv�ϵ��ֶ�����
	television.setting();
	television.onoff();
	television.chanup();//�ϵ�Ƶ��
	television.chanup();
	television.setting();
	
	Remote Rcontrol;
	Rcontrol.set_chan(television, 42);
	Rcontrol.volup(television);//����Ϊtelevision����
	Rcontrol.volup(television);//�����ϵ�
	television.setting();

	Tv television2(Tv::On);
	television2.set_mode();
	Rcontrol.set_chan(television2, 28);
	television2.setting();
	//���ԣ���Ԫ�����������ʾһЩ��ϵ
}