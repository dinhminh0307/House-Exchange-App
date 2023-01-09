//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_MEMBER_H
#define DAPDIXAYLAI_MEMBER_H
#include "../User/User.h"
#include "../System/System.h"
#include "../House/House.h"
#include "../Review/Review.h"
#include <iostream>
#include <vector>
using std::string;
using std::vector;

class House;
class Review;

class Admin : public User {
private:
    string fullName;
    vector<Review *> memberReviewList;

public:
    Admin::Admin(std::string username, std::string password, std::string fullName, std::string phoneNum);

    friend class System;
    friend class House;
    void showAccountInfo();
    void adminShowAllMember();
    void adminViewMemberDetail();
    void adminSortByMemberScore();
    void adminShowAllHouse();
    void adminViewHouseDetail(int id);
    void adminSearchHouseById();
    void adminSearchHouseByDateRange(string dateRange);
    void adminSearchHouseByCredit(int credit);
    void adminViewAllReQuest();
};

#endif //DAPDIXAYLAI_MEMBER_H