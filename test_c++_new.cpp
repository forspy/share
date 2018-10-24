#include<iostream>
#include<new>//��λnew�����ͷ�ļ�����newָ��Ҫʹ�õ�λ��
#include<string>
using namespace std;
struct test
{
	char name[20];
	int num;
};
char buffer1[50];
char buffer2[100];
//������
class Test
{
private:
	string words;
public:
	Test(const string& s="testing")
	{
		words = s;
		cout << words << " constructed" << endl;
	}
	~Test()
	{
		cout << words << " destroyed" << endl;
	}
	void show() { cout << words << endl; }
};
int main()
{
	//new��ʼ��
	int* pi = new int(6);//��*pi��ֵ6
	/*int* p = new int[6,1];
	std::cout << p[5] << std::endl;*/
	struct where
	{
		double x;
		double y;
	};
	where* one = new where{1.0, 2.0};
	int* ar = new int[4]{ 1,2,3,4 };
	delete one;
	delete[] ar;
	//--------��λ�����
	test* p1 = new (buffer1) test;//��ȫ��������buffer1�з����ڴ���ṹtest
	int* p2 = new(buffer2) int[20];//��ȫ��������buffer2�з����ڴ��20��int����
	std::cout << (void*)buffer2 << std::endl;//��Ϊp2��������buffer2�����Ͳ�ͬ�������ת��������ַ�����������Ҫ��buffer2��(void*)���͵�ת��
	//�����õ�buffer2�ĵ�ַ����buffer2��������int���ͣ�����cout�����int���͵�ֵ
	//������delete��delete[]�ͷţ���Ϊ��λnew�����ھ�̬��

	//---------�ඨλnew����
	cout << "--------" << endl;
	char* buffer = new char[512];
	Test *pc1, *pc2;
	pc1 = new (buffer)Test;
	pc2 = new Test("hello");
	cout << "buffer address:" << (void*)buffer << endl;
	cout << "pc1 address:" << pc1;
	pc1->show();
	cout << "pc2 address:" << pc2;
	pc2->show();
	//�޸�new��λλ��
	Test* pc3 = new (buffer + sizeof(Test)) Test("hello world!!");
	cout << "pc3 address:" << pc3;
	pc3->show();
	delete pc2;
	//��Ϊ�Ƕ�λnew������ϵͳ�����Զ���������Ҫ��ʽ�ֶ�����
	//1.�ֶ�������Ҫע������˳�������Ķ�����������紴���Ķ��������Ǻ���ȳ���������ʽ��ջһ��
	//2.�����ж��󶼱������Ժ󣬲����ͷ����ڴ�����Щ����Ļ�����
	pc3->~Test();//���ú�����Ҫ������
	pc1->~Test();
	//��λnew��Ϊ�Ƕ�λ��buffer�ϣ����Բ���Ҫͨ��pc1��pc3�ͷ�
	delete[] buffer;//ֱ���ͷ�buffer����
}