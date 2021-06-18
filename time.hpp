//header file time.hpp to declare your class
#ifndef TIME_HPP
#define TIME_HPP

class TimeRange {
	public:
	TimeRange();
	//~TimeRange();
	TimeRange(int hr0, int min0, int hr1, int min1);
	void inputTime();
	void outputTime();
	void setTime(int hr0, int min0, int hr1, int min1);

	int getBeginHour() const;
	int getBeginMinute() const;
	int getEndHour() const;
	int getEndMinute() const;
	bool totallyValid();

	private:
	bool isValidTime();
	int beginHour;
	int beginMinute;
	int endHour;
	int endMinute;
};
#endif
