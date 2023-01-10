
#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include "../Date/Date.h"
#include "../Member/Member.h"


class Date;
class Member;

class Request {
    std::string houseID;
    std::string requestStatus;
    Date* requestFromDate;
    Date* requestToDate;
    Member* requestedByMember;

public:
    Request(Date *requestFromDate, Date *requestToDate, Member *requestedByMember, std::string status);

    friend class System;

    friend class Member;


};

#endif



