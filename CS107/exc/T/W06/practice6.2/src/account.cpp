#include "account.h"

#include <cmath>

/// ------------------------------------------------------------------------ ///
///                                SaveAccount                               ///
/// ------------------------------------------------------------------------ ///
SaveAccount::SaveAccount(int balance, int period, float rate, int duration) {
	this->deposit(balance);
	this->m_period = period;
	this->m_rate = rate;
	this->m_duration = duration;
}

float SaveAccount::calcInterest() const {
	if (this->m_period == 0)
		return 0;

	// Interest = Balance * ((1 + (ratePerMonth * period)) ^ (duration / period) - 1)
	return ((float)this->getBalance()
			* ((1.0f
				+ (pow((float)((this->m_rate / 12) * this->m_period),
					   (int)(this->m_duration / this->m_period))))
			   - 1.0f));
}

void SaveAccount::deposit(float money) {
	Account::deposit(money + this->calcInterest());
	this->m_duration = 0;

	return;
}

void SaveAccount::withdraw(float money) {
	Account::deposit(this->calcInterest());
	Account::withdraw(money);
	this->m_duration = 0;

	return;
}

void SaveAccount::incrementByOneMonth() {
	this->m_duration++;

	return;
}