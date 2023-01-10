//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_USER_H
#define DAPDIXAYLAI_USER_H



//#include "../../System/System.h"


#include <iostream>

class System;

class User {
protected:
    std::string username;
    std::string password;

public:
    User(std::string username, std::string password);

    friend class System;

};


#endif //DAPDIXAYLAI_USER_H
