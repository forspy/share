
#define ALLOCSIZE 1000   /* ���ÿռ��С */

static char allocbuf[ALLOCSIZE];  /* allocʹ�õĴ洢�� */
static char *allocp;     /* ��һ������λ�� */
char *alloc(int n);
void afree(char *p);
int main()
{
	char m[] = "hello";
	int buffer;
	buffer = (int*)alloc(m);
	afree(m);
}

char *alloc(int n)       /* ����ָ��n���ַ���ָ�� */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {   /* ���㹻�Ŀռ� */
		allocp += n;
		return allocp - n;    /* ����ǰ��ָ�� */
	}
	else                 /* ���пռ䲻�� */
		return 0;
}

void afree(char *p)      /* �ͷ�pָ��Ĵ洢�� */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}