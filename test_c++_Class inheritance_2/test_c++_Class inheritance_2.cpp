//#include"TableTennisPlayer.h"
#include"RatedPlayer.h"//��ΪRatedPlayer.h��������TableTennisPlayer.h
#include<iostream>
int main()
{
	TableTennisPlayer player1;
	TableTennisPlayer player2("xiaoming", "wang", false);
	player1.name();
	if (player1.has_table())
		cout << "������" << endl;
	else
		cout << "û������" << endl;
	player2.name();
	if (player2.has_table())
		cout << "������" << endl;
	else
		cout << "û������" << endl;

	RatedPlayer rplayer1(1140, "xiaohong", "wang", true);
	rplayer1.name();//������ʹ���˻���ķ���
	if (rplayer1.has_table())
		cout << "������" << endl;
	else
		cout << "û������" << endl;
	RatedPlayer rplayer2(1212, player1);
	rplayer2.name();
	cout << "rplayer2 rating:" << rplayer2.Rating() << endl;
}