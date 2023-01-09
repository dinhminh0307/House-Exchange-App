//
// Created by Vo Nguyen Kien on 09/01/2023.
//

#ifndef DAPDIXAYLAI_HOUSE_H
#define DAPDIXAYLAI_HOUSE_H
#include <iostream>
#include "./Date/Date.h"
#include "./Request/Request.h"

class House {
    string houseID;
    std::string location;
    std::string houseDescription;
    string houseStatus;
    Member* houseOwner;

    bool isAdded;
    Date *startingDate;
    Date *endingDate;
    int consumingPointsPerDay;
    double minOccupierRating;

    std::vector<Review*> listHouseReview;

    std::vector<Request*> listHouseRequest;

    // std::vector<HouseOccupy*> houseOccupyList;

    // std::vector<HouseOccupy*> unratedOccupierList;

public:
    House(string houseID, std::string location,  std::string houseDescription, string houseStatus);

    std::string getCityName();

    std::string getHouseAddress();

    double getRatingScore();

    bool addRequestToHouseRequestList(Request *request);

    bool removeRequestFromHouseRequestList(Request *request);

//    bool removeOccupyFromHouseOccupyList(Date *occupyFromDate, Date *occupyToDate, Member *occupiedByMember);

    bool addReviewToHouseReviewList(Review *houseReview);

    // bool addOccupierToUnratedOccupierList(HouseOccupy *houseOccupier);

    // bool removeOccupierFromUnratedOccupierList(HouseOccupy *houseOccupier);

    std::string viewHouseInfo();


    std::string viewHouseReview();

    std::string viewHouseInfoByGuest();

    ~House();

    friend class Member;

    friend class System;

    friend class InputStorageManager;

    friend class OutputStorageManager;
};
#endif //DAPDIXAYLAI_HOUSE_H
