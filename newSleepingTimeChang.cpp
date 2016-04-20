#include "newSleepTimeChang.h"
#include "Soft.h"
#include "event.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>




//newSleepTimeChang::newSleepTimeChang(): calender(168)
newSleepTimeChang::newSleepTimeChang(calender* calend) : calen(calend){

    sleepStarts = new int[7];
    sleepEnds = new int[7];

    int start =0;
    int end =6;

    for(int i=0;i<7;i++){
        if(i>0){
            start = start+24;
            end  = end+24;
        }
        sleepStarts[i] = start;
        sleepEnds[i] = end;
    }
    for(int i=0;i<7;i++)
        cout<<" yes "<<sleepStarts[i]<<" "<<sleepEnds[i]<<endl;

    bool isValid = false;
    int j=0;

    for(int i=0;i<167;i++){
        if(i>=sleepStarts[j] && i<sleepEnds[j]){
            calen->setCalenderBoolToTrue(i);
            char* a = new char[6];
            strcpy(a,"sleep");
            calen->setcaleCderChar(i,a);
            isValid = true;
            continue;
        }
        if(isValid){
            j++;
            isValid = false;
        }
    }

}

newSleepTimeChang::~newSleepTimeChang(){

    //dtor
}

void newSleepTimeChang::get_new_sleep(int month,int day){

    int changeDay = getChnageDay(month,day+1);
    int old_ss = sleepStarts[changeDay-1];///ss sleep start
    int old_se = sleepEnds[changeDay-1];///sleep ends



    for(int i = old_ss;i<=old_se;i++){
        ///set value to false
        ///free  sleep time
        calen->calenderBool[i] = false;
       //setCalenderBoolToFalse(i);
        //setcaleCderChar();


        ///setCalenderBoolToFalse(i);
    }

    int new_ss = getSleepTime(1,changeDay-1,changeDay-1);
    int new_se = getSleepTime(2,new_ss,changeDay-1);

    ///getting new sleeping time


    if(0<changeDay-1){
        new_ss = new_ss+24*(changeDay-1);
        new_se = new_se+24*(changeDay-1);
    }

    sleepStarts[changeDay-1] = new_ss;
    sleepEnds[changeDay-1] = new_se;

    cout<<"\n\n\n\n chnageDay is "<<changeDay<<"\n\n\n";
    cout<<new_ss<<" "<<new_se<<endl;
    for(int i = new_ss;i<=new_se;i++){
        ///set value to true
        ///assign new sleep time
        calen->setCalenderBoolToTrue(i);
        char* temp = new char[6];
        strcpy(temp,"sleep");
        calen->setcaleCderChar(i,temp);


        ///setCalenderBoolToTrue(i);
    }

    ///test
    for(int i = 0;i<=168;i++){
            if(calen->getCalenderBool(i))
                cout<<i<<". "<<calen->getcaleCderChar(i)<<endl;
            else
                cout<<i<<". "<<"Free\n";
    }
}///end of newSleepTimeChang

int newSleepTimeChang::getSleepTime(int num,int changeDay,int day){

    bool valid = true;
    int newTime;

    if(num == 1){

        for(int i=0;i<24;i++){
            cout<<i<<". "<<i<<endl;

        }
        /*
        int i = 24*chnageDay;
        int j = 24*(chnageDay+1);
        if(j>168)
            j = 168

        for(i;i<=j;i++){
            if(getCalenderBool(i))
                cout<<i<<". "<<getcaleCderChar(i)<<endl;
            else
                cout<<i<<". <<"Free\n";
        }

            */


        while(valid){
            cout<<"enter new sleeping start time :";
            cin>>newTime;

            if(cin.fail() ||validTimeFrame(newTime)){
                std::cout<<"\n*** Invalid input ***\n";
                std::cout<<"    Enter an Integer\n";
                cin.clear();
                cin.ignore(255, '\n');
                continue;
            }
            valid = false;
        }
        return newTime;
    }
    else{
        int new_ss = changeDay;
        cout<<"Enter a new sleeping end time :";

        cout<<"chnaeday : "<<changeDay<<endl;
        int i = 24*day+changeDay;
        int j = 24*(day+1)+24;

        if(j>168)
            j = 168;

        int count = changeDay+1;
        for(i;i<=j;i++){
            if(calen->getCalenderBool(i))
                cout<<count<<". "<<calen->getcaleCderChar(i)<<endl;
            else
                cout<<count<<". "<<"Free\n";

                count++;
        }


        while(valid){
            cin>>newTime;
            if(cin.fail() || !validTimeFrameEnd(newTime,new_ss)){
                std::cout<<"\n*** Invalid input ***\n";
                std::cout<<"    Enter an Integer\n";
                cin.clear();
                cin.ignore(255, '\n');
                continue;
            }
            valid = false;
        }

        return newTime;
    }

}
bool newSleepTimeChang::validTimeFrameEnd(int new_se,int new_ss){


    ///if there is a plan in between then no
    while(new_ss<new_se){
        if(calen->getCalenderBool(new_ss))
            return false;
        new_ss++;
    }
    return true;
}

bool newSleepTimeChang::validTimeFrame(int time){

    ///check if time is valid
    ///at least 2 hours of sleep
    cout<<calen->getCalenderBool(time)<<" "<<calen->getCalenderBool(time+1)<<endl;
    if(!calen->getCalenderBool(time) && !calen->getCalenderBool(time+1)){
        cout<<"true\n";
        return false;
    }
    cout<<"false\n";
    return true;
}


int newSleepTimeChang::getChnageDay(int month,int day){

    int choice=0;
    bool valid = true;

    cout<<"\n\nwhat day of sleeping schedule do you want to change \n";

    for(int i =0 ;i<7;i++){
        cout<<i+1<<". "<<month<<"/"<<day+i<<"\n";
    }

    while(valid){
        cin>>choice;
        if(cin.fail() ||choice>7 || choice<1 ){
            std::cout<<"\n*** Invalid input ***\n";
            std::cout<<"    Enter an Integer\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }
        valid = false;
    }

    return choice;
}

int newSleepTimeChang::get_new_sleep_start(){
    return new_sleep_start;
};
void newSleepTimeChang::set_new_sleep_start(int new_sleep_start){
    this->new_sleep_start = new_sleep_start;
};
int newSleepTimeChang::get_new_sleep_end(){
    return new_sleep_end;
};
void newSleepTimeChang::set_new_sleep_end(int new_sleep_end){
    this->new_sleep_end = new_sleep_end;
};
