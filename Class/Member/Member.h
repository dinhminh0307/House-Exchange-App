//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_MEMBER_H
#define DAPDIXAYLAI_MEMBER_H

#include "../User/User.h"
#include "../House/House.h"

class House;

class Member: public User {
private:
    std::string memberId;
    std::string fullName;
    std::string phoneNum;
    House *ownedHouse;
    std::string location;
    double credit;
    double score;
public:
    Member(std::string memId, std::string fName, std::string phoneNum,std::string username, std::string password, std::string location, double credits, double scores);
    friend class System;
};


#endif //DAPDIXAYLAI_MEMBER_H
