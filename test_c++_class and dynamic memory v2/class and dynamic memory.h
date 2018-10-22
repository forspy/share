#pragma once
using namespace std;
class String_medium
{
private:
	char* str;//指向一样就应该能输出一样的内容啊？
	int len;
	static int num_strings;//对象的个数 这里通过static将num_strings声明为静态储存类，
	//静态储存类特点：无论创建了多少个对象，程序都只创建一个静态变量副本 类的所有对象共享一个静态成员
	static const int CLIMIT = 80;
public:
	/*
	   构造分为三种：
	        1、默认构造（无参数）
			2、带参构造（有参数）
			3、拷贝构造（参数是类的对象）
	*/
	//何时调用拷贝构造函数？新建一个对象并将其初始化为同类现有对象时，复制构造函数将被调用
	String_medium(const String_medium& other); //拷贝构造，就是把一个other的对象内容拷贝到本身，这里的参数必须是引用，如果不给引用，是值拷贝，会无限循环调用拷贝构造，const表示不会改变引用对象的值
	/*
	以下都将调用拷贝构造函数
	String_easy test(A);//隐式的赋值
	String_easy test=A;//显式地赋值
	String_easy test=String_easy(A);//调用复制构造函数式地赋值
	String_easy* p=new String_easy(A);//在堆上开辟一块内存建立A的拷贝对象，并用指针P指向该内存
	*/
	/*
	1.默认的复制构造函数逐一复制非静态成员，所以num_strings不会被复制（浅复制），因为静态函数属于整个类，所以他们不受影响
	2.如果成员本身就是类对象，则将使用这个类的复制构造函数来复制成员
	*/

	String_medium(const char* s);//构造函数
	String_medium();//默认构造函数
	~String_medium();//析构函数
	//当在main中test* p=new test[4];在堆上开辟内存在delete[] 时调用析构，或者在栈上开辟内存时test A；在作用域结束时自动调用
	//因为是String_medium所以添加一些新的功能
	//重载--------
	//考虑对象=对象
	String_medium& operator=(const String_medium& st);//由于在=赋值的时候也会遇到深度复制的问题，因此为String_easy类编写赋值运算符
	//考虑对象=char
	String_medium& operator=(const char* s);
	//对象[]，功能：显示对象字符的某个字符
	char& operator[](int i);
	const char& operator[](int i)const;
	//友元函数
	friend ostream& operator<<(ostream& os, const String_medium& st);
	//输入
	friend istream& operator >> (istream& is, String_medium& st);

	friend bool operator<(const String_medium& st1, const String_medium& st2);
	friend bool operator>(const String_medium& st1, const String_medium& st2);
	friend bool operator==(const String_medium& st1, const String_medium& st2);

};
