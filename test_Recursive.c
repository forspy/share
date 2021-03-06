//递归，类似于数学归纳法，假设小一级的知道了来推测当前，不断缩小规模直到最初的问题得到解决，那么所有的问题都得到解决
//递归在写法上是调用函数自己
//需要知道a（n）与a（n-1）的关系，以及a1等初值
//随着问题规模的增加，对栈的消耗是不一样的，过度地递归迭代会导致栈的溢出对比for循环中sum=sum+i，不同的规模对栈的消耗是一样的
//写递归的时候层次不易过多
//程序中栈的大小是可以修改的，默认栈大小1M,修改在项目文件夹-属性-链接-系统-栈堆保留大小中修改
#include<stdio.h>
int my_sum(int n);
int main()
{
	int num=10;//10000的话栈就扛不住了
	printf("%d\n", my_sum(num));
}
int total;
int my_sum(int n)
{
	if (n <= 1)
		return total = 1;
	total = n + my_sum(n - 1);//基于关系式
	return total;//逐级返回
}
