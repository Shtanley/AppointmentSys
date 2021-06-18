//time.cpp to implement your class
#include "time.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

TimeRange::TimeRange(){		//Constuctor
    int beginHour = 0;
    int beginMinute = 0;
    int endHour = 0;
    int endMinute = 0;
}

bool TimeRange::isValidTime(){	//Checks for invalid inputs
	if((beginHour > endHour) || (beginHour == endHour && beginMinute > endMinute)){	//Checks if starting time is before ending time
		cout << "Error, the starting time must be before the ending time\n\n";
		return false;
		}
	else if((beginHour < 1) || (beginHour > 23) || (endHour < 1) || (endHour > 23)){	
		cout << "Invalid hour, please enter an hour between 1 & 23.\n\n";
		return false;
		}
	else if(((beginMinute < 0) || (beginMinute > 59)) || (endMinute < 0) || (endMinute > 59)){
		cout << "Invalid minute, please enter a minute between 0 & 59 that is also an hour or half-hour booking.\n\n";
		return false;
		}
	else if(((beginMinute % 30) != 0) || ((endMinute % 30) != 0)){
		cout << "Invalid minute, please book by the hour/half-hour, in multiples of 30.\n\n";
		return false;
		}
	else {return true;}
}

void TimeRange::inputTime(){	//Takes user input
		cout << "Beginning hour: "; cin >> beginHour;
		cout << "Beginning minute: "; cin >> beginMinute;
		cout << "End hour: "; cin >> endHour;
		cout << "End minute: "; cin >> endMinute;
		isValidTime();
}
void TimeRange::outputTime(){	//Outputs time range
	cout << "The time range is: " << setw(2) << setfill('0') << beginHour << ":" << setw(2) << setfill('0') << beginMinute << "-" << setw(2) << setfill('0') << endHour << ":" << setw(2) << setfill('0') << endMinute << endl;
    cout << "beginHour: " << setw(2) << setfill('0') << beginHour << endl << "beginMinute: "<< setw(2) << setfill('0') << beginMinute << endl << "endHour: " << setw(2) << setfill('0') << endHour << endl << "endMinute: " << setw(2) << setfill('0') << endMinute << endl;
}

//Get functions
int TimeRange::getBeginHour() const{return beginHour;}

int TimeRange::getBeginMinute() const{return beginMinute;}

int TimeRange::getEndHour() const{return endHour;}

int TimeRange::getEndMinute() const{return endMinute;}

void TimeRange::setTime(int hr0, int min0, int hr1, int min1){	//Set function
	beginHour = hr0;
	beginMinute = min0;
	endHour = hr1;
	endMinute = min1;
}

bool TimeRange::totallyValid(){
	if (isValidTime() == true){return true;}

	else {return false;}
}
