#include<iostream>
#include"stock00.h"

int main()
{
	Stock business;//����һ����Ϊbusiness�������
	//��ù�Ʊ
	business.acquire("Qiushi", 100, 3);//����Stock��ĳ�Ա����
	business.show();
	//����
	business.buy(10, 3.5);
	business.show();
	//����
	business.sell(20, 3.3);
	business.show();
	//������Ҳ������
	business.update(3.6);
	business.show();
}