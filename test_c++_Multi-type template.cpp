//������ģ�壬һ�㹹�캯���������������������ϵ�ֵ
#include<iostream>
#include<string>
template<class T1,class T2>
//Ҳ�����ṩĬ������template<class T1,class T2=int>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();//���Ե���ֵ��Ҳ���Ե���ֵ
	T1 first() const { return a; }//�����constҲ�γ����أ�ֻ�ܵ���ֵ
	T2 second() const { return b; }
	Pair (const T1& aval,const T2& bval): a(aval),b(bval){ }
	Pair(){ }
};
//���⻹����ʹ����ʾ��ȫ���廯�Ͳ��־��廯������ģ���ͨ����
//��ȫ���廯:template <> class Pair<cha*>{...}
//���־��廯:template<class T1>class Pair<T1,int>{...}
//����ĵ������ȼ�Ϊ��1.ָ��ģ��template<class T*> 2.���廯ģ�� 3.��ͨģ��

template<class T1,class T2>
T1& Pair<T1, T2>::first()
{
	return a;//����һ������ΪT1�ĳ�Ա����
}

template<class T1,class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}

int main()
{
	using namespace std;
	//ע��Pair<char*,int>����������ȫ��ͬ����������
	Pair<string, int> rating[4] = {
		Pair<string,int>("xiaoming",5),
		Pair<string,int>("xiaowang",4),
		Pair<string,int>("xiaozhang",3),
		Pair<string,int>("xiaohong",2),
	};//��ʼ����Ҫд;
	int joints = sizeof(rating) / sizeof (Pair<string, int>);//��������Ĵ�С����һ������Ĵ�С���ڶ�������ĸ���
	cout << "Rating:\t eatery" << endl;
	for (int i = 0; i < joints; i++)
	{
		cout << rating[i].second() << "\t" << rating[i].first() << endl;
	}
	//��������һ������ĳ�Ա����
	rating[3].first() = "xiaohua";
	rating[3].second() = 1;
	cout << rating[3].second() << "\t" << rating[3].first() << endl;
}
