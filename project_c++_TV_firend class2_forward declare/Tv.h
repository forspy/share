#pragma once
//前向声明
/*因为主要的方法都是Tv的，而Remote实际只有set_channel用到了Tv的成员，所以可以只在class Tv中写上Remote的方法并把它声明为友元
class Tv
{
friend void Remote::set_channel(Tv& t,int c);
*/
//因为依赖于Remote所以Remote放在前面，然而Remote里面还有Tv对象，所以需要一个前向声明
/*
顺序为：
class Tv;
class Remote//因为Tv只是一个前向声明，所以Remote里面不能有关于Tv的内联方法实现
{
...
};
class Tv
{
...
};
*/
class Tv;//前向声明

class Remote
{
private:
	int mode;
public:
	//需要拿一些Tv类的枚举类型
	enum { Off, On };
	enum { MinVal, Maxval = 20 };
	enum { Antenna, Cable };//天线、电缆
	enum { TV, DVD };
	//--------
	Remote(int m=TV):mode(m){ }//默认TV模式打开
	//类内只声明，实现放在Tv类后面
	bool volup(Tv& t);//通过友元类使用了Tv类的成员和方法
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandown(Tv& t);
	void set_chan(Tv& t, int c);//直接改变Tv类成员
	void set_mode(Tv& t);
	void set_input(Tv& t);
};

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
	friend void Remote::set_chan(Tv& t, int c);//只将Remote类里面的set_chan()方法声明为友元，因为本来也只有这个函数要用到Remote里面的private成员,而原来所有Remote类里面的函数都是友元
						//---enum成员都是int类型的
	enum { Off, On };
	enum { MinVal, Maxval = 20 };
	enum { Antenna, Cable };//天线、电缆
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) { }
	void onoff() { state = (state == On) ? Off : On; }//利用简单的三目开关机
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }//利用简单的三目切换模式
	void set_input() { input = (input = TV) ? DVD : TV; }
	void setting();//显示所有设置
};

