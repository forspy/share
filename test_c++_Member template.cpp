#include<iostream>
using namespace std;
template<class T>
class Beta
{
private:
	//-----
	template<class M>//ģ�����Ա
	class hold
	{
	private:
		M val;
	public:
		hold(M v=0):val(v){ }
		void show()const { cout << val << endl; }
		M value()const { return val; }
	};
	hold<T> q;//��T���͵�
	hold<int> n;//��int���͵�
	//--------����holdģ�崴��holdģ�����������Ա,��Ϊ�����˶��������Ȱ�M���ó���T������������ó���int����
public:
	Beta(T t,int i):q(t),n(i){ }//ͨ��Beta�Ĺ��캯����q��n�������󸳳�ֵ
	template<class U>//ģ�����Ա����
	U blab(U u, T t);
	void Show() { q.show(); n.show(); }
};
//�����涨��ķ�ʽ��Ƕ��
template<class T>
template<class U>
U Beta<T>::blab(U u, T t)
{
	return((n.value() + q.value())*u / t);//n��int���͵ģ�q��T���͵ģ�����main��������TΪdouble���ͣ����int��double�������
}

int main()
{
	Beta<double>guy(3.5, 3);
	cout << "T ����Ϊdouble" << endl;
	guy.Show();//�����ģ������ķ�����Сģ������ķ���
	cout << guy.blab(10, 2.3) << endl;//������ֵ��Ƕ�û������U�����ͣ�ֱ�Ӹ��ݲ�����ȷ����U�����ͣ������
	//1.����blab������U�����ɸ÷���������ʱ�Ĳ�����ʽȷ������һ������T�����ɶ����ʵ��������ȷ����T����Ϊdouble�����Բ�����Ӧ��д��double����
	//2.��Ȼblab�����������double���ͣ����Ƿ���������U����U���ڱ����int���ͣ����Է������ݻ�����ض�
	cout << "U����Ϊint" << endl;
	cout << guy.blab(10.0, 2.3) << endl;//��ΪU��������double���ͣ����Է������ݲ���������ض�
	cout << "U����Ϊdouble" << endl;
}