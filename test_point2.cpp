#include<iostream>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	using namespace std;
	int a = 6;
	int b = 5;
	int *c, *d;//ÿ����Ҫ����*
	//��ʹ��ָ��֮ǰһ��Ҫ��ʼ��
	c = (int*)0x8000000;//c++Ҫ����ָ�븳ֵʱ�Գ�������ǿ�����͵�ת��
	cout << &a << endl;
	cout << &b << endl;
	int *p = new int;//ָ��p��һ��ջ��stack���ڴ棬pָ����ڴ���һ���ѣ�heap���ڴ�
	*p = 10086;
	cout << *p << endl;
	delete p;//1.�ͷ�new������ڴ�2.������ɾ��ָ�����p 3.���Խ�p����ָ��һ���µ��ڴ��4.���ܽ�delete�����ͷ���ͨ������ָ��
	int num=3;
	int *ptr = new int[num];//��̬����
	ptr[0] = 1;
	ptr[1] = 2;
	ptr[2] = 3;
	//cout << ptr << endl;
	//ptr[3] = 4;//�����鳬����̬����Ľ��ޣ��ᵼ���ڴ�������ͷŲ���
	//cout << ptr << endl;
	cout << ptr[2] << endl;//����Ԥ��������new���Զ�����2.����ָ�뵽���ĸ��������ֵ�ȼ���ptr[4]
	//ptr -= 2;
	delete []ptr;//�ͷ��ڴ�ע���[]
	//��̬����Ķ�̬������������Ĵ�С�������ñ���ָ��,��������ʱָ��������Ĵ�С֮����Ч���ͺ�һ������һ����ʹ���궯̬����֮��������Ҫʹ��delete []�ͷ�
	//��Ȼ�����ڴ�й©��ָ�����ظ��ڴ�ռ��
	short tell[20] = { 1,2,3 };
	short(*pas)[20] = &tell;//ָ��20��Ԫ�ص�ָ�룬ָ����ָ����������
	cout << (*pas)[1] << endl;//(*pas)��tell�ȼۣ�ע������
	short *p1 = &tell[0];
	short *p2 = &tell[2];
	cout << "ָ��ͬһ���������ָ��ļ��Ϊ" << p2 - p1 << endl;
	//ʹ��[]�ȼ��ڶ�ָ��Ľ������
	//c��������һ��relloc�������������Ѿ����õ�malloc�����ı߽�
	int *pp1 = (int*)malloc(100*sizeof(int));
	int *pp2 = (int*)realloc(pp1, 200 * sizeof(int));//ʹ��realloc�������ͷ���һ��malloc�����Ķ��ڴ棬���Բ���Ҫfree��pp1�������һ��ʼʲô��û���ο��ȴ�һ��NULL
	//free(pp1);
	free(pp2);
	//һ�����̽����Ժ�����ʹ�õ������ڴ���Դ���ᱻOS����
	//c����memmove(ptr,ptr2,90) memcopy(ptr,ptr2,�ֽ���)  �ڴ濽��
#if 0//��������
	ssss
#endif
	
}