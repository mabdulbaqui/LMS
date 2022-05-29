//
// Created by Moham on 5/28/2022.
//

#ifndef UNTITLED2_HELPER_H
#define UNTITLED2_HELPER_H
#include <iostream>
#include <ctime>
using  namespace std;
class helper {
public: string static printNewDate(int days)
    {
        time_t newtime = time(0)+86400*days;
        char * current_date= ctime(&newtime);
        return current_date;
    }

public:  static void cont(){
        int stop;
        cout<<"press 0 to continue\n";
        cin>>stop;
        while (stop);
}
};
#endif //UNTITLED2_HELPER_H
