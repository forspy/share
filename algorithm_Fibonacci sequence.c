#include <stdio.h>
//ì³²¨ÄÇÆõÊıÁĞ
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
//µİ¹é
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