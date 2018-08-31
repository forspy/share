#include<iostream>
#include<cctype>
using namespace std;
int main()
{
	char ch;
	cin.get(ch);
	if (isalpha(ch))
		cout << "是字母" << endl;
	if (isdigit(ch))
		cout << "是数字" << endl;
	if (isspace(ch))
		cout << "是空格" << endl;
	if (islower(ch))
		cout << "是小写" << endl;
	if (isupper(ch))
		cout << "是大写" << endl;
	if (tolower(ch))
		cout << "转成小写" << tolower(ch)<< endl;//返回int值
	if (toupper(ch))
		cout << "转成大写" << toupper(ch) << endl;//返回int值
}