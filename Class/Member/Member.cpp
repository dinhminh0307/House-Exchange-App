//
// Created by Trung Ngo on 09/01/2023.
//

#include "Member.h"

#include <utility>
Member::Member(string username, string password, string memberID, string fullName, string phoneNum,
               int credit, int score, string location) : User(std::move(username), std::move(password)) {
    this->memberId = memberID;
    this->fullName = fullName;
    this->phoneNum = phoneNum;
    this->credit = BEGIN_CREDIT;
    this->score = score;
    this->location = location;
    this->houseOwner = nullptr;

}
void Member::showAccountInfo() {
    cout << "\nYour information: \n";
    cout << "Your username: " << this->username << "\n";
    cout << "Your name: " << this->fullName << "\n";
    cout << "Your phone number: " << this->phoneNum << "\n";

}

bool Member::addHouse(Date *startDate, Date *endDate, int consumingPointsPerDay) {
    if(houseOwner->isAdded) {
        return false;
    }

    houseOwner->isAdded = true;
    houseOwner->startingDate = startDate;
    houseOwner->endingDate = endDate;
    houseOwner->consumingPointsPerDay = consumingPointsPerDay;
    houseOwner->houseStatus = "Available";
    return true;
}

bool Member::deleteHouse() {
    if(!houseOwner->isAdded) {
        return false;
    }

    houseOwner->isAdded = false;
    houseOwner->houseStatus = "Unavailable";
    houseOwner->startingDate = nullptr;
    houseOwner->endingDate = nullptr;
    houseOwner->consumingPointsPerDay = NULL;

    return true;
}

bool Member::viewAllRequest() {
    if(houseOwner->listHouseRequest.empty()) {
        cout << "\nYou dont have any request!\n";
        return false;
    }
    cout << std::left
            << std::setw(10)
            << "Request ID"
            << std::left
            << std::setw(10)
            << "Member ID"
            << std::left
            << std::setw(20)
            << "House ID"
            << std::left
            << std::setw(15)
            << "Request Date"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n";
    for(Request *i : houseOwner->listHouseRequest) {
        cout
                << std::left
                << std::setw(10)
                << i->requestID
                << std::left
                << std::setw(10)
                << i->requestedByMember->memberId
                << std::left
                << std::setw(10)
                << i->houseID
                << std::left
                << std::setw(10)
                << i->requestFromDate
                << std::left
                << std::setw(10)
                << i->requestStatus
                << "\n";
    }
}
