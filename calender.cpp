#include "calender.h"
#include "string.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


calender::calender(int size){
    calenderChar = new char*[size];///24hours * 7 days
    calenderBool = new bool[size];
    counter = 0;

    for(int i=0;i<size;i++){
        calenderBool[i] = false;
    }

}

calender::~calender()
{
    //dtor
}
bool calender::setCalenderBoolToTrue(int a){
    calenderBool[a] = true;
};

bool calender::setCalenderBoolToFalse(int a){
     calenderBool[a] = false;
};
void calender::setcaleCderChar(int a,char* b){
    calenderChar[a] = b;
};
bool calender::getcaleCderChar(int a){
    return calenderChar[a];
};

void calender::showCalender(vector<Event>& eventList,vector<Soft>& softEvent,int month,int day){
    int tempDay =day+1;
    if(eventList.size() == 0 && softEvent.size()==0){
        cout<<"\t\tNo item to show \n\n";
    }

    for(int i =0;i<eventList.size();i++){
        getTimeFrameHardEvent(eventList,calenderChar,calenderBool,day,i);
    }


    day = day+1;
    cout<<"Time   |\t";
    for(int i=0;i<7;i++){
        cout<<month<<"/"<<day<<"\t";
        day++;
    }
        cout<<"\n\n";


    /*

    display the one week schedule

    */
    for(int i=0;i<24;i++){
        int p=i;
        int count=0;
        if(i<10)
            cout<<i<<"      |\t";
        else
            cout<<i<<"     |\t";

        for(int j=0;j<168;j++){
            if(count == 7){
                j = 168;///to stop the array
                continue;
            }
            if(j == i || j == p){

                ///if calenderBool is true
                ///display the corresponding value in calenderChar
                if(calenderBool[j])
                    cout<<calenderChar[j]<<"\t";
                else
                    cout<<"\t";
                p=p+24;///24 represents one day
                count++;
            }
        }
        cout<<"\n";
    }

    if(get_counter() < softEvent.size())
        getTimeFrameSoftEvent(softEvent,tempDay);

}//end of showCalender

void calender::getTimeFrameHardEvent(vector<Event>& eventList,char** calenderChar,bool* calenderBool,int day,int index){

    int times = eventList[index].get_day() -day-1;
    int start = eventList[index].get_start_time();
    int end = eventList[index].get_end_time();
    int diff = end-start;
    //cout<<start<<" "<<end<<endl;

    ///get a time frame of task
    if(times != 0){
        start = start+24*times;
        end = start+diff;
    }

    for(int i=start;i<=end;i++){
        cout<<i<<endl;
        calenderBool[i] = true;
        calenderChar[i] = eventList[index].get_task();
    }
}

void calender::getTimeFrameSoftEvent(vector<Soft>& softEvent,int day){
    ///check is if soft event cen be done before due

    ///temp array for schedule
    bool* schedule  = new bool[169];

    ///copy schedule
    for(int i=0;i<168;i++){
        if(i>0)
            schedule[i] = getCalenderBool(i);
    }

    ///check if each soft event fit into the current schedule
    //for(int i=0;i<softEvent.size();i++)
    isFitInSchedule(softEvent,day,get_counter(),schedule);

    ///free up the memory
    delete[] schedule;
}

void calender::isFitInSchedule(vector<Soft>& softEvent,int day,int index,bool* schedule){
    bool* isSchedule = new bool[softEvent.size()+1];

    int times = 0;
    int base=6;

    ///this is for keep track of sleeping time
    for(int j = 0; j<168; j++) {
        if(j<base) {
            schedule[j] = true;///space is already taken
            continue;
        }

        if(j%24==0) {
            times++;
            base = 0;
            base = 6+24*times;
        }

        /*

        sleepStarts = new int[7];
        sleepEnds = new int[7];

        for(int i=0;i<7;i++){
            for(int j=sleepStarts[i];j<=sleepEnds[i];j++){
                schedule[j] = true;
            }
        }


        */
    }


    int mul = softEvent[index].get_day()-day;///how many days
    int due = softEvent[index].get_due();
    int startTimeFrame=0;
    int endTimeFrame=0;
    int duration = softEvent[index].get_duration();
    int consec =0;
    int maxConsec = 0;///keep the max value of consec


    if(mul != 0)
        due = due+mul*24;
    cout<<"due mul "<<due<<" "<<mul<<endl;

//    ///
    for(int i=0; i<due; i++) {
        if(schedule[i])
            cout<<i<<" true\n";
        else
            cout<<i<<" false\n";
    }

    ///check if there is a enough time to complete the task

    /*

        find the best way to fill the soft task
        1.  function 1
            finish the task as earlt as possible

        2. function 2
            finish the task 1-3 days before the dealline

    */

    ///its flag for now but
    ///a user can change one function to the other
    int flag =1;
    if(flag == 0){

        ///funnction 1
        ///find the earliest possible time frame
        findEarliestTimeFrame(due,duration,startTimeFrame,endTimeFrame,schedule,consec,maxConsec);

    }
    else{

        /*


            do another method of fitting the soft task


            this function will assinged time frame for the soft task based on due
            find a best(possible) fit
            The time frame will not be determined based on free time availble
        */
            fintBestFit(due,duration,startTimeFrame,endTimeFrame,schedule,consec,maxConsec);

    }


///just comment for now
    cout<<"Start:End "<<startTimeFrame<<" "<<endTimeFrame<<endl;

    if(maxConsec>=softEvent[index].get_duration()) {
        cout<<"has enough room for task - "<<softEvent[index].get_task()<<endl;

        fitSoftTask(softEvent,startTimeFrame,endTimeFrame,index);
        increment_counter();

    } else{
        cout<<"***   not enough time to compelte the task *** \n"<<
        "\t\t"<<softEvent[index].get_task()<<":"<<softEvent[index].get_month()<<"/"<<softEvent[index].get_day()<<
        "\n\n\n"<<endl;

    }

}

void calender::fintBestFit(int due,int duration,int& startTimeFrame,int& endTimeFrame,bool* schedule,int&consec,int& maxConsec){

    if(hasEnoughTime(schedule)){
        cout<<"";
    }



}//end of findBestFit

bool calender::hasEnoughTime(bool* schedule){
    int i=0;
    while(i<168){
        if(schedule[i])
            cout<<i+1<<" "<<"Taken\n";
        else
            cout<<i+1<<" "<<"FREE\n";
        i++;
    }



}

void calender::findEarliestTimeFrame(int due,int duration,int& startTimeFrame,int& endTimeFrame,bool* schedule,int&consec,int& maxConsec){

    bool isStarted = false;
    bool isEnded = false;

    for(int a = 0; a<=due; a++) {
        if(a+1<=due) {

            ///i can change this to just see the blank space
            ///instead of sequence of blank space
            if(schedule[a] == false && schedule[a+1] == false) {
                consec++;
                ///have a flag valiale to do one or the other for ifs


                ///this finds the earliest starting point possible for the soft task
                if(!isEnded) {
                    if(!isStarted) {
                        startTimeFrame = a;
                        isStarted = true;
                    }
                    cout<<"consec:due "<<consec<<" "<<duration<<endl;
                    if(consec == duration) {
                        endTimeFrame  = a;
                        isEnded = true;
                    }
                }
                ///////////////

                if(consec>maxConsec) {
                    maxConsec = consec;
                }
                continue;
            }
            consec =0;
        }
    }
}//end of findEarliestTimeFrame


void calender::fitSoftTask(vector<Soft>& softEvent,int startTimeFrame,int endTimeFrame,int index){

    cout<<startTimeFrame<<" "<<endTimeFrame<<endl;
    int i=0;

    for(i=startTimeFrame;i<=endTimeFrame;i++){
        calenderBool[i] = true;
        calenderChar[i] = softEvent[index].get_task();
    }

};

bool calender::getCalenderBool(int a){
    return calenderBool[a];
};

int calender::get_counter(){
    return counter;
}
void calender::increment_counter(){
    this->counter++;
}
