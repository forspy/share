#include "TableTennisPlayer.h"
#include<iostream>


TableTennisPlayer::TableTennisPlayer(const string& fn , const string& ln , bool ht ):firstname(fn),lastname(ln),m_has_table(ht)//��ʼ���б�
{//����const string& fn����fn��סconst char*�Ĺ����У�fn string������һ��string���캯����const char*������string���ڲ�ʵ�֣�
}
/*Ҳ����ʹ�����·�ʽ���죬�������Ȼ�Ϊfirstname����stringĬ�Ϲ��캯�����ٵ���string��ֵ=���������
TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht)
{
	firstname = fn;
	lastname = ln;
	m_has_table = ht;
}
*/
TableTennisPlayer::~TableTennisPlayer()
{
}
void TableTennisPlayer::name()const
{
	cout << lastname << firstname << endl;
}