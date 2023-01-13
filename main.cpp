
#include "System/System.h"

#include "Class/User/User.h"
#include "Class/House/House.h"
#include "Class/Tenant/Tenant.h"
#include "Class/Request/Request.h"
#include "Class/Review/Review.h"
#include "Class/OccupyHouse/OccupyHouse.h"
#include "Class/Member/Member.h"
#include "Class/Date/Date.h"
#include "define.h"

int main(){
    System sys;
    sys.inputAdminToSys();
    sys.inputMemberToSys();
    sys.inputHouseToSys();
    sys.inputMemHouseToSys();
    sys.inputHouseLstToSys();
    sys.inputOccupierToSys();  //check this
    sys.inputRatingHouseToSys();
    sys.inputRatingTenantToSys();
    sys.inputRequestToSys();
    sys.inputUnratedToSys();
    sys.mainMenu();

}