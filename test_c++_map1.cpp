#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	//map��һ��key��һ��value������������������
	
	map<int, double> mm1;
	map<string, double>mm2;//��ʾstring��Ϊkey��float��Ϊvalue 
						  //�е�������hash��
	map<int, double>::iterator m_it;//map ������
	mm1[3] = 4.0;
	mm2["xiaoming"] = 1.68;
	cout << mm1[3] <<'\t'<< mm2["xiaoming"] << endl;
	m_it=mm1.find(3);//����key=3���ڵĵ�����
	if (m_it != mm1.end())//��ʾ�ҵ���
	{
		cout << "is exit" << endl;
	}
	//Ҳ��������vector�Ĺ���
	mm2.clear();
	mm1.erase(3);//ɾ��3���key
}
