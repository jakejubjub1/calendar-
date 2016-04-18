
/*

    4/10/2016
    -user input for event (not all fields)
    -user is able to make a chnage for the event 
    -show the events 
    
    
    4/14/2016
    - added soft
    - added functions change an event 


    4/16/2016
    - hard event into calender 
    - added calkender class

    4/18/216
    
*/
#ifndef EVENT_H
#define EVENT_H
#include "time.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Event{

    friend class Soft;
    friend class calender;

    public:
        //Event(time_t start, time_t end,char* location);
        Event();
        virtual ~Event();
        int menu();
        vector<Event> fillVector(vector<Event>& eventList);
        void getLocation(vector<Event>& eventList,int index);
        void getUserinfo();
        int getStartTime(vector<Event>& eventList,int index);
        void getEndTime(int start,vector<Event>& HardEvent,int index);
        void getDate(vector<Event>& HardEvent, int index,int month, int day);
        void makeChange(vector<Event>& HardEvent);
        int pickChangeField(vector<Event>& HardEvent, int choice);
        void changeField(vector<Event>& HardEvent, int index,int field);
        bool isSleeping(vector<Event>& eventList,int i,int index);
        void getSleepingTime(vector<Event>& eventList,int index);
        bool validStartingTime(vector<Event>& eventList,int i,int index);
        bool validSleepTime(vector<Event>& eventList,int i,int index);
        void getTask(vector<Event>& eventList,int index);

        ///getter and setter
        double get_location_x();
        void set_location_x(double a);
        double get_location_y();
        void set_location_y(double a);
        unsigned int get_duration();
        unsigned int set_duration(unsigned int a);
        int get_start_time();
        void set_start_time(int a);
        int get_end_time();
        void set_end_time(int a);
        char* get_location_name(int i);
        void set_location_name();
        void set_user_loaction(char* i);
        char* get_user_loaction();
        void set_sleep_time_begin(int slee_time_begin);
        int get_sleep_time_begin();
        void set_sleep_time_end(int slee_time_end);
        int get_sleep_time_end();
        int get_day();
        void set_day(int a);
        int get_month();
        void set_month(int a);
        char* get_task();
        void set_task(char* a);
        void set_hard_task_list();
        void set_recurring(bool r);
        bool get_recurring();

    protected:

    private:
        bool recurring;
        int month;
        int day;
        double location_x;
        double location_y;
        unsigned int duration;
        int start_time;
        int end_time;
        char** location_name;///name of the location that event happends
        char* subject_name;///class or go to gym
        int sleep_time_begin;
        int sleep_time_end;
        char* user_loaction;
        char* task;
        char** hard_task_list;
};

#endif // EVENT_H
