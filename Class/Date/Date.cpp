
#include "Date.h"
//#include "../../System/System.h"
#include "../../define.h"
Date :: Date(int date, int month, int year) {
    this->date = date;
    this->month = month;
    this->year = year;
}

int Date::countDate() {
    int totalDays = year * 365 + date;

    for(int i = 0; i < month - 1; i++) {
        totalDays = totalDays + DAYS_IN_MONTHS[i];
    }

    totalDays = totalDays + countLeapYear();
    return totalDays;
}

int Date:: countLeapYear() {
    int currentYear = year;
    if(month <= 1) {
        currentYear--;
    }

    int leapYear = currentYear / 4 - currentYear / 100 + currentYear / 400;
    return leapYear;
}

bool Date::operator < (Date &date2) {
    if(countDate() - date2.countDate() <= 0) {
        return true;
    }
    else return false;
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

