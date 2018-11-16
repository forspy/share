#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	//map有一个key和一个value，都可以是任意类型
	
	map<int, double> mm1;
	map<string, double>mm2;//表示string作为key，float作为value 
						  //有点类似于hash表
	map<int, double>::iterator m_it;//map 迭代器
	mm1[3] = 4.0;
	mm2["xiaoming"] = 1.68;
	cout << mm1[3] <<'\t'<< mm2["xiaoming"] << endl;
	m_it=mm1.find(3);//返回key=3所在的迭代器
	if (m_it != mm1.end())//表示找到了
	{
		cout << "is exit" << endl;
	}
	//也有类似于vector的功能
	mm2.clear();
	mm1.erase(3);//删掉3这个key
}
