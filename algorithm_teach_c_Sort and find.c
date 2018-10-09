#include<stdio.h>

/*
函数名：find
功能：从数组中查找一个需要的数据
参数：arr是数组元素,size是数组大小，data是要查找的元素
*/
//交换
void swap(int* v, int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
//遍历查找
int find(int arr[], int size, int data)
{
	int i = 0;
	for (; i < size; i++)
	{
		if (data == arr[i])
			return i;
	}
	return -1;
}
//二分查找要求数据有序
//时间复查度看最大循环次数
//假设从小到大
int half_find(int arr[], int size, int data)
{
	int left = 0;
	int right = size - 1;


	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == data)
			return mid;//返回位置
		else if (arr[mid] > data)
			right = mid - 1;
		else if (arr[mid] < data)
			left = mid + 1;
	}
	return -1;//没有找到
}
//冒泡算法（升序）时间复杂度为O(n^2）需要遍历n次一次n秒所以为n^2
// 开始 ：1 0 3 5 9 2 4
//第一次：0 1 3 5 2 4 9 先排完最大的
//第二次：0 1 3 2 4 5 9 再排完次大的
void buble_sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)//外层只表示遍历次数
	{
		for (int j = 0; j < size - 1 - i; j++)//内层始终从数组下标0开始
		{
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}
}

//快速排序(升序) 时间复杂度为O(nlog2n),最糟情况O（n^2）即每次都换到一边另一边没有元素就需要n次了
void qsort(int* v, int left, int right)
{
	int i, last,mid;
	if (left > right)//两个要排，一个就不用排了
		return;
	mid = (left + right) / 2;
	swap(v, left, mid);//先把中间和left的换一下
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if (v[i] < v[left])
		{
			last++;
			swap(v, last, i);//last指向要大于中间值的那些数，让他们和小于中间值的数交换位置
		}
	}
	swap(v, left, last);//换回来
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

//选择排序
//  原始：1 8 3 5 9 6 0 4
//第一次: 0 8 3 5 9 6 1 4  先找到最小的和第一个交换
//第二次: 0 1 3 5 9 6 8 4 再找到次小的和第二个交换

void selectsort(int* arr, int size)
{
	int min;
	int temp;
	for (int i = 0; i < size ; i++)
	{
		min = i;//注意每次min都要先等于要排序数组的第一个元素
		for (int j = i; j <size ; j++)//注意j要取到数组的最后一个值就需要j<size
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
//插入排序(升序)
//  原始：1 10 3 5 9 6 0 4
//第一次：1 10 3 5 9 6 0 4 先把前两个个排啊
//第二次：1 3 10 5 9 6 0 4 再把前三个排好
//第三次：1 3 5 10 9 6 0 4
void insertsort(int* arr, int size)
{
	int temp;
	for (int i = 1; i < size ; i++)
	{
		temp = arr[i];//先保存要插入的数据
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (temp < arr[j])
				arr[j + 1] = arr[j];//往后移动一位
			else
				break;
		}
		arr[j + 1] = temp;
	}
}
int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("从0开始第%d个\n", find(a, 10, 6));
	printf("从0开始第%d个\n", half_find(a, 10, 9));
	int arr[10] = { 1,4,5,2,35,7,2434,12,9,6};
	//selectsort(arr, 10);//选择排序
	//buble_sort(arr, 10);//冒泡排序
	//insertsort(arr, 10);//插入排序
	qsort(arr, 0, 9);//快速排序
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}