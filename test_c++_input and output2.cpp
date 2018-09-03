#include<iostream>
#include<fstream>
#include<cstdlib>//support for exit()
using namespace std;
const int FILESIZE = 50;
int main()
{
	char filename[FILESIZE];
	ifstream infile;//����һ��ifstream��Ķ���
	cout << "�������ļ���\n";
	cin.getline(filename, FILESIZE);
	infile.open(filename);//������ļ�
	if (!infile.is_open())//���û��
	{
		cout << "failed open,program terminating \n";
		exit(EXIT_FAILURE);//��������
	}
	double value;
	double sum = 0.0;
	int count = 0;
	//infile >> value;//ȡ�õ�һ��������ҪԤ��ȡ�������ļ�ָ�����ƫ��һλ
	while (infile.good())//while input good and not at EOF
	{
		infile >> value;
		sum += value;
		count++;
	}
	if (infile.eof())
		cout << "�����ĵ�ĩβ\n";
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