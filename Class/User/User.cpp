//
// Created by Trung Ngo on 09/01/2023.
//

#include "User.h"

#include <utility>

User::User(std::string username, std::string password) {
    this->username = std::move(username);
    this->password = std::move(password);
}

