//
// Created by Moham on 5/28/2022.
//

#ifndef UNTITLED2_BORROWED_BOOK_H
#define UNTITLED2_BORROWED_BOOK_H
#include "helper.h"
#include <iostream>
#include <utility>
using  namespace  std;
class borrowed_book {
private:
    string gest_name;
    string book_name;
    string strat_day;
    string end_day;
    float  total_cost;

public:
    borrowed_book(){}
    borrowed_book(int rentDays, float pricePerDay,string bookName,string gestName):book_name(std::move(bookName)),gest_name(std::move(gestName)){
        time_t now = time(0);
        this->strat_day=ctime(&now);
        this->end_day=helper::printNewDate(rentDays);
        this->total_cost=(float)rentDays * pricePerDay;
    }

    const string &getStratDay() const {
        return strat_day;
    }

    const string &getEndDay() const {
        return end_day;
    }

    float getTotalCost() const {
        return total_cost;
    }

    const string &getBookName() const {
        return book_name;
    }

    const string &getGestName() const {
        return gest_name;
    }
};

#endif //UNTITLED2_BORROWED_BOOK_H
