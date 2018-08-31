#include<iostream>
#include<string>
using namespace std;
int main()
{
	char name[20];
	cin.getline(name,20);
	char str[20];
	char s;
	cin.get(str, 3).get(s).get();//c++支持函数重载，对于可以输入的多个参数，可以只输入部分参数
	//编译器会去寻找有不同参数的get()版本
	//cin >> name;
	cout << name << endl;
	cout << str << endl;
	//CTRL+Z 和enter=EOF
	char* city[3] = { "beijing","shanghai","guangdong" };//city[3]是一个指针数组
	char city1[3][20] = { "beijing","shanghai","guandong" };//利用二维数组去存储，每行最大19个字符，不建议
	string city2[5]= { "beijing","shanghai","guandong" };//利用string对象数组
	int a[3][2]=
	{
		{1,2},
		{3,4},
		{5,6},
	};
	for (int i = 0; i < 3; i++)
	{
		for(int j=0;j<2;j++)
		cout << a[i][j] ;
		cout << endl;
	}
	//三种字符串的输出方式相同
	for (int i = 0; i < 3; i++)
	{
		cout << city2[i] << "\t";//制表符对齐
	}
	
}