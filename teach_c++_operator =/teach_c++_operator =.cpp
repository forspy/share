#include"Array.h"

int  main()
{
	my_Array *p = new my_Array(4);//ע�ⲻ��Ҫ����4�����󣬶���ֻ����һ����������������г�Ա����,4��Ϊ���캯���Ĳ�������ȥ
	for (int i = 0; i < p->size(); i++)
	{
		p->at(i)=i;//����atȥ���ʶ���*p�ڵĳ�Ա���ﵽ[]��Ч��
		//p[i] = i;//p[i]=my_Array temp(i);�������ʽ�Ĺ����Ĭ��operator=����,�����ﲻ�У���Ϊ����ֻ��һ������
	}
	cout << *p << endl;

	my_Array a1;//Ĭ����ͨ����
	a1.at(0) = 111111;//������������Ա��ֵ
	cout << a1 << endl;
	my_Array a2(*p);//��������,���my_Array a2=a3;�ⲻ��=���أ�������ʽ���ÿ�������my_Array a2=my_Array(a3);
	cout << a2 << endl;
	delete p;
	my_Array a3 ;
	//a3 = a2;//1.Ĭ��=���ػᵼ��a3ԭ����Աָ��ָ����ڴ�й¶��2.����2�������ʱ��ᵼ��2���ͷ�3.�ܽ����ǳ����
	a3 = a1;
	cout << a3 << endl;
}