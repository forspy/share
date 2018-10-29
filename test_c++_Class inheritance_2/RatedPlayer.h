#pragma once
#include "TableTennisPlayer.h"
//类继承：派生类RatedPlayer继承基类TableTennisPlayer
/*
1.为什么要类继承？
a.厂商提供了类库，类库是以源代码的方式提供的，这意味着可以对其进行修改，以满足需求。C++提供了比修改代码更好的方法来扩展和修改类，叫做类继承（继承一笔财产要比白手起家更容易）
b.派生类继承了基类的特征和方法，所以通过继承派生的类通常比设计心类要容易的多
c.继承机制只需提供新的特性，甚至不需要访问源代码就可以派生出类，如果购买的类库只提供了类方法的头文件和编译后的代码(.out)，仍可以使用库中的类派生出新的类
*/
//派生类的特征：
//派生类储存了基类的数据成员
//派生类对象可以使用基类的公有方法
//基类引用可以接住派生类的对象 如：ostream& a=cout,也可以是ostream& a=fout;（基类->派生类（如：ostream->ofstream））
class RatedPlayer :
	public TableTennisPlayer//公有派生
	/*
	使用公有派生，基类的公有成员将成为派生类的公有成员
	基类的私有部分也将成为派生类的一部分，但只能通过基类的公有和保护方法访问
	*/
{
private:
	unsigned int rating;
public://派生类需要自己的构造函数
	//派生类构造函数
	/*
	1.首先创造基类对象，因为要使用基类的各种构造函数
	2.派生类构造函数应该通过成员初始化列表将基类信息传递给基类构造函数？
	（初始化列表是在各种类的构造函数之前，如果在派生类不用初始化列表，基类在先构造对象时基类信息传不进去，就会构建错误的基类对象，影响基类方法的调用）
	3.派生类构造函数应初始化派生类新增的成员
	*/
	RatedPlayer(unsigned int r, const string& fn = "none", const string& ln = "none", bool ht=false);
	RatedPlayer(unsigned int r, const TableTennisPlayer& tp);
	unsigned int Rating()const { return rating; }
	void ResetRating(unsigned int r) { rating = r; }
	~RatedPlayer();
	//释放对象的顺序与创建对象的顺序相反，所以先析构派生类，再析构基类
	//派生类只能将初始化列表值传递给相邻的基类？待解决
};



