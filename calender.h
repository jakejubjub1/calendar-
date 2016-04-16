#ifndef CALENDER_H
#define CALENDER_H
#include "Soft.h"
#include "event.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class calender{



    public:
        calender(int size);
        virtual ~calender();
        void showCalender(vector<Event>& eventList,vector<Soft>& softEvent,int month,int day);
        void getTimeFrame(vector<Event>& eventList,char** calenderChar,bool* calenderBool,int day,int index);

    protected:
    private:
        char** calenderChar;
        bool* calenderBool;
};

#endif // CALENDER_H
