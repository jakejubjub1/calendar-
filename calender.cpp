#include "calender.h"
#include "string.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


calender::calender(int size){
    calenderChar = new char*[size];///24hours * 7 days
    calenderBool = new bool[size];

    for(int i=0;i<size;i++){
        calenderBool[i] = false;
    }

}

calender::~calender()
{
    //dtor
}

void calender::showCalender(vector<Event>& eventList,vector<Soft>& softEvent,int month,int day){

    if(eventList.size() == 0 && softEvent.size()==0){
        cout<<"\t\tNo item to show \n\n";
    }

    for(int i =0;i<eventList.size();i++){
        getTimeFrame(eventList,calenderChar,calenderBool,day,i);
    }

    day = day+1;
    cout<<"Time   |\t";
    for(int i=0;i<7;i++){
        cout<<month<<"/"<<day<<"\t";
        day++;
    }
        cout<<"\n\n";
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

                if(calenderBool[j])
                    cout<<calenderChar[j]<<"\t";
                else
                    cout<<"\t";
                p=p+24;
                count++;
            }
        }
        cout<<"\n";
    }

}//end of showCalender

void calender::getTimeFrame(vector<Event>& eventList,char** calenderChar,bool* calenderBool,int day,int index){

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
    //int start = eventList->

}
