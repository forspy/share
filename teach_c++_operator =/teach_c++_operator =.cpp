#include"Array.h"

int  main()
{
	my_Array *p = new my_Array(4);//注意不是要构造4个对象，而是只构造一个对象，这个对象里有成员数组,4作为构造函数的参数传进去
	for (int i = 0; i < p->size(); i++)
	{
		p->at(i)=i;//利用at去访问对象*p内的成员，达到[]的效果
		//p[i] = i;//p[i]=my_Array temp(i);会调用隐式的构造和默认operator=重载,但这里不行，因为这里只有一个对象
	}
	cout << *p << endl;

	my_Array a1;//默认普通构造
	a1.at(0) = 111111;//给里面的数组成员赋值
	cout << a1 << endl;
	my_Array a2(*p);//拷贝构造,如果my_Array a2=a3;这不算=重载，而算隐式调用拷贝构造my_Array a2=my_Array(a3);
	cout << a2 << endl;
	delete p;
	my_Array a3 ;
	//a3 = a2;//1.默认=重载会导致a3原来成员指针指向的内存泄露，2.析构2个对象的时候会导致2次释放3.总结就是浅拷贝
	a3 = a1;
	cout << a3 << endl;
}