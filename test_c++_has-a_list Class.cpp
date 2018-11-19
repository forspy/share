#include<iostream>
#include<list>//已经实现好的链表STL容器
#include<iomanip>//格式化头文件
using namespace std;
//建立一个栈内链表类
//基于链表实现的栈
template <typename T>
class Stack
{
private:
	list<T> m_list;//生成一个链表类对象
public:
	Stack();
	Stack(const Stack<T>& that) :m_list(that.m_list) { }//拷贝构造,Stack<T>表示类型，名字Stack可以省略
	Stack<T>& operator=(const Stack<T>& that);
	~Stack();

	void push(const T& data);
	void pop();
	T& top();
	const T& top()const;//权当复习一下常函数
	bool empty() const;
};
int main()
{
	try//在调用top的时候一定要调用try
	{
		Stack<int> s1;//实例化对象
		for (int i = 0; i < 10; i++)
		{
			s1.push(i);
		}
		while (!s1.empty())
		{
			cout << setw(2) << left << s1.top();//setw(2)表示空两格打印
			s1.pop();
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;//输出异常
		return -1;//-1表示异常给程序员看
	}
}

template<typename T>
Stack<T>::Stack()//构造的时候先初始化链表
{
	m_list.clear();//把链表清空
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& that)
{
	//先判断自赋值
	if (that = *this)
		return *this;
	m_list = that.m_list;
	return *this;
}

template<typename T>
Stack<T>::~Stack()
{
	m_list.clear();//析构也是把链表清空
}

template<typename T>
void Stack<T>::push(const T & data)
{
	m_list.push_back(data);//利用封装好的list链表模板直接调用对象方法压入
}

template<typename T>
void Stack<T>::pop()
{
	if (empty())
	{
		throw underflow_error("堆栈下溢");//抛出一个异常（下溢出异常）
	}
	m_list.pop_back();
}

template<typename T>
T & Stack<T>::top()//返回栈顶元素，即链表的最后一个元素
{
	if (empty())
	{
		throw exception("异常");//exception 是所有异常的基类
	}
	return m_list.back();//取链表的最后一个元素
}
//处理常函数小心，常函数只能调用常版本
template<typename T>
const T & Stack<T>::top() const
{
	return ((Stack<T>*)this)->top();//this具有常属性所以不强转一直循环调用自己，所以需要去常
}

template<typename T>
bool Stack<T>::empty() const
{
	return m_list.empty();
}


