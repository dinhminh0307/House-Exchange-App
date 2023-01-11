// Created by Vo Nguyen Kien on 09/01/2023.


#ifndef DAPDIXAYLAI_HOUSE_H
#define DAPDIXAYLAI_HOUSE_H

#include "../Review/Review.h"

#include "../Member/Member.h"
#include "../Request/Request.h"
#include "../OccupyHouse/OccupyHouse.h"

#include "../Date/Date.h"

#include <iostream>

#include <vector>

class Member;

class Review;

class Date;

class Request;

class OccupyHouse;

class House {
private:

    std::string houseID;
    std::string location;
    std::string houseDescription;
    std::string houseStatus;

    Member *owner;


    bool isAdded;
    Date *startingDate;
    Date *endingDate;
    double consumingPointsPerDay;
    double minRating;
    double houseScores;

    std::vector<Review *> listHouseReview;

    std::vector<Request *> listHouseRequest;

    std::vector<OccupyHouse*> listOccupyHouse;

    std::vector<OccupyHouse *> unratedTenant;


public:

    House(std::string houseID, std::string location, std::string houseDescription);


    double getRatingScore();

    void addRequestToHouseRequestList(Request *request);

    bool removeRequestFromHouseRequestList(Request *request);


    void addReviewToHouseReviewList(Review *review);


    void viewHouseInfo();


    void viewHouseReview();

    std::string viewHouseInfoByGuest();
    

    ~House();

    friend class Member;

    friend class System;

};


#endif //DAPDIXAYLAI_HOUSE_H
