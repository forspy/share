#include<stdio.h>

int binsearch(int x, int month[], int n);//判定已排序数组中的某个特定值
//测试（1+2）/2=1,舍去小数位
int main()
{
	int m[12];
	int i;
	int x, n,val;
	printf("请输入要查询的值 x\n");
	scanf_s("%d", &x);
	printf("请输入一共几个月份 n\n");
	scanf_s("%d", &n);
	for (i = 0; i <= 11; ++i)
	{
		m[i] = i+1 ;
	}
	val = binsearch(x, m, n);
	printf("找到了第%d个，匹配值为%d\n", val+1, m[val]);
	printf("(1+2)/2=%d\n", (1 + 2) / 2);//测试
}

int binsearch(int x, int month[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < month[mid])
		{
			high = mid - 1;
		}
		else if (x > month[mid])
		{
			low = mid + 1;
		}
		else
			
			return mid;
	}
}