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
#include <iostream>
#include <vector>
#include <sstream>

#include<iomanip>


class House;

class Review;

class Request;



class Member : public User {
private:
    std::string memberId;
    std::string fullName;
    std::string phoneNum;
    House *houseOwner;
    double credit;
    double score;
    std::string location;
    std::vector<Review *> tenantReviewList;
    std::vector<Request*> requestList;

public:

    Member(std::string username, std::string password, std::string memberID, std::string fullName, std::string phoneNum,
           double credit, double score, std::string location);


    bool acceptedRequest();

    bool addHouse(Date *startDate, Date *endDate, double consumingPointsPerDay, double minRating);

    bool deleteHouse();

    bool viewAllRequest();

    friend class System;

    friend class House;

    void showAccountInfo();

    double getRatingScore();

    bool minusCredit(int creditPoint);

    bool addCredit(int creditPoint);

    void showReview();

    bool createHouse(House *house);

    friend class System;



};


#endif //DAPDIXAYLAI_MEMBER_H
