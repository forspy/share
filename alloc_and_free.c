
#define ALLOCSIZE 1000   /* 可用空间大小 */

static char allocbuf[ALLOCSIZE];  /* alloc使用的存储区 */
static char *allocp;     /* 下一个空闲位置 */
char *alloc(int n);
void afree(char *p);
int main()
{
	char m[] = "hello";
	int buffer;
	buffer = (int*)alloc(m);
	afree(m);
}

char *alloc(int n)       /* 返回指向n个字符的指针 */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {   /* 有足够的空间 */
		allocp += n;
		return allocp - n;    /* 分配前的指针 */
	}
	else                 /* 空闲空间不够 */
		return 0;
}

void afree(char *p)      /* 释放p指向的存储区 */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}