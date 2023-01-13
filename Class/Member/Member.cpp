//
// Created by Trung Ngo on 09/01/2023.
//

#include "Member.h"

//#include "../Date/Date.h"
//#include "../../System/System.h"
#include "../../define.h"
#include "../House/House.h"
#include "../Review/Review.h"
#include "../Request/Request.h"
#include "../OccupyHouse/OccupyHouse.h"
#include "../Tenant/Tenant.h"

#include <algorithm>


#include <utility>

Member::Member(std::string username, std::string password, std::string memberID, std::string fullName,
               std::string phoneNum,
               double credit, double score, std::string location) : User(std::move(username), std::move(password)) {
    this->memberId = memberID;
    this->fullName = fullName;
    this->phoneNum = phoneNum;
    this->credit = credit;

    this->score = score;

    this->location = location;
    this->houseOwner = nullptr;
    tenantReviewList.clear();
    requestList.clear();


}

double Member::getRatingScore() {
    if (this->tenantReviewList.empty()) {
        return 10;
    }
    double tempScore = 0;
    for (Review *rv: tenantReviewList) {
        tempScore += rv->ratingScore;
    }
    double ratingScore = (double) tempScore / (double) tenantReviewList.size();
    return ratingScore;
}


void Member::showAccountInfo() {
    std::cout << CYAN << "\nYour information: \n" << RESET;
    std::cout << CYAN << "Your username: " << this->username << "\n" << RESET;
    std::cout << CYAN << "Your name: " << this->fullName << "\n" << RESET;
    std::cout << CYAN << "Your phone number: " << this->phoneNum << "\n" << RESET;
    std::cout << CYAN << "Your credit: " << this->credit << "\n" << RESET;
    std::cout << CYAN << "Your location: " << this->location << "\n" << RESET;
    std::cout << CYAN << "Your score: " << this->getRatingScore() << "\n" << RESET;
    if (houseOwner == nullptr) {
        std::cout << "\n";
    } else {
        std::cout << CYAN << "HouseID: " << houseOwner->houseID << "  Location: " << houseOwner->location << "\n" << RESET;
    }
}

//add credit to member's credit
bool Member::addCredit(double creditPoint) {
    this->credit += creditPoint;
    return true;
}

//minus credit of member
bool Member::minusCredit(double creditPoint) {
    if (this->credit < creditPoint) {
        return false;
    }
    this->credit -= creditPoint;
    return true;
}

bool Member::showReview() {

    if (this->tenantReviewList.empty()) {
        std::cout << RED << "\nThere are no reviews for this member\n" <<RESET;
    } else {
        std::cout << CYAN << "\nAll review for this member: \n" << RESET;
        for (int i = 0; i < this->tenantReviewList.size(); i++) {
            Review *review = tenantReviewList[i];
            std::string tempComment = review->comment;
            int tempScore = review->ratingScore;
            Member *member = review->memberReview;
            std::cout << CYAN << "\n-----------------------"
                      << "\n\nReview by member: " << member->fullName
                      << "\n-----------------------"
                      << "Score: " << tempScore << "\n"
                      << "Comment: " << tempComment << RESET;

        }

    }
}

bool Member::createHouse(House *house) {
    if (this->houseOwner != nullptr) {
        return false;
    } else {
        this->houseOwner = house;
        house->owner = this;
        return true;
    }
}


bool Member::addHouse(Date *startDate, Date *endDate, int consumingPointsPerDay, double scores, std::string status) {


    if (houseOwner->isAdded) {
        return false;
    }

    houseOwner->isAdded = true;
    houseOwner->startingDate = startDate;
    houseOwner->endingDate = endDate;
    houseOwner->consumingPointsPerDay = consumingPointsPerDay;
    houseOwner->houseStatus = status;
    houseOwner->minRating = scores;

    return true;
}

bool Member::deleteHouse() {

    if (!houseOwner->isAdded || !houseOwner->listHouseRequest.empty()) {
        return false;
    }

    houseOwner->isAdded = false;
    houseOwner->houseStatus = STATUS[1];
    houseOwner->startingDate = nullptr;
    houseOwner->endingDate = nullptr;
    houseOwner->consumingPointsPerDay = 0;
    houseOwner->houseDescription = "";
    return true;
}


int Member::viewAllRequest() {
    int index = 0;
    if (houseOwner->listHouseRequest.empty()) {
        std::cout << RED << "\nNo request for you\n" << RESET;
        return 0;
    }
    std::cout
            << CYAN << std::left
            << std::setw(5)
            << "ID"
            << std::left
            << std::setw(10)
            << "Member ID"
            << std::left
            << std::setw(15)
            << "Request Date"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n" << RESET;
    for (Request *i: houseOwner->listHouseRequest) {
        index++;
        std::cout
                << CYAN << std::left
                << std::setw(5)
                << index
                << std::left
                << std::setw(10)
                << i->requestedByMember->memberId
                << std::left
                << std::setw(15)
                << i->startDate->convertDatetoString()
                << std::left
                << std::setw(15)
                << i->requestStatus
                << "\n" << RESET;
    }
    return index;
}

bool Member:: showRequestSent() {
    int index = 0;
    if(requestList.empty()) {
        std:: cout<< RED << "\nThere are no request that you sent\n" << RESET;
        return false;
    }
    std::cout
            << CYAN << std::left
            << std::setw(5)
            << "ID"
            << std::left
            << std::setw(10)
            << "House ID"
            << std::left
            << std::setw(15)
            << "Request Date"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n" << RESET;
    for(Request *i: requestList) {
         index++;
         std::cout
                << CYAN <<std::left
                << std::setw(5)
                << index
                << std::left
                << std::setw(10)
                << i->houseID
                << std::left
                << std::setw(15)
                << i->startDate->convertDatetoString()
                << std::left
                << std::setw(15)
                << i->requestStatus
                << "\n" << RESET;
    }
}

bool Member::cancelRequest(int ID) {
    int index = 0;
    if(ID - 1 > requestList.size()){
        return false;
    }
    auto request = requestList[ID-1];
    if(request->requestStatus == RE_STATUS[1]){
        return false;
    }
    else {
        requestList.erase(requestList.begin()+(ID-1));
        return true;
    }
}

void Member::reviewHouse(House *occupyHouse, int score, std::string comment) {
    //create object
    Review *review = new Review(score, comment, this);
    //add to review list of house
    occupyHouse->addReviewToHouseReviewList(review);
}


bool Member::declineRequest(int ID) {
    int indice = 0;
    for (auto i: houseOwner->listHouseRequest) {
        if (houseOwner->listHouseRequest[ID] == i) {
            continue;
        }
        if ((i->endDate->countDate() - houseOwner->listHouseRequest[ID]->startDate->countDate()) < 0 ||
            (houseOwner->listHouseRequest[ID]->endDate->countDate() - i->startDate->countDate()) < 0) {
            continue;
        }
        indice++;
        i->requestStatus = RE_STATUS[2];
    }
    houseOwner->listHouseRequest[ID]->requestStatus = RE_STATUS[2];


    return true;
}

bool Member::acceptRequest(int ID) {
    if (ID > houseOwner->listHouseRequest.size()) {
        return false;
    }


    if(houseOwner->listHouseRequest[ID]->requestStatus == RE_STATUS[1] || houseOwner->listHouseRequest[ID]->requestStatus == RE_STATUS[2]) {
        std::cout << RED <<"\nYou can not accept the request has been accepted or declined\n" << RESET;
        return false;
    }
    // cout << "\nThe request does not match\n";
    // return false;
    houseOwner->houseStatus = "UNAVAILABLE";
    auto rentDate = houseOwner->listHouseRequest[ID ]->startDate;
    auto endRentDate = houseOwner->listHouseRequest[ID]->endDate;
    auto tenant = houseOwner->listHouseRequest[ID]->requestedByMember;

    // int requiredCredit = (rentDate - endRentDate) *houseOwner->consumingPointsPerDay;
    declineRequest(ID );
    houseOwner->listHouseRequest[ID]->requestStatus = RE_STATUS[1];
    OccupyHouse *occupyHouse = new OccupyHouse(rentDate, endRentDate, tenant);
    Tenant *occupyMember = new Tenant(rentDate, endRentDate, houseOwner);
    // add object to occupy list
    tenant->tenantList.push_back(occupyMember);
    houseOwner->listOccupyHouse.push_back(occupyHouse);
    // add credit of owner and minus credit of tenant
    this->addCredit(houseOwner->consumingPointsPerDay * (endRentDate->countDate() - rentDate->countDate()));
    tenant->minusCredit(houseOwner->consumingPointsPerDay * (endRentDate->countDate() - rentDate->countDate()));
    return true;
}


void Member::viewTenant() {
    std::cout
            << CYAN << std::left
            << std::setw(15)
            << "Start Date"
            << std::left
            << std::setw(20)
            << "End Date"
            << std::left
            << std::setw(15)
            << "House ID"
            << std::left
            << std::setw(15)
            << "Owner ID"
            << "\n" << RESET;
    for (int i = 0; i < tenantList.size(); i++) {
        auto tenantStartDate = tenantList[i]->startFromDate->convertDatetoString();
        auto tenantEndDate = tenantList[i]->ToDate->convertDatetoString();
        auto House = tenantList[i]->occupyHouse;
        std::cout << CYAN << i+1 << "."
                  << std::left
                  << std::setw(15)
                  << tenantStartDate
                  << std::left
                  << std::setw(20)
                  << tenantEndDate
                  << std::left
                  << std::setw(15)
                  << House->houseID
                  << std::left
                  << std::setw(15)
                  << House->owner->memberId
                  << "\n" << RESET;
    }
}


bool Member::viewMemberOccupyList() {
    if (tenantList.empty()) {
        std::cout << RED << "\nThere are no houses you are occupying\n" << RESET;
        return false;
    }
    for (int i = 0; i < tenantList.size(); i++) {
        std::cout << CYAN << i + 1 << '.' << tenantList[i]->startFromDate->convertDatetoString() << "-->"
                  << tenantList[i]->ToDate->convertDatetoString() << ":" << tenantList[i]->occupyHouse->houseID << "\n" << RESET;
    }
    return true;
}

bool Member::checkout(int leaveId) {
    //if input greater than the size of list, return false
    if (leaveId > tenantList.size()) {
        return false;
    }
    //get object
    auto leaveTenant = tenantList[leaveId];
    auto leaveStartDate = leaveTenant->startFromDate;
    auto leaveDate = leaveTenant->ToDate;
    auto leaveHouse = leaveTenant->occupyHouse;
    //create object
    auto *unrated = new OccupyHouse(leaveStartDate, leaveDate, this);
    //add object to unrated list
    leaveHouse->unratedTenant.push_back(unrated);
    leaveHouse->houseStatus = STATUS[0];
    //delete from tenant list
    tenantList.erase(tenantList.begin() + (leaveId));
    //when leave house call member review house and member review occupier afterwards in menu
    return true;

}

bool Member::viewUnratedList() {
    //if list is empty
    if (houseOwner->unratedTenant.empty()) {
        return false;
    }
    //display data
    std::cout << GREEN << "\nAll unrated tenant will be displayed: \n" << RESET;
    std::cout
            << CYAN <<std::left
            << std::setw(10)
            << "Index"
            << std::left
            << std::setw(20)
            << "Start Date"
            << std::left
            << std::setw(20)
            << "End Date"
            << std::left
            << std::setw(10)
            << "MemberID"
            << "\n" << RESET;
    for (int i = 0; i < houseOwner->unratedTenant.size(); i++) {
        std::cout
                << CYAN << std::left
                << std::setw(10)
                << i+1
                << std::left
                << std::setw(20)
                << houseOwner->unratedTenant[i]->startFromDate->convertDatetoString()
                << std::left
                << std::setw(20)
                << houseOwner->unratedTenant[i]->toDate->convertDatetoString()
                << std::left
                << std::setw(10)
                << houseOwner->unratedTenant[i]->tenant->memberId
                << "\n" << RESET;
    }
    return true;
}

bool Member::reviewTenant(int rateId, int score, std::string comment) {
    if (rateId > houseOwner->unratedTenant.size()) {
        return false;
    }
    auto tenant = houseOwner->unratedTenant[rateId]->tenant;
    //create review object
    auto review = new Review(score, comment, tenant);
    //add review to review list
    tenant->tenantReviewList.push_back(review);
    //remove from unrated list
    houseOwner->unratedTenant.erase(houseOwner->unratedTenant.begin() + (rateId - 1));
    return true;


}

Member :: ~Member() {
    for(auto &request: requestList) {
        delete request;
    }

    for(auto &review : tenantReviewList) {
        delete review;
    }
    for(auto &tenant : tenantList) {
        delete tenant;
    }
}
