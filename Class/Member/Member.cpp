//
// Created by Trung Ngo on 09/01/2023.
//

#include "Member.h"

#include <utility>
Member::Member(string username, string password, string memberID, string fullName, string phoneNum,
               double credit, int score, string location) : User(std::move(username), std::move(password)) {
    this->memberId = memberID;
    this->fullName = fullName;
    this->phoneNum = phoneNum;
    this->credit = BEGIN_CREDIT;
    this->score = score;
    this->location = location;

    this->houseOwner = nullptr;
    tenantReviewList.clear();


}
double Member::getRatingScore() {
    if (this->tenantReviewList.empty()) {
        return 0;
    }
    double tempScore = 0;
    for (Review *rv: tenantReviewList) {
        tempScore += rv->ratingScore;
    }
    double ratingScore = (double) tempScore / (double) tenantReviewList.size();
    return ratingScore;
}

void Member::showAccountInfo() {
    cout << "\nYour information: \n";
    cout << "Your username: " << this->username << "\n";
    cout << "Your name: " << this->fullName << "\n";
    cout << "Your phone number: " << this->phoneNum << "\n";
    cout << "Your credit: " << this->credit << "\n";
    cout << "Your location: " << this->location << "\n";
    cout << "Your score: " << this->getRatingScore() << "\n";
    if (houseOwner == nullptr) {
        cout << "\nYou have not added a house\n";
    } else {
        houseOwner->showInfo();
    }
}
//add credit to member's credit
bool Member::addCredit(int creditPoint) {
    this->credit += creditPoint;
    return true;
}
//minus credit of member
bool Member::minusCredit(int creditPoint) {
    if (this->credit < creditPoint) {
        return false;
    }
    this->credit -= creditPoint;
    return true;
}
string Member::showReview() {
    std::stringstream ss;
    if (this->tenantReviewList.empty()) {
        cout << "\nThere are no reviews for this member\n";
    } else {
        cout << "\nAll review for this member: \n";
        for (int i = 0; i < this->tenantReviewList.size(); i++) {
            Review *review = tenantReviewList[i];
            string tempComment = review->comment;
            int tempScore = review->ratingScore;
            Member *member = review->memberReview;
            ss << "\n-----------------------"
               << "\n\nReview by member: " << member->fullName
               << "\n-----------------------"
               << "Score: " << tempScore << "\n"
               << "Comment: " << tempComment;

        }
        return ss.str();
    }
}

bool Member::createHouse(House *house) {
    if(this->houseOwner != nullptr){
        return false;
    }
    else {
        this->houseOwner = house;
        house->owner = this;
        return true;
    }
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


