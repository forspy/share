#include<iostream>
#include<string>
using namespace std;
string version1(const string& a, const string& b);
const string& version2(string& a, const string& b);
string& version3(const string& a, const string& b);
int main()
{
	string input;
	string copy;
	string result;

	cout << "enter a string!" << endl;
	getline(cin, input);
	copy = input;
	result = version1(input, "***");
	cout << "version1:   " << result << endl;
	cout << "original:   " << input << endl;
	input = copy;//reset
	result = version2(input, "###");
	cout << "version2:   " << result << endl;
	cout << "origina2:   " << input << endl;
	input = copy;//reset
	result = version3(input, "@@@");
	cout << "version3:   " << result << endl;
	cout << "origina3:   " << input << endl;
	input = copy;//reset

}

string version1(const string& a, const string& b)//const sting& �ܽ�סstring����const string�Ӳ�סstring,string �ܽ�סconst string��
//const string&�ܽ�סchar* ��string �ܽ�סchar*��������const char* ֻ��ʹ��const string&��ס
{
	string temp;
	temp = b + a + b;
	return temp;
}

const string& version2(string& a, const string& b)//have side effect��const string&��ʾ����һ�����ã��÷��ص����ò��ܳ�Ϊ��ֵ�����ܱ��޸ģ�
{
	a = b + a + b;
	return a;
}

//bad design
string& version3(const string& a, const string& b)//������һ��ջ���Ѿ��ͷŵ��ڴ棬error
{
	string temp;
	temp = b + a + b;
	return temp;
}