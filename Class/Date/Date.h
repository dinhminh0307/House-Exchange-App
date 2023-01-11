#ifndef DAPDIXAYLAI_DATE_H
#define DAPDIXAYLAI_DATE_H
#include <iostream>
#include <sstream>
#define SIZE 50


class Date {
    private:
        int date;
        int month;
        int year;
    public:
        Date();
        Date(int date, int month, int year);
        int getDay();
        int countLeapYear();
        int countDate();
        bool operator < (Date &date2);
        int operator - (Date &date2);
        std::string convertDatetoString();
        friend class System;
};
#endif

