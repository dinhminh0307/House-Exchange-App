//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_MEMBER_H
#define DAPDIXAYLAI_MEMBER_H

#include "../User/User.h"


#include "../House/House.h"
#include "../Request/Request.h"



#include "../OccupyHouse/OccupyHouse.h"
#include "../../System/System.h"

#include "../Review/Review.h"

// #include "../../System/System.h"


#include "../Tenant/Tenant.h"

#include <iostream>
#include <vector>
#include <sstream>

#include<iomanip>

class OccupyHouse;

class Tenant;

class System;

class House;

class Review;

class Request;

class Date;


class Member : public User {
private:

    std::string memberId;
    std::string fullName;
    std::string phoneNum;
    House *houseOwner;
    double credit;
    double score;
    std::string location;
    std::vector<Review *> tenantReviewList; //review cua owner
    std::vector<Request *> requestList; // Request da sent
    std::vector<Tenant *> tenantList; // list house ma minh da thue



public:

    Member(std::string username, std::string password, std::string memberID, std::string fullName, std::string phoneNum,
           double credit, double score, std::string location);


    bool addHouse(Date *startDate, Date *endDate, int consumingPointsPerDay, double scores, std::string status);


    bool deleteHouse();

    int viewAllRequest();

    bool cancelRequest(int ID);


    void showAccountInfo();

    double getRatingScore();

    bool minusCredit(double creditPoint);

    bool addCredit(double creditPoint);

    bool createHouse(House *house);

    void showAllAvailableHouse();

    bool acceptRequest(int ID);

    bool declineRequest(int ID);


    void reviewHouse(House *occupyHouse, int score, std::string comment);

    bool showRequestSent();

    void viewTenant();

    bool reviewTenant(int rateId, int score, std::string comment);


    bool showReview();

    bool checkout(int leaveId);

    bool viewMemberOccupyList();

    bool viewUnratedList();


    void tenantLeaveHouse();

    void getHouseIndex(int houseID);

    ~Member();

    friend class House;

    friend class System;

};


#endif //DAPDIXAYLAI_MEMBER_H
