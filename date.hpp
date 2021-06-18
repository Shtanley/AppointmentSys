//header file date.hpp to declare your class
#ifndef DATE_HPP
#define DATE_HPP
#include "time.hpp"

class Date {
	public: 
	Date();
	Date(int m, int d);
	//~Date();
	friend bool equal(Date date1, Date date2);
	int setDate(int m, int d);
	int getDay() const;
	int getMonth() const;
	
	void printFreeTimeSlots();
	void printAppointedTimeSlots();
	void inputDate();
	void outputDate();
	bool totallyValid();
	bool getAppointed() const;
	//void setAppointed();
	bool appointed[48];

	private:
	
	TimeRange timeSlot[48];
	int month;
	int day;

	bool isValid();
	bool isHoliday();
	bool isWeekend();
	void timeSlots(int temp);
};
#endif
