#include<iostream>
#include<cctype>
using namespace std;
int main()
{
	char ch;
	cin.get(ch);
	if (isalpha(ch))
		cout << "����ĸ" << endl;
	if (isdigit(ch))
		cout << "������" << endl;
	if (isspace(ch))
		cout << "�ǿո�" << endl;
	if (islower(ch))
		cout << "��Сд" << endl;
	if (isupper(ch))
		cout << "�Ǵ�д" << endl;
	if (tolower(ch))
		cout << "ת��Сд" << tolower(ch)<< endl;//����intֵ
	if (toupper(ch))
		cout << "ת�ɴ�д" << toupper(ch) << endl;//����intֵ
}