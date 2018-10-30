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
//派生类对象可以使用基类的公有方法（派生类不可以访问基类private成员，重要，只能通过基类方法）
//基类引用可以接住派生类的对象 如：ostream& a=cout,也可以是ostream& a=fout;（基类->派生类（如：ostream->ofstream））
/*
基类指针可以指向派生类对象
基类引用可以引用派生类对象
基类对象可以接住派生类对象（因为基类拷贝构造函数是一个引用），当然接住后的基类对象只能使用基类方法（无论有没有声明virtual）
如：
TableTennisPlayer* p=&rplayer;
TableTennisPlayer& rt=rplayer;
p->name();
rt.name();
但是基类指针和引用只能调用基类的方法，不能调用派生类的方法
c++要求类型一致对类继承来说是例外，但也只是单向的，不可以将基类对象和地址赋给派生类指针或引用
在公有继承中，可以将基类对象初始化为派生类对象
RatedPlayer xiaoming(1840,"wang","xiaoming",true);
TableTennisPlayer xiaogong(xiaoming);
TableTennisPlayer存在隐式拷贝构造函数TableTennisPlayer（const TableTennisPlayer& a）,因为基类引用a能接住派生类对象所以这个
默认拷贝构造函数把派生类对象xiaoming的所有成员复制了一遍给基类对象，完成了用派生类对象初始化基类对象
也可以通过
RatedPlayer xiaoming(1840,"wang","xiaoming",true);
TableTennisPlayer xiaogong;
xiaohong=xiaoming;
这种情况调用的是隐式赋值重载=运算符
TableTennisPlayer& operator=（const TableTennisPlayer& a）const

继承的形象说明：
假设有一个Fruit类可以保存水果的重量和热量，因为香蕉banana是一种特殊的水果，所以可以从Fruit类中派生出banana这个类，派生的类将继承原始类的所有数据成员类型
新的banana类还可以添加专门用于香蕉的成员 所以这种是 派生is a kind of继承 的关系，简称is-a
如果是午餐中有水果的模型，则不能使用Fruit派生出Lunch，因为Lunch类中还可能有其他类，而这些类跟Fruit类没有关系，也不能访问Fruit类的成员，因此，将Fruit
对象作为Lunch的成员？（可以用其他类当作成员，比如string类当成员，但是不能使用同一类对象当成员（自身类的指针和引用可以），会出现无限初始化的情况）。
公有继承不建立is-like-a的关系，人们通常说律师就像鲨鱼，但律师并不是鲨鱼。例如：鲨鱼可以在水下生活，继承可以在基类的基础上添加属性但不能删除基类的属性
所以不应该从Shark类派生出Laywer类
公有继承不建立use-a的关系，例如计算机computer可以控制Printer打印，但是computer派生Printer是不合适的，因为Printer没有Computer的功能，可以在Computer
类下建立Printer友元函数，或者友元对象来实现两者之间的通信
*/
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



