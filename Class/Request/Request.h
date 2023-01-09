#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include "./Date/Date.h"
#include "./Member/Member.h"
class Date;
class Member;

class Request {
    string requestID;
    string houseID;
    string requestStatus;
    Date* requestFromDate;
    Date* requestToDate;
    Member* requestedByMember;

public:
    Request(string reuqestID, Date *requestFromDate, Date *requestToDate, Member *requestedByMember);

    friend class System;

    friend class Member;

    friend class OutputStorageManager;
};

#endif


