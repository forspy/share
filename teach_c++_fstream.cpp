#include<iostream>
#include<sstream>//�ַ�����
#include<fstream>//�ļ���
using namespace std;
struct student
{
	char name[20];
	int num;
	int age;
	char sex;
};
struct fileinfo
{
	int filenamesize;//�ļ�����С
	int fileoff;//�ļ�ƫ��
	int filesize;//�ļ���С
	char filename[20];//�ļ���
};
void packfile();//�ļ����

int main()
{
	student stu[3] = {
		{"С��",1001,18,'m'},
		{"С��",1002,19,'w'},
		{"С��",1003,20,'m'},
	};//txt��������int��������룬�������ȫ���ַ�����ʽ����(�����Ϊ�˿��Ļ�)
	//д�Ǵ���������������൱�ڴ�һ������������������ofstream
	ofstream outfile("stu.txt",ios_base::out);//��txt��ʽ��(�Թ��췽ʽ)  
	//ofstream outfile("stu.dat", ios::binary);//�Զ����Ʒ�ʽ��(�Թ��췽ʽ) -n ���뷽ʽ��С����
	/*ofstream outfile;
	outfile.open("stu.dat", ios::binary);//������ȼ�*/
	//ios_base::in---'r'  ios_base::out----'w'  ios_base::out| ios_base::app----'a' 
	//ios_base::out|ios_base::in---'r+'  ios_base::out|ios_base::in|ios_base::trunc---'w+'
	//����Ҳ����ʡ��_base ��� ios::in
	if (!outfile)
	{
		cerr << "open error!" << endl;
		//exit(-1);//�˳�����
		abort();//�жϳ���
	}
	for (int i = 0; i < 3; ++i)
	{
		outfile.write((char*)&stu[i], sizeof stu[i]);//ofstream����.write(char*,sizeof),����ֻ��Ҫ��student*���͵�ָ��ת��char*���͵�ָ������ˣ��õ���ַ�Ϳ���
	}
	outfile.close();

	ofstream file1;
	file1.open("1.txt", ios::out);
	char name[] = "hello";
	file1.write(name, sizeof name);
	file1.close();

	ofstream file2;
	file2.open("2.txt", ios::out);
	int a = 10086;

	file2.write((const char*)&a, sizeof a);//����txt����int���ֲ��У����������
	file2.close();
	
	student rstu[3];//������Ҳ��Ҫ����һ�����������ס
	ifstream infile("stu.txt", ios_base::in); 
	if (!infile)
	{
		cerr << "open error!" << endl;
		//exit(-1);//�˳�����
		abort();//�жϳ���
	}
	for (int i = 0; i < 3; ++i)
	{
		infile.read((char*)&rstu[i], sizeof rstu[i]);
	}
	infile.close();
	//��ʾ
	for (int i = 0; i < 3; ++i)
	{
		cout << "name:" << rstu[i].name << endl;
		cout << "���:" << rstu[i].num << endl;
		cout << "����:" << rstu[i].age << endl;
		cout << "�Ա�:" << rstu[i].sex << endl;
	} 
	//˵����ʵ��Ȼtxt������ʾ�������룬�����������������ȷ�ģ�����int��������Ҫ����
	/*�ļ����
	�ļ�������(4�ֽ�)���������С��(4�ֽ�)�����������˼�Ǽ�¼�����ļ���Ϣһ���ж��ٸ��ֽڣ�
	д�ļ�1����Ϣ���ļ�1��С��4�ֽڣ����ļ�1��ƫ�ƣ�4�ֽڣ����ļ�1���ĳ��ȣ�4�ֽڣ����ļ�1����4�ֽڣ�
	д�ļ�2����Ϣ���ļ�2��С��4�ֽڣ����ļ�2��ƫ�ƣ�4�ֽڣ����ļ�2���ĳ��ȣ�4�ֽڣ����ļ�2����4�ֽڣ�
	...
	Ȼ��ʼ������ļ���Ϣ
	*/
	packfile();
}

void packfile()
{
	//��׼����һ���ļ���Ϣ����
	fileinfo filelist[4] = {
		{ 0,0,0,"1.jpg" },
		{ 0,0,0,"2.jpg" },
		{ 0,0,0,"3.jpg" },
		{ 0,0,0,"4.jpg" },
	};//�ȳ�ʼ��һ��
	//��Ϊfstream�̳���ofstream��ifstream�����Կ�����fstream����������
	fstream file[4];//׼���ĸ��ļ�������
	int listsize = 0;//׼���������С
	int listnum = 4;//1,׼���ļ�����
	for (int i = 0; i < 4; i++)//��д�ļ���Ϣ
	{
		filelist[i].filenamesize = strlen(filelist[i].filename) + 1;//+'\0',��Ϊ�ļ����Ѿ���ʼ����
		//д�ļ�1����Ϣ���ļ�1��С��4�ֽڣ����ļ�1��ƫ�ƣ�4�ֽڣ����ļ�1���ĳ��ȣ�4�ֽڣ����ļ�1����4�ֽڣ�
		/*2.�������С */listsize += 4 + 4 + 4 + filelist[i].filenamesize;
		//3.�����ļ���С----
		file[i].open(filelist[i].filename, ios::in | ios::binary);//�Զ����Ƶķ�ʽ��ȡͼƬ�е���Ϣ
		//�ļ�ָ����ļ�ͷ���ļ�β�߹��˶��پ�������ļ��Ĵ�С
		//seekg�����������ļ���ָ��λ��seekg��ƫ��ֵ���ƶ�����λ�ã������ļ�ͷbegƫ��Ϊ�������ļ�βend�����һ���ַ��ĺ�һλ��ƫ��Ϊ����curΪ��ǰ,
		//seekp(д)
		file[i].seekg(0, ios::end);//���ļ�ָ���Ƶ����ļ���ĩβ
		filelist[i].filesize = file[i].tellg();//���������ڵ�ָ����뿪ͷ�ж�Զ������ȡ���ļ���С,�����һ���ļ�����������59771���ֽ�
		file[i].seekg(0, ios::beg);//���ļ�ָ��Ų��ȥ
		//-------------
	}
	//Ȼ������ϵ���Ϣд�뵽һ���µ��ļ�������ȥ��������Ҫ����һ���µ��ļ�����
	fstream newfile("new.pack", ios::out | ios::binary);
	newfile.write((char*)&listsize, 4);//�������С��4���ֽڵĴ���Ǵ���ļ��Ĵ�С����Ϣ������һ��145603���ֽڴ�һ��
	newfile.write((char*)&listnum, sizeof(int));//ͬ������4���ļ�
	//д����ļ�����Ϣ
	for (int i = 0; i < listnum; i++)
	{
		//�ļ�ƫ����������˵�ļ�i��ʼ��λ�ã�
		if (i == 0)//��һ���ļ�
		{
			filelist[i].fileoff = 4 + 4 + listsize;//������4��+�ļ�������4��+���������ݴ�С
			/*
			���������С��145603��4�ֽڣ�  ���ļ�������4 ��4�ֽڣ�
			���ļ�1�Ĵ�С��59771��4�ֽڣ� ���ļ�1��ƫ�ƣ�80��4�ֽڣ� (�ļ�1���ĳ���)6��4�ֽڣ�  ���ļ�1����1.jpg��6�ֽڣ�
			���ļ�2�Ĵ�С��...
			*/
		}
		else
		{
			//ʣ�µ��ļ���ƫ��ֵΪǰһ���ļ���ƫ��ֵ+ǰһ���ļ��Ĵ�С
			filelist[i].fileoff = filelist[i - 1].fileoff + filelist[i - 1].filesize;
		}
		newfile.write((char*)&filelist[i].filenamesize, 4);//д���ļ�i�Ĵ�С
		newfile.write((char*)&filelist[i].fileoff, 4);//д�ļ�i��ƫ��
		newfile.write((char*)&filelist[i].filenamesize, 4);//�ļ�i���ĳ���
		newfile.write(filelist[i].filename, filelist[i].filenamesize);//�ļ�i��,��Ϊ�ļ�����������char*��
	}
	//д�ļ�
	//�������һ���ַ�һ���ַ�д��
	char ch;
	for (int i = 0; i < listnum; i++)
	{
		while (!file[i].eof())//while (ch = file[i].get()&&!file[i].eof())����д����ch='\0'�ͻ����
			//���ӲҪд��һ�����while (ch = file[i].get(),!file[i].eof()) ���ǲ�����
		{
			ch = file[i].get();
			newfile.put(ch);
		}
	}
	for (int i = 0; i < listnum; i++)
	{
		file[i].close();
	}
	newfile.close();
}
