#include <iostream>
#include <iomanip>
#include <math.h>
#include "time.hpp"
#include "date.hpp"
#include "calendar.hpp"
using namespace std;
/*
void nvaderZim(){
    cout << "Help\n";
	int x, y;
    cout << "Enter month: ";
	cin >> x;
    cout << "Enter day: ";
	cin >> y;
	Date tempDate(x, y);
}*/

int main(){
    cout << "HELP\n";
    Calendar cal(103);
    cout << "HELP1\n";
    cal.printEveryDay();
}
