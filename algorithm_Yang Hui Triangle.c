#include <stdio.h>

int Yang_Hui_Triangle(int m,int n);//杨辉三角

int main()
{
	int arr[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i + 1; j++)
			arr[i][j] = Yang_Hui_Triangle(i, j);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i + 1; j++)
			printf("%d ", arr[i][j]);//第3行第2列
		printf("\n");
	}
	

}

int Yang_Hui_Triangle(int m,int n)//第m+1行n+1列
{
	int a;
	int maxcount = m + 1;
	if (m < 2 || (m >= 2 && n == 0) || n == (maxcount - 1))
	{
		a = 1;
		return a;
	}
	else
	{
		a = Yang_Hui_Triangle(m - 1, n - 1) + Yang_Hui_Triangle(m - 1, n);
		return a;
	}
}