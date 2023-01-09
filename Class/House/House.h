//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_HOUSE_H
#define DAPDIXAYLAI_HOUSE_H


#include "../Rating/Rating.h"
#include "../Member/Member.h"
#include "../User/User.h"
#include "../Request/Request.h"
#include "./../../System/System.h"

class Member;
class Rating;
class Request;


class House {
private:
    std::string houseId;
    std::string location;
    std::string description;
    double houseScores;
    double minCredits;
    double minScores;
    Member *owner;
    std::vector<Member *> occupiers;
    std::vector<Rating *> ratings;
    std::vector<Request *> requests;


public:
    friend class System;
};


#endif //DAPDIXAYLAI_HOUSE_H
