#pragma once
//第二部分
/*
c++成员函数调用 thiscall
普通函数调用 stdcall
使用extern"c"{ }方式调用 _cdcel
*/
#ifdef _cplusplus//因为如果加上extern "C"就不能给c用了，所以要判定当前的编译器是不是C,使用条件编译（.c的编译器和.cpp/.cc的编译器时不同的）
extern "C"//表示使用c的方式在c++中调用c的代码
{
#endif

	//里面声明..
#ifdef _cplusplus
}
#endif