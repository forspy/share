#include<iostream>
#include<vector>//STL C++98 模板类
#include<array>//C++11 模板类
#include<string>
#include<map>
int main(int agrc, char* argv[])
{
	using namespace std;
	vector<int> vi(100,1) ;//创建一个int类型的长度为1的数组并初始化为1，这里的数组被称为对象
	vector<int> vi1(1);
	int a[10];
	double *p;
	cout << vi[99]<<endl<<sizeof vi << endl<<sizeof p<<endl;//已解决：vector 创建的是针指，
	//vector的四个成员变量_A allocator;iterator _First, _Last, _End; 因此大小始终是16字节，区别于数组的创建是实体的创建
	cout <<"vector创建的数组大小为"<< vi.size() << endl;//用这种方法可以查看vector创建数组的大小
	//vector <typename> vt(n_elem)  n_elem是一个变量也可以是常量
	
	//array<typename,n_elem> arr ,array的n_elem不能是变量
	vi[0] = 0;
	vi[1] = 1;
	vi[2] = 2;//STL vector只能这样初始化
	//新建一个vector模板对象
	vector<float> v;
	v.push_back(3.0);//表示加入到容器vector的结尾	
	v.push_back(4.0);//继续加入，有点类似于栈的数据结构
	v.pop_back();//栈类弹出,返回void无法接住弹出值
	float m=v[1];//vector重载了[]
	//vector的迭代器
	vector<float>::iterator it;//类似于元素指针
	it=v.begin();//第一个元素开始的位置
	it=v.end();//最后一个元素的下一个元素的位置
	
	//把迭代器it当成指针来使用
	it=v.begin();
	while(it<v.end())//输出vector容器内的值
	{
		cout<<*it<<endl;
		it++;
	}
	//删除（迭代器）
	v.erase(v.begin());//删除第一个元素位置
	v.erase(v.begin(),v.begin+2);//删除前三个
	//插入（迭代器）
	v.insert(v.begin());//插入到第一个位置
	//.at(),等同[]
	//.size();容器大小
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	//删除所有的元素
	v.clear();
	
	//vector储存在堆里，array储存在栈里，所以array的效率比较高
	
	array<int, 5> ai = { 1,2,3,4,5 };//创建一个5个元素的array并初始化
	array<int, 5>ai2;
	ai2 = ai;//1.array的对象是可以赋值给另一个变量的2.变量的类型和大小必须一样
	cout << ai2[0] << endl;
	ai2.at(0) = 9999;//也可以使用成员函数at()对数组赋值,可以防止数组下标越界
	//测试+复习
	cout << ai2[0] << endl;
	char* ptr = "hello";
	cout << ptr << (int)ptr << (int*)"ss" << endl;
	printf("%s\n", ptr);
	string aa;
	cin >>aa;//cin只能提取一个单词
	cout << aa << endl;
	//
	cin.get();//1.为什么要加这一句，因为cin读取字符串的时候，将回车键生成的换行符留在了输入队列之中。
	//		  //后面的cin.getline()看到换行符后，将认为这是一个空行，并将空字符赋值给下一个数组。
	//		  //可以利用cin.get()来接住这个回车符。
	//2.cin.get()只适用于接住一个空格或回车符，如果前面的输入是一行，则建议使用cin.getline() 或者getline（）
	//
	char bb[100];
	cin.getline(bb,100);//cin.getline 是iosteam类的
	cout << bb << endl;
	string cc;
	getline(cin, cc);//getline是string类的
	cout << cc << endl;
	
	 
	
}
