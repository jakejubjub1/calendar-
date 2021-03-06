#include "event.h"
#include "string.h"
#include "time.h"
#include "Soft.h"
#include "calender.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>///for time
using namespace std;

///this is not used...
Event::Event(time_t start, time_t end,char* location){
    location_x = 0;
    location_y = 0;
    duration =0;
    start_time =start;
    end_time =end;
    user_loaction = location;
    //location_name = new char*[25];///name is no more than 25 character
    //set_location_name();
}

Event::Event(){
    location_name = new char*[25];
    hard_task_list = new char*[6];
    set_location_name();
    set_hard_task_list();
    sleep_time_begin =0; ///default sleep time start
    sleep_time_end = 6;///default sleep time end
    start_time = 0;
    end_time = 0;
}

Event::~Event()
{
    //dtor
}

void Event::getTask(vector<Event>& eventList,int index){

   bool valid = true;
    int choice;
    for(int i=0;i<6;i++){
        cout<<i+1<<". "<<hard_task_list[i]<<endl;
    }
    cin>>choice;

    while(valid){
        if(choice<1 || cin.fail() ||choice>5){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;
    }
    eventList[index].set_task(hard_task_list[choice-1]);


}

void Event::getDate(vector<Event>& eventList,int index,int month, int day){
    int* dayArray = new int[7];
    int getDay;
    bool valid = true;



    eventList[index].set_month(month);///initializing

    ///day
    int j=0;
    int i;
    for(i =day;i<day+7;i++){
        dayArray[j] =i+1;
        cout<<j+1<<" "<<month<<"/"<<i+1<<endl;
        j++;
    }

    cout<<"pick a day:";

    valid  = true;
    while(valid){
        cin>>getDay;
        if(cin.fail() ||getDay<0 || getDay>8){
            std::cout<<"\n*** Invalid input ***\n";
            std::cout<<"    Enter an Integer\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }

        eventList[index].set_day(dayArray[getDay-1]);///initializing
        valid = false;
    }

}//end of getDate

time_t Event::getStartTime(vector<Event>& eventList,int index){
    int* time = new int[24];
    time_t Start;
    bool valid = true;

    std::cout<<"choose statring time: "<<endl;

    ///time frame of 0-24
    for(int i=0;i<24;i++){
        time[i] = i;
        if(i>=eventList[index].get_sleep_time_begin() && i<=eventList[index].get_sleep_time_end()){
            cout<<i+1<<". "<< time[i]<<" sleep"<<endl;
            continue;
        }
            cout<<i+1<<". "<< time[i]<<endl;
    }

    while(valid){
        cin>>Start;
        if(cin.fail() ||Start>23 || Start<1 || isSleeping(eventList,Start,index) || validStartingTime(eventList,Start,index)){
            std::cout<<"\n*** Invalid input ***\n";
            std::cout<<"    Enter an Integer\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }

        eventList[index].set_start_time(time[Start-1]);///initializing
        //start_time = time[Start-1];
        valid = false;
    }

    return Start;
}
bool Event::validStartingTime(vector<Event>& eventList,int i,int index){
    cout<<i<<">="<<eventList[index].get_end_time()<<" && "<<eventList[index].get_end_time()<<" != 0"<<endl;

    if(i>eventList[index].get_end_time() && eventList[index].get_end_time() != 0)
        return true;

        return false;
}

bool Event::isSleeping(vector<Event>& eventList,int i,int index){

    if(i>=eventList[index].get_sleep_time_begin() && i-1<=eventList[index].get_sleep_time_end()){
            return true;
    }
        return false;
}

void Event::getEndTime(time_t start,vector<Event>& eventList,int index){
    time_t endTime;
    int end;
    bool valid = true;
    int* time = new int[24];
    for(int i=0;i<24;i++)
        time[i] = i;

    ///display the ending time
    cout<<"Pick ending time"<<endl;
    for(int i=0;i<24;i++){

        if(i>=start){
            if(i>=eventList[index].get_sleep_time_begin() && i<=eventList[index].get_sleep_time_end()){
                cout<<i+1<<". "<< time[i]<<" sleep"<<endl;
                continue;
            }
            cout<<i+1<<". "<< time[i]<<endl;
        }
    }

    while(valid){
        cin>>end;
        if(cin.fail() ||end>24 || end<1 || end<=start ||isSleeping(eventList,end,index)){
            std::cout<<"\n*** Invalid input ***\n";
            std::cout<<"    Enter an Integer\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }
        eventList[index].set_end_time(time[end-1]);
        //set_end_time(time[end-1]);
        valid = false;
    }
}//end of getEndTime

int Event::menu(){
    int choice;
    std::cout<<"1. Add Event"<<endl;
    std::cout<<"2. show list"<<endl;
    std::cout<<"3. change an event"<<endl;
    std::cout<<"4. show Calender"<<endl;
    std::cout<<"5. Exit"<<endl;
    std::cout<<":";
    std::cin >> choice;

    return choice;
}

void Event::getLocation(vector<Event>& eventList,int index){
    bool valid = true;
    int choice;
    for(int i=0;i<25;i++){
        cout<<i+1<<". "<<location_name[i]<<endl;
    }
    cin>>choice;

    while(valid){
        if(choice<1 || cin.fail() ||choice>26){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;
    }
    eventList[index].set_user_loaction(location_name[choice-1]);

}
void Event::getSleepingTime(vector<Event>& eventList,int index){

    bool valid = true;
    int start,end;
cout<<eventList[index].get_start_time()<<"-"<<eventList[index].get_end_time()<<endl;
    cout<<"Enter sleeping time begin:\n";
    for(int i=0;i<24;i++){
     if(i >= eventList[index].get_start_time() && i <= eventList[index].get_end_time()){
            cout<<i<<". "<<i<<"   Event\n";
            continue;
        }
            cout<<i<<". "<<i<<endl;
    }

    while(valid){
        cin>>start;
        if(start<1 || cin.fail() ||start>23 || validSleepTime(eventList,start,index)){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;

    }
    eventList[index].set_sleep_time_begin(start);

    valid = true;

    cout<<"\n\nEnter sleeping time end:\n";
    for(int i=start;i<24;i++){
        if(i >= eventList[index].get_start_time() && i <= eventList[index].get_end_time()){
            cout<<i<<". "<<i<<"Event\n";
            continue;
        }
            cout<<i<<". "<<i<<endl;
    }

    while(valid){
        cin>>end;
        if(end<1 || cin.fail() ||end>24 ||end<=start){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;
    }

    eventList[index].set_sleep_time_end(end);

}//end of getUserinfo

bool Event::validSleepTime(vector<Event>& eventList,int i,int index){

    if(i>=eventList[index].get_start_time() && i<=eventList[index].get_end_time()){
            return true;
    }
        return false;
}

double Event::get_location_x(){
    return location_x;
}
void Event::set_location_x(double location_x){
    this->location_x = location_x;
}

double Event::get_location_y(){
    return location_y;
}

void Event::set_location_y(double location_y){
    this->location_y = location_y;
}

unsigned int Event::get_duration(){
    return duration;
}
unsigned int Event::set_duration(unsigned int duration){
    this->duration = duration;
}
time_t Event::get_start_time(){
    return start_time;
}
void Event::set_start_time(time_t start_time){
    this->start_time = start_time;
}

int Event::get_end_time(){
    return end_time;
}
void Event::set_end_time(int end_time){
    this->end_time = end_time;
}
char* Event::get_location_name(int i){
    return location_name[i];
}

void Event::set_sleep_time_begin(time_t slee_time_begin){
    this->sleep_time_begin = slee_time_begin;
}
time_t Event::get_sleep_time_begin(){
    return sleep_time_begin;
}

void Event::set_sleep_time_end(time_t slee_time_end){
    this->sleep_time_end = slee_time_end;
}
time_t Event::get_sleep_time_end(){
    return sleep_time_end;
}

void Event::set_user_loaction(char* input){
    user_loaction = input;
}

char* Event::get_user_loaction(){
    return user_loaction;
}
void Event::set_day(int day){
    this->day = day;
}
int Event::get_day(){
    return day;
}
void Event::set_month(int month){
    this->month = month;
}
int Event::get_month(){
    return month;
}
char* Event::get_task(){
    return task;
}
void Event::set_task(char* task){
    this->task = task;
}
void Event::set_hard_task_list(){

    for(int i=0;i<6;i++){
        hard_task_list[i] = new char[25];
        for(int j=0;j<25;j++){
            hard_task_list[i][j] = '\0';
        }
    }

    strcpy(hard_task_list[0],"Event");
    strcpy(hard_task_list[1],"Exam");
    strcpy(hard_task_list[2],"Assignment");
    strcpy(hard_task_list[3],"Class");
    ///create more location...
}
void Event::set_location_name(){

    for(int i=0;i<25;i++){
        location_name[i] = new char[25];
        for(int j=0;j<25;j++){
            location_name[i][j] = '\0';
        }
    }

    strcpy(location_name[0],"Library West");
    strcpy(location_name[1],"Library Marston");
    strcpy(location_name[2],"Computer Science Building ");
    ///create more location...
}


///not used...
vector<Event> Event::fillVector(vector<Event>& eventList){


    vector<Event> newEvnetLists;


    return newEvnetLists;

}

void Event::makeChange(vector<Event>& HardEvent){

   int index;
   bool valid = true;

   if(HardEvent.size() ==0){
        cout<<"No items to show\n\n";
        return;
   }

    cout<<"choose a number\n";
    cout<<"----- :-------\n";

   for(int i=0;i<HardEvent.size();i++){
        cout<<i+1<<". " <<HardEvent[i].get_month()<<"/"<<HardEvent[i].get_day()<<endl;
   }

   while(valid){
        cin>>index;
        if(index<1 || cin.fail() ||index>HardEvent.size()){
            cout<<"+++ invalid input +++\n\n\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }
        valid = false;
   }

    int field = pickChangeField(HardEvent,index);
    changeField(HardEvent,index-1,field);
}

void Event::changeField(vector<Event>& HardEvent, int index,int field){

    switch(field){
        case 1:
            getStartTime(HardEvent,index);
            break;
        case 2:
            getEndTime(HardEvent[index].get_start_time(),HardEvent,index);
            break;
        case 3:
            getLocation(HardEvent,index);
            break;
        case 4:
        case 5:{
            getSleepingTime(HardEvent,index);
            break;
        }
    }
}

int Event::pickChangeField(vector<Event>& HardEvent, int choice){
    int num;
    bool valid = true;

    cout<<"which field do you want to make a change\n";
    cout<<"1 "<<"Event start  : "<<HardEvent[choice-1].get_start_time()<<endl;
    cout<<"2 "<<"Event End    : "<<HardEvent[choice-1].get_end_time()<<endl;
    cout<<"3 "<<"Location     : "<<HardEvent[choice-1].get_user_loaction()<<endl;
    cout<<"4 "<<"sleep start  : "<<HardEvent[choice-1].get_sleep_time_begin()<<endl;
    cout<<"5 "<<"sleep end  : "<<HardEvent[choice-1].get_sleep_time_end()<<endl<<endl;


    while(valid){
        cin>>num;
        if(num<0 || cin.fail() ||num>6){
            cout<<"+++ invalid input +++\n\n\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }
        valid = false;
    }

    return num;
}
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

