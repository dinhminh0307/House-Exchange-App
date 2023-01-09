<<<<<<< HEAD
//#include "./CLass/Date/Date.h"
#include "Class/Member/Member.h"
#include "Class/User/User.h"
#include "./System/System.h"
int main() {
    Member member("kien", "kien", "1", "vo", "0901", 12, 13, "hue");
    member.showAccountInfo();
=======


#include "System/System.h"

int main(){
    System sys;
    sys.inputMemberToSys();
    if(sys.loginMember()){
        std::cout << "Logged in successfully!";
    }
    sys.outputMemberToFile();
>>>>>>> 8a16c053955ee69cda0326bf04ff7abbdf5021dc
}