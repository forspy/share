#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//写入
	FILE* fid = fopen("danny.txt","w+");
	if (!fid)
	{
		printf("打开文件失败\n");
		return -1;
	}
	char name[30] = "hello world!!\nhi!!";
	fwrite(name, 1, 20, fid);
	fclose(fid);
	//读取并拷贝
	FILE* fid1 = fopen("danny.txt", "r");
	if (!fid1)
	{
		printf("打开文件失败\n");
		return -1;
	}
	char txt_read[30] = { 0 };//初始化
	fread(txt_read, 1, 20, fid1);
	fclose(fid1);
	FILE* fid3 = fopen("tanzhou.txt", "w+");
	if (!fid3)
	{
		printf("打开文件失败\n");
		return -1;
	}
	fwrite(txt_read, 1, 20, fid3);
	fclose(fid3);
}