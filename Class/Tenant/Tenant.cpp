//
// Created by Vo Nguyen Kien on 10/01/2023.
//

#include "Tenant.h"
Tenant::Tenant(Date *occupyFromDate, Date *occupyToDate, House *occupyHouse) {
    this->startFromDate = occupyFromDate;
    this->ToDate = occupyToDate;
    this->occupyHouse = occupyHouse;
}
