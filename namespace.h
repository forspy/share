#pragma once
//c++�ṩ�����ƿռ��Ա���õؿ������Ƶ�������
//���ƿռ�ͨ����ͷ�ļ�����
#include<string>

namespace pers
{
	struct person//���ƿռ��ﶨ����һ���ṹ
	{
		std::string fname;
		std::string lname;/*
		�ṹ�ﶨ����һ��string�࣬��Ϊû��ʹ��using namespace std(using����ָ��--���std���ƿռ��µ����б�����)
		��using std::string��usingָ��--ֻ���std�µ�string����),����Ҫ��std::���������
		*/
	};
	void getperson(person&);//�����������ƿռ���������
}

namespace test
{
	using namespace pers;//�����������ƿռ���ʹ�ñ�����ƿռ�
	int m;
}

namespace test
{
	char add[20];//�����Զ����е����ƿռ�������
}

/*
�ܽ᣺
1.���ƿռ������ȫ�ֵģ�Ҳ����λ����һ�����ƿռ��У����ǲ���λ�ڴ������
2.���ƿռ��е����Ʋ����������ռ�����Ƴ�ͻ
3.����������ƿռ�
4.��������ͬ�����ƿռ�Ϊһ�������ƿռ��ṩ��������
5.���ַ�ʽ�������ƿռ��е�����
a. std::value
b. using namespace std(using����ָ��--���std���ƿռ��µ����б�����)
c. using std::string��usingָ��--ֻ���std�µ�string����),����Ҫ��std::������������Ƽ���
6.������#include֮��ʹ��using
7.������usingʹ���ھֲ�����
*/

