#pragma once
#include<iostream>
#include<string>
using namespace std;
class AcctABC//抽象基类
{
private:
	string fullName;
	long acctNum;
	double balance;
protected:
	const string& FullName()const { return fullName; }
	long AcctNum()const { return acctNum; }
public:
	AcctABC(const string& s="nulbody",long an=-1,double bal=0.0);//只要提供了构造函数，默认构造函数就消失了，因此需要全写上默认参数
	void Deposit(double amt);
	double Balance()const { return balance; }

	virtual void WithDraw(double amt) = 0;//纯虚函数,基类里面实现不了因为缺乏数据成员，所以在派生类里面实现
	virtual void ViewAcct()const = 0;

	virtual ~AcctABC();
};
//派生类Brass
class Brass :public AcctABC
{
public:
	Brass(const string& s="nullbody",long an=-1,double bal=0.0):AcctABC(s,an,bal){}//利用抽象基类的构造函数进行代码复用
	virtual void WithDraw(double amt);
	virtual void ViewAcct()const;
	virtual ~Brass(){}
};
//派生类BrassPlus
class BrassPlus :public AcctABC
{
private:
	double maxLoan;//最大贷款上限
	double rate;//贷款利率
	double owesBank;//签银行多少（计算利息）
public:
	BrassPlus(const string& s = "nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.1);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);//拷贝构造Brass
	virtual void ViewAcct()const;
	virtual void WithDraw(double amt);
	void ResetMax(double m) { maxLoan = m; }//重设最大贷款上限
	void ResetRate(double r) { rate = r; }//重设利息
	void ResetOwes() { owesBank = 0; }//还款
};
//所有的圆都是椭圆，也就是圆是椭圆的子集，因此根据is-a的关系，由椭圆派生出圆
/*
但是这里存在很多问题：
1.椭圆包括：椭圆的中心坐标、长半轴、短半轴、方向角，方法：移动椭圆、返回椭圆面积、旋转椭圆、缩放长半轴和短半轴
2.假设从椭圆类中派生出圆类，因为圆类只需要一个半径，中心坐标，返回面积，其他成员和方法不需要这样讲导致信息冗余(类继承能不能继承到基类的private成员？)
（tips:如果一个子类继承了父类，那么这个子类拥有父类所有的成员属性和方法，即使是父类里有private属性的变量，子类也是继承的，只不过不能使用，
也就是说，它继承了，但是没有使用权，似乎又点矛盾，用我们通俗的说法就是 只能看，不能用，谢谢！
虽然是这样，但是，我们还是可以通过set 和get的方法来间接的访问父类中的private属性的变量 谢谢）
所以出现一种方法，从椭圆和圆中抽象出它们的共性，将这些特性放到一个ABC中，然后从ABC派生出椭圆和圆这两个类（这样就可以使用基类指针同时管理圆和椭圆的对象，即可以使用多态的方法）

*/
//抽象基类
class BaseEllipse
{
	//抽象基类抽象出两个类的共同点：中心坐标、Move()方法和Area()方法
private:
	double x;
	double y;
	//...
public:
	BaseEllipse(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	virtual~BaseEllipse() {}
	void Move(int nx, int ny) { x = nx; y = ny; }
	virtual double Area()const = 0;//纯虚函数，虽然不能在抽象基类中实现Area的方法，因为它没有包含必要的数据成员（纯虚函数可以有定义）
								   //所以C++通过使用纯虚函数提供未实现的函数
								   //所以在一个抽象基类中必须要有一个纯虚函数，有一个纯虚函数是抽象基类的标志
};
//总之，可以从抽象基类BaseEllipse派生出椭圆类Ellipse类和圆Cirle类，特征为Cirle总是表示圆，而Ellipse可以表示为椭圆也可以表示为圆（因为存在包含关系）
//利用BaseEllipse抽象基类指针管理派生类，抽象基类的派生类被成为具体类