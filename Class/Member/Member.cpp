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
    this->ownedHouse = nullptr;
    memberReviewList.clear();

}
double Member::getRatingScore() {
    if (this->memberReviewList.empty()) {
        return 0;
    }
    double tempScore = 0;
    for (Review *rv: memberReviewList) {
        tempScore += rv->ratingScore;
    }
    double ratingScore = (double) tempScore / (double) memberReviewList.size();
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
    if (ownedHouse == nullptr) {
        cout << "\nYou have not added a house\n";
    } else {
        ownedHouse->showInfo();
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
    if (this->memberReviewList.empty()) {
        cout << "\nThere are no reviews for this member\n";
    } else {
        cout << "\nAll review for this member: \n";
        for (int i = 0; i < this->memberReviewList.size(); i++) {
            Review *review = memberReviewList[i];
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





