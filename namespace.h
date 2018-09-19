#pragma once
//c++提供了名称空间以便更好地控制名称的作用域
//名称空间通常在头文件声明
#include<string>

namespace pers
{
	struct person//名称空间里定义了一个结构
	{
		std::string fname;
		std::string lname;/*
		结构里定义了一个string类，因为没有使用using namespace std(using编译指令--针对std名称空间下的所有变量名)
		或using std::string（using指令--只针对std下的string对象),所以要加std::解析运算符
		*/
	};
	void getperson(person&);//还可以在名称空间声明函数
}

namespace test
{
	using namespace pers;//还可以在名称空间中使用别的名称空间
	int m;
}

namespace test
{
	char add[20];//还可以对已有的名称空间进行添加
}

/*
总结：
1.名称空间可以是全局的，也可以位于另一个名称空间中，但是不能位于代码段中
2.名称空间中的名称不会与其他空间的名称冲突
3.可以添加名称空间
4.可以在相同的名称空间为一个该名称空间提供函数代码
5.三种方式访问名称空间中的名称
a. std::value
b. using namespace std(using编译指令--针对std名称空间下的所有变量名)
c. using std::string（using指令--只针对std下的string对象),所以要加std::解析运算符（推荐），作用域为using声明所在的区域
6.尽量在#include之后使用using
7.尽量将using使用在局部区域
8.static和未命名的名称空间都可以将该变量限制在该程序文件内
*/

