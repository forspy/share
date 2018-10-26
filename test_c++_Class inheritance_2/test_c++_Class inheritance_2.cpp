//#include"TableTennisPlayer.h"
#include"RatedPlayer.h"//因为RatedPlayer.h，包含了TableTennisPlayer.h
#include<iostream>
int main()
{
	TableTennisPlayer player1;
	TableTennisPlayer player2("xiaoming", "wang", false);
	player1.name();
	if (player1.has_table())
		cout << "有桌子" << endl;
	else
		cout << "没有桌子" << endl;
	player2.name();
	if (player2.has_table())
		cout << "有桌子" << endl;
	else
		cout << "没有桌子" << endl;

	RatedPlayer rplayer1(1140, "xiaohong", "wang", true);
	rplayer1.name();//派生类使用了基类的方法
	if (rplayer1.has_table())
		cout << "有桌子" << endl;
	else
		cout << "没有桌子" << endl;
	RatedPlayer rplayer2(1212, player1);
	rplayer2.name();
	cout << "rplayer2 rating:" << rplayer2.Rating() << endl;
}