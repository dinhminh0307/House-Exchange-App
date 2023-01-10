
#include "Request.h"

Request::Request(std::string requestID, Date *startDate, Date *endDate, Member *requestedByMember) {


    //Note: need a function from system to get id of request

    this->startDate = startDate;
    this->endDate = endDate;
    this->requestedByMember = requestedByMember;
}

