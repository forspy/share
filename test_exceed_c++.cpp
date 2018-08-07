#include <iostream>
#include<climits>

#define ZERO 0
const int Months = 12;//限定符修饰的变量，其值不允许被改变
int main()
{
	using namespace std;
	short sam = SHRT_MAX;//表示这种类型的最大范围SHRT_MAX(short类型短整形)
	unsigned short Sue = ZERO;
	Months = 11;
	cout << "Sam is "<<sam << endl;
	cout << "Sue is " << Sue << endl;
	sam = sam + 1;
	Sue = Sue - 1;
	cout << "Sam is " << sam << endl;
	cout << "Sue is " << Sue << endl;
	//short 范围[-2^7,2^7-1]  unsigned short 范围[0,2^8-1],如果超越了限制，其值将在另一端取值
	int waist = 42;
	cout << hex;//以十六进制格式输出
	cout << "waist = " << waist << endl;
	cout << dec;//以十进制格式输出
	cout << sam << endl;
	//decimal（十进制）hexadecimal（十六进制）octal（八进制）,取首三个字母即可以该进制输出
	char ch;
	ch = 'A';
	cout << ch << endl;
	cout.put(ch);//该语句与上面一样，put是iostream类中，cout对象里的成员函数！！！
	cout << endl;
	cout << "don't do that !\a\n";//响铃
}