// Win32Project4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

int main()
{
	int m=1;
	float n=3.2,k;
	int i, j;
	k = m + n;
	for (i = j = 0; i <= 10; i++)//i=j=0�൱��i=0,j=0;�Ҳ����ظ���i��j��ֵ
	{
       printf("%d, %d\n", i, j);
	}
	printf("%f", k);
		
    return 0;
}

//���ͣ����������ʽ
//int 32λ 4�ֽ�
//float �����ȸ����� 4�ֽ�
//double ˫���ȸ����� 8�ֽ�
//short int ������ 16
//long int ������ ��12345L
//����һЩС����
//��׼�⺯��strlen(s) �����ַ�������s�ĳ��ȣ�ͷ�ļ�<string.h>��
//enum ������{С����1��С����2...}û��ָ����������ɣ�С����1��ֵҪָ����
//const ���� ����;const���εı���ֵ���ܸı�
//������0��Ϊ0����0��Ϊ1 �磺if(!valid)
//char����ʵ�ǽ�С���������ASCII�ַ�������Ӽ� ��c+'a'-'A'����ʵ�ִ�дת����Сд ��tolower()����<cytpe.h>
//unsigned�޷��ű���signed���ű���
//long+double=double int+float=float
//һЩ�������Զ�������ת�����ͣ���sqrt(double),α�������rand
//����/�Լ��������s[j++]=1;-->s[j]=1;j++;
//��ֵ����i=i+2;-->i+=2;x*=y+1;-->x=x*(y+1);
//�������ʽ z=(a>b)?a:b;