//ģ��array����ֻ�ܴ�����������ͣ��������Դ��������,���ﴢ����string�����
#include<iostream>
#include<array>
#include<string>
using namespace std;
const int Season = 4;
const array < string, Season > sname= {"spring", "summer", "fall", "winter"};
void filled_expense(array<double, Season> a, int n);
void filled_expense(array<double, Season> *a, int n);
void shou_expense(array<double, Season> ex, int n);
int main(int argc, char** argv)
{
	array<double, Season>expense = {0,0,0,0};//expense��һ��ָ�룬Ҳ��һ������һ��������һ�����壨�൱����һ����������һ��������һ�����壬�������Ԫ��ֻ������ĳ�Ա
	filled_expense(&expense, Season);//����ַ�޸Ķ���
	shou_expense(expense, Season);//�൱�ڿ����������

}
void filled_expense(array<double, Season>* a, int n)//��ʵa��һ��ָ��ָ���ָ�룬��Ϊarray<double, Season>�������һ��ָ��
{
	for (int i = 0; i < n; i++)
	{
		cout << "enter " << sname[i] << " expense" << endl;
		cin >> (*a)[i];//��ָ��ĽǶȿ��ǣ�a��һ��ָ��ָ���ָ�룬����Ҫ��*a���õ�expense�ĵ�ַ���ٽ�����
		               //�Ӷ���ĽǶȿ���aָ��expense�������һ��������һ�����壨�൱����һ�����������л�������Ҫ������
		//�Զ�����޸�ҪС���ˣ�ע�⼰ʱ������
	}
}
void shou_expense(array<double, Season> ex, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << sname[i] << " = " << ex[i] << endl;
	}
}
//�����Ǵ�ֵ�޸ģ����Կ���û���޸�ԭarray�����е�ֵ
void filled_expense(array<double, Season> a, int n)//��ʵa��һ��ָ��ָ���ָ�룬��Ϊarray<double, Season>�������һ��ָ��
{
	for (int i = 0; i < n; i++)
	{
		cout << "enter " << sname[i] << " expense" << endl;
		cin >> a[i];//��ָ��ĽǶȿ��ǣ�a��һ��ָ��ָ���ָ�룬����Ҫ��*a���õ�expense�ĵ�ַ���ٽ�����
		               //�Ӷ���ĽǶȿ���aָ��expense�������һ��������һ�����壨�൱����һ�����������л�������Ҫ������
	}
}