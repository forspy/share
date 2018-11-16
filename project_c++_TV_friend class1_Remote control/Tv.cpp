#include"Tv.h"
#include<iostream>
using namespace std;
bool Tv::volup()
{
	if (volume < Maxval)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}
void Tv::chanup()
{
	if (channel < maxchannel)
	{
		channel++;
	}
	else
		channel = 1;//频道循环
}
void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;//频道循环
}
void Tv::setting()
{
	cout << "Tv is" << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting:" << volume << endl;
		cout << "Channel setting:" << channel << endl;
		cout << "Mode setting:" << (mode == Antenna ? "antenna" : "Cable") << endl;
		cout << "Input setting:" << (input == TV ? "TV" : "DVD") << endl;
	}
}