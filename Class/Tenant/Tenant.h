#ifndef TENANT_H
#define TENANT_H
#include <iostream>
#include <vector>

class Member;
class Request;
class Tenant{
    private:
        std::vector <Request> listOfRequest;
    public:
    friend class Member;
};
#endif