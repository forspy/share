#include<iostream>
#include<sstream>//字符串流
#include<fstream>//文件流
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
	int filenamesize;//文件名大小
	int fileoff;//文件偏移
	int filesize;//文件大小
	char filename[20];//文件名
};
void packfile();//文件打包

int main()
{
	student stu[3] = {
		{"小马",1001,18,'m'},
		{"小红",1002,19,'w'},
		{"小明",1003,20,'m'},
	};//txt里面输入int会出现乱码，所以最好全以字符串方式输入(如果是为了看的话)
	//写是从流里面输出，就相当于从一个罐子流出，所以是ofstream
	ofstream outfile("stu.txt",ios_base::out);//以txt方式打开(以构造方式)  
	//ofstream outfile("stu.dat", ios::binary);//以二进制方式打开(以构造方式) -n 编码方式有小区别
	/*ofstream outfile;
	outfile.open("stu.dat", ios::binary);//与上面等价*/
	//ios_base::in---'r'  ios_base::out----'w'  ios_base::out| ios_base::app----'a' 
	//ios_base::out|ios_base::in---'r+'  ios_base::out|ios_base::in|ios_base::trunc---'w+'
	//这里也可以省略_base 变成 ios::in
	if (!outfile)
	{
		cerr << "open error!" << endl;
		//exit(-1);//退出程序
		abort();//中断程序
	}
	for (int i = 0; i < 3; ++i)
	{
		outfile.write((char*)&stu[i], sizeof stu[i]);//ofstream对象.write(char*,sizeof),所以只需要把student*类型的指针转成char*类型的指针就行了，得到地址就可以
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

	file2.write((const char*)&a, sizeof a);//发现txt输入int数字不行，会产生乱码
	file2.close();
	
	student rstu[3];//读出来也需要另外一个对象数组接住
	ifstream infile("stu.txt", ios_base::in); 
	if (!infile)
	{
		cerr << "open error!" << endl;
		//exit(-1);//退出程序
		abort();//中断程序
	}
	for (int i = 0; i < 3; ++i)
	{
		infile.read((char*)&rstu[i], sizeof rstu[i]);
	}
	infile.close();
	//显示
	for (int i = 0; i < 3; ++i)
	{
		cout << "name:" << rstu[i].name << endl;
		cout << "编号:" << rstu[i].num << endl;
		cout << "年龄:" << rstu[i].age << endl;
		cout << "性别:" << rstu[i].sex << endl;
	} 
	//说明其实虽然txt里面显示的是乱码，但是输入的数据是正确的，所以int的输入需要处理
	/*文件打包
	文件数量：(4字节)，索引表大小：(4字节)（索引表的意思是记录下面文件信息一共有多少个字节）
	写文件1的信息：文件1大小（4字节）；文件1的偏移（4字节）；文件1名的长度（4字节）；文件1名（4字节）
	写文件2的信息：文件2大小（4字节）；文件2的偏移（4字节）；文件2名的长度（4字节）；文件2名（4字节）
	...
	然后开始读打包文件信息
	*/
	packfile();
}

void packfile()
{
	//先准备好一组文件信息对象
	fileinfo filelist[4] = {
		{ 0,0,0,"1.jpg" },
		{ 0,0,0,"2.jpg" },
		{ 0,0,0,"3.jpg" },
		{ 0,0,0,"4.jpg" },
	};//先初始化一下
	//因为fstream继承了ofstream和ifstream，所以可以用fstream来创建对象
	fstream file[4];//准备四个文件流对象
	int listsize = 0;//准备索引表大小
	int listnum = 4;//1,准备文件数量
	for (int i = 0; i < 4; i++)//编写文件信息
	{
		filelist[i].filenamesize = strlen(filelist[i].filename) + 1;//+'\0',因为文件名已经初始化了
		//写文件1的信息：文件1大小（4字节）；文件1的偏移（4字节）；文件1名的长度（4字节）；文件1名（4字节）
		/*2.索引表大小 */listsize += 4 + 4 + 4 + filelist[i].filenamesize;
		//3.计算文件大小----
		file[i].open(filelist[i].filename, ios::in | ios::binary);//以二进制的方式读取图片中的信息
		//文件指针从文件头到文件尾走过了多少距离就是文件的大小
		//seekg（读）设置文件的指针位置seekg（偏移值，移动到的位置），在文件头beg偏移为正，在文件尾end（最后一个字符的后一位）偏移为负，cur为当前,
		//seekp(写)
		file[i].seekg(0, ios::end);//将文件指针移到该文件的末尾
		filelist[i].filesize = file[i].tellg();//告诉你现在的指针距离开头有多远，即获取了文件大小,比如第一个文件读出来的是59771个字节
		file[i].seekg(0, ios::beg);//把文件指针挪回去
		//-------------
	}
	//然后把整合的信息写入到一个新的文件流里面去，所以需要创建一个新的文件对象
	fstream newfile("new.pack", ios::out | ios::binary);
	newfile.write((char*)&listsize, 4);//索引表大小是4个字节的存的是打包文件的大小的信息，比如一共145603个字节存一下
	newfile.write((char*)&listnum, sizeof(int));//同理，比如4个文件
	//写逐个文件的信息
	for (int i = 0; i < listnum; i++)
	{
		//文件偏移量（或者说文件i起始的位置）
		if (i == 0)//第一个文件
		{
			filelist[i].fileoff = 4 + 4 + listsize;//索引表（4）+文件个数（4）+索引表内容大小
			/*
			（索引表大小）145603（4字节）  （文件个数）4 （4字节）
			（文件1的大小）59771（4字节） （文件1的偏移）80（4字节） (文件1名的长度)6（4字节）  （文件1名）1.jpg（6字节）
			（文件2的大小）...
			*/
		}
		else
		{
			//剩下的文件的偏移值为前一个文件的偏移值+前一个文件的大小
			filelist[i].fileoff = filelist[i - 1].fileoff + filelist[i - 1].filesize;
		}
		newfile.write((char*)&filelist[i].filenamesize, 4);//写入文件i的大小
		newfile.write((char*)&filelist[i].fileoff, 4);//写文件i的偏移
		newfile.write((char*)&filelist[i].filenamesize, 4);//文件i名的长度
		newfile.write(filelist[i].filename, filelist[i].filenamesize);//文件i名,因为文件名本来就是char*的
	}
	//写文件
	//这里采用一个字符一个字符写入
	char ch;
	for (int i = 0; i < listnum; i++)
	{
		while (!file[i].eof())//while (ch = file[i].get()&&!file[i].eof())这种写法在ch='\0'就会结束
			//如果硬要写在一起可以while (ch = file[i].get(),!file[i].eof()) 但是不建议
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
