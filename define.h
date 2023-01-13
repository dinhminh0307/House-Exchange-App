//
// Created by Vo Nguyen Kien on 11/01/2023.
//

#ifndef DAPDIXAYLAI_DEFINE_H
#define DAPDIXAYLAI_DEFINE_H
#include <iostream>

const std::string RED = "\033[0;31m";
const std::string GREEN = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string BLUE = "\033[0;34m";
const std::string MAGENTA = "\033[0;35m";
const std::string CYAN = "\033[0;36m";
const std::string WHITE = "\033[0;37m";
const std::string RESET = "\033[0m";

const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";
const std::string REVERSE = "\033[7m";
const std::string HIDDEN = "\033[8m";

const std::string BLACK = "\033[30m";

const std::string LOCATIONS[3] = {"HANOI", "HUE", "SAIGON"};
const int INITIAL_CREDITS = 500;
const int INITIAL_SCORES = 10;
const int DAYS_IN_MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::string STATUS[] = {"AVAILABLE", "UNAVAILABLE"};
const std::string RE_STATUS[] = {"PENDING", "ACCEPTED", "DECLINED"};
#endif //DAPDIXAYLAI_DEFINE_H
