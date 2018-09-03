#include<iostream>
#include<fstream>
#include<cstdlib>//support for exit()
using namespace std;
const int FILESIZE = 50;
int main()
{
	char filename[FILESIZE];
	ifstream infile;//声明一个ifstream类的对象
	cout << "请输入文件名\n";
	cin.getline(filename, FILESIZE);
	infile.open(filename);//打开这个文件
	if (!infile.is_open())//如果没打开
	{
		cout << "failed open,program terminating \n";
		exit(EXIT_FAILURE);//结束程序
	}
	double value;
	double sum = 0.0;
	int count = 0;
	//infile >> value;//取得第一个数，不要预读取，这样文件指针会先偏移一位
	while (infile.good())//while input good and not at EOF
	{
		infile >> value;
		sum += value;
		count++;
	}
	if (infile.eof())
		cout << "到达文档末尾\n";
	else if (infile.fail())
		cout << "input terminated by data mismatch.\n";
	else
		cout << "input terminated for unknow reason.\n";

	if (count == 0)
		cout << "No data processed.\n";
	else
	{
		cout << "items read:" << count << '\n';
		cout << "sum=" << sum << endl;
		cout << "average=" << sum / count << endl;
	}
	infile.close();
	return 0;
}