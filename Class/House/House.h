//
// Created by Vo Nguyen Kien on 09/01/2023.
//

#ifndef DAPDIXAYLAI_HOUSE_H
#define DAPDIXAYLAI_HOUSE_H
#include <iostream>
#include "../Member/Member.h"
#include "../Date/Date.h"
#include "../Request/Request.h"

using std::string;
using std::vector;
class House {

    string houseID;
    std::string location;
    std::string houseDescription;
    string houseStatus;
    Member* owner;

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

    void showInfo();

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

};
#endif //DAPDIXAYLAI_HOUSE_H
