

#include "System/System.h"
#include <iostream>

int main(){
    System sys;
    sys.inputMemberToSys();
    if(sys.loginMember()){
        std::cout << "Logged in successfully!";
    }
    sys.outputMemberToFile();

}