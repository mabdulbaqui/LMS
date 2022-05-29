//
// Created by Moham on 5/28/2022.
//

#ifndef UNTITLED2_GEST_H
#define UNTITLED2_GEST_H
#include <iostream>
using  namespace  std;
class gest {
private:

    string name ;
    string  phone_number;
    int id_number;
public:
    gest(){}
    gest(string name, string phoneNumber, int idNumber) : name(std::move(name)), phone_number(std::move(phoneNumber)),
                                                          id_number(idNumber) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        gest::name = name;
    }

    const string &getPhoneNumber() const {
        return phone_number;
    }

    void setPhoneNumber(const string &phoneNumber) {
        phone_number = phoneNumber;
    }

    int getIdNumber() const {
        return id_number;
    }

    void setIdNumber(int idNumber) {
        id_number = idNumber;
    }

};

#endif //UNTITLED2_GEST_H
