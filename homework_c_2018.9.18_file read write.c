#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//д��
	FILE* fid = fopen("danny.txt","w+");
	if (!fid)
	{
		printf("���ļ�ʧ��\n");
		return -1;
	}
	char name[30] = "hello world!!\nhi!!";
	fwrite(name, 1, 20, fid);
	fclose(fid);
	//��ȡ������
	FILE* fid1 = fopen("danny.txt", "r");
	if (!fid1)
	{
		printf("���ļ�ʧ��\n");
		return -1;
	}
	char txt_read[30] = { 0 };//��ʼ��
	fread(txt_read, 1, 20, fid1);
	fclose(fid1);
	FILE* fid3 = fopen("tanzhou.txt", "w+");
	if (!fid3)
	{
		printf("���ļ�ʧ��\n");
		return -1;
	}
	fwrite(txt_read, 1, 20, fid3);
	fclose(fid3);
}