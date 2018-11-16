#pragma once
class Tv
{
private:
	int state;//开或关
	int volume;//音量
	int maxchannel;//最大频道
	int channel;//当前频道
	int mode;//模式
	int input;//TV orDVD
public:
	//遥控器和电视机不是is-a的关系，也不是has-a的关系，但遥控器可以改变电视机状态，所以遥控器是电视机的友元类
	friend class Remote;//友元类Remote（以及方法）可以获取私有保护和公有成员
	//---enum成员都是int类型的
	enum{Off,On};
	enum{MinVal,Maxval=20};
	enum{Antenna,Cable};//天线、电缆
	enum{TV,DVD};

	Tv(int s=Off,int mc=125):state(s),volume(5),maxchannel(mc),channel(2),mode(Cable),input(TV){ }
	void onoff() { state = (state == On) ? Off : On; }//利用简单的三目开关机
	bool ison() const{ return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }//利用简单的三目切换模式
	void set_input() { input = (input = TV) ? DVD : TV; }
	void setting();//显示所有设置
};
class Remote
{
private:
	int mode;
public:
	Remote(int m=Tv::TV):mode(m){ }//默认TV模式打开
	bool volup(Tv& t) { return t.volup(); }//通过友元类使用了Tv类的成员和方法
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }//直接改变Tv类成员
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
};