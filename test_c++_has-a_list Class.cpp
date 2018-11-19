#include<iostream>
#include<list>//�Ѿ�ʵ�ֺõ�����STL����
#include<iomanip>//��ʽ��ͷ�ļ�
using namespace std;
//����һ��ջ��������
//��������ʵ�ֵ�ջ
template <typename T>
class Stack
{
private:
	list<T> m_list;//����һ�����������
public:
	Stack();
	Stack(const Stack<T>& that) :m_list(that.m_list) { }//��������,Stack<T>��ʾ���ͣ�����Stack����ʡ��
	Stack<T>& operator=(const Stack<T>& that);
	~Stack();

	void push(const T& data);
	void pop();
	T& top();
	const T& top()const;//Ȩ����ϰһ�³�����
	bool empty() const;
};
int main()
{
	try//�ڵ���top��ʱ��һ��Ҫ����try
	{
		Stack<int> s1;//ʵ��������
		for (int i = 0; i < 10; i++)
		{
			s1.push(i);
		}
		while (!s1.empty())
		{
			cout << setw(2) << left << s1.top();//setw(2)��ʾ�������ӡ
			s1.pop();
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;//����쳣
		return -1;//-1��ʾ�쳣������Ա��
	}
}

template<typename T>
Stack<T>::Stack()//�����ʱ���ȳ�ʼ������
{
	m_list.clear();//���������
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& that)
{
	//���ж��Ը�ֵ
	if (that = *this)
		return *this;
	m_list = that.m_list;
	return *this;
}

template<typename T>
Stack<T>::~Stack()
{
	m_list.clear();//����Ҳ�ǰ��������
}

template<typename T>
void Stack<T>::push(const T & data)
{
	m_list.push_back(data);//���÷�װ�õ�list����ģ��ֱ�ӵ��ö��󷽷�ѹ��
}

template<typename T>
void Stack<T>::pop()
{
	if (empty())
	{
		throw underflow_error("��ջ����");//�׳�һ���쳣��������쳣��
	}
	m_list.pop_back();
}

template<typename T>
T & Stack<T>::top()//����ջ��Ԫ�أ�����������һ��Ԫ��
{
	if (empty())
	{
		throw exception("�쳣");//exception �������쳣�Ļ���
	}
	return m_list.back();//ȡ��������һ��Ԫ��
}
//��������С�ģ�������ֻ�ܵ��ó��汾
template<typename T>
const T & Stack<T>::top() const
{
	return ((Stack<T>*)this)->top();//this���г��������Բ�ǿתһֱѭ�������Լ���������Ҫȥ��
}

template<typename T>
bool Stack<T>::empty() const
{
	return m_list.empty();
}


