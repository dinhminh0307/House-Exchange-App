//
// Created by Vo Nguyen Kien on 09/01/2023.
//

#ifndef DAPDIXAYLAI_REVIEW_H
#define DAPDIXAYLAI_REVIEW_H
#include <iostream>
//#include "../Member/Member.h"
//#include "../House/House.h"

class House;
class Member;
class Review {
private:
    double ratingScore;
    std::string comment;
    Member *memberReview;
public:
    Review(double ratingScore, std::string comment, Member *memberReview);
    friend class Member;
    friend class House;
    friend class System;
};


#endif //DAPDIXAYLAI_REVIEW_H
