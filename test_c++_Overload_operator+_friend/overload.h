#pragma once
class Time
{
private:
	int hours;
	int minutes;
public:
	Time();//构造函数
	Time(int h, int m = 0);
	void addmin(int m);
	void addhour(int h);
	void reset(int h = 0, int m = 0);
	Time sum(const Time& t)const;
	Time operator+(const Time& t)const;//为Time类添加加法运算（重要）
	Time operator-(const Time& t)const;
	Time operator*(double mult)const;
	

	//到现在为止，类的公有函数是访问类对象私有部分的唯一途径，为了适合特定的编程问题，c++提供了一种另外形式的访问权限：友元
	/*
	友元有三种：
	友元函数
	友元类
	友元成员函数

	*/
	//通过让函数成为类的友元，可以赋予该函数于与类的函数相同的访问权限，这里先介绍友元函数
	//友元函数的存在主要是为了让里面的对象能够访问到类中的私有成员

	//问题：如果想total=2*total就实现不了了，因为2不是对象，因此引入一个友元函数
	friend Time operator*(double mult, const Time& t);//注意：友元函数需要将函数原型放在类声明中，并加上friend
	/*
	虽然operator*()函数是在类里声明的的，但是它不是成员函数，不能使用.来调用 所以不需要使用Time::限定符来调用
	友元函数与成员函数的访问权相同
	实现中不需要写friend
	*/
	void show()const;
};

Time test(double a, const Time& t);