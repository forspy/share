#include<iostream>
#include<vector>//STL C++98 ģ����
#include<array>//C++11 ģ����

int main(int agrc, char* argv[])
{
	using namespace std;
	vector<int> vi(100,1) ;//����һ��int���͵ĳ���Ϊ1�����鲢��ʼ��Ϊ1����������鱻��Ϊ����
	vector<int> vi1(1);
	int a[10];
	double *p;
	cout << vi[99]<<endl<<sizeof vi << endl<<sizeof p<<endl;//�ѽ����vector ����������ָ��
	//vector���ĸ���Ա����_A allocator;iterator _First, _Last, _End; ��˴�Сʼ����16�ֽڣ�����������Ĵ�����ʵ��Ĵ���
	cout <<"vector�����������СΪ"<< vi.size() << endl;//�����ַ������Բ鿴vector��������Ĵ�С
	//vector <typename> vt(n_elem)  n_elem��һ������Ҳ�����ǳ���
	
	//array<typename,n_elem> arr ,array��n_elem�����Ǳ���
	vi[0] = 0;
	vi[1] = 1;
	vi[2] = 2;//STL vectorֻ��������ʼ��

	//vector�����ڶ��array������ջ�����array��Ч�ʱȽϸ�

	array<int, 5> ai = { 1,2,3,4,5 };//����һ��5��Ԫ�ص�array����ʼ��
	array<int, 5>ai2;
	ai2 = ai;//1.array�Ķ����ǿ��Ը�ֵ����һ��������2.���������ͺʹ�С����һ��
	cout << ai2[0] << endl;
	ai2.at(0) = 9999;//Ҳ����ʹ�ó�Ա����at()�����鸳ֵ,���Է�ֹ�����±�Խ��
	
	cout << ai2[0] << endl;
}