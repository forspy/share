#pragma once
//ǰ������
/*��Ϊ��Ҫ�ķ�������Tv�ģ���Remoteʵ��ֻ��set_channel�õ���Tv�ĳ�Ա�����Կ���ֻ��class Tv��д��Remote�ķ�������������Ϊ��Ԫ
class Tv
{
friend void Remote::set_channel(Tv& t,int c);
*/
//��Ϊ������Remote����Remote����ǰ�棬Ȼ��Remote���滹��Tv����������Ҫһ��ǰ������
/*
˳��Ϊ��
class Tv;
class Remote//��ΪTvֻ��һ��ǰ������������Remote���治���й���Tv����������ʵ��
{
...
};
class Tv
{
...
};
*/
class Tv;//ǰ������

class Remote
{
private:
	int mode;
public:
	//��Ҫ��һЩTv���ö������
	enum { Off, On };
	enum { MinVal, Maxval = 20 };
	enum { Antenna, Cable };//���ߡ�����
	enum { TV, DVD };
	//--------
	Remote(int m=TV):mode(m){ }//Ĭ��TVģʽ��
	//����ֻ������ʵ�ַ���Tv�����
	bool volup(Tv& t);//ͨ����Ԫ��ʹ����Tv��ĳ�Ա�ͷ���
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandown(Tv& t);
	void set_chan(Tv& t, int c);//ֱ�Ӹı�Tv���Ա
	void set_mode(Tv& t);
	void set_input(Tv& t);
};

class Tv
{
private:
	int state;//�����
	int volume;//����
	int maxchannel;//���Ƶ��
	int channel;//��ǰƵ��
	int mode;//ģʽ
	int input;//TV orDVD
public:
	//ң�����͵��ӻ�����is-a�Ĺ�ϵ��Ҳ����has-a�Ĺ�ϵ����ң�������Ըı���ӻ�״̬������ң�����ǵ��ӻ�����Ԫ��
	friend void Remote::set_chan(Tv& t, int c);//ֻ��Remote�������set_chan()��������Ϊ��Ԫ����Ϊ����Ҳֻ���������Ҫ�õ�Remote�����private��Ա,��ԭ������Remote������ĺ���������Ԫ
						//---enum��Ա����int���͵�
	enum { Off, On };
	enum { MinVal, Maxval = 20 };
	enum { Antenna, Cable };//���ߡ�����
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) { }
	void onoff() { state = (state == On) ? Off : On; }//���ü򵥵���Ŀ���ػ�
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }//���ü򵥵���Ŀ�л�ģʽ
	void set_input() { input = (input = TV) ? DVD : TV; }
	void setting();//��ʾ��������
};

