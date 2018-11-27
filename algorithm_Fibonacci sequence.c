#include <stdio.h>
//ì³²¨ÄÇÆõÊýÁÐ
int Fibonacci_sequence(n);
int main()
{
	int arr[30] = { 0 };
	for (int i = 0; i < 30; i++)
	{
		arr[i] = Fibonacci_sequence(i);
	}
	for (int i = 0; i < 30; i++)
	{
		printf(" %d", arr[i]);
	}
	

}
//µÝ¹é
int Fibonacci_sequence(n)
{
	
	int a;
	if (n < 2)
	{
		a = 1;
		return a;
	}
	else
	{
		a = Fibonacci_sequence(n - 1) + Fibonacci_sequence(n - 2);
		return a;
	}
}
/*递归：
有人送了我金、银、铜、铁、木五个宝箱，我想打开金箱子，却没有打开这个箱子的钥匙。
在金箱子上面写着一句话：“打开我的钥匙装在银箱子里。”
于是我来到银箱子前，发现还是没有打开银箱子的钥匙。
银箱子上也写着一句话：“打开我的钥匙装在铜箱子里。”
于是我再来到铜箱子前，发现还是没有打开铜箱子的钥匙。
铜箱子上也写着一句话：“打开我的钥匙装在铁箱子里。”
于是我又来到了铁箱子前，发现还是没有打开铁箱子的钥匙。
铁箱子上也写着一句话：“打开我的钥匙装在木箱子里。”
*/
