#include <stdio.h>
struct point
{
	int x;
	int y;
};
struct point origin, *pp;
//struct point *pp = &origin;//����������ʼ������
//int a;
//int *p;//һ��ָ��Ҳ��������ȫ�ֱ������ʼ��
//p = &a;
struct point makepoint(int x, int y);
main()
{
    pp = &origin;//ָ��ppָ��origin�ṹ,�ṹ��ָ�벻����ȫ�ֱ������ʼ��
	origin = makepoint(3, 4);
	printf("1 origin is (%d,%d)\n", (*pp).x, (*pp).y);
	printf("2 origin is (%d,%d)\n", pp->x, pp->y);
}

struct point makepoint(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}