#include<iostream>
const int size = 10;
int main()
{
	long arr[size];
	arr[0] = 1L;
	arr[1] = 1L;
	for (int i = 2; i < size; i++)
	{
		arr[i] = arr[i - 1] * i;
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << i << "!=" << arr[i] << std::endl;;
	}
}