#pragma once
#include<string>
#include<ctime>

namespace date {
    class Date {

    public:

        int year;
        int month;
        int day;
        int time;

        Date(int _year, int _month, int _day, int _time) :
            year(_year), month(_month), day(_day), time(_time) {
        }
        Date() {};
        void set(const Date& d2)
        {
            year = d2.year;
            month = d2.month;
            day = d2.day;
            time = d2.time;
        }
    };

    std::string DateToString(Date date1);

    Date GetLocalTime();

    bool IsVisokosna(int year1);

    bool ValidateDate(Date date1);

}
