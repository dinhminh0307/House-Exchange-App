//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_MEMBER_H
#define DAPDIXAYLAI_MEMBER_H
#include "../User/User.h"
#include "../../System/System.h"
#include "../House/House.h"
#include "../Review/Review.h"
#include "../Request/Request.h"
#include "../Tenant/Tenant.h"
#include <iostream>
#include <vector>
#include <sstream>

#include<iomanip>
#include <iostream>


class House;
class Review;
class Request;
class User;

class Member : public User {
    private:
    std::string memberId;
    std::string fullName;
    std::string phoneNum;
    House *houseOwner;
    int credit;
    int score;
    std::string location;
    std::vector<Review *> tenantReviewList;
    

public:

    Member(std::string username, std::string password, std::string memberID, std::string fullName, std::string phoneNum,
           double credit, int score, std::string location);


    bool acceptedRequest();
    bool addHouse(Date *startDate, Date *endDate, int consumingPointsPerDay, string description);
    bool deleteHouse();
    bool viewAllRequest();
    friend class System;
    friend class House;
    void showAccountInfo();
    double getRatingScore();
    bool minusCredit(int creditPoint);
    bool addCredit(int creditPoint);
    std::string showReview();
    bool createHouse(House *house);
    int requestHouse();
    void showAllAvailableHouse();
    bool acceptRequest(std::string requestID);
    bool declineRequest(std::string requestID);
};


#endif //DAPDIXAYLAI_MEMBER_H
