//��̳н���
//����->�����ࣨ�磺ostream->ofstream��
//   �̳�       �̳п���ʹ������ʹ�û���ķ���
//�̳е���һ���ص㣺�������ÿ��Խ�ס������Ķ��� �磺ostream& a=cout,Ҳ������ostream& a=fout;
//���ں�ʱʹ�����ã���ʱʹ��ָ�룬��ʱ����ֵ�Ƚ���
//1.������ݶ����С���������������ͻ�С�ͽṹ����ֵ����
//2.������ݶ��������飬��ָ�봫�ݣ���Ҫ�޸���������������fun(&x)����Ҳʹ��ָ���޸ģ�
//3.������ݶ����ǽϴ�Ľṹ����ʹ��ָ������ã�����߳���Ч��
//4.������ݶ������������ʹ�����á�
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
const int LIMIT = 2;
void file_it(ostream& os, double fo, const double* fe, int n);
int main()
{
	ofstream fout;
	const char* fn = "data.txt";
	fout.open(fn);
	if (!fout.is_open())//.is_open()�ж��Ƿ��
	{
		cout << "can't open" << fn << endl;
		exit(EXIT_FAILURE);
	}
	double objective;//�ﾵ����
	cout << "�������ﾵ����mm" << endl;
	cin >> objective;
	double eps[LIMIT];//��ͬĿ���Ľ���
	cout << "������Ŀ������mm" << endl;
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Ŀ��#" << i << "=  ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
}

void file_it(ostream& os, double fo, const double* fe, int n)
{
	//Ԥ�ȴ���ø�ʽ����ʽ
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);//ʹ�ö����ʾ�����������ֱ�ʾ��ʽ����initial�У�os��ostream������󣬿���ʹ�ø���ķ���.setf()
	//------------
	os.precision(0);//�����С������
	os << "�ﾵ����Ϊ" << fo << "mm" << endl;
	os.setf(ios::showpoint);//��ʾС����ʽ
	os.precision(1);//��ʾһλС��
	os.width(12);//.width()�෽��������ʾ��һ���ֶεĿ�ȣ�������һ���ֶλָ���Ĭ��
	os << "Ŀ������";
	os.width(15);
	os << "�Ŵ���" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];//os��ostream&�����ÿ��Խ�סcout��fout
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;//�Ŵ���Ϊ�ﾵ���ദ��Ŀ������
	}
	os.setf(initial);//�������fixed��ʽ
}
