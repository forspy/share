#include<iostream>
using namespace std;
char *getname(void);
void strcpy(char* s, char* t);
int main()
{
	char *p1;
	char name[20] = "hello";
	//p1 = NULL;������ָ���
	p1 = name;
	cout << "p1= " << p1 << endl;//���:"hello"
	//char *p2 = getname();
	
	//cout << "p2= " << *(p2+1) << endl;//���:"e",������filename��������Ѿ����ͷ��ˣ�Ϊʲô���ܶ�������ָ�������
	char *p2 = getname();
	cout << p2 << endl;
	delete[] p2;
}

char *getname(void)
{
	char filename[20] = "hello";
	//return filename;
	//�����ʹ���Ӻ�����ı�������Ҫ����һ�����ϵ��ڴ�
	char *ptr = new char[strlen(filename)+1];//����Ҫ����̬����ָ������
	strcpy(ptr, filename);//Ҫ�ڶ��Ͻ���һ������������ֿ�����ӦΪջ�ϵ�����ᱻ�ͷţ����Ա��뿽��ԭ����ֻ��ָ��û��
	//ptr = filename;
	return ptr;
}

//strcpyԭ��
void strcpy(char* s, char* t)
{
	while ((*s = *t) != '\0')//�Ƚ�*t��ֵ����*sȻ���ж��ǲ���='\0'
	{
		s++;
		t++;
	}
}