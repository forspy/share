#include<iostream>

using namespace std;

int main()
{
	char name[20] = "hello";
	char cpName[10];//过小会溢出

	//strcpy(cpName, name);
	strncpy(cpName, name, 2);
	cpName[2] = '\0';
	cout << cpName << endl;
}