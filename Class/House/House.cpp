//
// Created by Vo Nguyen Kien on 09/01/2023.
//

#include "House.h"
House::House(std::string houseID, std::string location, std::string houseDescription) {
    this->houseID = houseID;
    this->location = location;
    this->houseDescription = houseDescription;
    this->isAdded = false;
    this->startingDate = nullptr;
    this->endingDate = nullptr;
    this->owner = nullptr;
    this->minRating = 0;
    this->consumingPointsPerDay = 0;
}

double House::getRatingScore() {
    if(this->listHouseReview.empty()){
        cout << "\nThere are no reviews for this house\n";
        return 0;
    }
    double tempScore = 0;
    for(auto & i : listHouseReview){
        tempScore += i->ratingScore;
    }
    double avgScore = (double ) tempScore / (double ) listHouseReview.size();
    return avgScore;
}
void House::viewHouseInfo() {
    cout << "\nOwner: " << owner->fullName << "\n";
    cout << "Location: " << location << "\n";
    cout << "Description: " << houseDescription << "\n";
    cout << "Rating score: " << this->getRatingScore() << "\n";
    if(!isAdded){
        cout << "Available from: " << this->startingDate << " to " << this->endingDate << "\n";
        cout << "Credit per day: " << consumingPointsPerDay << "\n";
        cout << "Minimum rating score of tenant: " << minRating << "\n";
    }
}
void House::viewHouseReview() {
    if(listHouseReview.empty()){
        cout << "\nThere are no reviews for this house\n";
    }
    else {
        for(auto &i : listHouseReview){
            int tempScore = i->ratingScore;
            std::string tempComment = i->comment;
            auto memReview = i->memberReview;
            std::cout << "\n-----------------------"
                      << "\n\nReview by member: " << memReview->fullName
                      << "\n-----------------------"
                      << "Score: " << tempScore << "\n"
                      << "Comment: " << tempComment;
        }
    }
}
void House::addRequestToHouseRequestList(Request *request) {
    listHouseRequest.push_back(request);
}
void House::addReviewToHouseReviewList(Review *houseReview) {
    listHouseReview.push_back(houseReview);
}
