//header file calendar.hpp to declare your class
#ifndef CALENDAR_HPP
#define CALENDAR_HPP
#include "time.hpp"
#include "date.hpp"

class Calendar{
    public:
    Calendar();
    Calendar(int c);
    //~Calendar();

    bool book(Date date, TimeRange time);
    bool query(Date date, TimeRange time);
    bool del(Date date, TimeRange time);

    int getCalendarDay(Date date) const;
    int getCalendarBeginTime(TimeRange time) const;
    int getCalendarEndTime(TimeRange time) const;
    void setCalendar(int calendarDay, Date date);
    void printEveryDay();
    void setEveryDay();

    private:
    //bool app[48];
    Date *slot[103];
    int calendayDay;
    int calendayStart;
    int calendarEnd;
};

#endif
