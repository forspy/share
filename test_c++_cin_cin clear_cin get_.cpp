#include<iostream>

const int max = 5;
int main()
{
	using namespace std;
	int golf[max];
	cout << "Please enter your golf scores.\n";
	cout << "you must enter" << max << "rounds.\n";
	int i;
	for (i = 0; i < max; i++)
	{
		cout << "round#"<< i + 1 << ":";
		while (!(cin >> golf[i]))//cin已经输入到缓存
		{
			cin.clear();//清除缓存
			while (cin.get() != '\n')
				continue;
			cout << "Please enter a number:";
		}
	}
	double total = 0;
	for (i = 0; i < max; i++)
		total += golf[i];
	cout << total / max << "=average score " << max << " rounds\n";
	return 0;
}