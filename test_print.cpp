#include<iostream>//输入输出头文件

int main()
{
	//using namespace std;//1.make definitions visible 使用count和endl的前提
	//2.using 编译指令 意味着其实是使用了名称空间（namespace）

	std::cout << "Come up and C++ me some time.";//cont全称是std:count，是在调用了没有扩展名.h的头文件后的用法
	//是c++新的头文件，区别于c
		std::cout << std::endl;//start a new line
	std::cout << "you won't regret it!" << std::endl;
	return 0;
}