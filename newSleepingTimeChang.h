#ifndef NEWSLEEPTIMECHANG_H
#define NEWSLEEPTIMECHANG_H

#include "calender.h"

class newSleepTimeChang{
    public:
        newSleepTimeChang(calender* calen);
        virtual ~newSleepTimeChang();
        int get_new_sleep_start();
        void set_new_sleep_start(int a);
        int get_new_sleep_end();
        void set_new_sleep_end(int a);
        void get_new_sleep(int month,int day);
        int getChnageDay(int month,int day);
        int getSleepTime(int num,int i,int day);
        bool validTimeFrame(int time);
        bool validTimeFrameEnd(int time,int new_ss);

    protected:
        calender* calen;
        int new_sleep_start;
        int new_sleep_end;
        int* sleepStarts;
        int* sleepEnds;
    private:
};

#endif // NEWSLEEPTIMECHANG_H
