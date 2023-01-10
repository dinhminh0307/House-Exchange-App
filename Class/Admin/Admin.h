//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_MEMBER_H
#define DAPDIXAYLAI_MEMBER_H
#include "../User/User.h"
#include "../../System/System.h"
#include "../House/House.h"
#include "../Review/Review.h"
#include <iostream>

class User;
class House;
class Review;
class System;

class Admin : public User {

public:
    Admin(std::string username, std::string password);

    friend class System;
    friend class House;

};

#endif //DAPDIXAYLAI_MEMBER_H