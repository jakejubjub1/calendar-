#ifndef SOFT_H
#define SOFT_H
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
/*
test
*/

class Soft{

    public:
        Soft();
        virtual ~Soft();
        void getDuration(vector<Soft>& softEvent,int index);
        void getLocation(vector<Soft>& softEvent,int index);

        void set_location_name();
        char* get_location_name(int i);
        int get_day();
        void set_day(int a);
        int get_month();
        void set_month(int a);
        int get_hour();
        void set_hour(int a);
        int get_min();
        void set_min(int a);
        int get_duration();
        void set_duration(int a);
        void set_user_location(char* a);
        char* get_user_location();

    protected:

    private:
        int month;///for due day
        int day;///for due day
        int time_hour;///for due day
        int time_min;///for due day
        char** location_name;///name of the location that event happends
        char* user_loaction;
        unsigned int duration;

};

#endif // SOFT_H

