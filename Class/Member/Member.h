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
#include <sstream>
using std::string;
using std::vector;
class House;
class Review;

class Member : public User {
private:
    string memberId;
    string fullName;
    string phoneNum;
    House *ownedHouse;
    int credit;
    int score;
    string location;
    vector<Review *> memberReviewList;


public:
    Member(string username, string password, string memberID, string fullName, string phoneNum,
           double credit, int score, string location);

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
