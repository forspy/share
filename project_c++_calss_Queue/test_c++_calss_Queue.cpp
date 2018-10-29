#include"Queue.h"
using namespace std;
const int MIN_PER_HR = 60;
bool newcustomer(double x);//����ƽ��ÿX��������customer
int main()
{
	srand((unsigned int)time(NULL));
	cout << "����ATM������ģ��" << endl;
	cout << "������������" << endl;
	int qs;
	cin >> qs;
	Queue line(qs);
	cout << "������ģ��ʱ��/Сʱ" << endl;
	long hour;
	cin >> hour;
	int cycle_limit = hour*MIN_PER_HR;
	cout << "������Ԥ��ƽ��ÿ�����ٷ�����һ���˿�" << endl;
	int x;
	cin >> x;
	Customer customer;//����һ��customer����
	long turnaways = 0;//ͳ�ƿ�����������ȡ���Ŷӵ���
	long customers = 0;//ͳ���Ź����еĶ���˿�
	long served = 0;//ͳ��ATM��������Ķ���
	long sum_line = 0;//�ۼƵĶ��г���(ȥ�����ܵ�ʱ�����ÿ����ƽ�����г���)
	int wait_time = 0;//1��customer��ATM������ʱ��
	long line_wait = 0;//�ۼ�����customer�Ŷӵȴ���ʱ��
	long appear_customers = 0;//һ�����ֹ��Ĺ˿���
	int max_processing_time;//ATM������ÿ���˿����õ����ʱ�����Ϊ[1,max_processing_time+1]
	cout << "������ATM������ÿ���˿����õ����ʱ�䣬���Ϊ[1,���ʱ��+1]" << endl;
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
				customer.set(cycle, max_processing_time);//��¼����˿Ͷ�������ʱ�䲢���趨��ATM��������������ʱ��
				line.en_queue(customer);//���������������
			}
		}

		if (wait_time <= 0 && !line.isempty())//��һ����ҪΪ����������Ź��ӵĹ˿͵ȴ�����ʱ�䣬��ʾ�ֵ�����˿���ATM��������
		{
			line.de_queue(customer);//���ȴӶ��е�ͷ����������˿�(û�з����ĸ��˿Ͷ�����ΪֻҪcustomer�ĳ�Ա��һ�����������˹˿Ͷ���ͨ��customer.set������)
			wait_time = customer.ptime();//ȡ���Ķ�����ATM������ʱ��
			line_wait = line_wait + cycle - customer.when();//line_wait������ͳ���ܵ�ʱ��ģ�ÿ�����Ŷӵ������Ĺ˿͵�ʱ�䣨��ǰʱ��-����ʱ�䣩 ������
			served++;//������������ۼ�
		}
		if (wait_time > 0)
			wait_time--;
		sum_line = sum_line + line.queue_count();
	}
	//ͳ�ƽ��
	if (customers > 0)
	{
		cout << "��" << hour << "Сʱ��" << endl;
		cout << "һ����" << appear_customers << "���˿ͳ���" << endl;
		cout << "һ����"<< customers<<"���˿��Ź���" << endl;
		cout << "ATM��һ�������"<< served<<"���˿ͣ�˵���ڹ涨ʱ���ڻ���Щ�˿ͻ����Ŷӵ�ATM��ǰ������"<< endl;
		cout << "��" << turnaways << "���˿���Ϊ������ת��" << endl;
		cout.precision(2);
		cout << "ÿ����ƽ�����г���:" << (double)sum_line / cycle_limit << "��/����" << endl;
		cout << "ƽ��ÿ���˿͵ȴ�ʱ��:" << (double)line_wait / served << " ����" << endl;
	}
}

bool newcustomer(double x)
{
	return ((rand()*x / RAND_MAX) < 1);//����[0,6]����ĸ�������ͬ�ģ�Ҳ����˵ƽ��ÿִ��6�ξͻ���1��Ϊtrue��ִ��1���൱��1����
}