//
// Created by Trung Ngo on 09/01/2023.
//

#include "System.h"


System::System() {}

std::string System::trimString(std::string &str) {

    std::string finalStr;
    for (char ch: str) {
        if (ch == ' ') {
            continue;
        } else {
            finalStr += ch;
        }
    }
    return finalStr;

}

std::vector<std::string> System::splitStr(std::string &str, char del) {
    std::vector<std::string> dataLst;
    std::stringstream ss;
    ss << str;
    std::string cell;
    while (!ss.eof()) {
        std::getline(ss, cell, del);
        dataLst.push_back(cell);
    }
    return dataLst;
}

bool System::isValidNum(std::string &inputStr) {
    for (int i = 0; i < inputStr.length(); i++) {
        if (i == 0) {
            if (inputStr[i] == '-') {
                continue;
            }
        }
        if (!std::isdigit(inputStr[i])) {
            return false;
        }
    }
    return true;
}

bool System::isDouble(std::string &inputStr) {
    int dotCount = 0;
    for (int i = 0; i < inputStr.length(); i++) {
        if (i == 0) {
            if (inputStr[i] == '.') {
                dotCount++;
                continue;
            }
        }
        if (inputStr[i] == '.') {
            dotCount++;
            continue;
        }

        if (!std::isdigit(inputStr[i])) {
            std::cout << "Not a number!!! Try again: ";
            return false;
        }
        if (dotCount > 1) {
            std::cout << "Not a number!!! Try again: ";
            return false;
        }
    }
    return true;
}

bool System::isValidPhoneNum(std::string &phoneNum) {
    //false: phone number must have 10 numbers and start with 0
    //true: continue
    std::regex reg("^(?=0)[0-9]{10}$");
    phoneNum = trimString(phoneNum);
    if (std::regex_match(phoneNum, reg)) {
        return true;
    } else {
        std::cout << "Phone number must have 10 numbers and start with 0. Try again \n";
        return false;
    }
}

bool System::isValidPassword(std::string &password) {
    //false: Minimum 8 and maximum 10 characters, at least one uppercase letter, one lowercase letter, one number and one special character:
    //true: continue
    std::regex reg("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[@$!%*?&])[A-Za-z0-9@$!%*?&]{8,10}$");
    password = trimString(password);
    if (std::regex_match(password, reg)) {
        return true;
    } else {
        std::cout
                << "Minimum 8 and maximum 10 characters, at least one uppercase letter, one lowercase letter, one number and one special character. Try again \n";
        return false;
    }
}

bool System::isValidUserName(std::string &username) {
    std::regex reg("\\s");
    if (std::regex_match(username, reg)) {
        std::cout << "The username cannot have spaces! Try again \n";
        return false;
    } else {
        if (8 > username.length() || username.length() > 16) {
            std::cout << "The username can only have 8 to 16 characters! Try again \n";
            return false;
        } else {
            for (auto member: memberVector) {
                if (username == member->username) {
                    std::cout << "Taken username! Try again: \n";
                    return false;
                }
            }
            return true;
        }
    }
}

bool System::isValidFullname(std::string &fullname) {
    //false: Name must contain 8 to 20 characters and no digits, no special characters
    //true: continue
    std::regex reg("^[a-zA-Z]{8,20}$");
    fullname = trimString(fullname);
    if (std::regex_match(fullname, reg)) {
        return true;
    } else {
        std::cout << "Name must contain 8 to 20 characters and no digits, no special characters \n";
        return false;
    }
}

bool System::isValidCredit(Member *mem, House *house) {
    if (mem->credit < (house->consumingPointsPerDay * (house->endingDate->countDate() - house->startingDate->countDate()))) {
        return false;
    }
    return true;
}

bool System::isValidScore(Member *mem, House *house) {
    if (mem->score < house->minRating) {
        return false;
    }
    return true;
}

bool System::isValidDate(std::string date) {
    for (int i = 0; i < date.length(); i++) {
        if (i == 2 || i == 5) {
            if (date[i] != '/') {
                std::cout << "Date must follow the format xx/xx/xxxx. Try again \n";
                return false;
            }
        } else if (!std::isdigit(date[i])) {
            std::cout << "Your date is not valid. Try again \n";
            return false;
        }
    }
    return true;
}

bool System::isRightDateOrder(Date *start, Date *end) {
    if(end->countDate() - start->countDate() > 0){
        return true;
    }else{
        return false;
    }
}


int System::menuChoice(int start, int end) {
    int finalChoice;
    std::string tempChoice;
    bool flag;

    do {
        std::cout << "Enter your choice: ";
        std::cin >> tempChoice;
        if (!isValidNum(tempChoice)) {
            std::cout << "\nChoice is only number! Try again: ";
            flag = false;
            continue;
        }
        finalChoice = std::stoi(tempChoice);
        if (finalChoice < start || finalChoice > end) {
            std::cout << "Between " << start << " and " << end << " only! Try again: ";
            flag = false;
            continue;
        } else {
            flag = true;
        }
    } while (!flag);

    return finalChoice;
}

void System::guestShowHouse() {
    std::cout << std::left
              << std::setw(10)
              << "HouseID"
              << std::left
              << std::setw(10)
              << "Location"
              << std::left
              << std::setw(30)
              << "Description"
              << std::left
              << std::setw(20)
              << "Credits Required"
              << std::left
              << std::setw(10)
              << "Scores Required \n";
    for (auto *house: houseVector) {
        std::cout << std::left
                  << std::setw(10)
                  << house->houseID
                  << std::left
                  << std::setw(10)
                  << house->location
                  << std::left
                  << std::setw(30)
                  << house->houseDescription
                  << std::left
                  << std::setw(20)
                  << house->consumingPointsPerDay
                  << std::left
                  << std::setw(10)
                  << house->minRating << "\n";
    }
    guestMenu();
}

void System::mainMenu() {
    int choice;
    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n"
              << "VACATION HOUSE EXCHANGE APPLICATION\n"
              << "Instructors: Mr. Linh Tran & Phong Ngo\n"
              << "Group: Group Name\n"
              << "sXXXXXXX, Student Name\n"
              << "sXXXXXXX, Student Name\n"
              << "sXXXXXXX, Student Name\n"
              << "Use the app as 1. Guest   2. Member   3. Admin   4.Exit\n";
    choice = menuChoice(1, 4);
    switch (choice) {
        case 1:
            guestMenu();
            break;
        case 2:
            loginMemMenu();
            break;
        case 3:
            adminLoginMenu();
            break;
        case 4:
            outputMemberToFile();
            outputHouseToFile();
            outputHouseLstToFile();
            outputAdminToFile();
            outputRequestToFile();
            outputRatingHouseToFile();
            outputUnratedToFile();
            outputRatingTenantToFile();
            outputOccupierToFile();
            break;
    }
}

//guest menu
void System::guestMenu() {
    int choice;
    std::cout << "\t---GUEST MENU---\n";
    std::cout << "\t---1.View houses---\n" << "\t---2.Register---\n" << "\t---3.Back to main menu---\n";
    choice = menuChoice(1, 3);
    switch (choice) {
        case 1:
            guestShowHouse();
            break;
        case 2:
            registerMember();
            break;
        case 3:
            mainMenu();
            break;
    }

}

//admin menu - basic feature
void System::adminMenu() {
    int choice;
    std::cout << "\t---ADMIN MENU---\n";
    std::cout << "\t---1.View Member List---\n" << "\t--2.View House List" << "\t---3.Back to main menu---\n";
    choice = menuChoice(1, 3);
    switch (choice) {
        case 1:
            adminViewMemberMenu();
            break;
        case 2:
            adminViewHouseMenu();
            break;
        case 3:
            mainMenu();
            break;
    }


}

void System::adminViewMemberMenu() {
    int index = 1;
    std::cout << "All the member of the system: " << "\n";
    std::cout
            << std::left
            << std::setw(5)
            << "Index"
            << std::left
            << std::setw(10)
            << "MemberID"
            << std::left
            << std::setw(15)
            << "Full Name"
            << "\n";
    for (auto mem: memberVector) {
        std::cout
                << std::left
                << std::setw(5)
                << index
                << std::left
                << std::setw(10)
                << mem->memberId
                << std::left
                << std::setw(15)
                << mem->fullName
                << "\n";
        index++;
    }
    std::cout << "\t---1.View Member Detail---\n" << "\t---2.Back to admin menu---\n";
    int choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            std::cout
                    << std::left
                    << std::setw(10)
                    << "Index"
                    << std::left
                    << std::setw(15)
                    << "MemberID"
                    << std::left
                    << std::setw(15)
                    << "Full Name"
                    << std::left
                    << std::setw(15)
                    << "PhoneNum"
                    << std::left
                    << std::setw(15)
                    << "Username"
                    << std::left
                    << std::setw(8)
                    << "Credit"
                    << std::left
                    << std::setw(15)
                    << "Location"
                    << std::left
                    << std::setw(10)
                    << "Rating Score"
                    << "\n";
            for(int i = 0; i<memberVector.size();i++){
                std::cout
                        << std::left
                        << std::setw(10)
                        << i+1
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->memberId
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->fullName
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->phoneNum
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->username
                        << std::left
                        << std::setw(8)
                        << memberVector[i]->credit
                        << std::left
                        << std::setw(15)
                        << memberVector[i]->location
                        << std::left
                        << std::setw(10)
                        << memberVector[i]->getRatingScore()
                        << "\n";
            }
            std::cout << memberVector.size()+1 << ".Back to admin menu\n";
            menuChoice(memberVector.size()+1, memberVector.size()+1);
            adminMenu();

        case 2:
            adminMenu();
            break;
    }
}

void System::adminViewHouseMenu() {
    int index = 1;
    std::cout << "All house of the system: " << "\n";
    std::cout
            << std::left
            << std::setw(10)
            << "Index"
            << std::left
            << std::setw(8)
            << "HouseID"
            << std::left
            << std::setw(15)
            << "OwnerID"
            << std::left
            << std::setw(15)
            << "Location"
            << std::left
            << std::setw(35)
            << "Description"
            << "\n";
    for (auto i: houseVector) {
        std::cout
                << std::left
                << std::setw(10)
                << index
                << std::left
                << std::setw(8)
                << i->houseID
                << std::left
                << std::setw(15)
                << i->owner->memberId
                << std::left
                << std::setw(15)
                << i->location
                << std::left
                << std::setw(35)
                << i->houseDescription
                << "\n";
        index++;
    }
    std::cout << "\t---1.View House Detail---\n" << "\t---2.Back to admin menu---\n";
    int choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            std::cout
                    << std::left
                    << std::setw(10)
                    << "Index"
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
                    << "FinalDate"
                    << std::left
                    << std::setw(10)
                    << "CreditPerDay"
                    << std::left
                    << std::setw(15)
                    << "minScore"
                    << std::left
                    << std::setw(20)
                    << "Location"
                    << std::left
                    << std::setw(35)
                    << "Description"
                    << "\n";
            for(int j = 0; j < houseVector.size();j++) {
                std::cout
                        << std::left
                        << std::setw(10)
                        << j+1
                        << std::left
                        << std::setw(10)
                        << houseVector[j]->houseID
                        << std::left
                        << std::setw(10)
                        << houseVector[j]->owner->memberId
                        << std::left
                        << std::setw(20)
                        << houseVector[j]->startingDate->convertDatetoString()
                        << std::left
                        << std::setw(20)
                        << houseVector[j]->endingDate->convertDatetoString()
                        << std::left
                        << std::setw(10)
                        << houseVector[j]->consumingPointsPerDay
                        << std::left
                        << std::setw(15)
                        << houseVector[j]->minRating
                        << std::left
                        << std::setw(20)
                        << houseVector[j]->location
                        << std::left
                        << std::setw(35)
                        << houseVector[j]->houseDescription
                        << "\n";
            }
            std::cout << houseVector.size()+1 << ".Back to admin menu\n";
            menuChoice(houseVector.size()+1,houseVector.size()+1);
            adminMenu();
            break;
        case 2:
            adminMenu();
            break;
    }


}

void System::loginMemMenu() {
    std::string username, password;
    std::cout << "\t---1. Login ---\n" << "\t---2. Back to main menu ---\n";
    switch(menuChoice(1,2)){
        case 1:
            std::cout << "\t---MEMBER LOGIN---\n";
            std::cin.ignore();
            std::cout << "Enter your username: ";
            std::getline(std::cin, username);
            std::cout << "Enter your password: ";
            std::getline(std::cin, password);
            if(loginMember(username,password)){
                memberMenu();
                break;
            }
        case 2:
            mainMenu();
            break;
    }


}

void System::adminLoginMenu() {
    std::string username, password;

    std::cout << "\t---ADMIN LOGIN---\n";
    std::cout << "\t---1. Login ---\n" << "\t---2. Back to main menu ---\n";
    switch (menuChoice(1,2)){
        case 1:
            std::cin.ignore();
            std::cout << "Enter your username: ";
            std::getline(std::cin, username);
            std::cout << "Enter your password: ";
            std::getline(std::cin, password);
            if(admin->username == username && admin->password == password){
                std::cout << "Log in successfully!!! \n\n\n\n";
                adminMenu();
                break;
            }
            else {
                std::cout << "Wrong username or password!!! \n\n";
            }
        case 2:
            mainMenu();
            break;


    }
}


void System::memberMenu() {
    std::cout << "\t---MEMBER MENU---\n";
    int choice;
    std::cout << "\t---1.View Account's Information---\n" << "\t---2.View Available Houses ---\n"
              << "\t---3.Handle Requests---\n" << "\t---4.List House For Rental---\n" << "\t---5.Show rented menu---\n"
              << "\t---6.View Unrated Tenant List---\n" << "\t---7.Logout---\n";
    choice = menuChoice(1, 6);
    switch (choice) {
        case 1:
            currentUser->showAccountInfo();
            std::cout << "1. Back to menu...\n";
            menuChoice(1, 1);
            memberMenu();
            break;
        case 2:
            searchValidHouseMenu();
            break;
        case 3:
            viewRequestMenu();
            break;
        case 4:
            houseForRentMenu();
            break;
        case 5:
            showRentedHouse();
            break;
        case 6:
            
            break;
        case 7:
            currentUser = nullptr;
            mainMenu();
            break;
    }


}

void System::houseForRentMenu() {
    std::cout << "\t---UP HOUSE FOR RENT MENU ---\n";
    if (currentUser->houseOwner != nullptr) {
        if (currentUser->houseOwner->isAdded) {
            std::cout << "You are having a house for rent: \n";
            currentUser->houseOwner->viewHouseInfo();
            if (currentUser->houseOwner->listHouseRequest.empty()) {
                std::cout << "\n\n---\t1. Omit the house of renting site ---\n" << "\t---2. Back to member menu ---\n";
                switch (menuChoice(1, 2)) {
                    case 1:
                        deleteInRentHouse();
                        std::cout << "\tCome back to UP HOUSE FOR RENT MENU \n";
                        houseForRentMenu();
                        break;
                    case 2:
                        memberMenu();
                        break;
                }
            } else {
                std::cout << "\tCome back to member menu \n";
                memberMenu();
            }
        } else {
            std::cout << "You are having a house but not allowing rental yet: \n" << "1. Add the house for rent\n"
                      << "2. Back to member menu\n";
            switch (menuChoice(1, 2)) {
                case 1:
                    getInfoListHouseMenu();
                    std::cout << "\nSuccessfully added your house\n\n";
                    houseForRentMenu();
                    break;
                case 2:
                    memberMenu();
                    break;
            }
        }
    } else {
        std::cout << "You do not have a house. Add one: \n";
        enterHouseInfo();
        houseForRentMenu();
    }
}

bool System::getInfoListHouseMenu() {
    std::string startDate, endDate, minScores, minCredits;
    std::cin.ignore();

    std::cout << "\tPlease enter of your rental info\n";
    do {
        do {
            std::cout << "Enter the first renting date ";
            std::getline(std::cin, startDate);
        } while (!isValidDate(startDate));
        do {
            std::cout << "Enter the end renting date ";
            std::getline(std::cin, endDate);
        } while (!isValidDate(endDate));
    } while (!isRightDateOrder(stringToDate(startDate), stringToDate(endDate)));

    do {
        std::cout << "Enter the required credits per day ";
        std::getline(std::cin, minCredits);
    } while (!isDouble(minCredits));

    do {
        std::cout << "Enter the required minimum scores of renant ";
        std::getline(std::cin, minScores);
    } while (!isDouble(minScores));

    Date *start = stringToDate(startDate);
    Date *end = stringToDate(endDate);
    currentUser->addHouse(start, end, std::stod(minCredits), std::stod(minScores), STATUS[0]);
    return true;
}

bool System::enterHouseInfo() {
    std::string houseId, location, description;
    int choice;
    std::cout << "\tPlease enter your house's information\n";
    std::cout << "\tChoose the supported app location: ";
    std::cout << "\t1. HANOI \t2.HUE \t3.SAIGON\n";
    choice = menuChoice(1, 3);
    switch (choice) {
        case 1:
            location = LOCATIONS[0];
            break;
        case 2:
            location = LOCATIONS[1];
            break;
        case 3:
            location = LOCATIONS[2];
            break;
    }
    std::cin.ignore();
    std::cout << "\tEnter the description for your house: \n";
    std::getline(std::cin, description);
    auto *createdHouse = new House("HOU" + std::to_string(houseVector.size() + 1), location, description);
    houseVector.push_back(createdHouse);
    currentUser->createHouse(createdHouse);
    return true;
}

void System::showRentedHouse() {
    //Check if current member ocupying any house
    if (currentUser->tenantList.empty()) {
        std::cout << "\n\t\tThere are no house you are renting\n\n\t\tBack To Member Menu";
        memberMenu();
    }
    std::cout << "\nThe list of house you occupied:\n";
    currentUser->viewTenant();
    std::cout << "\n---" << currentUser->tenantList.size() + 1 << ".Back to menu\n";
    int choice = menuChoice(1, currentUser->tenantList.size() + 1);
    if (choice == currentUser->tenantList.size() + 1) {
        memberMenu();
    }
    auto tenantHouse = currentUser->tenantList[choice - 1]->occupyHouse;
    tenantHouse->viewHouseInfo();
    std::cout << "\n"
              << "\t\t1.Checkout\n"
              << "\t\t2.Back to menu\n";
    int newChoice = menuChoice(1, 2);
    switch (newChoice) {
        case 1:
            currentUser->checkout(choice - 1);
            std::cout << "\n\t\tLeft House\n";
            rateTenantMenu(choice - 1);
            break;
        case 2:
            memberMenu();
            break;
    }

}

void System::rateTenantMenu(int leaveID) {
    std::cout << "\n\t\tDo you want to rate the house?\n"
              << "\n\t\t1.Yes\n"
              << "\n\t\t2.No\n";

    int choice = menuChoice(1, 2);
    switch (choice) {
        case 1: {
            auto leaveMember = currentUser->tenantList[leaveID];
            std::string comment;
            int score;
            std::cout << "\n\t\tPlease leave a comment: ";
            std::cin.ignore();
            std::getline(std::cin, comment);
            std::cout << "\n\t\tPlease leave a score: ";
            std::cin >> score;
            currentUser->reviewHouse(leaveMember->occupyHouse, score, comment);
            memberMenu();
            break;
        }
        case 2:
            memberMenu();
            break;
    }

}

void System::searchValidHouseMenu() {
    std::string startDate, endDate, location;
    int choice;
    std::cin.ignore();
    std::cout << "\tSearch for suitable houses: \n\n";
    do {
        do {
            std::cout << "Enter when you want to rent (dd/mm/yyyy): ";
            std::getline(std::cin, startDate);
        } while (!isValidDate(startDate));
        do {
            std::cout << "Enter when you want to end renting (dd/mm/yyyy): ";
            std::getline(std::cin, endDate);
        } while (!isValidDate(endDate));
    } while (!(stringToDate(endDate) < stringToDate(startDate)));

    std::cout << "\tChoose the city you want to stay: \n\n";
    std::cout << "\t1. HANOI \t2.HUE \t3.SAIGON\n";
    choice = menuChoice(1, 3);
    switch (choice) {
        case 1:
            location = LOCATIONS[0];
            break;
        case 2:
            location = LOCATIONS[1];
            break;
        case 3:
            location = LOCATIONS[2];
            break;
    }
    Date *start = stringToDate(startDate);
    Date *end = stringToDate(endDate);

    validHouseMenu(start, end, location);

}

void System::validHouseMenu(Date *start, Date *end, std::string location) {
    memberSuitableHouseList.clear();
    int choice;
    getValidHouses(start, end, location);
    std::cout << memberSuitableHouseList.size() + 1 << ". Back to member menu\n";
    choice = menuChoice(1,memberSuitableHouseList.size() + 1);
    if(choice == memberSuitableHouseList.size() + 1){
        memberMenu();
    } else {
        memberSuitableHouseList[choice - 1]->viewHouseInfo();
        std::cout << "\n\n--> 1.\tRequest to rent this house\n\n"
                  << "--> 2.\tView house's reviews\n\n"
                  << "--> 3.\tBack to house list\n";
        switch (menuChoice(1, 3)) {
            case 1: {
                Request *request = new Request(start, end, currentUser, RE_STATUS[0]);
                memberSuitableHouseList[choice - 1]->addRequestToHouseRequestList(request);
                memberMenu();
                break; //function send requests
            }
            case 2:
                std::cout << "\nYour review is: \n";
                currentUser->showReview();
                memberMenu();
                break; //function view reviews
            case 3:
                validHouseMenu(start, end, location);
                break;
        }
    }
}

void System::actionRequestMenu(int requestID) {
    std::cout << "\n\n1.Accept Request\n2.Decline Request\n";
    switch (menuChoice(1, 2)) {
        case 1:
            currentUser->acceptRequest(requestID);
            std::cout << "\nRequest accepted\n";
            memberMenu();
            break;
        case 2:
            currentUser->declineRequest(requestID);
            std::cout << "\nRequest accepted\n";
            memberMenu();
            break;
    }
}

void System::viewRequestMenu() {
    int choice;
    std::cout << "\n\n\tYour request today:\n\n";
    int numberRequest = currentUser->viewAllRequest();
    std::cout << "\n\tChoose your option:\n\n";
    std::cout << "\n\n--> 1.\tPoint the Request:\n\n"
              << "--> 2.\tBack to Menu\n";
    choice = menuChoice(1, 3);
    switch (choice) {
        case 1: {
            std::cout << "Enter the request you want to proceed: \n";
            int newChoice = menuChoice(1, numberRequest);
            actionRequestMenu(newChoice);
            break;
        }
        case 2:
            memberMenu();
            break;
    }
}
bool System::memRequestHouse(Date *startDate, Date *endDate, int houseId) {
    if(houseId > memberSuitableHouseList.size()){
        return false;
    }

}

bool System::isValidHouses(Date *start, Date *end, Member *mem, House *house, std::string location) {
    if (!house->isAdded) {
        return false;
    }

    if (house->houseStatus == STATUS[1]){
        return false;
    }

    if (house == mem->houseOwner) {
        return false;
    }

    if (!isValidScore(mem, house)) {
        return false;
    }
    if (!isValidCredit(mem, house)) {
        return false;
    }

    if (location != house->location) {
        return false;
    }

    for (auto &occupier: house->listOccupyHouse) {
        if (end < occupier->startFromDate || start > occupier->toDate) {
            continue;
        }
        return false;
    }

    return true;
}

bool System::getValidHouses(Date *start, Date *end, std::string location) {
    memberSuitableHouseList.clear();
    for (auto &house: houseVector) {
        if (isValidHouses(start, end, currentUser, house, location)) {
            memberSuitableHouseList.push_back(house);
        }
    }

    if (memberSuitableHouseList.empty()) {
        std::cout << "\nThere is no houses matched your search\n";
        return false;
    }

    std::cout << "\nThe suitable house list:\n\n";
    for (int i = 0; i < memberSuitableHouseList.size(); i++) {
        std::cout << "--> " << i + 1 << ". ";
        std::cout << "House Id: " << memberSuitableHouseList[i]->houseID << "\tLocation: "
                  << memberSuitableHouseList[i]->location << "\tRating: "
                  << memberSuitableHouseList[i]->getRatingScore() << "\n";
    }
    std::cout << "\n\n";

    return true;
}

bool System::deleteInRentHouse() {
    if (currentUser->deleteHouse()) {
        std::cout << "\nSuccessfully omit the house\n";
        return true;
    } else {
        std::cout << "The house have requests hanging. Resolved all before omitting! \n";
        return false;
    }
}

void System::inputHouseToSys() {
    houseVector.clear();
    std::string dataLine;
    std::ifstream readFile{HOUSE_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << HOUSE_FILE << "\n";

    }
    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        auto *house = new House(dataLst[0], dataLst[2], dataLst[3]);
        houseVector.push_back(house);
    }
    readFile.close();
}

void System::inputAdminToSys() {
    std::string dataLine;
    std::ifstream readFile{ADMIN_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << ADMIN_FILE << "\n";
    }

    std::getline(readFile, dataLine);
    std::vector<std::string> dataLst = splitStr(dataLine, ';');
    std::string username = dataLst[0];
    std::string pass = dataLst[1];

    admin = new Admin(username, pass);

}

void System::inputHouseLstToSys() {
    std::string dataLine;
    std::ifstream readFile{HOUSE_LIST_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << HOUSE_LIST_FILE << "\n";
    }
    Member *owner;
    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        Date *startDate = stringToDate(dataLst[2]);
        Date *endDate = stringToDate(dataLst[3]);
        double credits = std::stod(dataLst[4]);
        double scores = std::stod(dataLst[5]);
        std::string status = dataLst[6];
        std::string ownerId = dataLst[1];
        for (Member *mem: memberVector) {
            if (ownerId == mem->memberId) {
                owner = mem;
            }
        }
        owner->addHouse(startDate, endDate, credits, scores,status);
    }
    readFile.close();
}

void System::inputMemHouseToSys() {
    std::string dataLine;
    std::ifstream readFile{HOUSE_FILE};
    Member *targetMem;
    House *memHouse;

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << HOUSE_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        for (House *house: houseVector) {
            if (dataLst[0] == house->houseID) {
                memHouse = house;
            }
        }
        for (Member *mem: memberVector) {
            if (dataLst[1] == mem->memberId) {
                targetMem = mem;
            }
        }
        targetMem->createHouse(memHouse);
    }
    readFile.close();

}

void System::inputMemberToSys() {
    memberVector.clear();
    std::string dataLine;
    std::ifstream readFile{MEMBERS_FILE};

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << MEMBERS_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        auto *member = new Member(dataLst[3], dataLst[4], dataLst[0], dataLst[1], dataLst[2],
                                  std::stod(dataLst[6]), std::stod(dataLst[7]), dataLst[5]);
        memberVector.push_back(member);
    }
    readFile.close();
}


void System::inputRatingTenantToSys() {
    std::string dataLine;
    std::ifstream readFile{RATING_TENANT_FILE};
    Member *beCommentedMem;
    Member *commentMem;


    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << RATING_HOUSE_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        for (auto mem: memberVector) {
            if (mem->memberId == dataLst[1]) {
                beCommentedMem = mem;
            }
        }
        for (auto mem2: memberVector) {
            if (mem2->memberId == dataLst[0]) {
                commentMem = mem2;
            }
        }


        auto memRating = new Review(std::stod(dataLst[2]), dataLst[3], commentMem);
        beCommentedMem->tenantReviewList.push_back(memRating);
    }

    readFile.close();

}

void System::outputRatingTenantToFile() {
    std::ofstream writeFile{RATING_TENANT_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << RATING_TENANT_FILE << "\n";
    }

    for (auto &mem: memberVector) {
        for (auto &memRating: mem->tenantReviewList) {
            writeFile << memRating->memberReview->memberId << ";"
                      << mem->memberId << ';'
                      << memRating->ratingScore << ";"
                      << memRating->comment << "\n";
        }
    }
    writeFile.close();
}

void System::outputRatingHouseToFile() {
    std::ofstream writeFile{RATING_HOUSE_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << RATING_HOUSE_FILE << "\n";
    }

    for (auto &house: houseVector) {
        for (auto &memRating: house->listHouseReview) {
            writeFile << memRating->memberReview->memberId << ";"
                      << house->houseID << ';'
                      << memRating->ratingScore << ";"
                      << memRating->comment << "\n";
        }
    }
    writeFile.close();
}

void System::inputRatingHouseToSys() {
    std::string dataLine;
    Member *targetMem;
    House *memHouse;
    std::ifstream readFile{RATING_HOUSE_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << RATING_HOUSE_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst = splitStr(dataLine, ';');
        for (auto mem: memberVector) {
            if (mem->memberId == dataLst[0]) {
                targetMem = mem;
            }
        }

        for (auto house: houseVector) {
            if (house->houseID == dataLst[1]) {
                memHouse = house;
            }
        }

        double houseScore = std::stod(dataLst[2]);
        std::string houseComment = dataLst[3];

        auto houseReview = new Review(houseScore, houseComment, targetMem);
        memHouse->addReviewToHouseReviewList(houseReview);
    }
    readFile.close();
}


void System::inputRequestToSys() {
    std::string dataLine;
    std::ifstream readFile{REQUEST_FILE};
    Member *targetMem;
    House *targetHouse;

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << REQUEST_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst;
        dataLst = splitStr(dataLine, ';');
        for (House *house: houseVector) {
            if (dataLst[1] == house->houseID) {
                targetHouse = house;
            }
        }
        for (Member *mem: memberVector) {
            if (dataLst[0] == mem->memberId) {
                targetMem = mem;
            }
        }
        Date *startDate = stringToDate(dataLst[2]);
        Date *endDate = stringToDate(dataLst[3]);
        std::string status = dataLst[4];
        Request *req = new Request(startDate, endDate, targetMem, status);
        targetHouse->addRequestToHouseRequestList(req);
        targetMem->requestList.push_back(req);
    }
    readFile.close();
}

void System::inputOccupierToSys() {
    std::string dataLine;
    std::ifstream readFile{OCCUPIERS_FILE};
    Member *targetMem;
    House *targetHouse;

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << OCCUPIERS_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst = splitStr(dataLine, ';');
        for (auto &mem: memberVector) {
            if (mem->memberId == dataLst[0]) {
                targetMem = mem;
            }
        }
        for (auto &house: houseVector) {
            if (house->houseID == dataLst[1]) {
                targetHouse = house;
            }
        }
        Date *start = stringToDate(dataLst[2]);
        Date *end = stringToDate(dataLst[3]);

        auto *occupyHouse = new OccupyHouse(start, end, targetMem);
        auto *occupyMem = new Tenant(start, end, targetHouse);

        targetMem->tenantList.push_back(occupyMem);
        targetHouse->listOccupyHouse.push_back(occupyHouse);
    }
}

void System::inputUnratedToSys() {
    std::string dataLine;
    std::ifstream readFile{UNRATED_OCC_FILE};
    Member *targetMem;
    House *targetHouse;

    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << UNRATED_OCC_FILE << "\n";
    }

    while (std::getline(readFile, dataLine)) {
        std::vector<std::string> dataLst = splitStr(dataLine, ';');
        for (auto &mem: memberVector) {
            if (mem->memberId == dataLst[1]) {
                targetMem = mem;
            }
        }
        for (auto &house: houseVector) {
            if (house->houseID == dataLst[0]) {
                targetHouse = house;
            }
        }
        Date *start = stringToDate(dataLst[2]);
        Date *end = stringToDate(dataLst[3]);

        auto *unratedOcc = new OccupyHouse(start, end, targetMem);
        targetHouse->unratedTenant.push_back(unratedOcc);
    }
}

void System::outputOccupierToFile() {
    std::ofstream writeFile{OCCUPIERS_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << OCCUPIERS_FILE << "\n";
    }

    for (auto &mem: memberVector) {
        for (auto &memOccupy: mem->tenantList) {
            writeFile << mem->memberId << ";"
                      << memOccupy->occupyHouse->houseID << ';'
                      << memOccupy->startFromDate->convertDatetoString() << ";"
                      << memOccupy->ToDate->convertDatetoString() << "\n";
        }
    }
    writeFile.close();
}

void System::outputAdminToFile() {
    std::ofstream writeFile{ADMIN_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << ADMIN_FILE << "\n";
    }

    writeFile << admin->username << ";"
              << admin->password << "\n";
}

void System::outputUnratedToFile() {
    std::ofstream writeFile{UNRATED_OCC_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << UNRATED_OCC_FILE << "\n";
    }

    for (auto &house: houseVector) {
        for (auto &unratedOcc: house->unratedTenant) {
            writeFile << house->houseID << ";"
                      << unratedOcc->tenant->memberId << ';'
                      << unratedOcc->startFromDate->convertDatetoString() << ";"
                      << unratedOcc->toDate->convertDatetoString() << "\n";
        }
    }
    writeFile.close();
}

void System::outputRequestToFile() {
    std::ofstream writeFile{REQUEST_FILE};

    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << REQUEST_FILE << "\n";
    }

    for (auto &house: houseVector) {
        for (auto &memRequest: house->listHouseRequest) {
            writeFile << memRequest->requestedByMember->memberId << ";"
                      << house->houseID << ';'
                      << memRequest->startDate->convertDatetoString() << ";"
                      << memRequest->endDate->convertDatetoString() << ";"
                      << memRequest->requestStatus << "\n";
        }
    }
    writeFile.close();
}

void System::outputHouseLstToFile() {
    std::ofstream writeFile{HOUSE_LIST_FILE};
    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << HOUSE_LIST_FILE << "\n";
        return;
    }

    for (auto mem: memberVector) {
        if (mem->houseOwner == nullptr) {
            continue;
        }
        if (!mem->houseOwner->isAdded) {
            continue;
        }

        writeFile << mem->houseOwner->houseID << ";"
                  << mem->memberId << ";"
                  << mem->houseOwner->startingDate->convertDatetoString() << ";"
                  << mem->houseOwner->endingDate->convertDatetoString() << ";"
                  << mem->houseOwner->consumingPointsPerDay << ";"
                  << mem->houseOwner->minRating << ";"
                  << mem->houseOwner->houseStatus << "\n";
    }
    writeFile.close();
}

void System::outputMemberToFile() {
    std::ofstream writeFile{MEMBERS_FILE};
    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << MEMBERS_FILE << "\n";
        return;
    }


    for (auto &mem: memberVector) {
        writeFile << mem->memberId << ";"
                  << mem->fullName << ";"
                  << mem->phoneNum << ";"
                  << mem->username << ";"
                  << mem->password << ";"
                  << mem->location << ";"
                  << mem->credit << ";"
                  << mem->score << "\n";
    }

    writeFile.close();
}

void System::outputHouseToFile() {
    std::ofstream writeFile{HOUSE_FILE};
    if (!writeFile.is_open()) {
        std::cerr << "Cannot open " << HOUSE_FILE << "\n";
        return;
    }
    for (House *house: houseVector) {
        writeFile << house->houseID << ";"
                  << house->owner->memberId << ";"
                  << house->location << ";"
                  << house->houseDescription << ";"
                  << house->houseScores << "\n";
    }
    writeFile.close();


}


bool System::loginMember(std::string username, std::string password) {
    int count = 0;
    for (Member *mem: memberVector) {
        if (mem->username == username && mem->password == password) {
            currentUser = mem;
            for (std::string loc: LOCATIONS) {
                if (loc == currentUser->location) {
                    count++;
                    break;
                }
            }
            if (count == 0) {
                std::cout << "The app do not support you in your region! \n";
                mainMenu();
                return false;
            }
            std::cout << "Log in successfully!!! \n\n\n\n";
            return true;
        }
    }
    std::cout << "Wrong username or password!!! \n\n";
    return false;
}

void System::registerMember() {
    int choice;
    int subChoice;
    std::string username, password, fullname, phoneNum, location;
    std::cout << "\t---MEMBER REGISTRATION---\n";
    std::cin.ignore();
    do {
        std::cout << "Enter your username: ";
        getline(std::cin, username);
    } while (!isValidUserName(username));

    do {
        std::cout << "Enter your password: ";
        getline(std::cin, password);
    } while (!isValidPassword(password));

    do {
        std::cout << "Enter your fullname: ";
        getline(std::cin, fullname);
    } while (!isValidFullname(fullname));

    do {
        std::cout << "Enter your phone number: ";
        getline(std::cin, phoneNum);
    } while (!isValidPhoneNum(phoneNum));


    std::cout << "1. Choose the locations the app support \n";
    std::cout << "2. Enter the location yourself \n";
    choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            std::cout << "Choose the following locations: \n";
            std::cout << "1.HANOI\t2.HUE\t3.SAIGON\n";
            subChoice = menuChoice(1, 3);
            switch (subChoice) {
                case 1:
                    location = LOCATIONS[0];
                    break;
                case 2:
                    location = LOCATIONS[1];
                    break;
                case 3:
                    location = LOCATIONS[2];
                    break;
            }
            break;
        case 2:
            std::cin.ignore();
            std::cout << "Enter your location: ";
            getline(std::cin, location);
            break;
    }
    Member *newMem = new Member(username, password, "MEM" + std::to_string(memberVector.size() + 1), fullname,
                                phoneNum,
                                INITIAL_CREDITS, INITIAL_SCORES, location);
    memberVector.push_back(newMem);
    std::cout << "You have registered successfully!\n";
    mainMenu();
}

Date *System::stringToDate(std::string &date) {
    std::vector<std::string> dataLst = splitStr(date, '/');
    Date *convertedDate = new Date(std::stoi(dataLst[0]), std::stoi(dataLst[1]), std::stoi(dataLst[2]));
    return convertedDate;

}
