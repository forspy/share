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
	//��Ԫ
	template<typename T>
	friend ostream& operator<<(ostream& os,  Stack<T>& that);
	//��Ԫ�����ڲ����岻��Ҫģ��ͷ���ⲿ������Ҫ���������ⶼ���֧�ַ��͵�ģ��ͷ
	
	
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
		cout << s1 << endl;
		//while (!s1.empty())
		//{
		//	cout << setw(2) << left << s1.top();//setw(2)��ʾ�������ӡ
		//	s1.pop();
		//}
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
template<typename T>
ostream & operator<<(ostream & os,  Stack<T>& that)
{
	//auto it=that.m_list.begin(); //����ʹ���Զ������ƶϣ�Ϊʲô���� list<T>::iterator it=that.m_list.begin()���У���������ѽ��
	for (list<T>::iterator  it = that.m_list.begin(); it != that.m_list.end(); it++)
	{
		os << *it << " ";
	}
	return os;
}
/*
list<T>::iterator  it = that.m_list.begin()
�ᱨ���´���
error C2440: ����ʼ����: �޷��ӡ�std::_List_const_iterator<_Mylist>��ת��Ϊ��std::_List_iterator<_Mylist>��
�鿴listԴ�����list.begin()����������:
iterator begin()
{	// return iterator for beginning of mutable sequence
return (iterator(this->_Nextnode(this->_Myhead), this));
}
const_iterator begin() const
{	// return iterator for beginning of nonmutable sequence
return (const_iterator(this->_Nextnode(this->_Myhead), this));
}


//ע���ˣ�����const����汾iteratorҲ����const_iterator�汾
template<typename T>
friend ostream& operator<<(ostream& os,const Stack<T>& that);


��Ϊ����Ĳ���Ϊconst�����Ե��õ��ǵڶ������������ص���const_iterator��������iterator���Żᱨ��
��ԭ�л������������޸ļ�����ȷ����
list<T>::const_iterator  it = that.m_list.begin();
*/