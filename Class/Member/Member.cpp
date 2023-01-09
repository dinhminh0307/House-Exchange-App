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
    this->ownedHouse = nullptr;

}
void Member::showAccountInfo() {
    cout << "\nYour information: \n";
    cout << "Your username: " << this->username << "\n";
    cout << "Your name: " << this->fullName << "\n";
    cout << "Your phone number: " << this->phoneNum << "\n";

}