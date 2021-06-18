//date.cpp to implement your class
#include "date.hpp"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

Date::Date(){ // constructor setting appointed, month & day to starting value
	cout << "Help\n";
	month = 9;
	day = 8;
	for (int i = 0; i < 48; i++){appointed[i] = false;}
}
Date::Date(int m, int d){ // constructor setting appointed, month & day to starting value
	month = m;
	day = d;
	for (int i = 0; i < 48; i++){appointed[i] = false;}
}

int Date::setDate(int m, int d){
	month = m;
	day = d;
	return 0;
}

int Date::getDay() const{return this->day;}

int Date::getMonth() const{return this->month;}

bool Date::isValid() {
        if ((month < 9) || (month > 12) || (day < 1) || (day > 31)) {
        cout << "Error, you must book between September and December\n\n";
        return false;
        }
        else if ((month == 9) && ((day < 8) || (day == 31 ))) {
        cout << "Error, if booking in September, it must be between September 8th and 30th\n\n";
        return false;
        }
        else if ((month == 11) && (day == 31)) {
        cout << "Error, you cannot book on November 31st, as it does not exist\n\n";
        return false;
        }
        else if ((month == 12) && (day > 20)) {
        cout << "Error, if booking in December, it must be between December 1st and 20th\n\n";
        return false;
        }
        else {
        return true;
        }
}
bool Date::isHoliday() {
	const int thanksgivingDay = 12;
	const int rememberanceDay = 11;
	if (month == 10 && day == thanksgivingDay) {
			cout << "Error, you can't book on Thanksgiving Day\n\n";
			return false;
	}
	else if (month == 11 && day == rememberanceDay) {
			cout << "Error, you can't book on Rememberance Day\n\n";
			return false;
	}
	else {
			return true;
	}
}

bool Date::isWeekend(){		//Check if date is a weekend
	if (((month == 9) || (month == 12)) && ((day % 7 == 5) || (day % 7 == 6))){
		cout << "Error. The day entered is a weekend, booking unavailable.\n\n";
		return true;
		}
	else if ((month == 10) && ((day % 7 == 3) || (day % 7 == 4))){
		cout << "Error. The day entered is a weekend, booking unavailable.\n\n";
		return true;
		}
	else if ((month == 11) && ((day % 7 == 0) || (day % 7 == 1))){
		cout << "Error. The day entered is a weekend, booking unavailable.\n\n";
		return true;
		}
	else{return false;}
}

bool equal(Date date1, Date date2){	//Check if 2 dates are the same
	if ((date1.month == date2.month) && (date1.day == date2.day)){return true;}
	else{return false;}
}

void Date::inputDate(){		//Input function
		cout << "Enter the month: "; cin >> month;
		cout << "Enter the day: "; cin >> day;
		isValid();
		isWeekend();
		isHoliday();
}
void Date::outputDate(){	//Output function
	cout << "Month = " << setw(2) << setfill('0') << month << ", day = " << setw(2) << setfill('0') << day << endl;
}

void Date::printFreeTimeSlots(){	//Print available time slots
	cout << "Open time slots: \n";
	timeSlots(0);
}
void Date::printAppointedTimeSlots(){	//Print booked time slots
	cout << "Booked time slots: \n";
	timeSlots(1);
}

void Date::timeSlots(int temp){
	for(int i = 0; i < 48; i++){
		if ((appointed[i] == false && temp == 0) || (appointed[i] == true && temp == 1)){
			int hour = i / 2;
			int minute = i % 2;
			cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute * 30;
			if (i < 48){cout << ", ";}
		}
	}
	cout << endl;
}

bool Date::totallyValid(){ // does all the checks at once
    if (isValid() == false && isHoliday() == true && isWeekend() == true){return false;}

    else {return true;}
}

bool Date::getAppointed() const{ return this->appointed[0];}
/*
bool Date::setAppointed(){
	for (int i = 0; i < 48; i++){
		appointed[i] = false;
	}
}*/