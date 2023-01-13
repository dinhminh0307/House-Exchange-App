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
            std::cout << RED << "Not a number!!! Try again: " << RESET;
            return false;
        }
        if (dotCount > 1) {
            std::cout << RED << "Not a number!!! Try again: " << RESET;
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
        std::cout << RED << "Phone number must have 10 numbers and start with 0. Try again \n" << RESET;
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
                << RED
                << "Minimum 8 and maximum 10 characters, at least one uppercase letter, one lowercase letter, one number and one special character. Try again \n"
                << RESET;
        return false;
    }
}

bool System::isValidUserName(std::string &username) {
    std::regex reg("\\s");
    if (std::regex_match(username, reg)) {
        std::cout << RED << "The username cannot have spaces! Try again \n" << RESET;
        return false;
    } else {
        if (8 > username.length() || username.length() > 16) {
            std::cout << RED << "The username can only have 8 to 16 characters! Try again \n" << RESET;
            return false;
        } else {
            for (auto member: memberVector) {
                if (username == member->username) {
                    std::cout << RED << "Taken username! Try again: \n" << RESET;
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
        std::cout << RED << "Name must contain 8 to 20 characters and no digits, no special characters \n" << RESET;
        return false;
    }
}

bool System::isValidCredit(Member *mem, House *house) {
    if (mem->credit <
        (house->consumingPointsPerDay * (house->endingDate->countDate() - house->startingDate->countDate()))) {
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
    std::string day = date.substr(0, 2);
    std::string month = date.substr(3, 2);
    std::string year = date.substr(6, 4);

    for (int i = 0; i < date.length(); i++) {
        if (i == 2 || i == 5) {
            if (date[i] != '/') {
                std::cout << RED << "Date must follow the format xx/xx/xxxx. Try again \n" << RESET;
                return false;
            }
        } else if (!std::isdigit(date[i])) {
            std::cout << RED << "Your date is not valid. Try again \n" << RESET;
            return false;
        } else if (std::stoi(month) > 13 || std::stoi(month) < 1) {
            std::cout << RED << "Your date is not valid. Try again \n" << RESET;
            return false;
        } else if (std::stoi(day) > DAYS_IN_MONTHS[std::stoi(month) - 1]) {
            std::cout << RED << "Your date is not valid. Try again \n" << RESET;
            return false;
        }
    }
    return true;
}

bool System::isRightDateOrder(Date *start, Date *end) {
    if (end->countDate() - start->countDate() > 0) {
        return true;
    } else {
        return false;
    }
}


int System::menuChoice(int start, int end) {
    int finalChoice;
    std::string tempChoice;
    bool flag;

    do {
        std::cout << CYAN << "Enter your choice: " << RESET;
        std::cin >> tempChoice;
        if (!isValidNum(tempChoice)) {
            std::cout << RED << "\nChoice is only number! Try again: " << RESET;
            flag = false;
            continue;
        }
        finalChoice = std::stoi(tempChoice);
        if (finalChoice < start || finalChoice > end) {
            std::cout << RED << "Between " << start << " and " << end << " only! Try again: " << RESET;
            flag = false;
            continue;
        } else {
            flag = true;
        }
    } while (!flag);

    return finalChoice;
}

void System::guestShowHouse() {
    std::cout << YELLOW << std::left
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
              << "Scores Required \n" << RESET;
    for (auto *house: houseVector) {
        std::cout << YELLOW << std::left
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
                  << house->minRating << "\n" << RESET;
    }
    guestMenu();
}

void System::mainMenu() {
    int choice;
    std::cout << GREEN << "-----------------------------------------------------------\n" << RESET;
    std::cout << GREEN << "|              EEET2482/COSC2082 ASSIGNMENT               |\n"
              << "|              VACATION HOUSE EXCHANGE APPLICATION        |\n"
              << "|              Instructors: Mr. Linh Tran & Phong Ngo     |\n"
              << "|                                                         |\n"
              << "|              Group: 26                                  |\n"
              << "|              s3938154, Ngo Lam Bao Trung                |\n"
              << "|              s3938016, Vo Nguyen Kien                   |\n"
              << "|              s3925113, Dinh Ngoc Minh                   |\n"
              << "|              s3926247, Mai Tran Duy Anh                 |\n"
              << "|              s3669698, Nguyen Huu Duc                   |\n"
              << "|                                                         |\n"
              << "| Use the app as 1. Guest   2. Member   3. Admin   4.Exit |\n" << RESET;
    std::cout << GREEN << "----------------------------------------------------------\n\n" << RESET;

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
    std::cout << GREEN << "---------------------------------------\n" << RESET;
    std::cout << GREEN << "|              GUEST MENU             |\n" << RESET;
    std::cout << GREEN << "|     1.View houses                   |\n"
              << "|     2.Register                      |\n"
              << "|     3.Back to main menu             |\n" << RESET;
    std::cout << GREEN << "---------------------------------------\n" << RESET;

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
    std::cout << GREEN << "---------------------------------------\n" << RESET;
    std::cout << GREEN << "|              ADMIN MENU             |\n" << RESET;
    std::cout << GREEN << "|     1.View Member List              |\n"
              << "|     2.View House List               |\n"
              << "|     3.Back to main menu             |\n" << RESET;
    std::cout << GREEN << "---------------------------------------\n" << RESET;
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
    std::cout << GREEN << "All the member of the system: " << "\n" << RESET;
    std::cout
            << CYAN << std::left
            << std::setw(5)
            << "Index"
            << std::left
            << std::setw(10)
            << "MemberID"
            << std::left
            << std::setw(15)
            << "Full Name"
            << "\n" << RESET;
    for (auto mem: memberVector) {
        std::cout
                << CYAN << std::left
                << std::setw(5)
                << index
                << std::left
                << std::setw(10)
                << mem->memberId
                << std::left
                << std::setw(15)
                << mem->fullName
                << "\n" << RESET;
        index++;
    }
    std::cout << "\n";
    std::cout << GREEN << "\t---1.View Member Detail---\n" << "\t---2.Back to admin menu---\n" << RESET;
    int choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            std::cout
                    << CYAN << std::left
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
                    << "\n" << RESET;
            for (int i = 0; i < memberVector.size(); i++) {
                std::cout
                        << CYAN << std::left
                        << std::setw(10)
                        << i + 1
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
                        << "\n" << RESET;
            }
            std::cout << "\n";
            std::cout << CYAN << memberVector.size() + 1 << ".Back to admin menu\n" << RESET;
            menuChoice(memberVector.size() + 1, memberVector.size() + 1);
            adminMenu();

        case 2:
            adminMenu();
            break;
    }
}

void System::adminViewHouseMenu() {
    int index = 1;
    std::cout << GREEN << "All house of the system: " << "\n" << RESET;
    std::cout
            << CYAN << std::left
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
            << "\n" << RESET;
    for (auto i: houseVector) {
        std::cout
                << CYAN << std::left
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
                << "\n" << RESET;
        index++;
    }
    std::cout << "\n";
    std::cout << GREEN << "\t---1.View House Detail---\n" << "\t---2.Back to admin menu---\n" << RESET;
    int choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            std::cout
                    << CYAN << std::left
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
                    << "Start Date"
                    << std::left
                    << std::setw(20)
                    << "End Date"
                    << std::left
                    << std::setw(25)
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
                    << "\n" << RESET;
            for (int j = 0; j < houseVector.size(); j++) {
                std::cout
                        << CYAN << std::left
                        << std::setw(10)
                        << j + 1
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
                        << std::setw(25)
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
                        << "\n" << RESET;
            }
            std::cout << "\n";
            std::cout << CYAN << houseVector.size() + 1 << ".Back to admin menu\n" << RESET;
            menuChoice(houseVector.size() + 1, houseVector.size() + 1);
            adminMenu();
            break;
        case 2:
            adminMenu();
            break;
    }


}

void System::loginMemMenu() {
    std::string username, password;
    std::cout << GREEN << "--------------------------------------\n" << RESET;
    std::cout << GREEN << "|            MEMBER LOGIN            |\n" << RESET;
    std::cout << GREEN << "|        1. Login as member          |\n"
              << "|        2. Back to main menu        |\n" << RESET;
    std::cout << GREEN << "--------------------------------------\n" << RESET;

    switch (menuChoice(1, 2)) {
        case 1:
            std::cin.ignore();
            std::cout << CYAN << "Enter your username: " << RESET;
            std::getline(std::cin, username);
            std::cout << CYAN << "Enter your password: " << RESET;
            std::getline(std::cin, password);
            if (loginMember(username, password)) {
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

    std::cout << GREEN << "---------------------------------------\n" << RESET;
    std::cout << GREEN << "|              ADMIN MENU             |\n" << RESET;
    std::cout << GREEN << "|     1.Login As Admin                |\n"
              << "|     2.Back to main menu             |\n" << RESET;
    std::cout << GREEN << "---------------------------------------\n" << RESET;
    switch (menuChoice(1, 2)) {
        case 1:
            std::cin.ignore();
            std::cout << CYAN << "Enter your username: " << RESET;
            std::getline(std::cin, username);
            std::cout << CYAN << "Enter your password: " << RESET;
            std::getline(std::cin, password);
            if (admin->username == username && admin->password == password) {
                std::cout << GREEN << "Log in successfully!!! \n\n\n\n" << RESET;
                adminMenu();
                break;
            } else {
                std::cout << RED << "\n\nWrong username or password!!! \n" << RESET;
            }
        case 2:
            mainMenu();
            break;


    }
}


void System::memberMenu() {
    int choice;
    std::cout << GREEN << "----------------------------------------\n" << RESET;
    std::cout << GREEN << "|          ---MEMBER MENU---           |\n" << RESET;
    std::cout << GREEN << "|  1.View Account's Information        |\n"
              << "|  2.View Available Houses             |\n"
              << "|  3.Handle Requests                   |\n"
              << "|  4.List House For Rental             |\n"
              << "|  5.Show rented menu                  |\n"
              << "|  6.View Unrated Tenant List          |\n"
              << "|  7.Show Request Sent                 |\n"
              << "|  8.Logout                            |\n" << RESET;
    std::cout << GREEN << "----------------------------------------\n" << RESET;
    choice = menuChoice(1, 8);
    switch (choice) {
        case 1:
            currentUser->showAccountInfo();
            std::cout << CYAN << "1. Back to menu...\n" << RESET;
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
            viewUnratedTenantList();
            break;
        case 7:
            showRequestSent();
            break;
        case 8:
            currentUser = nullptr;
            mainMenu();
            break;
    }


}

void System::houseForRentMenu() {
    std::cout << GREEN << "\t---UP HOUSE FOR RENT MENU ---\n" << RESET;
    if (currentUser->houseOwner != nullptr) {
        if (currentUser->houseOwner->isAdded) {
            std::cout << GREEN << "You are having a house for rent: \n" << RESET;
            currentUser->houseOwner->viewHouseInfo();
            if (currentUser->houseOwner->listHouseRequest.empty()) {
                std::cout << CYAN << "\n\n---\t1. Omit the house of renting site ---\n"
                          << "\t---2. Back to member menu ---\n" << RESET;
                switch (menuChoice(1, 2)) {
                    case 1:
                        deleteInRentHouse();
                        std::cout << GREEN << "\tCome back to UP HOUSE FOR RENT MENU \n" << RESET;
                        houseForRentMenu();
                        break;
                    case 2:
                        memberMenu();
                        break;
                }
            } else {
                std::cout << GREEN << "\tCome back to member menu \n" << RESET;
                memberMenu();
            }
        } else {
            std::cout << CYAN << "You are having a house but not allowing rental yet: \n"
                      << "1. Add the house for rent\n"
                      << "2. Back to member menu\n" << RESET;
            switch (menuChoice(1, 2)) {
                case 1:
                    getInfoListHouseMenu();
                    std::cout << GREEN << "\nSuccessfully added your house\n\n" << RESET;
                    houseForRentMenu();
                    break;
                case 2:
                    memberMenu();
                    break;
            }
        }
    } else {
        std::cout << RED << "You do not have a house. Add one: \n" << RESET;
        enterHouseInfo();
        houseForRentMenu();
    }
}

bool System::getInfoListHouseMenu() {
    std::string startDate, endDate, minScores, minCredits;
    std::cin.ignore();

    std::cout << GREEN << "\tPlease enter of your rental info\n" << RESET;
    do {
        do {
            std::cout << CYAN << "Enter the first renting date " << RESET;
            std::getline(std::cin, startDate);
        } while (!isValidDate(startDate));
        do {
            std::cout << CYAN << "Enter the end renting date " << RESET;
            std::getline(std::cin, endDate);
        } while (!isValidDate(endDate));
    } while (!isRightDateOrder(stringToDate(startDate), stringToDate(endDate)));

    do {
        std::cout << CYAN << "Enter the required credits per day " << RESET;
        std::getline(std::cin, minCredits);
    } while (!isDouble(minCredits));

    do {
        std::cout << CYAN << "Enter the required minimum scores of renant " << RESET;
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
    std::cout << GREEN << "\tPlease enter your house's information\n" << RESET;
    std::cout << GREEN << "\tChoose the supported app location: " << RESET;
    std::cout << CYAN << "\t1. HANOI \t2.HUE \t3.SAIGON\n" << RESET;
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
    std::cout << CYAN << "\tEnter the description for your house: \n" << RESET;
    std::getline(std::cin, description);
    auto *createdHouse = new House("HOU" + std::to_string(houseVector.size() + 1), location, description);
    houseVector.push_back(createdHouse);
    currentUser->createHouse(createdHouse);
    return true;
}

void System::showRentedHouse() {
    //Check if current member ocupying any house
    if (currentUser->tenantList.empty()) {
        std::cout << RED << "\n\t\tThere are no house you are renting\n\n\t\tBack To Member Menu\n" << RESET;
        memberMenu();
    }
    std::cout << GREEN << "\nThe list of house you occupied:\n" << RESET;
    currentUser->viewTenant();
    std::cout << "\n---" << currentUser->tenantList.size() + 1 << ".Back to menu\n";
    int choice = menuChoice(1, currentUser->tenantList.size() + 1);
    if (choice == currentUser->tenantList.size() + 1) {
        memberMenu();
    }
    auto tenantHouse = currentUser->tenantList[choice - 1]->occupyHouse;
    tenantHouse->viewHouseInfo();
    std::cout << CYAN << "\n"
              << "\t\t1.Checkout\n"
              << "\t\t2.Back to menu\n" << RESET;
    int newChoice = menuChoice(1, 2);
    switch (newChoice) {
        case 1:
            currentUser->checkout(choice - 1);
            std::cout << GREEN << "\n\t\tLeft House\n" << RESET;
            rateTenantMenu(choice - 1);
            break;
        case 2:
            memberMenu();
            break;
    }

}

void System::rateTenantMenu(int leaveID) {
    std::cout << CYAN << "\n\t\t1.Press 1 to rate the house: " << RESET;

    int choice = menuChoice(1, 1);
    if (choice == 1) {
        auto leaveMember = currentUser->tenantList[leaveID];
        std::string comment;
        std::string score;
        std::cout << CYAN << "\n\t\tPlease leave a comment: " << RESET;
        std::cin.ignore();
        std::getline(std::cin, comment);

        while (true) {
            std::cout << CYAN << "\n\t\tPlease leave a score: " << RESET;
            std::cin >> score;
            if (!isValidNum(score)) {
                continue;
            }
            if (std::stoi(score) < -10 || std::stoi(score) > 10) {
                std::cout << RED << "The rating scores can only be from -10 to 10: " << RESET;
                continue;
            }else{
                break;
            }
        }

        currentUser->reviewHouse(leaveMember->occupyHouse, std::stoi(score), comment);
        std::cout << CYAN << "\nPress 2 to back to the member Menu: " << RESET;
        if (menuChoice(2, 2) == 2) {
            memberMenu();
        }

    }
}

void System::showRequestSent() {
    std::cout << GREEN << "\nEnter the index of request that you want to cancel:\n" << RESET;
    std::cout << GREEN << "List of the request you have sent: \n" << RESET;
    currentUser->showRequestSent();
    std::cout << CYAN << currentUser->requestList.size() + 1 << ".Back to Member Menu\n" << RESET;
    int choice = menuChoice(1, currentUser->requestList.size() + 1);
    if (choice == currentUser->requestList.size() + 1) {
        memberMenu();
    } else {
        cancelRequestMenu(choice);
    }

}

void System::cancelRequestMenu(int ID) {
    std::cout << CYAN << "\nPress 1 to cancel the request\n" << RESET;
    std::cout << CYAN << "\nPress 2 to back to show request sent menu\n" << RESET;
    int choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            for (auto i: houseVector) {
                for (int j = 0; j < i->listHouseRequest.size(); j++) {
                    if (i->listHouseRequest[j]->houseID == currentUser->requestList[ID - 1]->houseID) {
                        i->listHouseRequest.erase(i->listHouseRequest.begin() + j);
                    }
                }
            }
            currentUser->cancelRequest(ID);
            std::cout << GREEN << "\nRequest canceled\nBack to menu:\n" << RESET;
            showRequestSent();
            break;

        case 2:
            showRequestSent();
            break;
    }
}

void System::searchValidHouseMenu() {
    std::string startDate;
    std::string endDate;
    std::string location;
    Date *end, *start;
    int choice;
    std::cout << GREEN << "\tSearch for suitable houses: \n" << RESET;
    std::cout << CYAN << "\t---1. Search by your start day ---\n" << "\t---2. Search by your end day ---\n" << RESET;
    switch (menuChoice(1, 2)) {
        case 1:
            std::cin.ignore();
            do {
                std::cout << CYAN << "Enter when you want to rent (dd/mm/yyyy): " << RESET;
                std::getline(std::cin, startDate);
            } while (!isValidDate(startDate));
            std::cout << startDate << "\n";
            break;

        case 2:
            std::cin.ignore();
            do {
                std::cout << CYAN << "Enter when you want to end renting (dd/mm/yyyy): " << RESET;
                std::getline(std::cin, endDate);
            } while (!isValidDate(endDate));
            break;
    }

    std::cout << GREEN << "\tChoose the city you want to stay: \n\n" << RESET;
    std::cout << CYAN << "\t1. HANOI \t2.HUE \t3.SAIGON\n" << RESET;
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

    if (endDate.length() == 0) {
        end = nullptr;
    } else {
        end = stringToDate(endDate);
    }

    if (startDate.length() == 0) {
        start = nullptr;
    } else {
        start = stringToDate(startDate);
    }

    validHouseMenu(start, end, location);

}

void System::validHouseMenu(Date *start, Date *end, std::string location) {
    memberSuitableHouseList.clear();
    Request *request;
    int choice;
    if (end == nullptr) {
        getValidStartHouses(start, location);
    } else {
        getValidEndHouses(end, location);
    }
    std::cout << CYAN << memberSuitableHouseList.size() + 1 << ". Back to member menu\n" << RESET;
    choice = menuChoice(1, memberSuitableHouseList.size() + 1);
    if (choice == memberSuitableHouseList.size() + 1) {

        memberMenu();
    } else {
        memberSuitableHouseList[choice - 1]->viewHouseInfo();
        std::cout << CYAN << "\n\n--> 1.\tRequest to rent this house\n\n"
                  << "--> 2.\tView house's reviews\n\n"
                  << "--> 3.\tBack to house list\n" << RESET;
        switch (menuChoice(1, 3)) {
            case 1: {
                if (end == nullptr) {
                    request = new Request(start, memberSuitableHouseList[choice - 1]->endingDate, currentUser,
                                          memberSuitableHouseList[choice - 1]->houseID,
                                          RE_STATUS[0]);
                } else {
                    request = new Request(memberSuitableHouseList[choice - 1]->startingDate, end, currentUser,
                                          memberSuitableHouseList[choice - 1]->houseID,
                                          RE_STATUS[0]);
                }
                memberSuitableHouseList[choice - 1]->addRequestToHouseRequestList(request);
                memberMenu();
                break; //function send requests
            }
            case 2:
                std::cout << CYAN << "\nReviews of the house you want: \n" << RESET;
                memberSuitableHouseList[choice - 1]->viewHouseReview();
                std::cout << CYAN << "\n4. Back to the request action menu: \n" << RESET;
                if (menuChoice(4, 4) == 4) {
                    validHouseMenu(start, end, location);
                    break; //function view reviews
                }


            case 3:
                validHouseMenu(start, end, location);
                break;
        }
    }
}

void System::actionRequestMenu(int requestID) {
    std::cout << CYAN << "\n\n1.Show Requester Review\n2.Accept Request\n3.Decline Request\n" << RESET;
    switch (menuChoice(1, 3)) {
        case 1: {
            std::cout << GREEN << "\nThe review of your requester is being shown below: \n" << RESET;
            auto requester = currentUser->houseOwner->listHouseRequest[requestID]->requestedByMember;
            if (requester->tenantReviewList.empty()) {
                std::cout << RED << "\nThere are no reviews for this member\n" << RESET;
                std::cout << CYAN << "4.Back to the Request Menu: \n" << RESET;

                if (menuChoice(4, 4) == 4) {
                    actionRequestMenu(requestID);
                }
                break;
            } else {
                requester->showReview();
            }

            std::cout << CYAN << "4.Back to the Request Menu: \n" << RESET;
            if (menuChoice(4, 4) == 4) {
                actionRequestMenu(requestID);
                break;
            }
        }
        case 2:
            if (!currentUser->acceptRequest(requestID)) {
                std::cout << CYAN << "\n" << currentUser->houseOwner->listHouseRequest.size() + 1
                          << ".Back to request menu\n" << RESET;
                menuChoice(currentUser->houseOwner->listHouseRequest.size() + 1,
                           currentUser->houseOwner->listHouseRequest.size() + 1);
                viewRequestMenu();
            } else {
                std::cout << GREEN << "\nRequest accepted\n" << RESET;
                memberMenu();
                break;
            }
        case 3:
            //Return owner to request menu once there is no valid accept yet
            if (!currentUser->declineRequest(requestID)) {
                std::cout << RED << "You can not decline a request that has been accpeted and declinded" << RESET;
                std::cout << CYAN << "\n" << currentUser->houseOwner->listHouseRequest.size() + 1
                          << ".Back to request menu\n" << RESET;
                menuChoice(currentUser->houseOwner->listHouseRequest.size() + 1,
                           currentUser->houseOwner->listHouseRequest.size() + 1);
                viewRequestMenu();
            } else {
                std::cout << GREEN << "\nRequest Declined\n" << RESET;
                memberMenu();
                break;
            }

    }
}

void System::viewUnratedTenantList() {
    std::cout << CYAN << "\n\t\tList of Unrated Occupiers: \n" << RESET;
    if (currentUser->houseOwner->unratedTenant.empty()) {
        std::cout << RED << "\nThere are no tenants in your list\n" << RESET;
        memberMenu();
    }
    currentUser->viewUnratedList();
    std::cout << GREEN << "\n" << currentUser->houseOwner->unratedTenant.size() + 1 << ".Back to member menu" << RESET;
    std::cout << CYAN << "\nChoose the Tenant you would like to review: " << RESET;
    int choice = menuChoice(1, currentUser->houseOwner->unratedTenant.size() + 1);

    if (choice == currentUser->houseOwner->unratedTenant.size() + 1) {
        memberMenu();
    } else {
        std::string comment;
        std::string score;
        std::cout << CYAN << "\nPlease leave a comment to this tenant: " << RESET;
        std::cin.ignore();
        std::getline(std::cin, comment);
        std::cout << CYAN << "\nPlease score the Tenant: " << RESET;
        while (true) {
            std::cout << CYAN << "\n\t\tPlease leave a score: " << RESET;
            std::cin >> score;
            if (!isValidNum(score)) {
                continue;
            }
            if (std::stoi(score) < -10 || std::stoi(score) > 10) {
                std::cout << RED << "The rating scores can only be from -10 to 10: " << RESET;
                continue;
            }else{
                break;
            }
        }
        currentUser->reviewTenant(choice - 1, std::stoi(score), comment);
        memberMenu();
    }

}

void System::viewRequestMenu() {
    int choice;
    std::cout << CYAN << "\n\n\tYour request today:\n\n" << RESET;
    if (currentUser->houseOwner == nullptr) {
        std::cout << RED << "You do not have a house. So you do not have any request! \n" << RESET;
        memberMenu();
    } else {
        int numberRequest = currentUser->viewAllRequest();
        std::cout << GREEN << "\n\tChoose your option:\n\n" << RESET;
        std::cout << CYAN << "\n\n--> 1.\tPoint the Request:\n\n"
                  << "--> 2.\tBack to Menu\n" << RESET;
        choice = menuChoice(1, 3);
        switch (choice) {
            case 1: {
                std::cout << GREEN << "Enter the request you want to proceed: \n" << RESET;
                int newChoice = menuChoice(1, numberRequest);
                actionRequestMenu(newChoice - 1);
                break;
            }
            case 2:
                memberMenu();
                break;
        }
    }

}

bool System::memRequestHouse(Date *startDate, Date *endDate, int houseId) {
    if (houseId > memberSuitableHouseList.size()) {
        return false;
    }

}

bool System::isValidStartHouses(Date *start, Member *mem, House *house, std::string location) {

    int count = 0;
    if (!house->isAdded) {
        return false;
    }

    if (house->houseStatus == STATUS[1]) {
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

    if (house->startingDate->convertDatetoString() == start->convertDatetoString()) {
        return true;
    }
    return false;

}

bool System::isValidEndHouses(Date *end, Member *mem, House *house, std::string location) {
    if (!house->isAdded) {
        return false;
    }

    if (house->houseStatus == STATUS[1]) {
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


    if (house->endingDate == end) {
        return true;
    }

    return false;
}

bool System::getValidStartHouses(Date *start, std::string location) {
    memberSuitableHouseList.clear();
    for (auto &house: houseVector) {
        if (isValidStartHouses(start, currentUser, house, location)) {
            memberSuitableHouseList.push_back(house);
        }
    }

    if (memberSuitableHouseList.empty()) {
        std::cout << RED << "\nThere is no houses matched your search\n" << RESET;
        return false;
    }

    std::cout << GREEN << "\nThe suitable house list:\n\n" << RESET;
    for (int i = 0; i < memberSuitableHouseList.size(); i++) {
        std::cout << CYAN << "--> " << i + 1 << ". " << RESET;
        std::cout << CYAN << "House Id: " << memberSuitableHouseList[i]->houseID << "\tLocation: "
                  << memberSuitableHouseList[i]->location << "\tRating: "
                  << memberSuitableHouseList[i]->getRatingScore() << "\n" << RESET;
    }
    std::cout << "\n\n";

    return true;
}

bool System::getValidEndHouses(Date *end, std::string location) {
    memberSuitableHouseList.clear();
    for (auto &house: houseVector) {
        if (isValidEndHouses(end, currentUser, house, location)) {

            memberSuitableHouseList.push_back(house);
        }
    }

    if (memberSuitableHouseList.empty()) {
        std::cout << RED << "\nThere is no houses matched your search\n" << RESET;
        return false;
    }

    std::cout << GREEN << "\nThe suitable house list:\n\n" << RESET;
    for (int i = 0; i < memberSuitableHouseList.size(); i++) {
        std::cout << "--> " << i + 1 << ". ";
        std::cout << CYAN << "House Id: " << memberSuitableHouseList[i]->houseID << "\tLocation: "
                  << memberSuitableHouseList[i]->location << "\tRating: "
                  << memberSuitableHouseList[i]->getRatingScore() << "\n" << RESET;
    }
    std::cout << "\n\n";

    return true;
}

bool System::deleteInRentHouse() {
    if (currentUser->deleteHouse()) {
        std::cout << GREEN << "\nSuccessfully omit the house\n" << RESET;
        return true;
    } else {
        std::cout << CYAN << "The house have requests hanging. Resolved all before omitting! \n" << RESET;
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
        owner->addHouse(startDate, endDate, credits, scores, status);
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
        Request *req = new Request(startDate, endDate, targetMem, targetHouse->houseID, status);
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
                  << mem->getRatingScore() << "\n";
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
                  << house->getRatingScore() << "\n";
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
                std::cout << RED << "The app do not support you in your region! \n" << RESET;
                mainMenu();
                return false;
            }
            std::cout << GREEN << "Log in successfully!!! \n\n" << RESET;
            return true;
        }
    }
    std::cout << RED << "\n\nWrong username or password!!! \n" << RESET;
    return false;
}

void System::registerMember() {
    int choice;
    int subChoice;
    std::string username, password, fullname, phoneNum, location;
    std::cout << GREEN << "\t---MEMBER REGISTRATION---\n" << RESET;
    std::cin.ignore();
    do {
        std::cout << CYAN << "Enter your username: " << RESET;
        getline(std::cin, username);
    } while (!isValidUserName(username));

    do {
        std::cout << CYAN << "Enter your password: " << RESET;
        getline(std::cin, password);
    } while (!isValidPassword(password));

    do {
        std::cout << CYAN << "Enter your fullname: " << RESET;
        getline(std::cin, fullname);
    } while (!isValidFullname(fullname));

    do {
        std::cout << CYAN << "Enter your phone number: " << RESET;
        getline(std::cin, phoneNum);
    } while (!isValidPhoneNum(phoneNum));


    std::cout << CYAN << "1. Choose the locations the app support \n" << RESET;
    std::cout << CYAN << "2. Enter the location yourself \n" << RESET;
    choice = menuChoice(1, 2);
    switch (choice) {
        case 1:
            std::cout << CYAN << "Choose the following locations: \n" << RESET;
            std::cout << GREEN << "1.HANOI\t2.HUE\t3.SAIGON\n" << RESET;
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
            std::cout << CYAN << "Enter your location: " << RESET;
            getline(std::cin, location);
            break;
    }
    Member *newMem = new Member(username, password, "MEM" + std::to_string(memberVector.size() + 1), fullname,
                                phoneNum,
                                INITIAL_CREDITS, INITIAL_SCORES, location);
    memberVector.push_back(newMem);
    std::cout << GREEN << "You have registered successfully!\n" << RESET;
    mainMenu();
}

Date *System::stringToDate(std::string &date) {
    std::vector<std::string> dataLst = splitStr(date, '/');
    Date *convertedDate = new Date(std::stoi(dataLst[0]), std::stoi(dataLst[1]), std::stoi(dataLst[2]));
    return convertedDate;

}
