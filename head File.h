#pragma once
/*
#ifndef DEF_NAME
#define DEF_NAME
struct rect
{
	int x;
	int y;
};
#endif
与#pragma once的效果基本一致
区别：#pragma once 针对一个文件，指不会包含同名头文件； 而ifndef--define--endif则会包含同名头文件，但不会包含重复代码；效率上时#pragma once效率快
另外，在编译链接模块的时候，请保证所有对象文件或库都是由同一个编译器生成的
*/