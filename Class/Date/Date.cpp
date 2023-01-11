
#include "Date.h"
//#include "../../System/System.h"
#include "../../define.h"
Date :: Date(int date, int month, int year) {
    this->date = date;
    this->month = month;
    this->year = year;
}



int Date:: countLeapYear() {
    int currentYear = year;
    if(month < 2) {
        currentYear--;
    }

    int leapYear = currentYear / 4 - currentYear / 100 + currentYear / 400;
    return leapYear;
}
int Date::countDate() {
    int totalDays = year * 365 + date;

    for(int i = 0; i < month - 1; i++) {
        totalDays = totalDays + DAYS_IN_MONTHS[i];
    }

    totalDays = totalDays + countLeapYear();
    return totalDays;
}

bool Date::operator < (Date &date2) {

    return  countDate() - date2.countDate() >= 0;
}

int Date::operator - (Date &date2) {
    // Get the difference between two dates
    return countDate() - date2.countDate();
}

std::string Date ::convertDatetoString() {
    std::stringstream ss;
    ss << date << "/" << month << "/" << year;
    return ss.str();
}

