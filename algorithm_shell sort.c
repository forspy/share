#include<stdio.h>
//shell �����Ƚ��������Զ��Ԫ��,��������
void shellsort(int v[], int n);
int test(int inside);
void test2(int inside2);
void test3(int inside3[]);
int test4(int inside4[]);
int main()
{
	int k[10] = { 1,3,5,7,9,10,8,6,4,2 };
	int n = 10;
	int m, mm, mmm;
	int aa = 0;
	int bb = 0;
	int cc[3] = { 0,0,0 };
	int dd[3];
	dd[0] = 0;
	dd[1] = 0;
	dd[2] = 0;
	shellsort(k, n);
	for (m = 0; m < n; m++)
		printf("%d,", k[m]);//Ϊʲôkֵ�ᱻ�޸ģ�
	test(aa);//�Ա�˵��void�����ĺ�����ı�����������ֵ������ͨ���κ�������ı�ֵ������Ҫ��һ����֤���ǲ���������õ��ǵ�ַ�����½�һ������ֱ����ԭ����������
	printf("\n%d\n", aa);
	test2(bb);
	printf("\n%d\n", bb);//����ʵ��˵��void���������ɲ���ı�ԭ��������
	test3(cc);
	for (mm = 0; mm < 3; mm++)
		printf("%d,", cc[mm]);//���������ı�ԭ��������
	test4(dd);
	for (mmm = 0; mmm < 3; mmm++)
		printf("%d,", dd[mmm]);//int����Ҳ��ı�ԭ����ֵ (��return��:��int���롰int *���ļ�Ӽ���ͬ),˵���������ָ���ˣ�����Ĵ��ݻ�ı�ԭ�����ֵ
}

void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}
int test(int inside)
{
	inside = inside + 1;
	return inside;
 }
void test2(int inside2)
{
	inside2 = inside2 + 1;
}

void test3(int inside3[])
{
	inside3[0] = inside3[0] + 1;
	inside3[1] = inside3[1] + 2;
	inside3[2] = inside3[2] + 3;
}
int test4(int inside4[])
{
	inside4[0] = inside4[0] + 1;
	inside4[1] = inside4[1] + 2;
	inside4[2] = inside4[2] + 3;
	return inside4;
}
