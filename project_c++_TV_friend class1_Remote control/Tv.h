#pragma once
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
	friend class Remote;//��Ԫ��Remote���Լ����������Ի�ȡ˽�б����͹��г�Ա
	//---enum��Ա����int���͵�
	enum{Off,On};
	enum{MinVal,Maxval=20};
	enum{Antenna,Cable};//���ߡ�����
	enum{TV,DVD};

	Tv(int s=Off,int mc=125):state(s),volume(5),maxchannel(mc),channel(2),mode(Cable),input(TV){ }
	void onoff() { state = (state == On) ? Off : On; }//���ü򵥵���Ŀ���ػ�
	bool ison() const{ return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }//���ü򵥵���Ŀ�л�ģʽ
	void set_input() { input = (input = TV) ? DVD : TV; }
	void setting();//��ʾ��������
};
class Remote
{
private:
	int mode;
public:
	Remote(int m=Tv::TV):mode(m){ }//Ĭ��TVģʽ��
	bool volup(Tv& t) { return t.volup(); }//ͨ����Ԫ��ʹ����Tv��ĳ�Ա�ͷ���
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }//ֱ�Ӹı�Tv���Ա
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
};