#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
void depack();//打包文件分离
struct fileinfo
{
	int filenamesize;//文件名大小
	int fileoff;//文件偏移
	int filesize;//文件大小
	char filename[20];//文件名
};
int main()
{
	depack();
}

void depack()
{
	//先准备好一组文件信息对象
	fileinfo filelist[4] = {
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 },
	};//先初始化一下
	
	int listsize = 0;//准备索引表大小
	int listnum = 0;//1,准备文件数量
	//打开pack.new
	fstream oldfile;
	oldfile.open("new.pack", ios::in | ios::binary);
	/*
	（索引表大小）72（4字节）  （文件个数）4 （4字节）
	（文件1的大小）59771（4字节） （文件1的偏移）80（4字节） (文件1名的长度)6（4字节）  （文件1名）1.jpg（6字节）
	（文件2的大小）...
	*/
	//先读索引表大小的内容：4字节
	/*char test[5] = { 0 };
	char ch;
	for (int i = 0; i < 4; i++)
	{
		test[i] = oldfile.get();
	}*/
	oldfile.read((char*)&listsize, 4);//72是对的
	oldfile.read((char*)&listnum, 4);//4
	for (int i = 0; i < listnum; i++)
	{
		oldfile.read((char*)&filelist[i].filesize, 4);//文件1的大小59771
		oldfile.read((char*)&filelist[i].fileoff, 4);//文件1的偏移80
		oldfile.read((char*)&filelist[i].filenamesize, 4);//文件1名的长度6
		oldfile.read(filelist[i].filename, filelist[i].filenamesize);//文件1名 filelist[0].filename	0x008ffd08 "1.jpg"char[20]
	}
	fstream file[4];//准备四个文件流对象接住包中的文件流
	stringstream s;
	string str;
	for (int i = 0; i < listnum; i++)
	{
		s << "new" << i+1 << ".jpg"<<'\0';//使用字符串流创建文件名
		s >> str;
		//cout << str;
		file[i].open(str, ios::out | ios::binary);
		s.clear();
	}
	//利用文件的偏移加文件的大小读取
	char ch;
	for (int i = 0; i < listnum; i++)
	{
		//拨动oldfile文件的指针
		//oldfile.seekg(filelist[i].fileoff, ios::beg);//拨动oldfile对象的文件指针到文件i的位置
		//能不能拿到偏移后的指针位置？file[i].write((char*)&oldfile, filelist[i].filesize);//写入到文件i中 待解决
		oldfile.seekg(filelist[i].fileoff, ios::beg);//拨动oldfile对象的文件指针到文件i的位置
		//方法一：一个字符一个字符的放
		for (int n = 0; n < filelist[i].filesize; n++)
		{
			ch = oldfile.get();
			file[i].put(ch);
		}
		file[i].close();
	}

	oldfile.close();
}
