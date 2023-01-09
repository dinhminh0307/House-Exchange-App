// Created by Vo Nguyen Kien on 09/01/2023.


#ifndef DAPDIXAYLAI_HOUSE_H
#define DAPDIXAYLAI_HOUSE_H

#include <iostream>

#include <vector>

class Member;

class Review;

class Date;

class Request;

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
    int consumingPointsPerDay;
    double minRating;

    std::vector<Review *> listHouseReview;

    std::vector<Request *> listHouseRequest;

    // std::vector<HouseOccupy*> houseOccupyList;

    // std::vector<HouseOccupy*> unratedOccupierList;

public:

    House(std::string houseID, std::string location, std::string houseDescription);


    double getRatingScore();

    void addRequestToHouseRequestList(Request *request);

    bool removeRequestFromHouseRequestList(Request *request);


    void addReviewToHouseReviewList(Review *houseReview);


    void viewHouseInfo();


    void viewHouseReview();

    std::string viewHouseInfoByGuest();

    ~House();

    friend class Member;

    friend class System;

};


#endif //DAPDIXAYLAI_HOUSE_H
