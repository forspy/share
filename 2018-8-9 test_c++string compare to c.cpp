#include<iostream>
#include<string>
#include<string.h>//c style

//比较c++与c的字符输出 字符输出
//c++以类对象的方法输出

int main()
{
	using namespace std;
	char char1[20];
	char char2[20] = "hello";
	
	string str1;
	string str2 = "hello world";

	strcpy(char1, char2);
	str1 = str2;

	strcat(char2, "world");
	str2 += "boy!";

	int len1 = strlen(char2);
	int len2 = str2.size();

	printf("the string %s contains %d chars\n", char2, len1);
	cout << "the string " << str2 << " contains " << len2 << " chars\n";
	
	getline(cin, str1);
	cout << str1 << endl;
    return 0;
}