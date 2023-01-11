
#include "Date.h"
//#include "../../System/System.h"
#include "../../define.h"
Date :: Date(int date, int month, int year) {
    this->date = date;
    this->month = month;
    this->year = year;
}



int Date:: countLeapYear() {
    int currentYear = this->year;
    if(this->month <= 2) {
        currentYear--;
    }

    int leapYear = currentYear / 4 - currentYear / 100 + currentYear / 400;
    return leapYear;
}

int Date::countDate() {
    int totalDays = this->year * 365 + this->date;

    for(int i = 0; i < this->month - 1; i++) {
        totalDays = totalDays + DAYS_IN_MONTHS[i];
    }

    totalDays = totalDays + this->countLeapYear();
    return totalDays;
}

bool Date::operator < (Date &date2) {

    return  countDate() - date2.countDate() >= 0;
}

int Date::operator - (Date &date2) {
    // Get the difference between two dates
    std::cout << this->countDate() << "\n";
    std::cout << date2.countDate() << "\n";

    return this->countDate() - date2.countDate();
}

std::string Date ::convertDatetoString() {
    std::stringstream ss;
    ss << date << "/" << month << "/" << year;
    return ss.str();
}

