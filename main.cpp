//main.cpp, put your driver code her,
//you can manipulate class objects here
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include "time.hpp"
#include "date.hpp"
#include "calendar.hpp"
using namespace std;
/*
void tempInputs(){
	Date date(9, 8);
	TimeRange time(0, 0, 0, 0);
}*/

int main(Calendar cal, Date date, TimeRange time){
	int ch;
	char ans;
	//int m, d, hr0, min0, hr1, min1;
	/*Calendar cal(103);
    Date date(9, 8);
	TimeRange time;*/

	cout << "\nWelcome to the automated appointment booking system.\n===================================================\n";
	cout << "We are currently open to bookings from September 8th to December 20th, 2020, Mondays to Fridays excluding holidays.\n";
	do {
		cout << "\n\n *** Menu ***";
		cout << "\n 1. Display Booked Slots";
		cout << "\n 2. Display Free Slots";
		cout << "\n 3. Book an Appointment";
		cout << "\n 4. Query an Appointment";
		cout << "\n 5. Delete an Appointment";

		cout << "\n\n\t Enter your choice: ";                        
		cin >> ch;
		
		switch (ch){
			case 1: //tempInputs();
			date.printAppointedTimeSlots();
			break;
			case 2: //tempInputs();
			date.printFreeTimeSlots();
			break;
			case 3: //tempInputs();
            /*cout << "Enter Month to book: "; cin >> m;
            cout << "Enter Day to book: "; cin >> d;
            cout << "Enter Start hour: "; cin >> hr0;
            cout << "Enter Start minute: "; cin >> min0;
            cout << "Enter End hour: "; cin >> hr1;
            cout << "Enter end minute: "; cin >> min1;
            Date tempDate(m, d);
            TimeRange tempTime(hr0, min0, hr1, min1);*/         
			cal.book(date, time);
			break;
			case 4: //tempInputs();
			cal.query(date, time);
			break;
			case 5: //tempInputs();
			cal.del(date, time);
			break;
			/*case 6: do{
				cout << "Enter the date you wish to book.\n";
				date.inputDate();
			} while (date.totallyValid() == false);
			do {
				cout << "Enter the time slot you wish to book in multiples of 30, eg. 11:0 to 12:30\n";
				time.inputTime();
			} while (time.totallyValid() == false);
			break;*/
			default: cout << "\n\t Invalid Option!";
		}
		cout << "\n\n\t Do you want to continue? (y/n) : ";
		cin >> ans;
	}while (ans == 'y' || ans == 'Y');
	
	//date.outputDate();
	//time.outputTime();

	return 0;
 cal.printEveryDay();
}
