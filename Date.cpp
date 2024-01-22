#include "Date.hpp"

std::string date::DateToString(date::Date date1) {
    std::string res = "";
    res += std::to_string(date1.time / 100);
    res += ":";
    res += std::to_string(date1.time % 100);
    res += "/";
    res += std::to_string(date1.day);
    res += "/";
    res += std::to_string(date1.month);
    res += "/";
    res += std::to_string(date1.year);
    return res;
}

date::Date date::GetLocalTime() {
    struct tm ltm;
    std::time_t now = time(0);
    localtime_s(&ltm, &now);
    date::Date localtime(1900 + ltm.tm_year, 1 + ltm.tm_mon, ltm.tm_mday, ((ltm.tm_hour) * 100) + ltm.tm_min);

    return localtime;
}

bool date::IsVisokosna(int year1) {
    if (year1 % 400 == 0) return true;
    if (year1 % 100 == 0) return false;
    if (year1 % 4 == 0) return true;
    return false;
}

bool date::ValidateDate(date::Date date1) {

    date::Date localtime;
    localtime.set(GetLocalTime());
    if (localtime.time < date1.time || localtime.day < date1.day ||
        localtime.month < date1.month || localtime.year < date1.year) return false;

    if (IsVisokosna(date1.year) && date1.month == 2 && date1.day > 29) return false;

    if (date1.month > 12) return false;

    int daysOfMonths[12] = { 31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31 };
    //                       jan, feb, mar, apr, may, jun, jul, aug, sep, okt, noe, dec

    if (date1.day > daysOfMonths[date1.month - 1]) return false;

    if (date1.time / 100 > 23) return false;
    if (date1.time % 100 > 59) return false;

    return true;
}
