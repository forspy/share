#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vector_array.h"
#define ELEM_STEP 64
void vector_def(struct vector_array* v, int size)
{
	memset(v, 0, sizeof(struct vector_array));//��ʼ��һ�¶�̬����
	v->sizeof_elem = size;
	//memset(v, 0, sizeof(struct vector_array));����Ѿ���ʾ���涼��0
	/*v->mem_data = NULL;
	v->elem_max = 0;
	v->elem_count = 0;*/
}

void vector_clear(struct vector_array* v)
{
	if (v->mem_data)
	{
		free(v->mem_data);//�ͷŵ�men_data��ָ��Ķ��ڴ�
		v->mem_data = NULL;//���³�ʼ��mem_data��ָ��
		v->elem_max = 0;
		v->elem_count = 0;
		v->sizeof_elem = 0;
	}
}
//ѹ��һ��ֵ
void vector_push(struct vector_array* v, const int* ele_ptr)//����const int* ele_ptrָ���Ǹ�ָ�벻���޸�ѹ���int���͵�ֵ
{
	//�����жϵ�ǰλ���Ƿ񳬹����λ��
	if (v->elem_count >= v->elem_max)//�������������
	{
		v->elem_max += ELEM_STEP;
		v->mem_data = realloc(v->mem_data, v->elem_max*v->sizeof_elem);//���ݵ� ������*ÿ����С
	}
	memcpy(v->mem_data + v->elem_count, ele_ptr, v->sizeof_elem);
	v->elem_count++;
}
//��ȡ��i�������ڴ��ַ��int���ͣ��ӵ�0������ʼ
void* vector_at(struct vector_array* v, int i)//����ע��void* ���Է���void*ָ�룬��void���ͺ������ܷ���ֵ������void*�������ǵ�������Ըĳ�int*
//��Ӧ��returnֵҲȥ����void*����Ϊint*
{
	if (i<0 || i>v->elem_max)
		return NULL;
	return (void*)(v->mem_data + i);
}
//��ȡ�������ڴ���׵�ַ
int* vector_begin(struct vector_array* v)
{
	return v->mem_data;
}

//�����������������Ԫ�أ����ǻ�Ҫ����ʹ��(��ʵ�൱�ڸ���д�룬���ܲ���ȫ)
void vector_popall(struct vector_array* v)
{
	v->elem_count = 0;
}
//ɾ��һ��Ԫ��
void vector_erase(struct vector_array* v, int start, int count)
{
	//�ж�start�Ϸ���
	if (start < 0 || start >= v->elem_count)
		return;
	//�ж�count�Ϸ���
	if (start + count > v->elem_count)
		count = v->elem_count - start;
	memmove(v->mem_data + start, v->mem_data + start + count, v->elem_count - start - count);
	v->elem_count -= count;
}
//�������һ��ֵ
void vector_popback(struct vector_array* v, int* out_of_elem)
{
	if (v->elem_count <= 0)
		return;
	v->elem_count--;
	*out_of_elem = *(v->mem_data+ v->elem_count);
	//Ҳ����ʹ��memcpy
	//memcpy(out_of_elem, v->mem_data + v->elem_count, v->sizeof_elem);
}