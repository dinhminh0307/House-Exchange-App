//
// Created by Trung Ngo on 09/01/2023.
//

#include "Admin.h"


Admin::Admin( std::string username, std::string password) : User( std::move(username), std::move(password)) {}