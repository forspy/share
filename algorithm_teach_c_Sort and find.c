#include<stdio.h>

/*
函数名：find
功能：从数组中查找一个需要的数据
参数：arr是数组元素,size是数组大小，data是要查找的元素
*/
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
int half_find(int arr[],int size,int data)
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
//冒泡算法（升序）
// 开始 ：1 0 3 5 9 2 4
//第一次：0 1 3 5 2 4 9 先排完最大的
//第二次：0 1 3 2 4 5 9 再排完次大的
void buble_sort(int arr[], int size)
{
	//
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
			

	}
}
//选择排序
//  原始：1 10 3 5 9 6 0 4
//第一次：10 1 3 5 9 6 0 4  先找到最大的和第一个交换
//第二次：10 9 3 5 1 6 0 4  再找到次大的和第二个交换
//第三次：10 9 6 5 1 3 0 4
//第四次：10 9 6 5 3 1 0 4
//第五次：10 9 6 5 4 1 0 3
//第六次：10 9 6 5 4 3 0 1
//第七次：10 9 6 5 4 3 1 0

void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
//快速排序
void qsort(int v[], int left, int right)
{
	int i, last;
	if (left > right)//两个要排，一个就不用排了
		return;
	swap(v, left, (left + right) / 2);//先把中间和left的换一下
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if (v[i]< v[left])
			swap(v, ++last, i);
	}
	swap(v, left, last);//换回来
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}
//选择排序
void selectsort(int arr[], int size)
{
	int min = 0;
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i; j < size - 1; j++)
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
void insertsort(int arr[], int size)
{
	int temp;
	for (int i = 1; i < size - 1; i++)
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
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("从0开始第%d个\n",find(arr, 10, 6));
	printf("从0开始第%d个\n", half_find(arr, 10, 9));
	int arr1[10] = { 1,4,5,2,35,7,2434,12,9,6 };
	//buble_sort(arr1, 10);
	//insertsort(arr1, 10);
	qsort(arr1, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
}