#include<iostream>
using namespace std;
class A
{
private:
	static int temp;
public:
	A() { temp++; }
	~A()
	{
		temp++;
	}
	static int get() { return temp; }

};
int A::temp = 0;
int main()
{
	A* p = new A;
	delete p;
	cout << A::get() << endl;//即使对象被销毁静态也是全局的
}