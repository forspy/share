#include <iostream>
#include<string>
using namespace std;
string getname(void);
char *getname1();
int main()
{

	//c����memmove(ptr,ptr2,90) memcopy(ptr,ptr2,�ֽ���)  �ڴ濽��
	cout << "hello" << endl;//ʵ����cout�ܽ�סһ��char��������׵�ַchar str[5]="hello"
	char food[6] = "good";
	char food1[12] = "hiiiiiiiii";
	strcpy(food1, food);//strcpy�Ḳ�ǵ�food�е��ַ�����Ϊfood1���ٵ��ڴ��㹻�����Ǽ�����food1���ڴ濪�ٲ��㣬��ʹ��strcpy��ʱ��Ҳ�����¿���
	//��֮strcpyȡ����food��ֵ����food1���ڴ��޹أ�food����ô����strcpy֮��food1������ô���ġ�
	cout << food1 << endl;
	strcat(food1, food);//strcat���ں�������ַ���
	cout << food1 << endl;
	//����һ���ṹ
	struct things
	{
		string name;
		int good;
		int bad;
	};
	things grubnose = { "things",3,4 };
	things *pt = &grubnose;
	cout << grubnose.good << pt->bad << (*pt).good << endl;//����ʹ�ýṹ���ڳ�Աֵ������
	things *ptr = new things;//����һ���ṹ��ռ䲢ָ����
	cout << "name" << endl;
	cin >> ptr->name;
	cout << ptr->name << endl;
	cout << (int*)ptr << endl; //(int*)ptr���Է���ָ��ָ��ĵ�ַ
	delete ptr;//ע���ͷ��ڴ�
			   //string����ʵ�����õ�new��delete������string���ַ������ǿ����ڶ��е�

	string nn;
	nn = getname();//ָ���ָ�뺯��
	cout << nn << endl;
	char *p;
	p = getname1();//�����ĵ��ú�Σ�գ��������ڶ��Ͽ����ڴ棬�������ò��ԣ���Ϊ����������ջ�Ͽ��ٵ��ڴ��ں�������֮��ᱻ�ͷ�

	cout << "filename=" << p[1] << endl;//
	char m[20] = "hello";
	char *pp = m;
	cout << m << pp << endl;
}

string getname()
{
	string temp;//temp�Ѿ���һ��ָ��������
	cout << "getname" << endl;
	cin >> temp;
	return temp;
}
char *getname1()
{
	char filename[20] = "world";
	//cout << "filename" << endl;
	//cin >> filename;
	return filename;
}