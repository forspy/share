#include<iostream>
#include<string>
using namespace std;
int main()
{
	char name[20];
	cin.getline(name,20);
	char str[20];
	char s;
	cin.get(str, 3).get(s).get();//c++֧�ֺ������أ����ڿ�������Ķ������������ֻ���벿�ֲ���
	//��������ȥѰ���в�ͬ������get()�汾
	//cin >> name;
	cout << name << endl;
	cout << str << endl;
	//CTRL+Z ��enter=EOF
	char* city[3] = { "beijing","shanghai","guangdong" };//city[3]��һ��ָ������
	char city1[3][20] = { "beijing","shanghai","guandong" };//���ö�ά����ȥ�洢��ÿ�����19���ַ���������
	string city2[5]= { "beijing","shanghai","guandong" };//����string��������
	int a[3][2]=
	{
		{1,2},
		{3,4},
		{5,6},
	};
	for (int i = 0; i < 3; i++)
	{
		for(int j=0;j<2;j++)
		cout << a[i][j] ;
		cout << endl;
	}
	//�����ַ����������ʽ��ͬ
	for (int i = 0; i < 3; i++)
	{
		cout << city2[i] << "\t";//�Ʊ������
	}
	
}