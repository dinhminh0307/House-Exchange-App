//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_MEMBER_H
#define DAPDIXAYLAI_MEMBER_H
#include "../User/User.h"
#include "../System/System.h"
#include "../House/House.h"
#include "../Review/Review.h"
#include "../Request/Request.h"
#include <iostream>
#include <vector>
#include <sstream>

#include<iomanip>

using std::string;
using std::vector;
class House;
class Review;
class Request;
class User;
class Member : public User {
private:
    string memberId;
    string fullName;
    string phoneNum;
    House *houseOwner;
    int credit;
    int score;
    string location;
    vector<Review *> tenantReviewList;


public:

    Member(string username, string password, string memberID, string fullName, string phoneNum,
           double credit, int score, string location);


    bool acceptedRequest();
    bool addHouse(Date *startDate, Date *endDate, int consumingPointsPerDay);
    bool deleteHouse();
    bool viewAllRequest();
    friend class System;
    friend class House;
    void showAccountInfo();
    double getRatingScore();
    bool minusCredit(int creditPoint);
    bool addCredit(int creditPoint);
    string showReview();
    bool createHouse(House *house);

};


#endif //DAPDIXAYLAI_MEMBER_H
