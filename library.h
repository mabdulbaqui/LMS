//
// Created by Moham on 5/28/2022.
//

#ifndef UNTITLED2_LIBRARY_H
#define UNTITLED2_LIBRARY_H
#include "borrowed_book.h"
#include "helper.h"
#include "book.h"
#include "gest.h"
#include <vector>
#include <iostream>
#include <string>
using  namespace  std;
class library{
private:
    vector<book>books;
    vector<borrowed_book>b_books;
    vector<gest>gests;
public:
    int counterb=0 ;
    int counterbb=0 ;
    int guest=0 ;

public:
    library(){};

    static bool find_book(const library& lb,const string& name,int index) {
        if (index == 1) {
            for (const auto &a: lb.books) {
                if (a.getBookName() == name)return true;
            }
        }

        else if (index == 2) {
            for (const auto &x: lb.b_books) {
                if (x.getBookName() == name)return true;
            }
        }
    }


    static bool find_gest(const library& lb ,const string & name ,int index) {
        if (index == 1) {
            for (const auto a: lb.b_books){
                if(a.getGestName()==name)return  true;
            }

        }
        else if (index==2){
            for(const auto a:lb.gests){
                if(a.getName()==name)return true;
            }
        }
        return false;
    }


    bool  not_avaliable(const string& bookName){
        for(const auto& obj : b_books){
            if(obj.getBookName() == bookName)
                return true ;
        }
        return false;

    }


public :void add_book(const book& b){
        counterb ++;
        books.emplace_back(b);
        cout<< " book has been add successfully \n";
    }
public:void add_bookb(const borrowed_book& bb){
        counterbb++;
        b_books.emplace_back(bb);
        for(auto& a:books){
            if(a.getBookName()==bb.getBookName()){
                cout<<a.getBookName()<<"   "<<bb.getBookName()<<"\n";
                a.setNotavaliable(1);}
        }

        cout<< "book barrow _book has been add successfully \n and the total cost of to be late:"<<bb.getTotalCost()<<"\nand the end date is: "<<bb.getEndDay()+'\n';
        helper::cont();
    }

public:void add_gest(const gest& g){
        guest++;
        gests.emplace_back(g);
        cout<< "guest has been add successfully \n";
    }
    bool return_book(string name){
        for (int i =0 ; i <b_books.size();i++){
            if (b_books[i].getBookName()==name){
                b_books.erase(b_books.begin()+i);
                return true;
            }
        }
        return false;
    }
    string find_gest(int id){
        string ret;
        for (auto q :gests){
            if (q.getIdNumber()==id) {
                ret= "name : " + q.getName() + '\n' + "phone_number: " + q.getPhoneNumber() + '\n' +"phone_number : " + to_string(q.getIdNumber())+'\n';
                for (auto x: b_books) {
                    if (q.getName() == x.getGestName()) {
                        ret += "the book has been borrowed  " + x.getBookName()+"\n";
                        return ret;
                    }
                }
                return ret;
            }
        }
        return "NotFound\n";
    }
    string find_book(const int& id){
        string ret="NotFound\n";
        cout<<books.size();
        for (const auto& q :books){
            cout<<q.getId()<<" her \n";


            if (id == q.getId()) {
                ret= "name : " + q.getBookName() + '\n' + "id: " + to_string(q.getId())+ '\n' +"notAvailable : " + to_string(q.getNotavaliable())+"\n";
                }
                return ret;
            }
        return ret;
    }

    string find_book(const string& name){
        string ret="NotFound \n";
        for (const auto& q :books){
            cout<<q.getBookName();
            if (name == q.getBookName()) {
                ret= "name : " + q.getBookName() + '\n' + "id: " + to_string(q.getId())+ '\n' +"Available : " + to_string(q.getNotavaliable())+"\n";
            }
            return ret;
        }
        return ret;
    }


public: const vector<book> &getBooks() const {
        return books;
    }
public:const vector<borrowed_book> &getBBooks() const {
        return b_books;
    }
public:const vector<gest> &getGests() const {
        return gests;
    }
public:int getCounterb() const {
        return counterb;
    }
public:int getCounterbb() const {
        return counterbb;
    }
public:int getGuest() const {
        return guest;
    }
};



#endif //UNTITLED2_LIBRARY_H
