#include<iostream>
//抛异常是针对运行阶段的错误
#include<csetjmp>
int fun1();
int fun2();
void fun3();
void fun4();
jmp_buf j_err;
//抛出异常
void fun();
using namespace std;
class A{};
class B:public A{};
//异常就是一个预防机制。在运行阶段灵活处理
//标准库异常--返回的是一个类 对象
//自定义异常可以继承标准库异常
void push(int data);
void push1(int data);
//-----
class overflow :public exception
{
	//既然子类继承了父类就可以重写虚函数，因为what是一个虚函数
	const char* what()const 
	{
		cout << "撑不住了" << endl;
	}
};
int main()
{
	if (setjmp(j_err)==0)//j_eer默认为0
	{
		fun4();
	}
	//---------
	try
	{
		fun();
	}
	catch (int ex)
	{
		if (ex == -1)
		{
			cout << "文件打开失败" << endl;
		}
		return -1;
	}
	//catch..可以使用多个catch捕获异常
	//只要抛出就异常就必须抓住异常，不然会报错
	//捕获顺序
	try
	{
		throw B();
	}
	catch (A& ex)
	{
		cout << "A异常" << endl;
	}
	catch (B& ex)
	{
		cout << "B异常" << endl;
	}
	//将先被A捕获，就近原则
	//
	try
	{
		push(10);
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
	}
}

int fun1()//接口层
{
	//移植性很低---------只能在控制台使用 界面Qt和MFC就不能使用，而c++的目的优势就是移植性好
	FILE *fid = fopen("out.txt", "r");
	if (fid == NULL)
	{
		printf("打开%s失败\n", "txt_out.txt");//
		return;
	}
	//-------------
	if (fid == NULL)
	{
		return -1;//返回-1代表文件打开失败，这样这一块的接口代码就通用了
	}
}
int fun2()//设计层
{
	if (fun1() == -1)
	{
		//...错误处理
		return -2;
	}
}

//fun1，fun2的有点是层次清晰  但缺点是层数多，需要逐层判断
//setjmp（设置一个跳跃点） longjmp（然后长跳转）
void fun3()
{
	FILE *fid = fopen("out.txt", "r");
	if (fid == NULL)
	{
		longjmp(j_err, -1);//利用longjmp把j_err设置成-1，然后一个大跳跳到if (setjmp(j_eer)==0)
	}
}
void fun4()
{
	fun3();
}
void fun()
{
	FILE *fid = fopen("out.txt", "r");
	if (fid == NULL)
	{
		throw - 1;//z这个是需要处理的,抛出了异常就停在这里，如果有try就测试异常，并使用catch捕获异常
	}
	char* pb = (char*)malloc(0xfeeefeee);//申请一块不存在的地址
	if (!pb)
	{
		throw "内存申请失败";
	}
}

void push(int data)
{
	throw overflow_error("内存溢出");
	
}
void push1(int data)
{
	throw overflow();//使用自定义的类抛出异常
}