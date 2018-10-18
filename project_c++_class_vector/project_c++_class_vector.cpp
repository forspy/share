#include<iostream>
#include<cstdlib>
#include<ctime>
#include"vector.h"
using namespace std;
using VECTOR::Vector;//使用类
int main()
{
	/*
	enum TT
	{
		RED,GREEN
	};
	std::cout<<TT(1);//小tips通过枚举下标也可以找到枚举值只不过是枚举名(num)
	*/
	//模拟醉汉行走
	srand((unsigned int)time(NULL));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);//初始化对象
	unsigned long steps = 0;//统计步数
	double target;//表示距离起点目标距离
	double dstep;
	cout << "请输入距离起点的目标距离有多远(按q推出)" << endl;
	while (cin >> target)//只要输入流符合格式就会循环
	{
		cout << "请输入每步步长" << endl;
		if (!(cin >> dstep))//如果输入格式不对则退出
		{
			cout << "输入格式不对 退出" << endl;
			break;
		}
		while (result.magval() < target)
		{
			direction = rand() % 360;//随机一个方向
			//step = Vector(dstep, direction, Vector::POL);这样每次设置构造函数都会产生一个对象，不利于内存的管理
			step.reset(dstep, direction, Vector::POL);//设置走一小步的大小和方向
			result = result + step;//实现矢量叠加
			steps++;//统计步数
		}
		//分析结果
		cout << "经过" << steps << "步,醉汉走出了" << target << "米（离原点）" << endl;
		result.polar_mode();//设置为极坐标模式
		//利用重载<<显示
		cout << "极坐标模式" << endl;
		cout << result << endl;
		cout << "平均每步距离" << result.magval() / steps << endl;
		//重置
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "请输入距离起点的目标距离有多远(按q推出)" << endl;
	}
	cout << "bye" << endl;
	cin.clear();//清除返回的bool值
	while (cin.get() != '\n')//释放缓存小技巧
		continue;
	return 0;
}