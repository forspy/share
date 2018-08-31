#pragma once
struct vector_array
{
	int* mem_data;
	int elem_max;//������
	int elem_count;//��ǰλ��
	int sizeof_elem;//ÿ��Ԫ�ش�С
};

void  vector_def(struct vector_array* v, int size);//���������̬���������

void vector_clear(struct vector_array* v);//�ͷ������̬�ڴ�

void vector_push(struct vector_array* v, const int* ele_ptr);//ѹ��һ��ֵ

void* vector_at(struct vector_array* v, int i);//��ȡ��i�������ڴ��ַ��int���ͣ�

int* vector_begin(struct vector_array* v);//��ȡ�������ڴ���׵�ַ

//#define vector_size(v) ((v)->elem_count)Ҳ����дһ���ӿڱ�ʾ��ǰ�Ѿ�����ĸ���

//�����������������Ԫ�أ����ǻ�Ҫ����ʹ��
void vector_popall(struct vector_array* v);

//��start��ʼɾ��i��Ԫ��
void vector_erase(struct vector_array* v, int start, int i);
//�������һ��ֵ
void vector_popback(struct vector_array* v, int* out_of_elem);