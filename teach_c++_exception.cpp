#include<iostream>
//���쳣��������н׶εĴ���
#include<csetjmp>
int fun1();
int fun2();
void fun3();
void fun4();
jmp_buf j_err;
//�׳��쳣
void fun();
using namespace std;
class A{};
class B:public A{};
//�쳣����һ��Ԥ�����ơ������н׶�����
//��׼���쳣--���ص���һ���� ����
//�Զ����쳣���Լ̳б�׼���쳣
void push(int data);
void push1(int data);
//-----
class overflow :public exception
{
	//��Ȼ����̳��˸���Ϳ�����д�麯������Ϊwhat��һ���麯��
	const char* what()const 
	{
		cout << "�Ų�ס��" << endl;
	}
};
int main()
{
	if (setjmp(j_err)==0)//j_eerĬ��Ϊ0
	{
		fun4();
	}
	//---------
	try
	{
		fun();
	}
	catch (int ex)
	{
		if (ex == -1)
		{
			cout << "�ļ���ʧ��" << endl;
		}
		return -1;
	}
	//catch..����ʹ�ö��catch�����쳣
	//ֻҪ�׳����쳣�ͱ���ץס�쳣����Ȼ�ᱨ��
	//����˳��
	try
	{
		throw B();
	}
	catch (A& ex)
	{
		cout << "A�쳣" << endl;
	}
	catch (B& ex)
	{
		cout << "B�쳣" << endl;
	}
	//���ȱ�A���񣬾ͽ�ԭ��
	//
	try
	{
		push(10);
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
	}
}

int fun1()//�ӿڲ�
{
	//��ֲ�Ժܵ�---------ֻ���ڿ���̨ʹ�� ����Qt��MFC�Ͳ���ʹ�ã���c++��Ŀ�����ƾ�����ֲ�Ժ�
	FILE *fid = fopen("out.txt", "r");
	if (fid == NULL)
	{
		printf("��%sʧ��\n", "txt_out.txt");//
		return;
	}
	//-------------
	if (fid == NULL)
	{
		return -1;//����-1�����ļ���ʧ�ܣ�������һ��Ľӿڴ����ͨ����
	}
}
int fun2()//��Ʋ�
{
	if (fun1() == -1)
	{
		//...������
		return -2;
	}
}

//fun1��fun2���е��ǲ������  ��ȱ���ǲ����࣬��Ҫ����ж�
//setjmp������һ����Ծ�㣩 longjmp��Ȼ����ת��
void fun3()
{
	FILE *fid = fopen("out.txt", "r");
	if (fid == NULL)
	{
		longjmp(j_err, -1);//����longjmp��j_err���ó�-1��Ȼ��һ����������if (setjmp(j_eer)==0)
	}
}
void fun4()
{
	fun3();
}
void fun()
{
	FILE *fid = fopen("out.txt", "r");
	if (fid == NULL)
	{
		throw - 1;//z�������Ҫ�����,�׳����쳣��ͣ����������try�Ͳ����쳣����ʹ��catch�����쳣
	}
	char* pb = (char*)malloc(0xfeeefeee);//����һ�鲻���ڵĵ�ַ
	if (!pb)
	{
		throw "�ڴ�����ʧ��";
	}
}

void push(int data)
{
	throw overflow_error("�ڴ����");
	
}
void push1(int data)
{
	throw overflow();//ʹ���Զ�������׳��쳣
}