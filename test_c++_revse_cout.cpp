#include<iostream>
#include<string>
using namespace std;
int main()
{
	string word;
	cout << "������һ������" << endl;
	cin >> word;
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << endl;
	int a = 20;
	int b = 20;
	cout << a++ <<endl<< ++b << endl;//ǰ��++�ͺ���++����ʱ�䲻һ���������ͬЧ���¶��������ǰ׺��Ч��Ҫ�Ⱥ�׺�ߣ���׺�����ȼ���ǰ׺Ҫ��
	//*++p,��++��*
	//++*p����*��++
	//*p++���ȵõ�*p��Ȼ���p++
	int x = 20;
	{
		int x = 5;
		cout << x << endl;//{ }��ʹ���±�����������{����
	}
	cout << x << endl;//{ }��ʹ�þɱ���
	//Ҳ������������ķ�����ת�ַ���
	char temp;
	
	//int i=0;
	for (int j=0, i = word.size() - 1; j < i; j++, i--)//int j=0,int i = word.size() - 1  ���������ʹ���ˣ���Ϊ���������ʽ��ֻҪ��һ��int������
		//Ҳ������for(int i=0;i<word.size()/2-1;i++)  word[i]=word[size-i-1]
	{
		temp = word[j];
		word[j] = word[i];
		word[i] = temp;
	}
	cout << "�ٴη�ת" << word << endl;
	//,������
	int c ;
	c = 17, 18;
	cout << c << endl;
	c = (17, 18);
	cout << c << endl;
}