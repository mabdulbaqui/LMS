#include<bits/stdc++.h>
#include "book.h"
#include "gest.h"
#include "user.h"
#include "borrowed_book.h"
#include "library.h"
using  namespace std;
int main(){
    library lb = * new library();
    string username;
    int password;
    user admin("mohamed",123);
    vector<gest> gests;
    cout<<"hello \n";
    cout<<" opreate the system please enter your username and pasword \n";
    while (true){
        cout<<"Username : \n";
        cin>>username;
        cout<<"password  : \n";
        cin>>password;
    if(admin.user_name == username && admin.password== password){
        cout<<"welcom "<<admin.user_name<<"\n";
        break;
        }
    cout<<"try adin \n";
    }
    int condition;
    while (true){
        cout<<"Please chose operations \n1.add_book\n2.add_new_gest\n3.borrow_book\n4.return_book\n5.browse_books\n6.find_guest\n7.find_book\n8.find_rented_book\n9.browse_all_rented_books\n10.browse_all_gests \n11.Exit\n";
        cin>>condition;
            if (condition ==1) {
                int id;
                string name;
                id=lb.counterb;
                cout << "book_name \n";
                cin >> name;
                cout << " avaliable";
                book bo(id, name, 0);
                lb.add_book(bo);
            }
            else if   (condition ==2){
                string name,  phoneNumber; int idNumber;
                cout<<"gest name \n";
                cin>>name;
                cout<<"phoneNumber \n";
                cin>>phoneNumber;
                cout<<"idNumber \n";
                cin>>idNumber;
                lb.add_gest(gest( name,  phoneNumber,  idNumber));
            }
        else if   (condition ==3) {
                int rentDays;
                float pricePerDay;
                string book_name;
                string gest_name;
                cout << "the number of rentDays \n";
                cin >> rentDays;
                cout << "the  pricePerDay \n";
                cin >> pricePerDay;
                cout << "book_name \n";
                cin >> book_name;
                cout << "gest name \n";
                cin >> gest_name;
                if (library::find_book(lb, book_name, 1) && library::find_gest(lb,gest_name,2)&& !lb.not_avaliable(book_name)) {
                  borrowed_book  bb(rentDays, pricePerDay, book_name, gest_name);
                    lb.add_bookb(bb);
                } else {
                    int cases;
                    cout << "the book name or user name in not correct \nplz re enter the book name aging or back\n to back enter 1 else enter 0 \n";
                    cin>>cases;
                    while (cases) {
                        cout<<"enter book name";
                        cout<<"enter user name name";
                        cin >> book_name;
                        cin>>gest_name;
                        if (library::find_book(lb, book_name, 1) && library::find_gest(lb,gest_name,1) && !lb.not_avaliable(book_name)) {
                            borrowed_book  bb(rentDays, pricePerDay, book_name, gest_name);
                            lb.add_bookb(bb);
                            break;
                        }
                        else{
                            cout << "the book name in not correct \nplz re enter the book name aging or back\nto re_enter press 1 else press 0 \n";
                            cin>>cases;

                        }
                    }
                }
            }
            else if(condition ==4){
                string bookname;
                cout<<"book_name";
                cin>>bookname;
                if (lb.return_book(bookname)){cout<<"the book has been returned scruffily \n";}
            }

        else if   (condition ==5) {
//                int stop = 1;

                    for (auto x: lb.getBooks()) {
                        cout << "name : "<<x.getBookName()<<"\n"<<"id : "<<x.getId()<<'\n'<<"rented"<<x.getNotavaliable()<<'\n';

                    }
//                cin>>stop;
//                    while (stop);
                    helper::cont();
                }

            else if   (condition ==6){
            int  id;
            cout<<  "enter guest id \n";
            cin>>id;
//            int stop=1;
                    cout << lb.find_gest(id);

                helper::cont();

            }
            else if(condition ==7) {
                    cout << "name or id\n";
                    string selector;
                    cin >> selector;

                    if (selector == "name") {
                        string name;
                        cout << "Enter book name\n";
                        cin >> name;
                        cout << lb.find_book(name);
                        helper::cont();
                    }
                    else if (selector == "id") {
                        int id;
                        cout << "Enter book id\n";
                        cin >> id;
                        lb.find_book(id);
                        helper::cont();
                    }
                    cout << "id or name only\n";

                }

            else if(condition ==8){
                int id ;
                string name;
                cout<<"enter your book id or name for name enter name for id enter id \n";

                for(auto a:lb.getBBooks()){
                       if( a.getBookName()==name){
                           cout<< "the_book_name : "<<a.getBookName()<<"\nthe_guest_name"<<a.getGestName()<<"\nthe_total_cost"<<a.getTotalCost()<<"\nthe_start_day"<<a.getStratDay()<<"\nthe_end_date"<<a.getEndDay()<<"\n";
                           break;
                       }
                    }

                }

            else if(condition ==9){
                for(auto a:lb.getBooks()) {
                    if (a.getId() == 1) {
                        cout << "name : " << a.getBookName() << "\n" << "id : " << a.getId() << '\n' << "rented" << a.getNotavaliable() << '\n';
                    }
                }

            }

            else if(condition ==10){

                for(auto q:lb.getGests()){
                    string ret="name : " + q.getName() + '\n' + "phone_number: " + q.getPhoneNumber() + '\n' +"phone_number : " + to_string(q.getIdNumber())+'\n';
                    cout<<ret ;
                }
            }
            else if(condition==11){ break;}





    }


    }