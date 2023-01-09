//
// Created by Trung Ngo on 09/01/2023.
//

#ifndef DAPDIXAYLAI_USER_H
#define DAPDIXAYLAI_USER_H


#include "../../System/System.h"
#include <iostream>
using std::string;

class User {
protected:
    string username;
    string password;
public:
    User(string username, string password);
};


#endif //DAPDIXAYLAI_USER_H
