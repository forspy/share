#include<stdio.h>
//˵��������v��Ԫ�ر�������������
//ԭ���۰����ʱ�����xС���м�Ԫ�ص�ֵ�����ڸ������ǰ�벿�ֲ��ң������ڸ�����ĺ�벿�ֲ��ҡ�������ȥֱ��
//�ҵ�ָ����ֵ���߲��ҷ�ΧΪ��

//��κ����Ĺ��ܲ���ָ�����·ݣ������������ַ�����
int binsearch(int x, int month[], int n);//�ж������������е�ĳ���ض�ֵ
										 //���ԣ�1+2��/2=1,��ȥС��λ
int main()
{
	int m[12];
	int i;
	int x, n, val;
	printf("������Ҫ��ѯ��ֵ x\n");
	scanf_s("%d", &x);
	printf("������һ�������·� n\n");
	scanf_s("%d", &n);
	for (i = 0; i <= 11; ++i)
	{
		m[i] = i + 1;
	}
	val = binsearch(x, m, n);//n=12
	printf("�ҵ��˵�%d����ƥ��ֵΪ%d\n", val + 1, m[val]);
	printf("(1+2)/2=%d\n", (1 + 2) / 2);//����
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