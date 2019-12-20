#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//绝对路径
	//win：D:\visual stdio2015 code\file_read and write2\file_read and write2
	//linux：根目录下开始 /XXXX/XXXX
	//相对路径：当前工作目录（程序在运行时的所在的目录）（也可以调用操作系统的API来修改当前的目录）
	// ./表示当前目录  ../表示上一级目录  
	//fopen函数返回一个 struc FLIE* 的结构对象（也称文件句柄）
	//字符串内 "\\"表示转义成\，也可以使用/
	FILE* f=NULL;//不用加struct，因为FILE已经是一种type了，就像int一样
	f = fopen("D:\\visual stdio2015 code\\file_read and write2\\file_read and write2\\test.txt", "r");
	//绝对路径
	if (f == NULL)
		printf("open filed\n");
	fclose(f);

	FILE* fid = NULL;
	fid = fopen("test.txt", "rb");//相对路径，也可以是fid = fopen("./test.txt", "r");
	if (fid == NULL)
		printf("open filed\n");
	
	//r只读 r+可读写（要求文件必须存在，不清0但写入的话会覆盖原来的内容） w（打开只写文件，清0重写）
	//w+（打开可读可写文件，清0重写） a（打开或建立一个只可以写文件，存在会在文件尾部继续写）
	//a+（打开或建立一个可读可写的文件，存在会在文件尾部继续写）
	//b二进制读写，可与前面结合，如rb+
	
	//参考点：开始的位置SEEK_SET 0,当前的位置 SEEK_CUR 1,文档结尾 SEEK_END 2
	//读的模式下移动光标fseek(FILE* fid，偏移量,参考位置)
	fseek(fid, 2, SEEK_SET);//从头开始往后面移2位
	
	fseek(fid, -2, SEEK_CUR);//从当前位置往前面移2位
	
	fseek(fid, -2, SEEK_END);//从结尾往前移2位
	int pos = ftell(fid);//返回当前的位置
	printf("%d\n", pos);
	fseek(fid, 0, SEEK_END);
	int file_size = ftell(fid);
	printf("光标个数%d\n", file_size);
	fseek(fid, 0, SEEK_SET);//将光标拨回文件开始处

	//文件读取
	char* file_data = malloc(file_size + 1);//包含字符串的结尾符号
	
	int read_size= fread(file_data, 1, file_size, fid);
	file_data[file_size] = '\0';//利用fopen(,"rb")rb方式打开的ASCII码计入回车键和'\0'，
	printf("文件大小%d\n", read_size);
	printf("%s\n", file_data);
	fclose(fid);

	FILE* fid2 = fopen("write_test.txt", "a");//w会清空原文件，a会追加(a需要原来有文件)
	char* name = "hello world!!!\nhehehe";
	fwrite(name, 1, strlen(name), fid2);

	

	//系统是先写到缓存区，再由缓存区写入硬盘，因为需要等到缓存区缓存到了一定数目后
	//再写入硬盘，这样可以增加硬盘的使用寿命；另外u盘正在使用中可能是因为还有部分
	//缓存没有写入u盘，其实强制拔出对u盘的硬件没有多大影响，主要可能造成数据的丢失
	//fflish(fid2)强制操作系统将缓存刷入硬盘（尽量少使用）

	//格式化输入到文件
	fprintf(stdout, "hello test!!\n");//stdout表示输入到屏幕
	fprintf(fid2, "%d %d %s", 1, 1, "ss");
	fclose(fid2);
}