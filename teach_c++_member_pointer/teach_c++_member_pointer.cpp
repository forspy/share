#include"Integer.h"

int main()
{
	Integer i1(10), i2(20);
	//成员指针
	int Integer::*p = &Integer::m_i; //是Integer里面的(::)int类型的东西2.要保持类型一致，访问到的其实是偏移值
	i1.*p = 50;

	//成员指针相对于对象的偏移值
	//强转不会对变量有影响，相当于编译器把一个变量类型解释成另一个变量类型
	volatile
}