#include "Date.h"

Date :: Date(int date, int month, int year) {
    this->date = date;
    this->month = month;
    this->year = year;
}

int Date::countDate() {
    int totalDays = year * 365 + date;

    for(int i = 0; i < month - 1; i++) {
        totalDays = totalDays + daysOfMonth[i];
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


string Date ::convertDatetoString() {
    std::stringstream ss;
    ss << date << "/" << month << "/" << year;
}