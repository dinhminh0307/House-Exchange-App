
#include "Request.h"

Request::Request(Date *requestFromDate, Date *requestToDate, Member *requestedByMember, std::string status) {
    //Note: need a function from system to get id of request
    this->requestFromDate = requestFromDate;
    this->requestToDate = requestToDate;
    this->requestedByMember = requestedByMember;
    this->requestStatus = status;
}

