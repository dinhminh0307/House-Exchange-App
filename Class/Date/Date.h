#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>
#define SIZE 50
using std::string;
const int daysOfMonth[SIZE] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Date {
    private:
        int date;
        int month;
        int year;
    public:
        Date();
        Date(int date, int month, int year);
        int countLeapYear();
        int countDate();

        bool operator < (Date &date2);
        int operator - (Date &date2);
        string convertDatetoString();
        friend class System;
};
#endif