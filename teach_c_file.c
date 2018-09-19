#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
mode:
r 只读，如果文件不存在，返回NULL，不可写
w 只写，如果文件不存在，创建；如果文件存在，则清空。
r+ 可读可写 r的属性 文件不存在则打开失败，写入会覆盖
w+ 可读可写 w的属性 文件不存在创建，文件存在则清空
a 追加 在当前位置后加一部分 不清空内容
a+（打开或建立一个可读可写的文件，存在会在文件尾部继续写）
rb 二进制方式读取内容
*/

int main()
{
	//1.打开文件
	FILE* fid = fopen("hello.txt","a+");
	if (!fid)
	{
		printf("打开文件失败\n");
	}
	//2.读取文件
	int a=fgetc(fid);//fgetc返回字符的ASCII码
	printf("%c\n", a);
	fclose(fid);
	//--------------------------------复制文件内容
	FILE* fid1 = fopen("hello.txt", "r");
	if (!fid1)
		printf("打开文件失败\n");

	FILE* f1 = fopen("hi.txt", "w");
	if (!f1)
		printf("打开文件失败\n");
	char c;
	while ((c = fgetc(fid1)) != EOF)
		fputc(c, f1);
	fclose(fid1);
	fclose(f1);
	//----------------------------------读
	FILE* fid2 = fopen("hello.txt", "r");
	if (!fid2)
		printf("打开文件失败\n");
	char* buf = (char*)malloc(sizeof(char) * 100);
	fgets(buf, 10, fid2);//9个字符+'\0'
	printf("%s\n", buf);
	free(buf);
	fclose(fid2);

	//---------------------------------写
	FILE* f2 = fopen("hi2.txt", "w");
	if (!f2)
		printf("打开文件失败\n");
	char* buf2 = (char*)malloc(sizeof(char) * 100);
	memset(buf2, 0, 100);
	fputs("hello2", fid2);
	free(buf2);
	fclose(f2);

	//fread 读fwrite写  不仅仅局限于字符
	/*
	fread：
	buf读取的内容存到buf中
	eachsize 每一次读取的内存的大小
	count 读取多少次
	stream 文件指针
	*/
	//----------------------------
	FILE* fid3 = fopen("hello.txt", "r");
	if (!fid3)
		printf("打开文件失败\n");
	char buf3[100] = {0};//预赋值
	int x = fread(buf3, 2, 5, fid3);
	printf("实际读取次数%d\n", x);
	printf("%s\n", buf3);
	fclose(fid3);

	FILE* f4 = fopen("hi3.txt", "w");
	if (!f4)
		printf("打开文件失败\n");
	int m = 123;//fwrite输入int可能会导致txt显示出错
	char name[100] = "hello3";
	int y=fwrite(&m, 1,10,f4);
	printf("实际写入次数%d\n", y);
	fclose(f4);
	//---------------------------------------
	//ftell(文件指针)获取现有光标的位置
	//rewind(文件指针)把光标移到文件头
	//fseek
	/*
	//参考点：开始的位置SEEK_SET 0,当前的位置 SEEK_CUR 1,文档结尾 SEEK_END 2
	//读的模式下移动光标fseek(FILE* fid，偏移量,参考位置)
	fseek(fid, 2, SEEK_SET);//从头开始往后面移2位
	
	fseek(fid, -2, SEEK_CUR);//从当前位置往前面移2位
	
	fseek(fid, -2, SEEK_END);//从结尾往前移2位
	*/
	FILE* fid5 = fopen("hello.txt", "r");
	if (!fid5)
		printf("打开文件失败\n");

}