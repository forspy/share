#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
void depack();//����ļ�����
struct fileinfo
{
	int filenamesize;//�ļ�����С
	int fileoff;//�ļ�ƫ��
	int filesize;//�ļ���С
	char filename[20];//�ļ���
};
int main()
{
	depack();
}

void depack()
{
	//��׼����һ���ļ���Ϣ����
	fileinfo filelist[4] = {
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 },
	};//�ȳ�ʼ��һ��
	
	int listsize = 0;//׼���������С
	int listnum = 0;//1,׼���ļ�����
	//��pack.new
	fstream oldfile;
	oldfile.open("new.pack", ios::in | ios::binary);
	/*
	���������С��72��4�ֽڣ�  ���ļ�������4 ��4�ֽڣ�
	���ļ�1�Ĵ�С��59771��4�ֽڣ� ���ļ�1��ƫ�ƣ�80��4�ֽڣ� (�ļ�1���ĳ���)6��4�ֽڣ�  ���ļ�1����1.jpg��6�ֽڣ�
	���ļ�2�Ĵ�С��...
	*/
	//�ȶ��������С�����ݣ�4�ֽ�
	/*char test[5] = { 0 };
	char ch;
	for (int i = 0; i < 4; i++)
	{
		test[i] = oldfile.get();
	}*/
	oldfile.read((char*)&listsize, 4);//72�ǶԵ�
	oldfile.read((char*)&listnum, 4);//4
	for (int i = 0; i < listnum; i++)
	{
		oldfile.read((char*)&filelist[i].filesize, 4);//�ļ�1�Ĵ�С59771
		oldfile.read((char*)&filelist[i].fileoff, 4);//�ļ�1��ƫ��80
		oldfile.read((char*)&filelist[i].filenamesize, 4);//�ļ�1���ĳ���6
		oldfile.read(filelist[i].filename, filelist[i].filenamesize);//�ļ�1�� filelist[0].filename	0x008ffd08 "1.jpg"char[20]
	}
	fstream file[4];//׼���ĸ��ļ��������ס���е��ļ���
	stringstream s;
	string str;
	for (int i = 0; i < listnum; i++)
	{
		s << "new" << i+1 << ".jpg"<<'\0';//ʹ���ַ����������ļ���
		s >> str;
		//cout << str;
		file[i].open(str, ios::out | ios::binary);
		s.clear();
	}
	//�����ļ���ƫ�Ƽ��ļ��Ĵ�С��ȡ
	char ch;
	for (int i = 0; i < listnum; i++)
	{
		//����oldfile�ļ���ָ��
		//oldfile.seekg(filelist[i].fileoff, ios::beg);//����oldfile������ļ�ָ�뵽�ļ�i��λ��
		//�ܲ����õ�ƫ�ƺ��ָ��λ�ã�file[i].write((char*)&oldfile, filelist[i].filesize);//д�뵽�ļ�i�� �����
		oldfile.seekg(filelist[i].fileoff, ios::beg);//����oldfile������ļ�ָ�뵽�ļ�i��λ��
		//����һ��һ���ַ�һ���ַ��ķ�
		for (int n = 0; n < filelist[i].filesize; n++)
		{
			ch = oldfile.get();
			file[i].put(ch);
		}
		file[i].close();
	}

	oldfile.close();
}
