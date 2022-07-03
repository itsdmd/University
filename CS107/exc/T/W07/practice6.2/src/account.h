#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
	private:
		float m_balance = 0;

	public:
		float getBalance() const { return m_balance; }

		void deposit(float money) {
			m_balance += money;

			return;
		}

		void withdraw(float money) {
			if (money <= m_balance) {
				m_balance -= money;
			}

			return;
		}
};

class SaveAccount: public Account {
	private:
		int m_period = 0;								  // Months
		float m_rate = 0.0f;							  // Yearly percentage
		int m_duration = 0;								  // Since last deposit/withdrawal

	public:
		SaveAccount(int balance, int period, float rate, int duration);
		float calcInterest() const;

		void deposit(float money);
		void withdraw(float money);

		void incrementByOneMonth();
};

#endif