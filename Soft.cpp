#include "Soft.h"
#include "string.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

Soft::Soft(){
    //ctor

    location_name = new char*[25];
    soft_task_list = new char*[6];
    set_location_name();
    set_hard_task_list();
}


Soft::~Soft()
{
    //dtor
}

void Soft::getDueTime(vector<Soft>& softEvent,int index){

    int due;
    bool valid = true;

    cout<<"Pick due time"<<endl;
    for(int i=0;i<24;i++){
        cout<<i+1<<". "<<i<<endl;
    }


    while(valid){
        cin>>due;
        if(cin.fail() || due<1 ||due >25){
            std::cout<<"\n*** Invalid input ***\n";
            std::cout<<"    Enter an Integer\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }
        softEvent[index].set_due(due-1);
        valid = false;
    }

};

void Soft::getDate(vector<Soft>& softEvent,int index,int month, int day){
    int* dayArray = new int[7];
    int getDay;
    bool valid = true;

    softEvent[index].set_month(month);///initializing

    ///day
    int j=0;
    int i;

    for(i =day;i<day+7;i++){
        dayArray[j] =i+1;
        cout<<j+1<<" "<<month<<"/"<<i+1<<endl;
        j++;
    }

    cout<<"choose Due day:";

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

        softEvent[index].set_day(dayArray[getDay-1]);///initializing
        valid = false;
    }

}//end of getDate

void Soft::getTask(vector<Soft>& softEvent,int index){

    bool valid = true;
    int choice;
    for(int i=0;i<3;i++){
        cout<<i+1<<". "<<soft_task_list[i]<<endl;
    }
    cin>>choice;

    while(valid){
        if(choice<1 || cin.fail() ||choice>5){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;
    }
    softEvent[index].set_task(soft_task_list[choice-1]);
}

void Soft::getDuration(vector<Soft>& softEvent,int index){

    bool valid = true;
    int estimatedHours;
    cout<<"How long Do you think it's going to take?\n";
    cout<<"Enter extimated hour no more than 15 hours \n";

    while(valid){
        cin>>estimatedHours;
        if(estimatedHours<1 || cin.fail() ||estimatedHours>15){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;
    }

    softEvent[index].set_duration(estimatedHours);
}

void Soft::getLocation(vector<Soft>& softEvent,int index){
    bool valid = true;
    int pick;
    cout<<"choose location\n";

    for(int i=0;i<25;i++){
        cout<<i+1<<". "<<get_location_name(i)<<endl;
    }

    while(valid){
        cin>>pick;
        if(pick<1 || cin.fail() ||pick>25){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;
    }

    softEvent[index].set_user_location(get_location_name(pick-1));
}

///getter and setter
void Soft::set_location_name(){
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


///getters and setters
char* Soft::get_location_name(int i){
    return location_name[i];
};

int Soft::get_day(){
    return day;
}
void Soft::set_day(int day){
    this->day =day;
}

int Soft::get_month(){
    return  month;
}

void Soft::set_month(int month){
    this->month =month;
}

int Soft::get_hour(){
    return time_hour;
}
void Soft::set_hour(int hour){
    this->time_hour =hour;
}

int Soft::get_min(){
    return  time_min;
}

void Soft::set_min(int time_min){
    this->time_min=time_min;
}

int Soft::get_duration(){
    return  duration;
}

void Soft::set_duration(int duration){
    this->duration = duration;
}
void Soft::set_user_location(char* a){
    this->user_loaction = a;
}
char* Soft::get_user_location(){
    return this->user_loaction;
}
char* Soft::get_task(){
    return task;
}
void Soft::set_task(char* task){
    this->task = task;
}
int Soft::get_due(){
    return due;
};
void Soft::set_due(int due){
    this->due = due;
};
void Soft::set_hard_task_list(){

    for(int i=0;i<6;i++){
        soft_task_list[i] = new char[25];
        for(int j=0;j<25;j++){
            soft_task_list[i][j] = '\0';
        }
    }

    strcpy(soft_task_list[0],"Goal");///
    strcpy(soft_task_list[1],"study");
    strcpy(soft_task_list[2],"gym");
}
int Soft::findBestDay(vector<Soft>& softEvent, int index){
    //worst fit algorithm  
};
void Soft::addToHard(vector<Soft>& softEvent,int index){
    //add to hard tasks
}



