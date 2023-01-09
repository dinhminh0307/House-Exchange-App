
#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include "../Date/Date.h"
#include "../Member/Member.h"

class Date;
class Member;

class Request {
    std::string requestID;
    std::string houseID;
    std::string requestStatus;
    Date* startDate;
    Date* endDate;
    Member* requestedByMember;

public:
    Request(std::string reuqestID, Date *startDate, Date *endDate, Member *requestedByMember);


    friend class System;

    friend class Member;


};

#endif



