#include "timeStamp.h"
#include <iostream>

using namespace std;

timeStamp::timeStamp()
{
}
timeStamp::timeStamp(int second, int minute, int hour)
{
    this->second = second;
    this->minute = minute;
    this->hour = hour;
}

bool timeStamp::operator==(timeStamp t)
{
    if ((second == t.second) && (minute == t.minute) && (hour == t.hour))
        return true;
    else
        return false;
}

bool timeStamp::operator!=(timeStamp t)
{
    if (!(second == t.second) && (minute == t.minute) && (hour == t.hour))
        return true;
    else
        return false;
}

bool timeStamp::operator>(timeStamp t)
{
    if ((hour > t.hour) || ((hour == t.hour) && (minute > t.minute)) || ((hour == t.hour) && (minute == t.minute) && (second > t.second)))
        return true;
    else
        return false;
}

bool timeStamp::operator<(timeStamp t)
{
    if ((hour < t.hour) || ((hour == t.hour) && (minute < t.minute)) || ((hour = t.hour) && (minute == t.minute) && (second < t.second)))
        return true;
    else
        return false;
}

ostream &operator<<(ostream &os, timeStamp &t)
{
    os << t.second << ":" << t.minute << ":" << t.hour;
    return os;
}