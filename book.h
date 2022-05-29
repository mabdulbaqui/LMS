//
// Created by Moham on 5/28/2022.
//

#ifndef UNTITLED2_BOOK_H
#define UNTITLED2_BOOK_H
#include <iostream>
using  namespace std;
class book {
private:
    int id=0;
    string book_name ;
    int  notavaliable=0;
public:
    book(){}
    book(int id, string bookName, int notavaliable) : id(id), book_name(std::move(bookName)), notavaliable(notavaliable) {}

    int getId() const {
        return id;
    }

    const string &getBookName() const {
        return book_name;
    }

    int getNotavaliable() const {
        return notavaliable;
    }

    void setId(int idd) {
        book::id = idd;
    }

    void setBookName(const string &bookName) {
        book_name = bookName;
    }

    void setNotavaliable(int notavaliable) {
        book::notavaliable = notavaliable;
    }
};
#endif //UNTITLED2_BOOK_H