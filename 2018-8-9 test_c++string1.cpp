#include<iostream>
#include<string>//make string class available,ʹ��c++��׼���е�string��
using namespace std;
const int SIZE = 20;
int main()
{
	char name[SIZE], name1[SIZE], name2[SIZE], name3[SIZE];
	string str1;//��������һ������Ϊ0��string����,str1��һ������
	cout << "please enter a string!" << endl;
	cin >> str1;
	string str2 = "hello!";//string����Բ���������ĳ���
	cout << str1 << str2 [0]<< endl;
	string str3;
	str3 = str1 + str2;//string�����ַ����ĺϲ�����
	cout << str3 << endl;
	cout << "please enter your name" << endl;
	cin >> name;//cin�������ո�ʱ���ж�һ���������
	cout << "please enter your name again!" << endl;
	cin >> name1;
	cout << name<<name1 << endl;
	cin.get();//ΪʲôҪ����һ�䣬��Ϊcin��ȡ�ַ�����ʱ�򣬽��س������ɵĻ��з��������������֮�С�
	//�����cin.getline()�������з��󣬽���Ϊ����һ�����У��������ַ���ֵ����һ�����顣
	//��������cin.get()����ס����س�����
	cout << "test 2��" << endl;
	cout << "please enter your name" << endl;
	cin.getline(name2, 20);//�ڵ��������е�����ʱǰ�治����
	cout << "please enter your name again!" << endl;
	cin.getline(name3, 20);
	cout << name2 << name3 << endl;
	return 0;
}