//
// Created by Trung Ngo on 09/01/2023.
//

#include "Admin.h"

#include <utility>

Admin::Admin(std::string username, std::string password, std::string fullName, std::string phoneNum){}

void Admin::adminShowAccountInfo()
{
    std::cout << "\nYour information: \n";
    std::cout << "Your username: " << this->username << "\n";
    std::cout << "Your name: " << this->fullName << "\n";
}

void Admin::adminShowAllMember() {
    std::cout << "All the member of the system: " << "\n";
    std::cout
            << std::left
            << std::setw(8)
            << "MemberID"
            << std::left
            << std::setw(15)
            << "Full Name"
            << "\n";
    std::vector<vector<string> > memberList = System::extractByRow(memberFile);
    for (int i = 0; i < memberList.size(); i++) {
        std::cout
                << std::left
                << std::setw(8)
                << memberList[i][0]
                << std::left
                << std::setw(15)
                << memberList[i][1]
                << "\n";
    }
}

void Admin::adminViewMemberDetail() {
    std::vector<vector<string> > memberList = System::extractByRow(memberFile);

    std::cout << "\nAll members: " << "\n";
    std::cout
            << std::left
            << std::setw(15)
            << "Full Name"
            << std::left
            << std::setw(15)
            << "PhoneNum"
            << std::left
            << std::setw(8)
            << "MemberID"
            << std::left
            << std::setw(5)
            << "Credit"
            << std::left
            << std::setw(10)
            << "Rating Score"
            << std::endl;
    for (int i = 0; i < memberList.size(); i++) {
        std::cout
                << std::left
                << std::setw(15)
                << memberList[i][0]
                << std::left
                << std::setw(15)
                << memberList[i][1]
                << std::left
                << std::setw(8)
                << memberList[i][2]
                << std::left
                << std::setw(5)
                << memberList[i][3]
                << std::left
                << std::setw(10)
                << memberList[i][4]
                << std::endl;
    }
};

void Admin::adminSortByMemberScore() {
    std::vector<vector<string> > sortList = System::sortAscending(4, memberFile);

    std::cout << "\nAll members after sorted will be displayed: " << "\n";
    std::cout
            << std::left
            << std::setw(15)
            << "Full Name"
            << std::left
            << std::setw(15)
            << "PhoneNum"
            << std::left
            << std::setw(8)
            << "MemberID"
            << std::left
            << std::setw(5)
            << "Credit"
            << std::left
            << std::setw(10)
            << "Rating Score"
            << std::endl;
    for (int i = 0; i < sortList.size(); i++) {
        std::cout
                << std::left
                << std::setw(15)
                << sortList[i][0]
                << std::left
                << std::setw(15)
                << sortList[i][1]
                << std::left
                << std::setw(8)
                << sortList[i][2]
                << std::left
                << std::setw(5)
                << sortList[i][3]
                << std::left
                << std::setw(10)
                << sortList[i][4]
                << std::endl;
    }
};

void Admin::adminShowAllHouse() {
    std::cout << "List of available houses is being showed below:\n";
    std::vector<string> listofHouse;
    listofHouse = System::extractByColumnIndex(0, houseFile);

    std::cout << "House name: \n";
    for (std::string &obj: listofHouse) {
        cout << obj << " ";
    }
};

void Admin::adminViewHouseDetail(int id) {
    std::cout << "\nHouse with this ID will be displayed " << "\n";
    std::cout
            << std::left
            << std::setw(10)
            << "HouseID"
            << std::left
            << std::setw(10)
            << "OwnerID"
            << std::left
            << std::setw(20)
            << "CurrentDate"
            << std::left
            << std::setw(20)
            << "DateRange"
            << std::left
            << std::setw(10)
            << "Credit"
            << std::left
            << std::setw(10)
            << "minScore"
            << std::left
            << std::setw(15)
            << "Location"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n";


    vector<vector<string> > houseList = System::extractByRow(houseFile);

    for (auto & i : houseList) {
        if (id == std::stoi(i[0])) {
            std::cout
                    << std::left
                    << std::setw(10)
                    << i[0]
                    << std::left
                    << std::setw(10)
                    << i[1]
                    << std::left
                    << std::setw(20)
                    << i[2]
                    << std::left
                    << std::setw(20)
                    << i[3]
                    << std::left
                    << std::setw(10)
                    << i[4]
                    << std::left
                    << std::setw(10)
                    << i[5]
                    << std::left
                    << std::setw(15)
                    << i[6]
                    << std::left
                    << std::setw(15)
                    << i[7]
                    << "\n";
        } else {
            std::cout << "\nThere is no house with this ID" << "\n";
        }
    }
};

void Admin::adminSearchHouseByDateRange(string dateRange) {
    std::cout << "\nAll houses with this date range will be displayed: " << "\n";
    std::cout
            << std::left
            << std::setw(10)
            << "HouseID"
            << std::left
            << std::setw(10)
            << "OwnerID"
            << std::left
            << std::setw(20)
            << "CurrentDate"
            << std::left
            << std::setw(20)
            << "DateRange"
            << std::left
            << std::setw(10)
            << "Credit"
            << std::left
            << std::setw(10)
            << "minScore"
            << std::left
            << std::setw(15)
            << "Location"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n";


    std::vector<vector<string> > houseList = System::extractByRow(houseFile);

    for (int i = 0; i < houseList.size(); i++) {
        if (dateRange == houseList[i][3]) {
            std::cout
                    << std::left
                    << std::setw(10)
                    << houseList[i][0]
                    << std::left
                    << std::setw(10)
                    << houseList[i][1]
                    << std::left
                    << std::setw(20)
                    << houseList[i][2]
                    << std::left
                    << std::setw(20)
                    << houseList[i][3]
                    << std::left
                    << std::setw(10)
                    << houseList[i][4]
                    << std::left
                    << std::setw(10)
                    << houseList[i][5]
                    << std::left
                    << std::setw(15)
                    << houseList[i][6]
                    << std::left
                    << std::setw(15)
                    << houseList[i][7]
                    << "\n";
        }
    }
};

void Admin::adminSearchHouseByCredit(int credit) {
    std::cout << "\nAll houses with this credit will be displayed: " << "\n";
    std::cout
            << std::left
            << std::setw(10)
            << "HouseID"
            << std::left
            << std::setw(10)
            << "OwnerID"
            << std::left
            << std::setw(20)
            << "CurrentDate"
            << std::left
            << std::setw(20)
            << "DateRange"
            << std::left
            << std::setw(10)
            << "Credit"
            << std::left
            << std::setw(10)
            << "minScore"
            << std::left
            << std::setw(15)
            << "Location"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n";

    vector<vector<string> > houseList = System::extractByRow(houseFile);

    for (int i = 0; i < houseList.size(); i++) {
        if (credit == std::stoi(houseList[i][4])) {
            std::cout
                    << std::left
                    << std::setw(10)
                    << houseList[i][0]
                    << std::left
                    << std::setw(10)
                    << houseList[i][1]
                    << std::left
                    << std::setw(20)
                    << houseList[i][2]
                    << std::left
                    << std::setw(20)
                    << houseList[i][3]
                    << std::left
                    << std::setw(10)
                    << houseList[i][4]
                    << std::left
                    << std::setw(10)
                    << houseList[i][5]
                    << std::left
                    << std::setw(15)
                    << houseList[i][6]
                    << std::left
                    << std::setw(15)
                    << houseList[i][7]
                    << "\n";
        }
    }
};

void Admin::adminViewAllReQuest() {
    std::vector<vector<string> > list_of_request = System::extractByRow(requestFile); // Get data into a 2D vector

    std::cout << "Your request today is: \n";
    for (std::vector<string> &obj: list_of_request) {
        for (std::string &temp: obj) {
            std::cout << "temp ";
        }
    }
};