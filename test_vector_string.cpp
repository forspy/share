#include<iostream>
#include<cstring>
#include<vector>

int main()
{
	using namespace std;
	//int myvector[8];
    //vector<int> vec;
	vector <int> aa(5, 10);
	for (int i = 0; i < 5; i++)
		//printf("%d", aa[i]);
	cout << aa[i] << endl;;
	
	//c++���д��
	//cout << "v2 =";
	//for (auto& v : v2) {
	//	cout << " " << v;
	//}
	//ps����f1�鿴����
	char s[2] = "s";//ʵ���ϻ���'\0'
	const int SIZE = 15;
	char name1[SIZE];
	char name2[SIZE] = "C++ boy";
	cout << "�������ַ�����" << endl;
	cin >> name1;
	name2[3] = '\0';//�Ե��ĸ��ַ����¸���
	cout<<name1<<"һ����"<<strlen(name1)<<"���ַ�"<< endl;
	cout <<name2 << endl;
}
