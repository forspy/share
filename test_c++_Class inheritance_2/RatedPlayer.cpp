#include "RatedPlayer.h"

RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht) :TableTennisPlayer(fn,ln,ht)//��������û��๹�캯��������ʹ��Ĭ�ϵĻ��๹�캯��
//��Ϊ���๹�캯�����ڣ�����û���Ĭ�Ϲ��죬�������������ȼ�
//RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht)
{
	rating = r;
}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp):TableTennisPlayer(tp)	,rating(r)//
//1.��ΪTableTennisPlayer��û�ж��忽�����캯��
//2.���Ի����Ĭ�ϵ�TableTennisPlayer�Ŀ������캯������TableTennisPlayer�Ŀ������캯���Ḵ������TableTennisPlayerĿ�����ĳ�Ա
//3.��Ϊ����û��ʹ�ö�̬�ڴ����
{
	
}
RatedPlayer::~RatedPlayer()
{

}
