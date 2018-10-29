#include"Queue.h"
using namespace std;
const int MIN_PER_HR = 60;
bool newcustomer(double x);//设置平均每X分钟来个customer
int main()
{
	srand((unsigned int)time(NULL));
	cout << "银行ATM机队列模拟" << endl;
	cout << "请输入最大队列" << endl;
	int qs;
	cin >> qs;
	Queue line(qs);
	cout << "请输入模拟时间/小时" << endl;
	long hour;
	cin >> hour;
	int cycle_limit = hour*MIN_PER_HR;
	cout << "请输入预计平均每隔多少分钟来一个顾客" << endl;
	int x;
	cin >> x;
	Customer customer;//创建一个customer对象
	long turnaways = 0;//统计看到队列满而取消排队的人
	long customers = 0;//统计排过队列的对象顾客
	long served = 0;//统计ATM机服务过的对象
	long sum_line = 0;//累计的队列长度(去处以总的时间就是每分钟平均队列长度)
	int wait_time = 0;//1个customer的ATM机处理时间
	long line_wait = 0;//累计所有customer排队等待的时间
	long appear_customers = 0;//一共出现过的顾客数
	int max_processing_time;//ATM机处理每个顾客所用的最大时间随机为[1,max_processing_time+1]
	cout << "请输入ATM机处理每个顾客所用的最大时间，随机为[1,最大时间+1]" << endl;
	cin >> max_processing_time;
	for (int cycle = 0; cycle < cycle_limit; cycle++)
	{
		if (newcustomer(x))
		{
			appear_customers++;
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				customer.set(cycle, max_processing_time);//记录这个顾客对象到来的时间并且设定好ATM机处理这个对象的时间
				line.en_queue(customer);//将这个对象插入队列
			}
		}

		if (wait_time <= 0 && !line.isempty())//这一步主要为了求出所有排过队的顾客等待过的时间，表示轮到这个顾客在ATM机操作了
		{
			line.de_queue(customer);//首先从队列的头部弹出这个顾客(没有分是哪个顾客对象，因为只要customer的成员不一样就算区分了顾客对象（通过customer.set（））)
			wait_time = customer.ptime();//取到改对象在ATM机待的时间
			line_wait = line_wait + cycle - customer.when();//line_wait是用来统计总的时间的，每个从排队到出来的顾客的时间（当前时间-进入时间） 加起来
			served++;//服务过的人数累加
		}
		if (wait_time > 0)
			wait_time--;
		sum_line = sum_line + line.queue_count();
	}
	//统计结果
	if (customers > 0)
	{
		cout << "在" << hour << "小时内" << endl;
		cout << "一共有" << appear_customers << "个顾客出现" << endl;
		cout << "一共有"<< customers<<"个顾客排过队" << endl;
		cout << "ATM机一共服务过"<< served<<"个顾客（说明在规定时间内还有些顾客还在排队到ATM机前操作）"<< endl;
		cout << "有" << turnaways << "个顾客因为队列满转身" << endl;
		cout.precision(2);
		cout << "每分钟平均队列长度:" << (double)sum_line / cycle_limit << "个/分钟" << endl;
		cout << "平均每名顾客等待时间:" << (double)line_wait / served << " 分钟" << endl;
	}
}

bool newcustomer(double x)
{
	return ((rand()*x / RAND_MAX) < 1);//落在[0,6]区间的概率是相同的，也就是说平均每执行6次就会有1次为true，执行1次相当于1分钟
}