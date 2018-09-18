/*内存空间的基础知识补充
1.代码块内的作用域
2.auto声明的变量为局部变量
3.栈上使用两个指针来跟踪内存，一个指针指向栈底--栈的开始位置，
另一个指针指向栈顶--下一个可用的内存单元
4.寄存器变量--储存局部变量  register int a;提高访问变量的速度
*/
#include<iostream>
#include<cmath>
int global = 1000;//全局变量，不仅可以在该文件中使用，而且在别的文件中也能使用该变量，在持续性上来说也是静态的

static int one_file = 50;//静态全局变量，只能在该文件中使用
//静态初始化
int x;//0初始化
int x1 = 6;//常量表达式初始化
//动态初始化
int y = 4 * atan(1.0);//需要调用函数计算
int main()
{
	static int count = 0;//静态局部变量，作用域只在main内，但是在该文件一开始运行时就存在
}
//如果想让file2使用file1的变量需要
//file2
// extern int a;
//...
//file1
//extern int a=1;//需要在file1内定义+声明extern，（如果是全局变量extern可省略，局部变量不能省略）