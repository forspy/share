#include"Student.h"

ostream & Student::arr_out(ostream & os)//ʹ��˽�з��� ���ģ�����Ա����m_scores
{
	int i;
	int lim = m_scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << m_scores[i] << " ";
			if (i % 6 == 5)//ÿ��5��Ԫ�ػ�һ��
				os << endl;
		}
	}
	else
		os << "empty array";
	return os;
}

double Student::Average()
{
	if (m_scores.size() > 0)
		return m_scores.sum() / m_scores.size();
	else
		return 0.0;
}

string & Student::Name()
{
	return m_name;
}

double & Student::operator[](int i)
{
	return m_scores[i];//ʹ��valarray�ķ���[]
}

double Student::operator[](int i) const
{
	return m_scores[i];
}

istream & operator >> (istream & is, Student & stu)
{
	is >> stu.m_name;
	return is;
}

istream & getline(istream & is, Student & stu)//.getline()��������ķ���
{
	getline(is, stu.m_name);//getline��iostream����ķ���
	return is;
}

ostream & operator<<(ostream & os,Student & stu)
{
	os << "Scores for " << stu.m_name << ":" << endl;
	stu.arr_out(os);//���ø�������
	return os;
}
