#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//����·��
	//win��D:\visual stdio2015 code\file_read and write2\file_read and write2
	//linux����Ŀ¼�¿�ʼ /XXXX/XXXX
	//���·������ǰ����Ŀ¼������������ʱ�����ڵ�Ŀ¼����Ҳ���Ե��ò���ϵͳ��API���޸ĵ�ǰ��Ŀ¼��
	// ./��ʾ��ǰĿ¼  ../��ʾ��һ��Ŀ¼  
	//fopen��������һ�� struc FLIE* �Ľṹ����Ҳ���ļ������
	//�ַ����� "\\"��ʾת���\��Ҳ����ʹ��/
	FILE* f=NULL;//���ü�struct����ΪFILE�Ѿ���һ��type�ˣ�����intһ��
	f = fopen("D:\\visual stdio2015 code\\file_read and write2\\file_read and write2\\test.txt", "r");
	//����·��
	if (f == NULL)
		printf("open filed\n");
	fclose(f);

	FILE* fid = NULL;
	fid = fopen("test.txt", "rb");//���·����Ҳ������fid = fopen("./test.txt", "r");
	if (fid == NULL)
		printf("open filed\n");
	
	//rֻ�� r+�ɶ�д��Ҫ���ļ�������ڣ�����0��д��Ļ��Ḳ��ԭ�������ݣ� w����ֻд�ļ�����0��д��
	//w+���򿪿ɶ���д�ļ�����0��д�� a���򿪻���һ��ֻ����д�ļ������ڻ����ļ�β������д��
	//a+���򿪻���һ���ɶ���д���ļ������ڻ����ļ�β������д��
	//b�����ƶ�д������ǰ���ϣ���rb+
	
	//�ο��㣺��ʼ��λ��SEEK_SET 0,��ǰ��λ�� SEEK_CUR 1,�ĵ���β SEEK_END 2
	//����ģʽ���ƶ����fseek(FILE* fid��ƫ����,�ο�λ��)
	fseek(fid, 2, SEEK_SET);//��ͷ��ʼ��������2λ
	
	fseek(fid, -2, SEEK_CUR);//�ӵ�ǰλ����ǰ����2λ
	
	fseek(fid, -2, SEEK_END);//�ӽ�β��ǰ��2λ
	int pos = ftell(fid);//���ص�ǰ��λ��
	printf("%d\n", pos);
	fseek(fid, 0, SEEK_END);
	int file_size = ftell(fid);
	printf("������%d\n", file_size);
	fseek(fid, 0, SEEK_SET);//����겦���ļ���ʼ��

	//�ļ���ȡ
	char* file_data = malloc(file_size + 1);//�����ַ����Ľ�β����
	
	int read_size= fread(file_data, 1, file_size, fid);
	file_data[file_size] = '\0';//����fopen(,"rb")rb��ʽ�򿪵�ASCII�����س�����'\0'��
	printf("�ļ���С%d\n", read_size);
	printf("%s\n", file_data);
	fclose(fid);

	FILE* fid2 = fopen("write_test.txt", "a");//w�����ԭ�ļ���a��׷��(a��Ҫԭ�����ļ�)
	char* name = "hello world!!!\nhehehe";
	fwrite(name, 1, strlen(name), fid2);

	

	//ϵͳ����д�������������ɻ�����д��Ӳ�̣���Ϊ��Ҫ�ȵ����������浽��һ����Ŀ��
	//��д��Ӳ�̣�������������Ӳ�̵�ʹ������������u������ʹ���п�������Ϊ���в���
	//����û��д��u�̣���ʵǿ�ưγ���u�̵�Ӳ��û�ж��Ӱ�죬��Ҫ����������ݵĶ�ʧ
	//fflish(fid2)ǿ�Ʋ���ϵͳ������ˢ��Ӳ�̣�������ʹ�ã�

	//��ʽ�����뵽�ļ�
	fprintf(stdout, "hello test!!\n");//stdout��ʾ���뵽��Ļ
	fprintf(fid2, "%d %d %s", 1, 1, "ss");
	fclose(fid2);
}