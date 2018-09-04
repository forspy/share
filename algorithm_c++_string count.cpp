#include<iostream>
using namespace std;
int c_in_str(const char* str, char ch);
int main()
{
	char mm[15] = "minmum";
	char* wail = "hello";
	cout << c_in_str(mm, 'm') << endl;
	cout << c_in_str(wail, 'l') << endl;
	return 0;
}

int c_in_str(const char* str, char ch)
{
	int count = 0;
	while (*str)
	{
		if (*str == ch)
			count++;
		str++;
	}
	return count;
}