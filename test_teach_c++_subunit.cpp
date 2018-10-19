#include<iostream>
using namespace std;
void func(int, int b, int)//为了产品升级服务的，产品升级后可能参数1和参数3不使用了
//为了不在main用户使用里改大量的代码，所以使用亚元
{
	cout << b << endl;
}
int main()
{
	func(1, 2, 3);
}