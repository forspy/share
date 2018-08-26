#include <stdio.h>

int main()
{
	for (int j = 5; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
			printf("*");
		printf("\n");
	}

	for (int j = 5; j > 0; j--)
	{
		for (int k = j; k < 5; k++)
		{
			printf(" ");
		}
		for (int i = 0; i < j; i++)
		{
			printf("* ");
		}
	printf("\n");
	}

	for (int yuan_10 = 0; yuan_10 <= 10; yuan_10++)
	{
		for (int yuan_5 = 0; yuan_5 <= ((100 - 10 * yuan_10) / 5); yuan_5++)
			printf("组成100元需要%d张十元%d张5元%d张1元\n", yuan_10, yuan_5, 100 - 10 * yuan_10 - 5 * yuan_5);
	}
}