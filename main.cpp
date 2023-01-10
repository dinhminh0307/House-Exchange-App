


#include "System/System.h"

int main(){
    System sys;
    sys.inputMemberToSys();
    if(sys.loginMember()){
        std::cout << "Logged in successfully!";
    }
    sys.outputMemberToFile();
}