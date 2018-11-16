#pragma once
template<class T>
class QueueTP
{
private:
	enum{Q_SIZE=10};
	//Ƕ���࣬ԭ����struct�ṹ�壬��ʵ�ṹ��Ҳ����һ����
	//�������һ�����ǣ������������ڶ���һ�����Ա����Ƕ��ֻ������
	class Node
	{
	public:
		T item;
		Node* next;
		Node(const T& i):item(i),next(0){ }//Node��Ĺ��캯��
	};
	Node* front;
	Node* rear;
	int items;//��ǰ�������������
	int qsize;//����������
	QueueTP(const QueueTP& q):qsize(0){ }
	QueueTP& operator=(const QueueTP& q) { return *this; }
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty() { return items == 0; }
	bool isfull() { return items == qsize; }
	int queueCount() { return items; }
	bool enqueue(const T& item);
	bool dequeue(T& item);
};
//ע��templateģ�����ʵ�ֱ���Ƕ����.h�ļ���
template <class T>
QueueTP<T>::QueueTP(int qs) :qsize(qs)
{
	front = rear = 0;
	items = 0;
}
template<class T>
QueueTP<T>::~QueueTP()
{
	Node* temp;
	while (front != 0)
	{
		temp = front;//����Ҫɾ����ͷ�ڵ�
		front = front->next;
		delete temp;
	}
}
template<class T>
bool QueueTP<T>::enqueue(const T& item)//ʵ�ֲ�����е��㷨
{
	if (isfull())
		return false;
	Node* add = new Node(item);//ʹ����Node��Ĺ��캯��
							   //���ʧ�ܻ��׳�exception
	items++;
	if (front == 0)
		front = add;
	else
		rear->next = add;
	rear = add;//
	return true;
}
template <class	T>
bool QueueTP<T>::dequeue(T& item)
{
	if (front == 0)
		return false;
	item = front->item;//��ͷ����ȥ,ͨ�����÷������������item�������Ժ�Ҫ�õ�
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = 0;
	return true;
}