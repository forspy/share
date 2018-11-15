#include<iostream>
using namespace std;
template<class T>
class Beta
{
private:
	//-----
	template<class M>//模板类成员
	class hold
	{
	private:
		M val;
	public:
		hold(M v=0):val(v){ }
		void show()const { cout << val << endl; }
		M value()const { return val; }
	};
	hold<T> q;//是T类型的
	hold<int> n;//是int类型的
	//--------根据hold模板创建hold模板类的两个成员,因为创建了对象所以先把M设置成了T类型随后又设置成了int类型
public:
	Beta(T t,int i):q(t),n(i){ }//通过Beta的构造函数给q，n两个对象赋初值
	template<class U>//模板类成员函数
	U blab(U u, T t);
	void Show() { q.show(); n.show(); }
};
//在外面定义的方式，嵌套
template<class T>
template<class U>
U Beta<T>::blab(U u, T t)
{
	return((n.value() + q.value())*u / t);//n是int类型的，q是T类型的，但是main里面声明T为double类型，因此int和double可以相加
}

int main()
{
	Beta<double>guy(3.5, 3);
	cout << "T 设置为double" << endl;
	guy.Show();//区别大模板里面的方法和小模板里面的方法
	cout << guy.blab(10, 2.3) << endl;//这里奇怪的是都没有申明U的类型，直接根据参数就确定的U的类型，待解决
	//1.解释blab方法的U类型由该方法被条用时的参数显式确定，另一个参数T类型由对象的实例化类型确定，T类型为double，所以参数都应该写成double类型
	//2.虽然blab方法算出的是double类型，但是返回类型是U，而U现在变成了int类型，所以返回数据会产生截断
	cout << "U设置为int" << endl;
	cout << guy.blab(10.0, 2.3) << endl;//因为U本来就是double类型，所以返回数据并不会产生截断
	cout << "U设置为double" << endl;
}