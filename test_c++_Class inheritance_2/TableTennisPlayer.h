#pragma once
#include<string>

using namespace std;
class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool m_has_table;
public:
	TableTennisPlayer(const string& fn="none",const string& ln="none",bool ht=false);
	~TableTennisPlayer();
	void name()const;
	bool has_table()const { return m_has_table; }
	void reset_table(bool v) { m_has_table = v; }
};

