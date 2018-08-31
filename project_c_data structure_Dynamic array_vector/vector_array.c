#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vector_array.h"
#define ELEM_STEP 64
void vector_def(struct vector_array* v, int size)
{
	memset(v, 0, sizeof(struct vector_array));//初始化一下动态数组
	v->sizeof_elem = size;
	//memset(v, 0, sizeof(struct vector_array));这个已经表示下面都是0
	/*v->mem_data = NULL;
	v->elem_max = 0;
	v->elem_count = 0;*/
}

void vector_clear(struct vector_array* v)
{
	if (v->mem_data)
	{
		free(v->mem_data);//释放掉men_data所指向的堆内存
		v->mem_data = NULL;//重新初始化mem_data的指向
		v->elem_max = 0;
		v->elem_count = 0;
		v->sizeof_elem = 0;
	}
}
//压入一个值
void vector_push(struct vector_array* v, const int* ele_ptr)//这里const int* ele_ptr指的是该指针不会修改压入的int类型的值
{
	//首相判断当前位置是否超过最大位置
	if (v->elem_count >= v->elem_max)//如果超过则扩容
	{
		v->elem_max += ELEM_STEP;
		v->mem_data = realloc(v->mem_data, v->elem_max*v->sizeof_elem);//扩容到 最大个数*每个大小
	}
	memcpy(v->mem_data + v->elem_count, ele_ptr, v->sizeof_elem);
	v->elem_count++;
}
//获取第i个数的内存地址（int类型）从第0个数开始
void* vector_at(struct vector_array* v, int i)//这里注意void* 可以返回void*指针，但void类型函数不能返回值，这里void*根据我们的输入可以改成int*
//对应的return值也去掉（void*）成为int*
{
	if (i<0 || i>v->elem_max)
		return NULL;
	return (void*)(v->mem_data + i);
}
//获取数组存放内存的首地址
int* vector_begin(struct vector_array* v)
{
	return v->mem_data;
}

//清理掉这个数组的所有元素，但是还要继续使用(其实相当于覆盖写入，功能不完全)
void vector_popall(struct vector_array* v)
{
	v->elem_count = 0;
}
//删除一个元素
void vector_erase(struct vector_array* v, int start, int count)
{
	//判断start合法性
	if (start < 0 || start >= v->elem_count)
		return;
	//判断count合法性
	if (start + count > v->elem_count)
		count = v->elem_count - start;
	memmove(v->mem_data + start, v->mem_data + start + count, v->elem_count - start - count);
	v->elem_count -= count;
}
//弹出最后一个值
void vector_popback(struct vector_array* v, int* out_of_elem)
{
	if (v->elem_count <= 0)
		return;
	v->elem_count--;
	*out_of_elem = *(v->mem_data+ v->elem_count);
	//也可以使用memcpy
	//memcpy(out_of_elem, v->mem_data + v->elem_count, v->sizeof_elem);
}