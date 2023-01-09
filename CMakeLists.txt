cmake_minimum_required(VERSION 3.23)
project(dapdixaylai)

set(CMAKE_CXX_STANDARD 14)

include_directories(System)

add_executable(dapdixaylai
        main.cpp
        Class/Request/Request.h
        Class/Request/Request.cpp
        Class/Date/Date.cpp
        Class/Date/Date.h
        System/System.cpp
        System/System.h
        Class/Member/Member.cpp
        Class/Member/Member.h
        Class/User/User.h
<<<<<<< HEAD
        Class/User/User.cpp Class/Admin/Admin.cpp Class/Admin/Admin.h Class/House/House.cpp Class/House/House.h Class/Review/Review.cpp Class/Review/Review.h)
=======
        Class/User/User.cpp
        Class/Admin/Admin.cpp
        Class/Admin/Admin.h
        Class/House/House.cpp
        Class/House/House.h Class/Rating/Rating.cpp Class/Rating/Rating.h Class/Request/Request.cpp Class/Request/Request.h Class/HouseList/HouseList.cpp Class/HouseList/HouseList.h Class/Date/Date.cpp Class/Date/Date.h main.cpp)
>>>>>>> 8a16c053955ee69cda0326bf04ff7abbdf5021dc


