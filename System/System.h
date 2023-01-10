//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_SYSTEM_H
#define DAPDIXAYLAI_SYSTEM_H



#define ADMIN_FILE "Data/admin.dat"
#define HOUSE_FILE "Data/house.dat"
#define HOUSE_LIST_FILE "Data/houseList.dat"
#define REQUEST_FILE "Data/request.dat"
#define RATING_HOUSE_FILE "Data/ratingHouse.dat"
#define RATING_TENANT_FILE "Data/ratingTenant.dat"
#define OCCUPIERS_FILE "Data/occupiers.dat"
#define MEMBERS_FILE "Data/members.dat"



#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <fstream>
#include "../Class/Member/Member.h"
#include "../Class/House/House.h"
#include "../Class/Admin/Admin.h"

#include "../Class/Date/Date.h"



const std::string LOCATIONS[3] = {"HANOI", "HUE", "SAIGON"};
const int INITIAL_CREDITS = 500;
const int INITIAL_SCORES = 10;
const int DAYS_IN_MONTHS[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const std::string STATUS = {"AVAILABLE", "UNAVAILABLE"};
const std::string RE_STATUS = {"PENDING", "ACCEPTED", "DECLINED"};

class House;
class Member;
class Admin;
class Date;
class User;
class System {
public:
    std::vector<Member *> memberVector;
    Admin* admin;
    std::vector<House* >houseVector;
    Member* currentUser;
    House* currentUserHouse;
    std::vector<House *> memberSuitableHouseList;

    System();

    std::string trimString(std::string &str);
    std::vector<std::string> splitStr(std::string &str, char del);
    bool isValidNum(std::string &inputStr);
    bool isDouble(std::string &inputStr);
    bool isValidPhoneNum(std::string &phoneNum);
    bool isValidPassword(std::string &password);
    bool isValidUserName(std::string &username);
    bool isValidFullname(std::string &fullname);
    bool isValidCredit(Member* mem, House* house);
    bool isValidScore(Member *mem, House *house);
    bool isValidDate(std::string date);
    int menuChoice(int start, int end);

    void guestShowHouse();
    void mainMenu();
    void guestMenu();
    void memberMenu();
    void houseForRentMenu();
    bool getInfoListHouseMenu();
    bool enterHouseInfo();
    void validHouseMenu(Date *start, Date *end, std::string location);
    void searchValidHouseMenu();

    bool isValidHouses(Date *start, Date *end, Member *mem, House *house, std::string location);
    bool getValidHouses(Date *start, Date *end, std::string location);
    bool deleteInRentHouse();


    void inputHouseToSys();
    void inputMemHouseToSys();
    void inputHouseLstToSys();
    void inputMemberToSys();
    void inputRatingTenantToSys();
    void inputRatingHouseToSys();
    void inputRequestToSys();
    void inputOccupierToSys();
    void inputUnratedToSys();
    void outputOccupierToFile();
    void outputUnratedToFile();
    void outputRequestToFile();
    void outputRatingTenantToFile();
    void outputRatingHouseToFile();
    void outputHouseToFile();
    void outputHouseLstToFile();
    void outputMemberToFile();


    void registerMember();
    bool loginMember();
    Date *stringToDate(std::string &date);






};


#endif //DAPDIXAYLAI_SYSTEM_H
