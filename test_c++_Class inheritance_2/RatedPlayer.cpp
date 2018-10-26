#include "RatedPlayer.h"

RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht) :TableTennisPlayer(fn,ln,ht)//如果不调用基类构造函数，程序将使用默认的基类构造函数
//因为基类构造函数存在，会调用基类默认构造，所以与下列语句等价
//RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht)
{
	rating = r;
}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp):TableTennisPlayer(tp)	,rating(r)//
//1.因为TableTennisPlayer类没有定义拷贝构造函数
//2.所以会调用默认的TableTennisPlayer的拷贝构造函数，而TableTennisPlayer的拷贝构造函数会复制所有TableTennisPlayer目标对象的成员
//3.因为基类没有使用动态内存分配
{
	
}
RatedPlayer::~RatedPlayer()
{

}
