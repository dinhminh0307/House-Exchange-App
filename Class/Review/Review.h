//
// Created by Vo Nguyen Kien on 09/01/2023.
//

#ifndef DAPDIXAYLAI_REVIEW_H
#define DAPDIXAYLAI_REVIEW_H
#include <iostream>
#include "../Member/Member.h"
#include "../House/House.h"
using std::string;
class House;
class Member;
class Review {
private:
    int ratingScore;
    string comment;
    Member *memberReview;
public:
    Review(int ratingScore, string comment, Member *memberReview);
    friend class Member;
    friend class House;
};


#endif //DAPDIXAYLAI_REVIEW_H
