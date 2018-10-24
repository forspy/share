/*
C++允许在类和基本类型之间进行转换
比如：
类中有一个构造函数Stack(double a)
则可以自动完成Stack money=1.6的转换（隐式转换）
类中有一个构造函数Stack(char* a)
则可以自动完成Stack name="hello world"的转换（隐式转换）
如果在构造函数前面声明了explicit(翻译为明确的),则该构造函数只能用于显式地转换 Stack name=Stack("hello world");
将类对象转换成其他类型，必须定义转换函数operator typename()
1.转换函数必须是成员函数
2.转换函数没有返回类型、没有参数，但必须返回转换后地值
Vector::operator double()
{
...
	return a_double_value;
}
使用转换函数要小心，可以在声明构造函数时使用关键字explicit，以防止它被用于隐式转换
*/
