//ģ��array����ֻ�ܴ�����������ͣ��������Դ��������,���ﴢ����string�����
#include<iostream>
#include<array>
#include<string>
#include<vector>
using namespace std;
const int Season = 4;
const array < string, Season > sname= {"spring", "summer", "fall", "winter"};
void filled_expense(array<double, Season> a, int n);
void filled_expense(array<double, Season> *a, int n);
void shou_expense(array<double, Season> ex, int n);
int main(int argc, char** argv)
{
	int m[10] = {0};
	array<double, Season>expense = {0,0,0,0};//expense����һ��ָ�룬��һ������һ��������һ�����壨�൱����һ����������һ��������һ�����壬�������Ԫ��ֻ������ĳ�Ա
	filled_expense(&expense, Season);//����ַ�޸Ķ���
	shou_expense(expense, Season);//�൱�ڿ����������
	array<double, Season>* ptr = &expense;
	//----------------------------����������vector/arrayģ��ıȽ�
	int* p = m;
	vector<int> vi(100, 1);
	vector<int>* pointer = &vi;
	cout << p[1] << endl;//��ʾ��ʽ�ǽ����ã���ַ��
	cout << (*ptr)[1] << endl;//��ʾ��ʽ�Ƕ���[������]
	cout << (*pointer)[1]<< endl;//��ʾ��ʽ�Ƕ���[������]
	//cout << *(vi+1) << endl;vi��vector��Ķ��󣬶Ըö��󲻴���ָ�������ͬ��arrayģ��
	

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