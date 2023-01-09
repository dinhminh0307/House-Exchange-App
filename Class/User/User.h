//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_USER_H
#define DAPDIXAYLAI_USER_H



#include "../../System/System.h"


#include <iostream>


class User {
protected:
    std::string username;
    std::string password;

public:
    User(std::string username, std::string password);

};


#endif //DAPDIXAYLAI_USER_H
