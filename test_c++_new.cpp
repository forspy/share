#include<iostream>
#include<new>//��λnew�����ͷ�ļ�����newָ��Ҫʹ�õ�λ��
struct test
{
	char name[20];
	int num;
};
char buffer1[50];
char buffer2[100];
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
	delete[] ar;
	//--------��λ�����
	test* p1 = new (buffer1) test;//��ȫ��������buffer1�з����ڴ���ṹtest
	int* p2 = new(buffer2) int[20];//��ȫ��������buffer2�з����ڴ��20��int����
	std::cout << (void*)buffer2 << std::endl;//��Ϊp2��������buffer2�����Ͳ�ͬ�������ת��������ַ�����������Ҫ��buffer2��(void*)���͵�ת��
	//�����õ�buffer2�ĵ�ַ����buffer2��������int���ͣ�����cout�����int���͵�ֵ
	//������delete��delete[]�ͷţ���Ϊ��λnew�����ھ�̬��
}