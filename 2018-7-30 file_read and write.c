#include<stdio.h>

main()
{
	FILE *fid = fopen("out.txt", "r");
	if (fid == NULL)
	{
		printf("��%sʧ��\n", "txt_out.txt");//
		return;
	}
	int mode = 2;
	if (mode == 1)//����ַ�����fgetc(fid)
	{
		//���ַ����벢ֱ�����
		char ch;       //��ȡ���ַ����ж�׼��Ϊch�����ڽ�����EOF��end of file��
		while (EOF != (ch = fgetc(fid)))
			printf("%c", ch);
	}
	if (mode == 2)//��������fgets(�ַ�����ַ�����ȣ��ļ�ͨ����)
	{
		//ע�������ʼ��
		char line[1024];
		char *c = line;
		//memset(line, 0, 1024);
		while (!feof(fid))
		{
			fgets(c, 1024, fid);//�����ı�����󳤶ȣ�ָ���ļ���ָ��
			printf("%s\n", c); //���
		}
	}
	/*if (mode == 3)
	{
	//֪�����ݸ�ʽ�����ж��벢�洢���
	int index_tmp;
	double x_tmp, y_tmp;
	while (!feof(fid))
	{
	fscanf(fid, "%d%lf%lf\n", &index_tmp, &x_tmp, &y_tmp);
	index.push_back(index_tmp);
	x_pos.push_back(x_tmp);
	y_pos.push_back(y_tmp);
	}
	for (int i = 0; i < index.size(); i++)
	printf("%04d\t%4.8lf\t%4.8lf\n", index[i], x_pos[i], y_pos[i]);
	}
	*/
	fclose(fid);

}