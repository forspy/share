#include<iostream>
using namespace std;
double probability(double total, double choices);
int main()
{
	double total, choices;
	cout << "请输入总的个数以及选几个?\n";
	while ((cin >> total >> choices) && choices <= total)//cin可以连续输入
	{
		cout << probability(total, choices);
		cout << "输入字符结束\n";
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
