#include<iostream>
#include<cstring>
#include<vector>

int main()
{
	using namespace std;
	//int myvector[8];
    //vector<int> vec;
	vector <int> aa(5, 10);
	for (int i = 0; i < 5; i++)
		//printf("%d", aa[i]);
	cout << aa[i] << endl;;
	
	//c++输出写法
	//cout << "v2 =";
	//for (auto& v : v2) {
	//	cout << " " << v;
	//}
	//ps：按f1查看帮助
	char s[2] = "s";//实际上还有'\0'
	const int SIZE = 15;
	char name1[SIZE];
	char name2[SIZE] = "C++ boy";
	cout << "请输入字符串！" << endl;
	cin >> name1;
	name2[3] = '\0';//对第四个字符重新复制
	cout<<name1<<"一共有"<<strlen(name1)<<"个字符"<< endl;
	cout <<name2 << endl;
}
