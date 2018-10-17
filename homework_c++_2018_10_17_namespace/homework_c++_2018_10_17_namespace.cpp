#include"bank.h"

int main()
{
	ICBC::Bank I_deposit;
	ABC::Bank A_deposit;
	I_deposit = I_deposit + 3000 - 2000;
	I_deposit.show();
	A_deposit = A_deposit - 1500 + 800;
	A_deposit.show();
}