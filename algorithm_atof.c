#include<stdio.h>

main()
{
	int i,j;
	double power,val;
	int s[3] = { 1,2,3 };
		
		printf("%d\n",s[0]);
		char ss[4] = { '1','2','3','\0' };//�ַ������鸳ֵ
		printf("%c\n", ss[0]);
		printf("%s\n", ss);
		char p[] = "hello";//c���Գ�ʼ����ʽ�ȼ���p[0]='h',p[1]='e',...
		printf("%s\n", p);
		char pp[] = "123";//C���Գ�ʼ����ʽ
		printf("%s\n", pp);
		char *m;//1.���԰��ַ�����ֵ��ָ��mm 2.ָ���ֵ�ǵ�ַ 3.�����ֵ�ǳ���
		m = "123";//˫��������������1.����һ���ռ�2.���ַ�����β����'\0' 3.���ص�ַ
		//�ַ���������hello��������һ������ʽ��ʱ����hello������ʽʹ�õ�ֵ������Щ�ַ����洢�ĵ�ַ���ڳ�����������������Щ�ַ�������
		printf("%s\n", m);
		/*tips������������Ӧ����һ������ֵ������ν����ֵ������ָ�ڳ�����ռ���ڴ�ռ䡢���Ա��޸ĵ���, ������ֱ�����

			��ʹ��ָ���ʱ��ָ���������������������������

			����������������˿ռ䣬����a�ĵ�ַ�ͱ�ʾһ�������ˣ��ó���������϶��ǲ��еġ�*/


	//power = 1.0;//Ĭ��double/float�����Ϊ1.000000
	//printf("%f", power);
	/*for (i = 0; i < 3; i++)
	{
		power *= 10.0;
	}*/
	//ctrl+k+c����ע��ctrl+k+uȡ��ע��
	/*printf("%f", power);
	for (j = 0; j < 3; j++)
	{
		val = 10.0*val + (s[j] - '0');
	}*/

}