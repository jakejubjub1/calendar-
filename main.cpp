#include "event.h"
#include "Soft.h"
#include "time.h"
#include "calender.h"
#include "newSleepTimeChang.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
void showVector(vector<Event>& HardEvent,vector<Soft>& softEvent);

int main() {

    time_t currentTime;
    struct tm *localTime;///struct to get a current time
    time( &currentTime );                   // Get the current time
    localTime = localtime( &currentTime );  // Convert the current time to the local time
    int Day    = localTime->tm_mday;
    int Month  = localTime->tm_mon + 1;
    int Year   = localTime->tm_year + 1900;
    int Hour   = localTime->tm_hour;
    int Min    = localTime->tm_min;
    int Sec    = localTime->tm_sec;


    Event* event = new Event();///create hard event
    Soft* soft = new Soft();///create soft event
    calender* calen = new calender(169);
    newSleepTimeChang* newSleepTime = new newSleepTimeChang(calen);


    std::cout << "This program was exectued at: " << Hour << ":" << Min << ":" << Sec << std::endl;
    std::cout << "\tThe current data : " << Month << "/" << Day << "/" << Year << endl<<endl;
    int choice = event->menu();

    vector<Event> HardEvent;
    vector<Soft> softEvent;


    while(choice!= 5) {

        switch(choice) {
        case 1: {
            cout<<"1 .hard"<<endl;
            cout<<"2 .soft"<<endl;
            int hardOrsoft;
            cin>> hardOrsoft;

            switch(hardOrsoft) {
            case 1:{
                ///create new object for an event
                Event* newEvent = new Event();
                ///add new event to evetlist
                HardEvent.push_back(*newEvent);

                int index = HardEvent.size()-1;
                event->getDate(HardEvent,index,Month,Day);
                time_t start = event->getStartTime(HardEvent,index);
                event->getEndTime(start,HardEvent,index);
                event->getLocation(HardEvent,index);
                event->getTask(HardEvent,index);
                break;
            }
            case 2:{
                Soft* newSoft = new Soft();
                softEvent.push_back(*newSoft);

                int index = softEvent.size()-1;
                soft->getDate(softEvent,index,Month,Day);
                soft->getDueTime(softEvent,index);
                soft->getDuration(softEvent,index);///done
                soft->getLocation(softEvent,index);
                soft->getTask(softEvent,index);
                break;
                }
            }
            break;
        }
        case 2: {
            showVector(HardEvent,softEvent);
            break;
        }
        case 3: {
            event->makeChange(HardEvent);
            break;
        }
        case 4:{
            calen->showCalender(HardEvent,softEvent,Month,Day);
            break;
        }
        case 6:{
            newSleepTime->get_new_sleep(Month,Day);

            break;
        }

        }//end of switch

        std::cout << "\tThe current data : " << Month << "/" << Day << "/" << Year << std::endl<<endl;
        choice = event->menu();

    }//ebd of while
    return 0;
}

void showVector(vector<Event>& HardEvent,vector<Soft>& softEvent){

    int softOrHard;

    if(HardEvent.size() == 0 && softEvent.size() == 0 ){
        cout<<"No items to show\n\n";
        return;
    }

    cout<<"1. hard"<<endl;
    cout<<"2. soft"<<endl;
    cin >>softOrHard;

    switch(softOrHard) {
        case 1: {
            if(HardEvent.size() == 0 ) {
                cout<<"No hard items to show\n\n";
                return;
            }

            for(int i=0; i<HardEvent.size(); i++) {
                cout<<i+1<<"\n";
                cout<<HardEvent[i].get_month()<<"/"<<HardEvent[i].get_day()<<endl;
                cout<<"Task Name       : "<<HardEvent[i].get_task()<<endl;
                cout<<"task start      : "<<HardEvent[i].get_start_time()<<endl;
                cout<<"task End        : "<<HardEvent[i].get_end_time()<<endl;
                cout<<"Location        : "<<HardEvent[i].get_user_loaction()<<endl<<endl;
            }
            break;
        }
        case 2: {
            if(softEvent.size() == 0 ) {
                cout<<"No soft items to show\n\n";
                return;
            }
            for(int i=0; i<softEvent.size(); i++) {
                cout<<i+1<<"\n";
                cout<<softEvent[i].get_month()<<"/"<<softEvent[i].get_day()<<endl;
                cout<<"Task Name        : "<<softEvent[i].get_task()<<endl;
                cout<<"due              : "<<softEvent[i].get_due()<<endl;
                cout<<"duration         : "<<softEvent[i].get_duration()<<endl;
                cout<<"Location         : "<<softEvent[i].get_user_location()<<endl<<endl;
            }
            break;
        }
    }
}

