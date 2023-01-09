
#include "Request.h"

<<<<<<< HEAD
Request::Request(string requestID, Date *startDate, Date *endDate, Member *requestedByMember) {
=======
Request::Request(std::string requestID, Date *requestFromDate, Date *requestToDate, Member *requestedByMember) {
>>>>>>> a4ac98ebc9bd402663195869800385c827969747
    //Note: need a function from system to get id of request

    this->startDate = startDate;
    this->endDate = endDate;
    this->requestedByMember = requestedByMember;
}

