//
// Created by Vo Nguyen Kien on 09/01/2023.
//

#ifndef DAPDIXAYLAI_HOUSE_H
#define DAPDIXAYLAI_HOUSE_H
#include <iostream>
#include "../Member/Member.h"

using std::string;
using std::vector;
class House {
private:
    Member *owner;
    string houseId;
    string description;
    string status;
    int consumingPoint;
    int minScore;
public:
    void showInfo();


};
#endif //DAPDIXAYLAI_HOUSE_H
