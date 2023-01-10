
//
// Created by Vo Nguyen Kien on 10/01/2023.
//

#ifndef DAPDIXAYLAI_TENANT_H
#define DAPDIXAYLAI_TENANT_H
class Date;
class House;

class Tenant {
    Date *startFromDate;
    Date *ToDate;
    House *occupyHouse;

public:
   Tenant(Date *occupyFromDate, Date *occupyToDate, House *occupyHouse);

    friend class Member;

    friend class House;

    friend class System;


};
#endif //DAPDIXAYLAI_TENANT_H
