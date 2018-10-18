/*
类的作用域；
1.类中定义的名称作用域为整个类
2.要调用公有成员函数必须通过对象
3.在定义成员函数时，必须使用作用域解析运算符
*/
#include<iostream>
#define MM 12
class Test
{
private:
	const int Months = 12;
	static const int MONTHS=12;
	//int m0[Months];//这样是不行的，因为：
	//1.声明类只是描述了对象的形式，并没有创建对象，因此在创建对象前，将没有用于存储的空间
	//2.可以使用#define 进行文本替代
	int m4[MONTHS];//这样是可以的，但是不推荐，因为这样也开辟了内存
	int m0[12];//这样是不可以的，尽管编译器没有报错但是，在类声明中不要开辟内存
	int m1[MM];
	//3.可以使用枚举提供符号名称
	enum{my_Months=12};//这里的枚举只是为了创建符号常量，并不打算创建枚举类型的变量，因此没有必要提供枚举名
	//例如ios_base::fixed  其中fixed是ios_base中定义的枚举量
	int m2[my_Months];
	//4.使用static
	static const int Mon = 12;//该常量储存在静态变量区，而不是储存在对象中，因此这个Mon常量被所有Test对象共享
	int m3[Mon];
	//为了避免枚举名发生冲突，c++定义了类中的枚举
	//例如：
	enum old { small, large };//全域
	enum class young { little, big };//作用域
	old one = small;//全域
	young two = young::little;//作用域
	int king = one;//全域的可以进行隐式类型的转换
	//int ring = two;//局部作用域内不能进行隐式类型的转换
	int ring = (int)two;//类作用域内的枚举需要显式地强制转换
};

int main()
{
	return 0;
}
