#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include"jigsaw puzzle.h"
/*
1 2 3
4 5 6
7 8 0
*/
int pic[3][3];
/*
= {
	{1,2,3},
	{4,5,6},
	{7,8,0},
};
*/

IMAGE img[9];

void init()
{
	//�������������
	srand((unsigned int)time(NULL));
	//0 1 2 3 4 5 6 7 8��ʾ9��ͼƬ������0��ʾ�հ�ͼƬ��
	/*
	Ҫ�����9��ͼƬ��ֵ ���Ҳ����ظ�
	ʵ�ַ�����
	0.����һ��һλ����a[9]={0��1��2��3��4��5��6��7��8};
	1.���һ���±�b
	2.�ó���ֵ��ʹ��memmove
	*/ 
	int a[9] = { 0,1,2,3,4,5,6,7,8 };
	int n;//ȥһ��������±�
	int len=9;//����±�ķ�Χ
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			n = rand() % len;
			pic[i][j]=a[n];
			memmove(a + n, a + n + 1, (9 - n) * sizeof(int));
			/*����Ҳ��ʵ��memove�Ĺ���
			for(int k=n;k<len;k++)
			a[k]=a[k+1];
			*/
			len--;
		}
	}
	/*�������������
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", pic[i][j]);
		}
	}
	*/
	//����ͼƬ
	loadpicture();
}
//����ͼƬ
void loadpicture()
{
	TCHAR path[50] ;//·��������ΪeasyXֻ֧�ֶ��ֽ�
	for (int i = 0; i < 9; i++)
	{
		memset(path, 0, sizeof(path));//ÿ��ѭ����path��ʼ��
		_stprintf_s(path, L"./source/images/%d.jpg", i);//��ʽ�����룬��������iת��ΪTchar����
		loadimage(&img[i], path, SIZE, SIZE);//����ͼƬ��������ÿ��ͼƬ�Ĵ�СΪ100*100
	}
}

//��ͼ
void drawpicture()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//���pic[0][0]=3���Ͱ�3.jpg����0��0λ��
			/*easyx��putimage�Ǻ�windowsϵͳ�ϵ������෴�Ĵ�ͳ����x��Ӧrow�У�y��Ӧcol��
			   x
			������������
			| 
	y		|
			|
			*///    x col��    y row��
			putimage(j*SIZE, i*SIZE, &img[pic[i][j]]);
		}
	}
}

//����Ϸ
void playgame()
{
	MOUSEMSG m;//������ȡ�����Ϣ
	int row;//��
	int col;//��
	while (1)
	{

		drawpicture();
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			row = m.y / 100;//m.y��ʾ��row
			col = m.x / 100;//m.x��ʾ��col
			/*(windows�ı�ʾ)
			 col   x
			|��������
	row	y	|
			|
			*/
			if (pic[row - 1][col + 0] == 0 && is_cross(row - 1, col))//����������ǰͼƬ�������ǿհף�������ƶ�,���Ҳ���Խ��
				my_swap(row, col, -1, 0);
			else if (pic[row + 1][col + 0] == 0 && is_cross(row + 1, col))//����հ�
				my_swap(row, col, 1, 0);
			else if (pic[row + 0][col - 1] == 0 && is_cross(row, col - 1))//����ǿհ�
				my_swap(row, col, 0, -1);
			else if (pic[row + 0][col + 1] == 0 && is_cross(row, col + 1))//�ұ��ǿհ�
				my_swap(row, col, 0, 1);

			break;
		}
		if (is_win())
			break;
	}
	MessageBox(GetHWnd(), L"��ϲ��ȡŮ����һö", L"ͨ����ʾ", MB_OK);
}
//����
void my_swap(int row,int col,int a, int b)
{
	int temp;
	temp = pic[row][col];
	pic[row][col] = pic[row + a][col + b];
	pic[row + a][col + b] = temp;
}

//�ж��Ƿ�Խ��
bool is_cross(int row,int col)
{
	return row >= 0 && row < 3 && col >= 0 && col < 3;
}
//�ж�ʤ������
bool is_win()
{
	int goal[9] = { 1,2,3,4,5,6,7,8,0 };
	
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pic[i][j] != goal[k++])//���������goal��˳���ĺõĻ�ͨ��
			{
				return false;
			}
		}
	}
	return true;
}