
#include<iostream>
#include"class and dynamic memory.h"
using namespace std;
void call_1(String_easy&);
void call_2(String_easy);
int main()
{
	String_easy headline1("hello world");
	String_easy headline2("better");
	cout << "headline1  " << headline1 << endl;
	cout << "headline2  " << headline2 << endl;
	cout << "done" << endl;

	/*
	    引用：就是一个变量取一个别名，并不会发生值拷贝的过程
		
		比如：
		int a = 10;
		int b = a;   这中情况，就把a的值拷贝一份到b中，但是b和a内存不一样？不是b.str指向难道和a.str不一样？
		int &c = a;  这是给a取一个外号，c和a的内存是相同的。 
	*/
	String_easy copy= headline1;
	call_1(headline1);//按引用传递，先这样，这里引用对象没有调用了析构函数
	call_2(headline1);//按值传递，=0x00801578 "hello world" 
	
	//析构函数先删除headline2对象创建的内存，再删除headline1创建的内存，倒着删除
}
void call_1(String_easy& r)
{
	cout << "按引用传递" << r << endl;
}


/*

	对象 是什么类型？  我们自己定义的类型 

	我们普通的int float

	直接传参数没有问题，拷贝，系统帮我们实现了。

	但是我们自己定义类型呢？

	对象 = 对象   你没有实现拷贝构造或者重载=，对象里面的成员的数据，会拷贝过去吗？哦明白了，但是 

	为什么要报错，语法没有问题，操作的不是野指针，干嘛要给你抛异常？哦哦，明白啦，能不能写一个拷贝构造
*/


/*
    对象r = 对象headline1   进行拷贝，内存都不属于同一个内存。
	 this       other

	 call_2函数结束之前，调用对象r的析构函数。


	 对象headline1  会在main()结束之前，调用headline1对象的析构函数

*/

void call_2(String_easy r)//这里没有引用啊，为什么和原型不一样也行啊？不是的啊，你的实参和形参会发送拷贝的，只要发送拷贝，它就会调用，明白了，刚才想歪了！！
//这个过程就已经实现拷贝了，但是还有最后一个问题，在headline1拷贝给r对象这个过程完成后，会不会马上调用headline1的析构函数？？？？？最后一问
//如果要传值有没有什么办法？，这样传参不就实现拷贝构造了吗？还是还需要写一个拷贝构造函数？刚才老师你说的我明白，但是为什么运行的时候编译器没有报错呢？能通过编译啊
{
	cout << "类的拷贝构造" << r << endl;
	//这里如果没有显式的编写拷贝构造函数，在call_2函数结束之前就会调用r对象的析构函数，导致指向字符串动态内存被释放，而后面headline1结束时会再释放一次，造成错误
}
