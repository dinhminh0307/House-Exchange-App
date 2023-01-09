#include "Request.h"

Request::Request(std::string requestID, Date *requestFromDate, Date *requestToDate, Member *requestedByMember) {
    //Note: need a function from system to get id of request
    this->requestFromDate = requestFromDate;
    this->requestToDate = requestToDate;
    this->requestedByMember = requestedByMember;
}