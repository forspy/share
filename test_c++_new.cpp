#include<iostream>

int main()
{
	//new��ʼ��
	int* pi = new int(6);//��*pi��ֵ6
	/*int* p = new int[6,1];
	std::cout << p[5] << std::endl;*/
	struct where
	{
		double x;
		double y;
	};
	where* one = new where{1.0, 2.0};
	int* ar = new int[4]{ 1,2,3,4 };
	delete[] ar;
}