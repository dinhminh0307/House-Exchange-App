//
// Created by Vo Nguyen Kien on 10/01/2023.
//

#ifndef DAPDIXAYLAI_OCCUPYHOUSE_H
#define DAPDIXAYLAI_OCCUPYHOUSE_H

class Date;

class Member;

class OccupyHouse {
private:
    Date *startFromDate;
    Date *toDate;
    Member *tenant;
public:
    OccupyHouse(Date *startFromDate, Date *toDate, Member *tenant);

    friend class System;

    friend class House;

    friend class Member;

};
#endif //DAPDIXAYLAI_OCCUPYHOUSE_H
