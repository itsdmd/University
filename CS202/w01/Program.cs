using System;

// Write a program to work with a date.
// + You can hard-code 3 int variables: day, month, and year.
// + Check if these 3 variables create a valid date.
// + Print out the next date
// + Print out the previous date

class Date {
	static int m_day = 0;
	static int m_month = 0;
	static int m_year = 0;
	
	public Date(int day, int month, int year) {
		m_day = day;
		m_month = month;
		m_year = year;
	}
	
	public void PrintDate() {
		Console.WriteLine("Date: {0}/{1}/{2}", m_day, m_month, m_year);
	}
	
	public bool isLeapYear() {
		if (m_year % 4 == 0) {
			if (m_year % 100 == 0) {
				if (m_year % 400 == 0) {
					return true;
				} else {
					return false;
				}
			} else {
				return true;
			}
		} else {
			return false;
		}
	}
	
	public bool isValidDate() {
		if ((m_day < 1) || (m_day > 31)) {
			return false;
		}
		if ((m_month < 1) || (m_month > 12)) {
			return false;
		}
		if (m_year < 1) {
			return false;
		}
		
		if (m_month == 2) {
			if (isLeapYear()) {
				if (m_day > 29) {
					return false;
				}
			} else {
				if (m_day > 28) {
					return false;
				}
			}
		}
		if ((m_month == 4) || (m_month == 6) || (m_month == 9) || (m_month == 11)) {
			if (m_day > 30) {
				return false;
			}
		}
		
		return true;
	}
	
	public void printIsValidDate() {
		if (isValidDate()) {
			Console.WriteLine("The date {0}/{1}/{2} {3}", m_day, m_month, m_year, "is valid.");
		} else {
			Console.WriteLine("The date {0}/{1}/{2} {3}", m_day, m_month, m_year, "is not valid.");
		}
	}
	
	public void printNextDate() {
		int next_day = m_day;
		int next_month = m_month;
		int next_year = m_year;
		
		if (isValidDate()) {
			if (next_day == 31) {
				if (next_month == 12) {
					next_day = 1;
					next_month = 1;
					next_year++;
				} else {
					next_day = 1;
					next_month++;
				}
			} else {
				if (next_month == 2) {
					if (isLeapYear()) {
						if (next_day == 29) {
							next_day = 1;
							next_month++;
						} else {
							next_day++;
						}
					} else {
						if (next_day == 28) {
							next_day = 1;
							next_month++;
						} else {
							next_day++;
						}
					}
				} else {
					if ((next_month == 4) || (next_month == 6) || (next_month == 9) || (next_month == 11)) {
						if (next_day == 30) {
							next_day = 1;
							next_month++;
						} else {
							next_day++;
						}
					} else {
						next_day++;
					}
				}
			}
			
			Console.WriteLine("Next date: {0}/{1}/{2}", next_day, next_month, next_year);
		}
		
		else {
			Console.WriteLine("The date {0}/{1}/{2} {3}", m_day, m_month, m_year, "is not valid.");
		}
	}
	
	public void printPreviousDate() {
		int prev_day = m_day;
		int prev_month = m_month;
		int prev_year = m_year;
		
		if (isValidDate()) {
			if (prev_day == 1) {
				if (prev_month == 1) {
					prev_day = 31;
					prev_month = 12;
					prev_year--;
				} else {
					prev_month--;
					if (prev_month == 2) {
						if (isLeapYear()) {
							prev_day = 29;
						} else {
							prev_day = 28;
						}
					} else {
						if ((prev_month == 4) || (prev_month == 6) || (prev_month == 9) || (prev_month == 11)) {
							prev_day = 30;
						} else {
							prev_day = 31;
						}
					}
				}
			} else {
				prev_day--;
			}
			
			Console.WriteLine("Previous date: {0}/{1}/{2}", prev_day, prev_month, prev_year);
		}
		
		else {
			Console.WriteLine("The date {0}/{1}/{2} {3}", m_day, m_month, m_year, "is not valid.");
		}
	}
}

class w01 {
	static void Main() {
		Date date1 = new Date(31, 12, 2003);
		date1.PrintDate();
		date1.printIsValidDate();
		date1.printNextDate();
		date1.printPreviousDate();
		
		Console.WriteLine("\n");
		
		Date date2 = new Date(29, 2, 2902);
		date2.PrintDate();
		date2.printIsValidDate();
		date2.printNextDate();
		date2.printPreviousDate();
		
		Console.WriteLine("\n");
		
		Date date3 = new Date(1, 3, 2000);
		date3.PrintDate();
		date3.printIsValidDate();
		date3.printNextDate();
		date3.printPreviousDate();
	}
}