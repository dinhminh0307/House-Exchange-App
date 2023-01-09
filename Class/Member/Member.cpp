//
// Created by Trung Ngo on 09/01/2023.
//

#include "Member.h"


#include "../House/House.h"

#include <utility>

Member::Member(std::string memId, std::string fName, std::string phoneNum, std::string username, std::string password, std::string location, double credits, double scores) :
    User(std::move(username), std::move(password)) {
    this->memberId = std::move(memId);
    this->fullName = std::move(fName);
    this->phoneNum = std::move(phoneNum);
    this->location = std::move(location);
    this->ownedHouse = nullptr;
    this->credit = credits;
    this->score = scores;
}