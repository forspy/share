#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
mode:
r ֻ��������ļ������ڣ�����NULL������д
w ֻд������ļ������ڣ�����������ļ����ڣ�����ա�
r+ �ɶ���д r������ �ļ����������ʧ�ܣ�д��Ḳ��
w+ �ɶ���д w������ �ļ������ڴ������ļ����������
a ׷�� �ڵ�ǰλ�ú��һ���� ���������
a+���򿪻���һ���ɶ���д���ļ������ڻ����ļ�β������д��
rb �����Ʒ�ʽ��ȡ����
*/

int main()
{
	//1.���ļ�
	FILE* fid = fopen("hello.txt","a+");
	if (!fid)
	{
		printf("���ļ�ʧ��\n");
	}
	//2.��ȡ�ļ�
	int a=fgetc(fid);//fgetc�����ַ���ASCII��
	printf("%c\n", a);
	fclose(fid);
	//--------------------------------�����ļ�����
	FILE* fid1 = fopen("hello.txt", "r");
	if (!fid1)
		printf("���ļ�ʧ��\n");

	FILE* f1 = fopen("hi.txt", "w");
	if (!f1)
		printf("���ļ�ʧ��\n");
	char c;
	while ((c = fgetc(fid1)) != EOF)
		fputc(c, f1);
	fclose(fid1);
	fclose(f1);
	//----------------------------------��
	FILE* fid2 = fopen("hello.txt", "r");
	if (!fid2)
		printf("���ļ�ʧ��\n");
	char* buf = (char*)malloc(sizeof(char) * 100);
	fgets(buf, 10, fid2);//9���ַ�+'\0'
	printf("%s\n", buf);
	free(buf);
	fclose(fid2);

	//---------------------------------д
	FILE* f2 = fopen("hi2.txt", "w");
	if (!f2)
		printf("���ļ�ʧ��\n");
	char* buf2 = (char*)malloc(sizeof(char) * 100);
	memset(buf2, 0, 100);
	fputs("hello2", fid2);
	free(buf2);
	fclose(f2);

	//fread ��fwriteд  �������������ַ�
	/*
	fread��
	buf��ȡ�����ݴ浽buf��
	eachsize ÿһ�ζ�ȡ���ڴ�Ĵ�С
	count ��ȡ���ٴ�
	stream �ļ�ָ��
	*/
	//----------------------------
	FILE* fid3 = fopen("hello.txt", "r");
	if (!fid3)
		printf("���ļ�ʧ��\n");
	char buf3[100] = {0};//Ԥ��ֵ
	int x = fread(buf3, 2, 5, fid3);
	printf("ʵ�ʶ�ȡ����%d\n", x);
	printf("%s\n", buf3);
	fclose(fid3);

	FILE* f4 = fopen("hi3.txt", "w");
	if (!f4)
		printf("���ļ�ʧ��\n");
	int m = 123;//fwrite����int���ܻᵼ��txt��ʾ����
	char name[100] = "hello3";
	int y=fwrite(&m, 1,10,f4);
	printf("ʵ��д�����%d\n", y);
	fclose(f4);
	//---------------------------------------
	//ftell(�ļ�ָ��)��ȡ���й���λ��
	//rewind(�ļ�ָ��)�ѹ���Ƶ��ļ�ͷ
	//fseek
	/*
	//�ο��㣺��ʼ��λ��SEEK_SET 0,��ǰ��λ�� SEEK_CUR 1,�ĵ���β SEEK_END 2
	//����ģʽ���ƶ����fseek(FILE* fid��ƫ����,�ο�λ��)
	fseek(fid, 2, SEEK_SET);//��ͷ��ʼ��������2λ
	
	fseek(fid, -2, SEEK_CUR);//�ӵ�ǰλ����ǰ����2λ
	
	fseek(fid, -2, SEEK_END);//�ӽ�β��ǰ��2λ
	*/
	FILE* fid5 = fopen("hello.txt", "r");
	if (!fid5)
		printf("���ļ�ʧ��\n");

}