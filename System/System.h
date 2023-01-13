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
#define UNRATED_OCC_FILE "Data/unratedOcc.dat"
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <fstream>
#include <iomanip>
//#include "../Class/Member/Member.h"
#include "../Class/Admin/Admin.h"

#include "../Class/House/House.h"
#include "../Class/Date/Date.h"
#include "../Class/OccupyHouse/OccupyHouse.h"
#include "../Class/Tenant/Tenant.h"
#include "../Class/Review/Review.h"
#include "../Class/Request/Request.h"
#include "../define.h"
//#include "../Class/Admin/Admin.h"
class Admin;


class House;

class Member;

class Date;

class User;

class System {
public:
    std::vector<Member *> memberVector;


    Admin *admin;
    std::vector<House *> houseVector;
    Member *currentUser = nullptr;
    House *currentUserHouse;
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

    bool isValidCredit(Member *mem, House *house);

    bool isValidScore(Member *mem, House *house);

    bool isValidDate(std::string date);

    bool isRightDateOrder(Date* start, Date *end);

    int menuChoice(int start, int end);

    void guestShowHouse();

    void mainMenu();

    void guestMenu();

    void adminMenu();

    void adminLoginMenu();

    void showRequestSent();

    void adminViewMemberMenu();

    void adminViewHouseMenu();

    void loginMemMenu();
    void memberMenu();

    void houseForRentMenu();

    void rateTenantMenu(int leaveID);

    bool getInfoListHouseMenu();

    bool enterHouseInfo();

    void validHouseMenu(Date *start, Date *end, std::string location);

    void searchValidHouseMenu();
    bool memRequestHouse(Date *startDate, Date *endDate, int houseId);
    void viewRequestMenu();
    void actionRequestMenu(int requestID);
    void showRentedHouse();

    void cancelRequestMenu(int ID);
    void showReview();

    void viewUnratedTenantList();

    bool isValidStartHouses(Date *start, Member *mem, House *house, std::string location);

    bool isValidEndHouses(Date *end, Member *mem, House *house, std::string location);


    bool getValidStartHouses(Date *start, std::string location);
    bool getValidEndHouses(Date *end, std::string location);


    bool deleteInRentHouse();

    void inputHouseToSys();

    void inputAdminToSys();

    void inputMemHouseToSys();

    void inputHouseLstToSys();

    void inputMemberToSys();

    void inputRatingTenantToSys();

    void inputRatingHouseToSys();

    void inputRequestToSys();

    void inputOccupierToSys();

    void inputUnratedToSys();

    void outputOccupierToFile();

    void outputAdminToFile();

    void outputUnratedToFile();

    void outputRequestToFile();

    void outputRatingTenantToFile();

    void outputRatingHouseToFile();

    void outputHouseToFile();

    void outputHouseLstToFile();

    void outputMemberToFile();

    void registerMember();

    bool loginMember(std::string username, std::string password);

    Date *stringToDate(std::string &date);


};


#endif //DAPDIXAYLAI_SYSTEM_H
