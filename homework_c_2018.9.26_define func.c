#include<stdio.h>
#define swap(x,y,temp) temp=x;x=y;y=temp//������ʱ��������
#define swap1(x,y) x=x^y;y=y^x;x=x^y//λ���㽻��
#define swap2(x,y) x=x-y;y=y+x;x=y-x//����x��y֮��Ĳ�ֵ
int main()
{
	int temp;
	int x=1;
	int y=2;
	swap(x, y,temp);
	printf("x=%d y=%d\n", x, y);
	swap1(x, y);
	printf("x=%d y=%d\n", x, y);
	swap2(x, y);
	printf("x=%d y=%d\n", x, y);
}