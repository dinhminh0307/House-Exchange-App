//
// Created by Trung Ngo on 09/01/2023.
//

#include "Member.h"

#include <algorithm>



#include <utility>
Member::Member(std::string username, std::string password, std::string memberID, std::string fullName, std::string phoneNum,
               double credit, double score, std::string location) : User(std::move(username), std::move(password)) {
    this->memberId = memberID;
    this->fullName = fullName;
    this->phoneNum = phoneNum;
    this->credit = INITIAL_CREDITS;

    this->score = INITIAL_SCORES;

    this->location = location;
    this->houseOwner = nullptr;
    tenantReviewList.clear();
    requestList.clear();


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
    std::cout << "\nYour information: \n";
    std::cout << "Your username: " << this->username << "\n";
    std::cout << "Your name: " << this->fullName << "\n";
    std::cout << "Your phone number: " << this->phoneNum << "\n";
    std::cout << "Your credit: " << this->credit << "\n";
    std::cout << "Your location: " << this->location << "\n";
    std::cout << "Your score: " << this->getRatingScore() << "\n";
    if (houseOwner == nullptr) {
        std::cout << "\nYou have not added a house\n";
    }
    else {
        houseOwner->viewHouseInfo();
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
void  Member::showReview() {

    if (this->tenantReviewList.empty()) {
        std::cout << "\nThere are no reviews for this member\n";
    } else {
        std::cout << "\nAll review for this member: \n";
        for (int i = 0; i < this->tenantReviewList.size(); i++) {
            Review *review = tenantReviewList[i];
            std::string tempComment = review->comment;
            int tempScore = review->ratingScore;
            Member *member = review->memberReview;
            std::cout << "\n-----------------------"
               << "\n\nReview by member: " << member->fullName
               << "\n-----------------------"
               << "Score: " << tempScore << "\n"
               << "Comment: " << tempComment;

        }

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



bool Member::addHouse(Date *startDate, Date *endDate, int consumingPointsPerDay, std::string description, double scores) {


    if(houseOwner->isAdded) {
        return false;
    }

    houseOwner->isAdded = true;
    houseOwner->startingDate = startDate;
    houseOwner->endingDate = endDate;
    houseOwner->consumingPointsPerDay = consumingPointsPerDay;
    houseOwner->houseDescription = description;
    houseOwner->houseStatus = "Available";
    houseOwner->houseScores = scores;

    return true;
}

bool Member::deleteHouse() {
    if(!houseOwner->isAdded) {
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

bool Member::viewAllRequest() {
    if(houseOwner->listHouseRequest.empty()) {
        std::cout << "\nYou dont have any request!\n";
        return false;
    }
    std::cout << std::left
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
        std::cout
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
                << i->startDate
                << std::left
                << std::setw(10)
                << i->requestStatus
                << "\n";
    }
    return true;
}

bool Member:: declineRequest(std::string requestID) {
    	int index = 0;
        int indice = 0;
        for(auto i : houseOwner->listHouseRequest) {
            if(i->requestID == requestID) {
                index++;
                continue;
            }
            if((i->startDate - houseOwner->listHouseRequest[index]->endDate) < 0 || (houseOwner->listHouseRequest[index]->startDate -i->endDate) < 0) {
                indice++;
                houseOwner->listHouseRequest.erase(houseOwner->listHouseRequest.begin() + indice);//Delete overlap
                continue;
            }
        }
        houseOwner->listHouseRequest.erase(houseOwner->listHouseRequest.begin() + index); //Delete accepted request
        return true;
}
bool Member:: acceptRequest(std::string requestID) {
    for(int i = 0; i < houseOwner->listHouseRequest.size(); i++) {
        if(houseOwner->listHouseRequest[i]->requestID == requestID) {
            // cout << "\nThe request does not match\n";
            // return false;
            houseOwner->houseStatus = "Unavailable";
            auto rentDate = houseOwner->listHouseRequest[i]->startDate;
            auto endRentDate = houseOwner->listHouseRequest[i]->endDate;
            auto tenant =houseOwner->listHouseRequest[i]->requestedByMember;
            // int requiredCredit = (rentDate - endRentDate) *houseOwner->consumingPointsPerDay;
            declineRequest(requestID);
            OccupyHouse *occupyHouse = new OccupyHouse(rentDate, endRentDate, tenant);
        }
    }
    
}



