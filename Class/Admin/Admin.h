//
// Created by Vo Nguyen Kien on 11/01/2023.
//

#ifndef DAPDIXAYLAI_ADMIN_H
#define DAPDIXAYLAI_ADMIN_H

#endif //DAPDIXAYLAI_ADMIN_H
#include <iostream>
#include "../User/User.h"


class Admin : public User {
public:
    Admin(std::string username, std::string password);

    friend class System;

    friend class House;
};