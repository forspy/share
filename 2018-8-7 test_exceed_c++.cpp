#include <iostream>
#include<climits>

#define ZERO 0
const int Months = 12;//�޶������εı�������ֵ�������ı�
int main()
{
	using namespace std;
	short sam = SHRT_MAX;//��ʾ�������͵����ΧSHRT_MAX(short���Ͷ�����)
	unsigned short Sue = ZERO;
	Months = 11;
	cout << "Sam is "<<sam << endl;
	cout << "Sue is " << Sue << endl;
	sam = sam + 1;
	Sue = Sue - 1;
	cout << "Sam is " << sam << endl;
	cout << "Sue is " << Sue << endl;
	//short ��Χ[-2^7,2^7-1]  unsigned short ��Χ[0,2^8-1],�����Խ�����ƣ���ֵ������һ��ȡֵ
	int waist = 42;
	cout << hex;//��ʮ�����Ƹ�ʽ���
	cout << "waist = " << waist << endl;
	cout << dec;//��ʮ���Ƹ�ʽ���
	cout << sam << endl;
	//decimal��ʮ���ƣ�hexadecimal��ʮ�����ƣ�octal���˽��ƣ�,ȡ��������ĸ�����Ըý������
	char ch;
	ch = 'A';
	cout << ch << endl;
	cout.put(ch);//�����������һ����put��iostream���У�cout������ĳ�Ա����������
	cout << endl;
	cout << "don't do that !\a\n";//����
}