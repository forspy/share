//endl���ͷŻ���
//��һ���ض���Ķ������������������
//<ios>������<ostream>(cout)��<istream>(cin),<ostream>��<istream>��ͬ������<iostream>
//<istream>-><ifstream>����ȡ�ļ��� <ostream>-><ofstream> , <iostream>-><fstream>
//        -><istringstream>                  -><ostringstream>  �ַ���string��
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a = 21;
	//1.setf()���ø�ʽ
	cout.setf(ios::showbase);
	cout << "dec " << a << endl;//Ϊ�������һ������ǰ׺��Ĭ��ʮ����
	cout.unsetf(ios::dec);//ȡ����ʮ���ƣ���ʽ
	cout.setf(ios::hex);//����ʮ������
	cout << "hex " << a << endl;
	//һ�׿��������׵ģ�����ʡ��
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);
	cout << "oct" << a << endl;
	cout.unsetf(ios::oct);//����Ĭ��ʮ����
	cout << a << endl;
	//-------------
	const char* p = "hello";
	//2.��Ա�������ø�ʽ
	cout.width(10);//ָ����� ���ڿո�С�ڳ������·���
	cout << p << endl;
	//----��*���
	cout.width(10);
	cout.fill('*');
	cout << p << endl;
	//��ѧ������
	double pi = 22.0 / 7.0;
	cout.setf(ios::scientific);
	cout << pi << endl;
	cout.unsetf(ios::scientific);

	//�ĸ��ַ� �Ҷ��� �á�0����䣨���ã�
	cout << setw(4) << /*left*/right << setfill('0') << 1 << endl;//�����ķ�ʽ 
	cout << showbase << hex << 21 << endl;//һ����oct���21
	bool b = false;
	cout << b << endl;
	cout << boolalpha << b << endl;
	cout << b << endl;
	cout << noboolalpha << b << endl;

	//����ض���
	//cout��׼������� ���л�������cerr ��׼��������޻������� clog��׼��������л�������
	//����ڴ�������coutʧЧ����Ϊû�пռ���仺���ˣ�Ӧ��ʹ��cerr���޻�������
	//cout��Ϊ�л�������������������ض���һ���ļ��У������ļ���  cerrֻ���������Ļ
	//����
	cout << "cout" << endl;
	cerr << "cerr" << endl;
	//tips:shift�Ҽ����ڴ˴�������� cmd �Ͻ�ȥҲ��
	//cmd <<�ض����ļ��� cerr�����ض���
	//����
	//���� .obj/.o->.exe/.out

	cout << "a";
	cout << "b" << ends;//'\0'
	cout << "c" << endl;//'\n'+flush
	cout << "d" << flush;//ˢ�»�����

	char c = cin.get();//��ȡ�����ַ�
	cout << c << endl;

	cout.put(c);//��ȡ�����ַ�
	//cout << putc << c << endl;
	endl(cout << c);
	char str[200] = { 0 };
	cin >> str;//�����ո�֮ǰ
	cout << str;//ʣ�µĻ������
	//�����ַ���
	cin.getline(str, 20);
	cout << str;
	cin.getline(str, 20, '/');//����/֮ǰ
	cout << str << endl;
}