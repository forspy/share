#include "TableTennisPlayer.h"
#include<iostream>


TableTennisPlayer::TableTennisPlayer(const string& fn , const string& ln , bool ht ):firstname(fn),lastname(ln),m_has_table(ht)//初始化列表
{//对于const string& fn，在fn接住const char*的过程中，fn string类会调用一个string构造函数（const char*）（在string类内部实现）
}
/*也可以使用如下方式构造，但是首先会为firstname调用string默认构造函数，再调用string赋值=重载运算符
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