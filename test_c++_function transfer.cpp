#include<iostream>
using namespace std;
double probability(double total, double choices);
int main()
{
	double total, choices;
	cout << "�������ܵĸ����Լ�ѡ����?\n";
	while ((cin >> total >> choices) && choices <= total)//cin������������
	{
		cout << probability(total, choices);
		cout << "�����ַ�����\n";
	}
}

double probability(double total, double choices)
{
	long double result = 1.0;
	//double n, m;
	for (; choices > 0; total--, choices--)
		result *= total / choices;
	return result;
}
