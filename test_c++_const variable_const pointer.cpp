#include<iostream>

int main()
{
	const int a = 1;
	const int* p = &a;
	//������int*���͵�ָ��ȥָ��const int���͵�ֵ����Ϊa�ǲ��ܱ��޸ĵģ�������ͨ��ָ���޸ģ����Բ�����ì��
	//ͬ��
	const int months[12] = { 1,2,3 };
	const int* ptr = months;
	//����months����Ҳ�ǲ��ܱ��޸ĵģ����Բ�����int* ���͵�ָ��ȥָ��

	int b = 1;
	int* const pointer = &b;
	//pointer = &a;int* const�������޸�ָ��
	*pointer = 2;//����������ָ���޸�b��ֵ

}