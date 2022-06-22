#include "account.h"

/// ------------------------------------------------------------------------ ///
///                                SaveAccount                               ///
/// ------------------------------------------------------------------------ ///
SaveAccount::SaveAccount(int balance, int period, float rate, int duration) {
	this->deposit(balance);
	this->m_period = period;
	this->m_rate = rate;
	this->m_duration = duration;
}

float SaveAccount::calcIntrst() const {
	return ((float)this->getBalance() * (this->m_rate / 100) * this->m_duration)
		   - ((float)this->getBalance() * (this->m_rate / 100) * (this->m_duration % this->m_period));
}

void SaveAccount::deposit(float money) {
	Account::deposit(money - this->calcIntrst());
	this->m_duration = 0;

	return;
}

void SaveAccount::withdraw(float money) {
	Account::withdraw(money - this->calcIntrst());
	this->m_duration = 0;

	return;
}

void SaveAccount::incrementByOneMonth() {
	this->m_duration++;

	return;
}