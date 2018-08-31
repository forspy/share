#pragma once
struct vector_array
{
	int* mem_data;
	int elem_max;//最大个数
	int elem_count;//当前位置
	int sizeof_elem;//每个元素大小
};

void  vector_def(struct vector_array* v, int size);//定义这个动态数组的类型

void vector_clear(struct vector_array* v);//释放这个动态内存

void vector_push(struct vector_array* v, const int* ele_ptr);//压入一个值

void* vector_at(struct vector_array* v, int i);//获取第i个数的内存地址（int类型）

int* vector_begin(struct vector_array* v);//获取数组存放内存的首地址

//#define vector_size(v) ((v)->elem_count)也可以写一个接口表示当前已经储存的个数

//清理掉这个数组的所有元素，但是还要继续使用
void vector_popall(struct vector_array* v);

//从start开始删除i个元素
void vector_erase(struct vector_array* v, int start, int i);
//弹出最后一个值
void vector_popback(struct vector_array* v, int* out_of_elem);