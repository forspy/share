#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vector_array.h"

int main()
{
	struct vector_array array;
	//���������̬���������
	vector_def(&array, sizeof(int));//����array����Ϊint����
	
	//����̬�����ϴ��Ԫ��
	int value = 4;
	vector_push(&array,&value);
	value = 8;
	vector_push(&array, &value);
	value = 16;
	vector_push(&array, &value);
	//��ȡ��i�������ڴ��ַ��int���ͣ��ӵ�0������ʼ
	int* ptr=NULL;
	ptr = vector_at(&array, 0);
	printf("%d\n", *ptr);
	ptr = vector_at(&array, 1);
	printf("%d\n", *ptr);
	ptr = vector_at(&array, 2);
	printf("%d\n", *ptr);
	//��ȡ�������ڴ���׵�ַ
	int* p=NULL;
	p = vector_begin(&array);
	for (int i = 0; i < array.elem_count; i++)
		printf("%d\n", p[i]);
	//����ĳ��Ԫ��
	vector_erase(&array, 2, 1);//�ӵ�2��Ԫ�ؿ�ʼ����һ��
	printf("-----------\n");
	for (int i = 0; i < array.elem_count; i++)
		printf("%d\n", p[i]);
	printf("-----------\n");
	int last;
	vector_popback(&array, &last);
	printf("%d\n", last);

	//��������Ԫ��
	vector_popall(&array);//��ʵû�е�����ֻ�ǲ���ʾ��
	printf("-----------\n");
	for (int i = 0; i < 3; i++)
		printf("%d\n", p[i]);

	//---------------------------------------------
	//�ͷŶ��ϵĶ�̬�ڴ�,������
	vector_clear(&array);

}