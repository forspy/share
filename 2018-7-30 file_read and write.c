#include<stdio.h>

main()
{
	FILE *fid = fopen("out.txt", "r");
	if (fid == NULL)
	{
		printf("打开%s失败\n", "txt_out.txt");//
		return;
	}
	int mode = 2;
	if (mode == 1)//逐个字符输入fgetc(fid)
	{
		//按字符读入并直接输出
		char ch;       //读取的字符，判断准则为ch不等于结束符EOF（end of file）
		while (EOF != (ch = fgetc(fid)))
			printf("%c", ch);
	}
	if (mode == 2)//逐行输入fgets(字符串地址，长度，文件通道号)
	{
		//注意变量初始化
		char line[1024];
		char *c = line;
		//memset(line, 0, 1024);
		while (!feof(fid))
		{
			fgets(c, 1024, fid);//改行文本，最大长度，指向文件的指针
			printf("%s\n", c); //输出
		}
	}
	/*if (mode == 3)
	{
	//知道数据格式，按行读入并存储输出
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