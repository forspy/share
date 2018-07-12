#include<stdio.h>
//shell 排序先交换距离较远的元素,递增排序
void shellsort(int v[], int n);
int test(int inside);
void test2(int inside2);
void test3(int inside3[]);
int test4(int inside4[]);
int main()
{
	int k[10] = { 1,3,5,7,9,10,8,6,4,2 };
	int n = 10;
	int m, mm, mmm;
	int aa = 0;
	int bb = 0;
	int cc[3] = { 0,0,0 };
	int dd[3];
	dd[0] = 0;
	dd[1] = 0;
	dd[2] = 0;
	shellsort(k, n);
	for (m = 0; m < n; m++)
		printf("%d,", k[m]);//为什么k值会被修改？
	test(aa);//对比说明void声明的函数会改变主函数参数值，而普通传参函数不会改变值（还需要进一步验证，是不是数组调用的是地址，不新建一个数组直接在原数组上排序）
	printf("\n%d\n", aa);
	test2(bb);
	printf("\n%d\n", bb);//该组实验说明void声明后依旧不会改变原参数变量
	test3(cc);
	for (mm = 0; mm < 3; mm++)
		printf("%d,", cc[mm]);//发现数组会改变原参数变量
	test4(dd);
	for (mmm = 0; mmm < 3; mmm++)
		printf("%d,", dd[mmm]);//int声明也会改变原参数值 (“return”:“int”与“int *”的间接级别不同),说明数组存在指针了，数组的传递会改变原数组的值
	//所以当被调函数在函数体中修改数组元素时，真正修改的是存储在原存储单元中的数组元素。
	//当遇到某些情况函数中禁止修改数组元素值时，可使用const类型限定符防止被调函数修改数组元素如下：void printArray(const int b[], int size);
}

void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}
int test(int inside)
{
	inside = inside + 1;
	return inside;
 }
void test2(int inside2)
{
	inside2 = inside2 + 1;
}

void test3(int inside3[])
{
	inside3[0] = inside3[0] + 1;
	inside3[1] = inside3[1] + 2;
	inside3[2] = inside3[2] + 3;
}
int test4(int inside4[])
{
	inside4[0] = inside4[0] + 1;
	inside4[1] = inside4[1] + 2;
	inside4[2] = inside4[2] + 3;
	return inside4;
}
