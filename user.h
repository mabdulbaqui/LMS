//
// Created by Moham on 5/28/2022.
//

#ifndef UNTITLED2_USER_H
#define UNTITLED2_USER_H
#include <iostream>
using  namespace std;
class user{
public:
    string user_name;
    int password{};

public:
    user(string userName, int password) : user_name(std::move(userName)), password(password) {}

    explicit user(string userName) : user_name(std::move(userName)) {}
};
#endif //UNTITLED2_USER_H
