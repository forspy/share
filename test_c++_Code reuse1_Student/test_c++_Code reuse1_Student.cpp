//Ŀ�����һ��Student�࣬�����Ա���������������飬���ǿɱ䳤�ȵġ��������е����Ա����1.��������ʹ��string�����
//2.�������ʹ��ģ��������valarray
//����valarray��
/*
valarry����ͷ�ļ�<valarray>֧�ֵģ����ڴ���������ֵ������֧�ֽ�����������Ԫ�ص�ֵ��ӣ��Լ����������ҳ�������Сֵ�Ȳ���
*/
#include<valarray>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	valarray<double> v1;//����һ��double���͵�0��Ԫ�ص����飨valarrayҲ��Ҫ���ƿռ�std��֧�֣�
	valarray<int>v2(8);//8��Ԫ�ص�����
	valarray<int>v3(10,8);//8��Ԫ�ص�����,ÿ��Ԫ����Ϊ10
	double gpa[5] = { 1,2,3,4,5 };
	valarray<double>v4(gpa, 4);//4��Ԫ�����飬4��ֵΪgpa�����ڵ�ֵ
	valarray<int>v5 = { 1,2,3,4,5 };//Ҳ����ʹ�������ʼ��
	/*
	������������һЩ������
	[]����Ԫ�أ�����operator[]��
	size()���ذ�����Ԫ��
	sum()����Ԫ�ص��ܺ�
	max()�������ֵ��Ԫ��
	min()������Сֵ��Ԫ��
	*/
	cout << v5.max() << v5.min() << endl;
}
