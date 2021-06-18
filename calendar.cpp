//calendar.cpp to implement your class
#include <iostream>
#include <math.h>
#include <iomanip>
#include "date.hpp"
#include "time.hpp"
#include "calendar.hpp"
using namespace std;

Calendar::Calendar(){
        for (int j = 0; j < 103; j++){
                for (int i = 0; i < 48; j++) {
                        //slot[j].getAppointed() = false;
                        //cout << slot[i].app[j];
                }
                //cout << endl;
        }
}
Calendar::Calendar(int c){
        for (int j = 0; j < c; j++){
                for (int i = 0; i < 48; j++) {
                        //slot[j]->appointed[i] = false;
                        //cout << slot[i].app[j];
                }
                //cout << endl;
        }
}

int Calendar::getCalendarDay(Date date) const{
        int monthValue;
        int calendarDay;
        if (date.getMonth() == 9){
                monthValue = 0;
        }
        else if (date.getMonth() == 10) {
                monthValue = 22;
        }
        else if (date.getMonth() == 11) {
                monthValue = 53;
        }
        else if (date.getMonth() == 12) {
                monthValue = 83;
        }
        else {
                cout << "Error, invalid month\n";
                return 0;
        }
        calendarDay = monthValue + (date.getDay() - 1);
        return calendarDay;
}
int Calendar::getCalendarBeginTime(TimeRange time) const{
        int hourValue;
        int minuteValue;
        int calendarBeginTime;
        if (time.getBeginMinute() == 0){
                minuteValue = 0;
        }
        else if (time.getBeginMinute() == 30){
                minuteValue = 1;
        }
        else {
                cout << "Error, invalid minute\n";
                return 0;
        }
        hourValue = time.getBeginHour() * 2;
        calendarBeginTime = hourValue + minuteValue;
        return calendarBeginTime;
}
int Calendar::getCalendarEndTime(TimeRange time) const{
        int hourValue;
        int minuteValue;
        int calendarEndTime;
        if (time.getEndMinute() == 0){
                minuteValue = 0;
        }
        else if (time.getEndMinute() == 30){
                minuteValue = 1;
        }
        else {
                cout << "Error, invalid minute\n";
                return 0;
        }
        hourValue = time.getEndHour() * 2;
        calendarEndTime = hourValue + minuteValue;
        return calendarEndTime;
}
void Calendar::setCalendar(int calendarDay, Date date) {
        if (calendarDay > 83) {
                date.setDate(12, (calendarDay - 83));
        }
        else if (calendarDay > 53) {
                date.setDate(11, (calendarDay - 53));
        }
        else if (calendarDay > 22) {
                date.setDate(10, (calendarDay - 23));
        }
        else if (calendarDay > -1) {
                date.setDate(9, (calendarDay + 1));
        }
        else {
                cout << "Error\n";
        }
}

bool Calendar::book(Date date, TimeRange time){
         do{
                cout << "Enter the date you wish to book.\n";
                date.inputDate();
        } while (date.totallyValid() == false);
        do {
                cout << "Enter the time slot you wish to book in multiples of 30, eg. 11:0 to 12:30\n";
                time.inputTime();
        } while (time.totallyValid() == false);
        
        if (date.totallyValid() == false || time.totallyValid() == false){
                return false;
        }
        else {/*
                int calendarDay = getCalendarDay(date);
                int calendarStart = getCalendarBeginTime(time);
                int calendarEnd = getCalendarEndTime(time);
                for (int i = calendarStart; i < calendarEnd; i++){
                        if (slot[calendarDay]->getAppointed() == true){
                                cout << "Sorry, the time frame is already booked";
                                return false;
                        }
                        else {
                        slot[calendarDay]->getAppointed() == true;
                        }

                }
                for (int i = 0; i < 48; i++){
                        if (slot[calendarDay]->getAppointed() == false){
                                cout << slot[calendarDay]->appointed[i];
                        }
                }
                return true;*/
                for (int i = 0; i < 48; i++){
                        if(date.appointed[i] == true){
                                cout << "Selected time slot is already booked.\n";
                                return false;
                        }
                        else {date.appointed[i] = true;}
                }
        }
}

bool Calendar::query(Date date, TimeRange time){
        do{
                cout << "Enter the date you wish to book.\n";
                date.inputDate();
        } while (date.totallyValid() == false);
        do {
                cout << "Enter the time slot you wish to book in multiples of 30, eg. 11:0 to 12:30\n";
                time.inputTime();
        } while (time.totallyValid() == false);

        if (date.totallyValid() == false || time.totallyValid() == false){
                return false;
        }
        else {
                int bookedCounter = 0;
                int calendarDay = getCalendarDay(date);
                int calendarStart = getCalendarBeginTime(time);
                int calendarEnd = getCalendarEndTime(time);
                for (int i = calendarStart; i < calendarEnd; i++){
                        if (slot[calendarDay]->getAppointed() == true){
                                bookedCounter++;
                        }
                }
                if (bookedCounter == (calendarEnd - calendarStart)){
                        cout << "Sorry, the entire time range is booked\n";
                }
                else if (bookedCounter > 0){
                        cout << "The time range is partially booked\n";
                }
                else if (bookedCounter == 0){
                        cout << "The entire time range is available\n";
                }
                else {
                        cout << "An error occured while querying the calendar\n";
                }
                return true;
        }

}

bool Calendar::del(Date date, TimeRange time){
        do{
                cout << "Enter the date you wish to book.\n";
                date.inputDate();
        } while (date.totallyValid() == false);
        do {
                cout << "Enter the time slot you wish to book in multiples of 30, eg. 11:0 to 12:30\n";
                time.inputTime();
        } while (time.totallyValid() == false);

        if (date.totallyValid() == false || time.totallyValid() == false){
                return false;
        }
        else {
                int calendarDay = getCalendarDay(date);
                int calendarStart = getCalendarBeginTime(time);
                int calendarEnd = getCalendarEndTime(time);
                for (int i = calendarStart; i < calendarEnd; i++){
                        if (slot[calendarDay]->getAppointed() == true){
                                slot[calendarDay]->appointed[i] = false;
                        }
                }
                return true;
        }
}

void Calendar::printEveryDay(){
        for(int j; j < 103; j++){
                slot[j]->printFreeTimeSlots();
        }
}
/*
void Calendar::setEveryDay(){
        for(int j; j < 103; j++){
                Date *date = new Date();
                slot[j] *appointed[48];
                slot[j]->getAppointed() == false;
        }
}*/
